/*********************************************************************************
** Program name: Lab 3 (Game Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: Game header file for Lab 3. The Game class has two dynamically 
**				allocated objects of either Die or LoadedDie classes. It also has
**				a variable for each player to keep track of number of rounds won.
**				There is a setDie method that generates either a Die or LoadedDie
**				object. There is a menu method that displays options to the user
**				with input validation for user inputs. There is a play method
**				that rolls the die of each player, displays the results, and 
**				increments the correct player's win count for the specified
**				number of rounds. Finally, there is a results method which
**				displays the final results of the game then deletes the 
**				Die/LoadedDie objects and resets the win counts and number of 
**				rounds to zero.
*********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include "integerValidation.hpp"
#include "LoadedDie.hpp"
#include <string>

class Game
{
private:
	Die *player1;
	Die *player2;
	int player1Wins;
	int player2Wins;

public:
	Game(); //default constructor
	~Game(); //deconstructor

	void setDie(int numSides, bool Loaded, int playerNum);
	void menu();
	void play(int rounds);
	void results();


};

#endif