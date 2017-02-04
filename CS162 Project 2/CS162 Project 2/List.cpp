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
	
	delete itemList;
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
	bool inArray = false;
	Item* newItem = generateItem();
	
	//checks if item exists and adds to existing item as applicable
	for (int i = 0; i < numItems; i++)
	{
		if (*newItem == *itemList[i])
		{
			inArray = true;
			*itemList[i] + *newItem;
		}
	}
	
	//If itemList is full increase array size
	if ((numItems == capacity) && (inArray == false))
	{
		arrayIncrease();
	}

	//adds item
	if ((numItems < capacity) && (inArray == false))
	{		
		numItems++;
		itemList[numItems - 1] = newItem;
	}

}

void List::arrayIncrease()
{
	capacity++;
	Item** temp;
	temp = new Item*[capacity];
	
	//copies the Item pointers to temp array
	for (int i = 0; i < numItems; i++)
	{
		temp[i] = itemList[i];
	}
	
	//clears itemList array
	delete[] itemList;
	itemList = NULL;
	
	//makes itemList a copy of temp
	itemList = temp;

	//removes temp array
	temp = NULL;
	delete temp;

}

void List::arrayDecrease()
{
	std::cout << "Test" << std::endl;
}

void List::removeItem()
{
	std::string name;
	bool inArray = false;
	int itemLocation;
	
	std::cout << "What is the name of the item to remove? ";
	std::cin >> name;
	std::cout << std::endl;

	for (int i = 0; i < numItems; i++)
	{
		if (*itemList[i] == name)
		{
			inArray = true;
			itemLocation = i;
			std::cout << "Item found in array." << std::endl;
		}
	}

	if (inArray)
	{
		for (int i = itemLocation; i < (numItems - 1); i++)
		{
			itemList[i] = itemList[i + 1];
		}

		itemList[numItems] = NULL;
		
		numItems--;
	}

	if (!inArray)
	{
		std::cout << name << " was not found in the list." << std::endl;
	}
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