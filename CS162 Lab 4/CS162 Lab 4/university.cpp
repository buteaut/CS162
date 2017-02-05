/*********************************************************************************
** Program name: Lab 4 (Person Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Person implementation file. Person is virtual class so only
**				constructors and destructors are defined here. Person has a name
**				and age.
*********************************************************************************/

#include "university.hpp"

//default constructor
University::University()
{
	uniName = "Oregon State University";
}

//destructor
University::~University()
{
	people.clear();
	places.clear();
}

/*****************************************************************************
**						University::pushPerson
** Description: Adds the Person object pointer argument to the vector people.
**
*****************************************************************************/
void University::pushPerson(Person* p)
{
	people.push_back(p);
}

/*****************************************************************************
**						University::pushBuilding
** Description: Adds the Building object pointer argument to the vector 
**				places.
**
*****************************************************************************/
void University::pushBuilding(Building* b)
{
	places.push_back(b);
}

/*****************************************************************************
**						University::displayPeople
** Description: Calls the << operator for each Person object pointer in the 
**				people array.
**
*****************************************************************************/
void University::displayPeople()
{
	std::cout << uniName << " has record of the following people." << std::endl;
	for (int i = 0; i < people.size(); i++)
	{
		std::cout << i + 1 << ": " << *(people[i]);
	}
}

/*****************************************************************************
**						University::displayBuildings
** Description: Calls the << operator for each Building object pointer in the
**				places array.
**
*****************************************************************************/
void University::displayBuildings()
{
	std::cout << uniName << " has record of the following buildings." << std::endl;
	for (int i = 0; i < places.size(); i++)
	{
		std::cout << i + 1 << ": " << *(places[i]);
	}
}

/*****************************************************************************
**						University::Menu
** Description: Menu method provides user options and will call other methods
**				based on user input.
**
*****************************************************************************/
void University::menu()
{
	std::string strChoice;
	int choice;
	bool exit = false;

	std::cout << "CS162 Lab 4 'OSU Information System'" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Main Menu: " << std::endl;
		std::cout << "1. Display buildings." << std::endl;
		std::cout << "2. Display people." << std::endl;
		std::cout << "3. Choose person to do work." << std::endl;
		std::cout << "4. Exit program." << std::endl;

		std::cin >> strChoice;
		while (!intValPos(strChoice, 1, 1, 4)) //calls the integer validation function
		{
			std::cout << "User input invalid, please try again." << std::endl;
			strChoice = "";
			std::cin >> strChoice;
		}
		choice = atoi(strChoice.c_str());
		strChoice = "";

		if (choice == 1) //Display buildings
		{
			displayBuildings();
		}

		if (choice == 2) //Display people
		{
			displayPeople();
		}

		if (choice == 3) //Do work
		{
			peopleMenu();
		}

		if (choice == 4) //exit
		{
			exit = true;
		}
	} while (exit == false);
}

/*****************************************************************************
**						University::peopleMenu
** Description: Displays list of People object pointers in people vector then
**				calls do_work on user selected object.
**
*****************************************************************************/
void University::peopleMenu()
{
	std::string strChoice;
	int choice;

	displayPeople();
	std::cout << "Enter the number of the person to do work. ";
	std::cin >> strChoice;
		while (!intValPos(strChoice, 1, 1, people.size())) //calls the integer validation function
		{
			std::cout << "User input invalid, please try again." << std::endl;
			strChoice = "";
			std::cin >> strChoice;
		}
	choice = atoi(strChoice.c_str());
	strChoice = "";
	people[choice - 1]->do_work();
}