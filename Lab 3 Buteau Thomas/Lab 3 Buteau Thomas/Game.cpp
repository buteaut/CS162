/*********************************************************************************
** Program name: Lab 3 (Game Implementation File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: Game implementation file for Lab 3. The Game class has two 
**				dynamically	allocated objects of either Die or LoadedDie classes. 
**				It also has	a variable for each player to keep track of number of 
**				rounds won. There is a setDie method that generates either a Die 
**				or LoadedDie object. There is a menu method that displays options 
**				to the user	with input validation for user inputs. There is a play 
**				method that rolls the die of each player, displays the results, 
**				and	increments the correct player's win count for the specified
**				number of rounds. Finally, there is a results method which
**				displays the final results of the game then deletes the
**				Die/LoadedDie objects and resets the win counts and number of
**				rounds to zero.
*********************************************************************************/

#include "Game.hpp"

//default constructor
Game::Game()
{
	player1Wins = 0;
	player2Wins = 0;
}

//deconstructor
Game::~Game()
{
	delete player1;
	player1 = NULL;
	delete player2;
	player2 = NULL;
}

/*****************************************************************************
**						Game::setDie
** Description: Assigns either a Die or LoadedDie object with numSides sides
**				to either player1 or player2.
**
*****************************************************************************/
void Game::setDie(int numSides, bool Loaded, int playerNum)
{
	if (playerNum == 1)
	{
		if (Loaded == true)
		{
			player1 = new LoadedDie(numSides);
		}

		else if (Loaded == false)
		{
			player1 = new Die(numSides);
		}
	}

	else if (playerNum == 2)
	{
		if (Loaded == true)
		{
			player2 = new LoadedDie(numSides);
		}

		else if (Loaded == false)
		{
			player2 = new Die(numSides);
		}
	}

	//else statement for debugging purposes
	else
	{
		std::cout << "Error in setDie method playerNum argument." << std::endl;
	}
		
}

/*****************************************************************************
**						Game::menu
** Description: Presents the user options to set the dice, start the game, or
**				exit the program. Includes input verification.
**
*****************************************************************************/
void Game::menu()
{
	std::string strChoice;
	int choice;
	bool exit = false;


	std::cout << "CS162 Lab 3 'Dice War'" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Main Menu: " << std::endl;
		std::cout << "1. Configure dice." << std::endl;
		std::cout << "2. Play dice war." << std::endl;
		std::cout << "3. Exit program." << std::endl;

		std::cin >> strChoice;
		while (!intVal(strChoice, 1)) //calls the integer validation function
		{
			std::cout << "User input invalid, please try again." << std::endl;
			strChoice = "";
			std::cin >> strChoice;
		}
		choice = atoi(strChoice.c_str());
		strChoice = "";

		if (choice > 0 && choice < 4)
		{
			if (choice == 1) //configure dice
			{
				int numSides;
				std::string inputUser;
				bool Loaded;

				for (int i = 1; i < 3; i++)
				{
					std::cout << "Enter the number of sides for player "
						<< i << "'s die between 1 and 999." << std::endl;
					std::cin >> inputUser;

					//calls the positive integer validation function
					while (!intValPosRanged(inputUser, 3, 1, 999))
					{
						std::cout << "User input invalid, please try again."
							<< std::endl;
						inputUser = "";
						std::cin >> inputUser;
					}
					numSides = atoi(inputUser.c_str());
					strChoice = "";

					std::cout << "Is the die loaded?" << std::endl;
					std::cout << "1 for yes or 0 for no." << std::endl;
					std::cin >> inputUser;

					//calls the positive integer validation function
					while (!intValPosRanged(inputUser, 1, 0, 1))
					{
						std::cout << "User input invalid, please try again."
							<< std::endl;
						inputUser = "";
						std::cin >> inputUser;
					}
					Loaded = atoi(inputUser.c_str());
					strChoice = "";

					//creates die
					setDie(numSides, Loaded, i);
				}
			}

			if (choice == 2) //play dice war
			{
				if (player1 == NULL || player2 == NULL)
				{
					std::cout << "Please configure the dice before playing." 
						<< std::endl;
				}

				else
				{
					int rounds;
					std::string strRounds;
					
					std::cout << "Enter a number of rounds between 1 and 999." 
						<< std::endl;
					std::cin >> strRounds;
					while (!intValPosRanged(strRounds, 3, 1, 999)) //calls the positive 
													 //integer validation
													 //function
					{
						std::cout << "User input invalid, please try again." 
							<< std::endl;
						strRounds = "";
						std::cin >> strRounds;
					}
					rounds = atoi(strRounds.c_str());
					strChoice = "";
					
					play(rounds);
				}
			}

			if (choice == 3) //exit
			{
				exit = true;
			}
		}
		else
		{
			std::cout << "Input outside of range. Please enter a number "
				<< "between 1 and 3." << std::endl;

		}
		} while (exit == false);
}

/*****************************************************************************
**						Game::play
** Description: Calls the roll method for both player Die/LoadedDie objects
**				a number of times equal to the rounds argument. It compares
**				the results of the rolls and increments the appropriate
**				player win count as well as displays a message detailing the
**				round. When all round are complete it calls the results 
**				method.
**
*****************************************************************************/
void Game::play(int rounds)
{
	int tempP1;
	int tempP2;

	for (int i = 0; i < rounds; i++)
	{
		tempP1 = 0; //ensures no carryover from previous loop
		tempP2 = 0; //ensures no carryover from previous loop
		std::cout << std::endl;
		std::cout << "Round " << i << ":" << std::endl;
		tempP1 = player1->roll();
		std::cout << "Player 1 rolled: " << tempP1 << std::endl;
		tempP2 = player2->roll();
		std::cout << "Player 2 rolled: " << tempP2 << std::endl;

		if (tempP1 > tempP2)
		{
			player1Wins++;
			std::cout << "Player 1 has won the round." << std::endl;
		}

		else if (tempP2 > tempP1)
		{
			player2Wins++;
			std::cout << "Player 2 has won the round." << std::endl;
		}

		else
		{
			std::cout << "The round ends in a draw." << std::endl;
		}
	}

	results();
}

/*****************************************************************************
**						Game::results
** Description: Displays the winner of the game then deletes the player
**				pointers and resets the playerWins to 0.
**
*****************************************************************************/
void Game::results()
{
	int winner = 0;
	if (player1Wins > player2Wins)
	{
		winner = 1;
	}
	else if (player2Wins > player1Wins)
	{
		winner = 2;
	}

	if (winner != 0)
	{
		std::cout << std::endl;
		std::cout << "Congratulations player " << winner << ", you've won!" << std::endl;	
	}

	else if (winner == 0)
	{
		std::cout << std::endl;
		std::cout << "The game ends in a draw!" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "The final score is " << std::endl;
	std::cout << "Player 1: " << player1Wins << std::endl;
	std::cout << "Player 2: " << player2Wins << std::endl;

	//resets game variables to play again
	delete player1;
	player1 = NULL;
	delete player2;
	player2 = NULL;

	player1Wins = 0;
	player2Wins = 0;

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.get();
	std::cin.get();

}