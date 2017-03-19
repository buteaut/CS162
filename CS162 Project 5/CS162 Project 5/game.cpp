/*********************************************************************************
** Program name: Project 5 (Game Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Game implementation file. 
**
*********************************************************************************/

#include "game.hpp"

Game::Game()
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
	this->exit = false;
	
}

Game::Game(Rooms* r)
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

Game::~Game()
{
	//left blank for now
}

void Game::tick()
{
	--power;
	if (!airpatch)
	{
		air -= 5;
	}
	else
	{
		--air;
	}
}

void Game::clearScreen()
{
	std::system(clear.c_str());
}

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

void Game::writeDes()
{
	std::cout << currentLocation->getDescription() << std::endl << std::endl;
}

void Game::writeEvents()
{
	std::cout << events << std::endl << std::endl;
	events = "";
}

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

void Game::endGame()
{
	this->clearScreen();

	if (this->air < 1)
	{
		std::cout << "As the last of the air runs out you wonder what you could "
			<< "have done differently." << std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	else if (this->power < 1)
	{
		std::cout << "The hum of the engines dies. An ominous silence envelops "
			<< "you as you sit in the dark pondering how long the air supply "
			<< "will last." << std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	else if (this->airpatch == true && this->elecpatch == true)
	{
		std::cout << "The damage to the hull has been repaired, and the reactor "
			<< "has been stabilized. A sigh of relief turns into a groan as you "
			<< "look at your watch and see your shift starts in 7 minutes."
			<< std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	else
	{
		std::cout << "You have failed at your mission. The entire crew is doomed "
			<< "to die." << std::endl << std::endl << std::endl;
		std::cout << "Game over." << std::endl;
	}

	std::cout << "Press enter to quit." << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::string exit;
	std::getline(std::cin, exit);
}

void Game::addItem()
{
	if (currentLocation->itemReport() != 0)
	{
		if (inventory.size() > 1)
		{
			int choice;
			events = "You will have to drop something if you want to take another item.";
			//events += '/n';
			events += "1. Drop the " + inventory.front() + " and take the " + currentLocation->itemName();
			events += "2. Drop the " + inventory.back() + " and take the " + currentLocation->itemName();
			events += "3. Keep current items and leave the " + currentLocation->itemName();

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

void Game::travel(int foo)
{
	if (foo = 1) //north
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
	if (foo = 2) //south
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
	if (foo = 3) //east
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
	if (foo = 4) //south
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

void Game::search()
{
	std::string roomItem = "";
	std::string roomAction = currentLocation->hasAction();

	if (currentLocation->itemReport() > 0)
	{
		roomItem = currentLocation->itemName();
	}
	
	if (roomItem != "")
	{
		events += "After searching the room you find " + roomItem + ". ";
	}
	if (roomAction != "")
	{
		events += roomAction;
	}
	if (roomAction == "" && roomItem == "")
	{
		events = "A long search of the room turns up nothing of use.";
	}
}

void Game::action()
{
	if (currentLocation->hasAction() != "")
	{
		int action = currentLocation->action();
		if (action = 1)
		{
			airpatch = true;
		}
		if (action = 2)
		{
			elecpatch = true;
		}
		if (action = 3)
		{
			exit = true;
		}
	}

	else
	{
		events = "Panic begins to set in as you are unable to think of ";
		events += ("what to do in the " + currentLocation->getName());
	}
}

void Game::menu()
{
	int choice = valIntPos(1,1,7);

	if (choice <= 4)
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