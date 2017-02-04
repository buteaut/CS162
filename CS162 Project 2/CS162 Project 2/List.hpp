/*********************************************************************************
** Program name: Project 2 (List Header File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: List header file for Project 2.


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

	void arrayDecrease();

	void removeItem();

	void displayItems();

	void displayTotal();

	void menu();
	

};
#endif