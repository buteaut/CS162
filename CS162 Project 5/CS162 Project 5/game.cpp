/*********************************************************************************
** Program name: Project 5 (Game Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Game implementation file. 
**
*********************************************************************************/

#include "game.hpp"

Game::Game() //default constructor
{
//determintes OS and sets appropriate 'clear screen' command
#if defined(_WIN32)
	{
		clear = "cls";
	}
#endif

#if defined(__linux__)
	{
		clear = "clear";
	}
#endif

	this->air = 100;
	this->power = 100;
	this->airpatch = false;
	this->elecpatch = false;
	this->gambling = false;
	this->exit = false;
	
}

Game::Game(Rooms* r) //constructor
{
	//determintes OS and sets appropriate 'clear screen' command
#if defined(_WIN32)
	{
		clear = "cls";
	}
#endif

#if defined(__linux__)
	{
		clear = "clear";
	}
#endif

	this->air = 100;
	this->power = 100;
	this->airpatch = false;
	this->elecpatch = false;
	this->currentLocation = r;


}

Game::~Game() //destructor
{
	//left blank for now
}

/*********************************************************************************
**								Game::tick
** Description: Decriments both power and air to simulate time passing.
**
*********************************************************************************/
void Game::tick()
{
	if (!elecpatch)
	{
		--power;
	}
	if (!airpatch)
	{
		air -= 5;
	}
	else
	{
		--air;
	}
}

/*********************************************************************************
**								Game::clearScreen
** Description: Clears the terminal screen.
**
*********************************************************************************/
void Game::clearScreen()
{
	std::system(clear.c_str());
}

/*********************************************************************************
**								Game::writeStatus
** Description: Writes the current air and power supplies as well as the current
**				room name to the terminal.
**
*********************************************************************************/
void Game::writeStatus()
{
	std::cout << "Air supply" << std::setw(40) << std::right << "Current location"
		<< std::setw(40) << std::right << "Power remaining" << std::endl;
	std::cout << air << "%" << std::setw(46) << std::right
		<< currentLocation->getName() 
		<< std::setw(46 - (currentLocation->getName()).length()) << std::right
		<< power << "%" << std::endl;
	std::cout << std::endl;
}

/*********************************************************************************
**								Game::writeDes
** Description: Writes the current room's description to the terminal.
**
*********************************************************************************/
void Game::writeDes()
{
	std::cout << currentLocation->getDescription() << std::endl << std::endl;
}

/*********************************************************************************
**								Game::writeEvents
** Description: Writes the current events to the terminal.
**
*********************************************************************************/
void Game::writeEvents()
{
	std::cout << events << std::endl << std::endl;
	events = "";
}

/*********************************************************************************
**								Game::writeMenu
** Description: Write the menu of options to the terminal.
**
*********************************************************************************/
void Game::writeMenu()
{
	std::cout << "1: Go north" << std::endl;
	std::cout << "2: Go south" << std::endl;
	std::cout << "3: Go east" << std::endl;
	std::cout << "4: Go west" << std::endl;

	std::cout << "5: Search the " + currentLocation->getName() << std::endl;
	std::cout << "6: Perform actions" << std::endl;
	std::cout << "7: Take items" << std::endl;

}

/*********************************************************************************
**								Game::endGame
** Description: Method to get room information back to game class. Number
**				returned is used by Game::action to flip conditional triggers.
**
*********************************************************************************/
void Game::endGame()
{
	this->clearScreen();

	if (this->air < 1) //out of air
	{
		std::cout << "As the last of the air runs out you wonder what you could "
			<< "have done differently." << std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	else if (this->power < 1) //out of power
	{
		std::cout << "The hum of the engines dies. An ominous silence envelops "
			<< "you as you sit in the dark pondering how long the air supply "
			<< "will last." << std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	else if (this->airpatch == true && this->elecpatch == true) //all issues fixed
	{
		std::cout << "The damage to the hull has been repaired, and the reactor "
			<< "has been stabilized. \nA sigh of relief turns into a groan as you "
			<< "look at your watch and see your shift \nstarts in 7 minutes."
			<< std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	else if (this->gambling == true && this->airpatch == true) //fixed reactor without fixing short
	{
		std::cout << "You know that with the short in the system there is only a "
			<< "10% chance the reactor will \nrestart successfully. Maybe it is the"
			<< " lowered oxygen level, but you're feeling lucky as \nyou reset the "
			<< "system.";
		std::cout << std::endl << std::endl;
		std::cout << "Your reckless endangerment of the ship and crew paid off "
			<< "this time. Best not let the \ncaptain know of your gambling ways."
			<< std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	else //failed
	{
		std::cout << "You know that with the short in the system there is only a "
			<< "10% chance the reactor will \nrestart successfully. Maybe it is the"
			<< " lowered oxygen level, but you're feeling lucky as \nyou reset the "
			<< "system.";
		std::cout << std::endl << std::endl;
		std::cout << "You have failed at your mission. The entire crew is doomed "
			<< "to die." << std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	std::cout << "Press enter to quit." << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::string foo;
	std::getline(std::cin, foo);
}

/*********************************************************************************
**								Game::addItem
** Description: Checks if the current room has items. If so, it will add it to 
**				the player inventory. If the player inventory is full it will
**				call the exchangeItem method to switch items.
**
*********************************************************************************/
void Game::addItem()
{
	if (currentLocation->itemReport() != 0)
	{
		if (inventory.size() > 1)
		{
			int choice;
			events = "You will have to drop something if you want to take another item.";
			events += "\n1. Drop the " + inventory.front() + " and take the " + currentLocation->itemName();
			events += "\n2. Drop the " + inventory.back() + " and take the " + currentLocation->itemName();
			events += "\n3. Keep current items and leave the " + currentLocation->itemName();

			clearScreen();
			writeStatus();
			writeDes();
			writeEvents();

			choice = valIntPos(1, 1, 3);

			if (choice == 3)
			{
				events = "";
			}

			else
			{
				exchangeItem(choice);
			}
		}

		else
		{
			inventory.push_back(currentLocation->getItem());
			events = "You take the " + inventory.back() + ".";
		}
	}

	else //no items in room
	{
		events = "An exhaustive search of the " + currentLocation->getName() +
			" yields no items of use for the tasks at hand.";
	}
}

/*********************************************************************************
**								Game::exchangeItem
** Description: Transfers items between the Game object and the current Room;
**
*********************************************************************************/
void Game::exchangeItem(int foo)
{
	if (foo = 1) //exchange first inventory item with room
	{
		std::string item = inventory.front();
		exchange.push_back(inventory.back()); //item 2 to exchange
		inventory.pop_back();

		exchange.push_back(inventory.back()); //item 1 to exchange
		inventory.pop_back();

		inventory.push_back(currentLocation->getItem()); //room item to inventory

		currentLocation->setItem(exchange.back()); //item 1 to room
		exchange.pop_back();

		inventory.push_back(exchange.back()); //item 2 to inventory
		exchange.pop_back();
		events = "You drop the " + item + " and take the " + inventory.front();
	}

	else if (foo = 2) //exchange second inventory item with room
	{
		std::string item = inventory.back();
		exchange.push_back(inventory.back()); //item 2 to exchange
		inventory.pop_back();

		inventory.push_back(currentLocation->getItem()); //room item to inventory

		currentLocation->setItem(exchange.back()); //item 2 to room
		exchange.pop_back();
		events = "You drop the " + item + " and take the " + inventory.back();
	}

	else
		std::cout << "Error with exhangeItem" << std::endl;
}

/*********************************************************************************
**								Game::travel
** Description: Changes the current room to the chosen connected room.
**
*********************************************************************************/
void Game::travel(int foo)
{
	if (foo == 1) //north
	{
		if (currentLocation->getNorth() == NULL)
		{
			events = "You are unable to go north from here.";
		}
		else
		{
			currentLocation = currentLocation->getNorth();
		}
	}
	if (foo == 2) //south
	{
		if (currentLocation->getSouth() == NULL)
		{
			events = "You are unable to go south from here.";
		}
		else
		{
			currentLocation = currentLocation->getSouth();
		}
	}
	if (foo == 3) //east
	{
		if (currentLocation->getEast() == NULL)
		{
			events = "You are unable to go east from here.";
		}
		else
		{
			currentLocation = currentLocation->getEast();
		}
	}
	if (foo == 4) //south
	{
		if (currentLocation->getWest() == NULL)
		{
			events = "You are unable to go west from here.";
		}
		else
		{
			currentLocation = currentLocation->getWest();
		}
	}
}

/*********************************************************************************
**								Game::search
** Description: Changes events to reflect if there are any items or actions in 
**				the current room.
**
*********************************************************************************/
void Game::search()
{
	std::string roomItem = "";
	std::string roomAction = currentLocation->hasAction();
	std::string roomDes = currentLocation->actionDescription();

	if (currentLocation->itemReport() > 0)
	{
		roomItem = currentLocation->itemName();
	}
	
	if (roomItem != "")
	{
		events += "After searching the room you find " + roomItem + ". \n";
	}
	if (roomAction != "")
	{
		events += roomDes;
	}
	if (roomAction == "" && roomItem == "")
	{
		events = "A long search of the room turns up nothing of use.";
	}
}

/*********************************************************************************
**								Game::action
** Description: Carries out an action on the current room if able. Will change
**				airpatch or elecpatch as needed.
**
*********************************************************************************/
void Game::action()
{
	if (currentLocation->hasAction() != "")
	{
		if (inventory.size() > 0 && (inventory.front() == currentLocation->hasAction()
			|| inventory.back() == currentLocation->hasAction()))
		{
			int action = currentLocation->action();
			if (action == 1)
			{
				airpatch = true;
				events = "The patch on the hull has slowed the air leak";
				events += " by 80%. You've bought enough time to solve \nthe ";
				events += "rest of the ships problems before someone has to ";
				events += "go outside to finish sealing the leak.";
			}
			if (action == 2)
			{
				elecpatch = true;
				events = "Utilizing your toolkit you manage to fix the short";
				events += " in the electrical system.";
			}
			if (action == 3)
			{
				exit = true;
				if (elecpatch)
				{
					events = "With the short in the system repaired you restart";
					events += " the reactor, confident that it will work.";
				}
				else
				{
					int chance = rand() % 100 + 1;
					events = "You know that with the short in the system there";
					events += " is only a 10% chance the reactor will restart ";
					events += "successfully. Maybe it is the lowered oxygen ";
					events += "level, but you're feeling lucky as you reset the";
					events += " system.";
					if (chance >= 90)
					{
						gambling = true;
					}
				}
			}
		}
		else
		{
			events = "You don't have the right equipment to do that.";
		}
	}

	else
	{
		events = "Panic begins to set in as you are unable to think of ";
		events += ("what to do in the " + currentLocation->getName());
	}
}

/*********************************************************************************
**								Game::menu
** Description: Menu method which will call other game methods.
**
*********************************************************************************/
void Game::menu()
{
	int choice = valIntPos(1,1,7);

	if (choice == 1)
	{
		travel(choice);
	}
	if (choice == 2)
	{
		travel(choice);
	}
	if (choice == 3)
	{
		travel(choice);
	}
	if (choice == 4)
	{
		travel(choice);
	}
	if (choice == 5)
	{
		search();
	}
	if (choice == 6)
	{
		action();
	}
	if (choice == 7)
	{
		addItem();
	}

}

/*********************************************************************************
**								Game::play
** Description: Runs the game until the exit conditions have been met.
**
*********************************************************************************/
void Game::play()
{
	while (!exit)
	{
		tick();
		clearScreen();
		writeStatus();
		writeDes();
		writeEvents();
		writeMenu();
		menu();

		if (this->air < 1 || this->power < 1)
		{
			exit = true;
		}
	}

	endGame();
}

/*********************************************************************************
**								Game::startup
** Description: Start-up menu and game introduction.
**
*********************************************************************************/
void Game::startup()
{
	bool exit = false;

	std::cout << "CS162 Project 5: A day in the life of a spacer" << std::endl 
		<< std::endl;

	while (!exit)
	{
		std::cout << "1. Play game" << std::endl;
		std::cout << "2. Walkthrough" << std::endl;
		std::cout << "3. Exit" << std::endl;

		int choice = valIntPos(1, 1, 3);

		if (choice == 1)
		{
			clearScreen();
			std::cout << std::endl;
			std::cout << "After pulling a double shift recalibrating the life support \n";
			std::cout << "system you finally get a chance to lay down on your bunk for \n";
			std::cout << "some well deserved rest. As you close your eyes you hear \n";
			std::cout << "several loud pops and your comlink begins to ring. \"Jack,\n";
			std::cout << "we just got his with micrometerorites and you're the only one\n";
			std::cout << "on that side of the ship. There's a couple big problems here. \n";
			std::cout << "First, your wing of the ship is leaking air fast. Second, \n";
			std::cout << "something has shorted out in the communications room and it has\n";
			std::cout << "destabilized the reactor. The safety system has locked us out of\n";
			std::cout << "your part of the ship so you'll have to get the reactor fixed \n";
			std::cout << "before we can get to you. I have Frank suiting up to fix the \n";
			std::cout << "holes on the outside of the ship but he won't get there before\n";
			std::cout << "you run out of air to breathe. You'll have to find a way to \n";
			std::cout << "patch the holes and hope it holds until Frank can get to it.\n";
			std::cout << "Good luck, we're counting on you. Adams out.\" \nSeems like ";
			std::cout << "there's always something trying to kill you on this ship.";
			std::cout << std::endl << std::endl;
			std::cout << "Press enter to continue." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::string foo;
			std::getline(std::cin, foo);
			play();
			exit = true;
		}

		if (choice == 2)
		{
			std::cout << "north, west, take item, east, use item, north, "
				<< "north, take item, south, east, use item, west, "
				<< "west, action" << std::endl << std::endl;
		}

		if (choice == 3)
		{
			exit = true;
		}
	}
}