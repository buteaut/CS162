/*********************************************************************************
** Program name: Project 2 (List Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: List implementation file for Project 2. Contains an array of Item 
**				object pointers as well as ints to keep track of the array 
**				capacity and number of spots used in the array. There are methods 
**				to add Items, remove Items, generate Items, increase array size, 
**				display Items, display total cost, and a menu driver method.
**
*********************************************************************************/

#include "List.hpp"

List::List() //default constructor
{
	numItems = 0;
	capacity = 4;
	itemList = new Item*[capacity];
	
}

List::~List() //destructor
{

	for (int i = 0; i < numItems; i++)
	{
		delete itemList[i];
	}

	delete[] itemList;
}

/*****************************************************************************
**						Item::generateItem
** Description: Uses user input to generate and return a pointer to an Item
**				object.
**
*****************************************************************************/
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

/*****************************************************************************
**						Item::addItem
** Description: Calls generateItem then if that item is already in the 
**				itemList it adds to the quantity of the existing item. If the
**				item is not already in the list it will add it and increase
**				itemList size if needed.
**
*****************************************************************************/
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
			delete newItem;
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

/*****************************************************************************
**						Item::arrayIncrease
** Description: Increases the size of the itemList array by 1.
**
*****************************************************************************/
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
	delete []temp;

}

/*****************************************************************************
**						Item::removeItem
** Description: Looks through the itemArray for an Item object with a name
**				that equals user input. If so it removes that Item object and
**				moves Items down in the array as needed so that no empty spots
**				exist. If the Item is not found it displays an error message.
**
*****************************************************************************/
void List::removeItem()
{
	std::string name;
	bool inArray = false;
	int itemLocation;
	
	std::cout << "What is the name of the item to remove? ";
	std::cin >> name;
	std::cout << std::endl;

	//looks for the Item object with name.
	for (int i = 0; i < numItems; i++)
	{
		if (*itemList[i] == name)
		{
			inArray = true;
			itemLocation = i;
		}
	}

	//removes Item object and readjusts the array
	if (inArray)
	{
		delete itemList[itemLocation];
		for (int i = itemLocation; i < (numItems - 1); i++)
		{
			itemList[i] = itemList[i + 1];
		}

		itemList[numItems] = NULL;
		
		numItems--;

		std::cout << name << " removed from the list." << std::endl;
	}

	//error message, name not found
	if (!inArray)
	{
		std::cout << name << " was not found in the list." << std::endl;
	}
}

/*****************************************************************************
**						Item::displayItems
** Description: Uses the overloaded << operator for the Item class to print
**				out all the Items in the array.
**
*****************************************************************************/
void List::displayItems()
{
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

/*****************************************************************************
**						Item::displayTotal
** Description: Calculates and prints out the total price for all Items in
**				the array.
**
*****************************************************************************/
void List::displayTotal()
{
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

/*****************************************************************************
**						Item::menu
** Description: menu function allowing the user to display list Items, add or
**				remove Items, or exit.
**
*****************************************************************************/
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
