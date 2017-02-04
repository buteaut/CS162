/*********************************************************************************
** Program name: Project 2 (List Header File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: List header file for Project 2. Contains an array of Item object
**				pointers as well as ints to keep track of the array capacity and
**				number of spots used in the array. There are methods to add Items,
**				remove Items, generate Items, increase array size, display Items,
**				display total cost, and a menu driver method.
**
*********************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include "Item.hpp"
#include "dataValidation.hpp"
#include <string>
#include <iostream>

class List
{
private:
	int numItems;
	int capacity;
	Item** itemList;
	

public:
	List(); //default constructor
	~List(); //destructor

	void addItem();

	Item* generateItem();

	void arrayIncrease();

	void removeItem();

	void displayItems();

	void displayTotal();

	void menu();
	

};
#endif