/*********************************************************************************
** Program name: Project 2 (List Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: List implementation file for Project 2.


*********************************************************************************/

#include "List.hpp"

List::List() //default constructor
{
	numItems = 0;
	capacity = 4;
	//Item* itemList[4] = { NULL, NULL, NULL, NULL };
	//Item* itemList = new Item[capacity];
	itemList = new Item*[capacity];
	
}

List::~List() //destructor
{
	for (int i = 0; i < numItems; i++)
	{
		delete itemList[i];
	}
}

Item* List::generateItem()
{
	std::string name;
	int quantity;
	std::string qUnits;
	double unitPrice;
	std::string strChoice;
	bool exists = false;

	std::cout << "Enter the name of the item. ";
	std::cin >> name;
	std::cout << std::endl;
	std::cout << "Enter the type of units. ";
	std::cin >> qUnits;
	std::cout << std::endl;
	std::cout << "Enter the number of " << qUnits << ": ";
	std::cin >> strChoice;
	while (!intValPos(strChoice, 3, 1, 999)) //calls the integer validation function
	{
		std::cout << "User input invalid, please try again." << std::endl;
		strChoice = "";
		std::cin >> strChoice;
	}
	quantity = atoi(strChoice.c_str());
	strChoice = "";
	std::cout << std::endl;

	std::cout << "Enter the price per " << qUnits << ": ";
	std::cin >> strChoice;
	while (!doubleValPos(strChoice, 6, 1, 999.99)) //calls the integer validation function
	{
		std::cout << "User input invalid, please try again." << std::endl;
		strChoice = "";
		std::cin >> strChoice;
	}
	unitPrice = atof(strChoice.c_str());
	strChoice = "";
	std::cout << std::endl;

	return new Item(name, quantity, qUnits, unitPrice);
}

void List::addItem()
{
	Item* newItem = generateItem();
	
	//test only remove for production
	if (numItems == 2)
	{
		arrayIncrease();
	}


	if (numItems < capacity)
	{		
		numItems++;
		itemList[numItems - 1] = newItem;
	}

}

void List::arrayIncrease()
{
	
	Item** temp; // = new Item[capacity];
	capacity++;
	temp = new Item*[capacity];
	for (int i = 0; i < numItems; i++)
	{
		temp[i] = itemList[i];
		//temp[i] = *(itemList)[i];
	}
	
	delete[] itemList;
	itemList = NULL;
	capacity++;
	itemList = temp;

	/*
	//test only remove for production
	for (int i = 0; i < numItems; i++)
	{
		std::cout << *(itemList[i]);
	}
	*/
	std::cout << "Test" << std::endl;
}

void List::arrayDecrease()
{
	std::cout << "Test" << std::endl;
}

void List::removeItem()
{
	std::cout << "Test" << std::endl;
}

void List::displayItems()
{
	//std::cout << "Test" << std::endl;
	if (numItems > 0)
	{
		for (int i = 0; i < numItems; i++)
		{
			std::cout << *(itemList[i]);
		}
	}

	else
	{
		std::cout << "No items currently in the list." << std::endl;
	}
}

void List::displayTotal()
{
	//std::cout << "Test" << std::endl;
	double total = 0;
	if (numItems > 0)
	{
		for (int i = 0; i < numItems; i++)
		{
			total += itemList[i]->getTotalPrice();
		}
		
		std::cout << "The total price for all items is " << total << std::endl;
	}

}

void List::menu()
{
	std::string strChoice;
	int choice;
	bool exit = false;


	std::cout << "CS162 Project 2 'Shopping List'" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Main Menu: " << std::endl;
		std::cout << "1. Display list." << std::endl;
		std::cout << "2. Add items." << std::endl;
		std::cout << "3. Remove items." << std::endl;
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

		if (choice == 1) //Display list
		{
			//Display list
			displayItems();
			displayTotal();
		}

		if (choice == 2) //Add item
		{
			//add item
			std::cout << "Add items" << std::endl;
			addItem();
		}

		if (choice == 3) //Remove item
		{
			//remove item
			removeItem();
		}

		if (choice == 4) //exit
		{
			exit = true;
		}
	} while (exit == false);
};