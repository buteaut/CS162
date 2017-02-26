/*********************************************************************************
** Program name: Lab 7 (Menu Implementation File)
** Author: Thomas Buteau
** Date: 2-26-17
** Description: Menu implementation file. General menu function to be adapted and 
**				reused in future projects.
**
*********************************************************************************/

#include "menu.hpp"


/*****************************************************************************
**						Menu()
** Description: Menu method provides user options and will call other methods
**				based on user input.
**
*****************************************************************************/
void menu()
{
	Queue* cList = new Queue;
	std::string strChoice;
	char choice;
	bool exit = false;

	std::cout << "CS162 Lab 5 'Recursive Recursions'" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Main Menu: " << std::endl;
		std::cout << "a. Enter a value to be added to the queue." << std::endl;
		std::cout << "b. Display the first node (front) value." << std::endl;
		std::cout << "c. Remove first node (front) value." << std::endl;
		std::cout << "d. Display the queue contents" << std::endl;
		std::cout << "x. Exit program." << std::endl;

		choice = valChar();
		
		if (choice == 'a') //add value to queue
		{
			std::cout << "Enter a positive int to add to the list." << std::endl;
			cList->addBack(valIntPos(5));
		}

		else if (choice == 'b') //display front value
		{
			std::cout << "The front node value is " << cList->getFront() << "."
				<< std::endl;
		}

		else if (choice == 'c') //remove front valve
		{
			std::cout << "Now removing front node: " << cList->removeFront() << "."
				<< std::endl;
		}

		else if (choice == 'd') //display all nodes
		{
			cList->displayNodes();
		}

		else if (choice == 'x') //exit
		{
			exit = true;
		}

		else
		{
			std::cout << "Invalid choice, please try again." << std::endl;
		}

	} while (exit == false);

	delete cList;
}