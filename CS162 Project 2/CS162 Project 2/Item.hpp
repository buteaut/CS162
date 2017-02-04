/*********************************************************************************
** Program name: Project 2 (Item Header File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Item header file for Project 2. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

class Item
{
private:
	std::string name;
	int quantity;
	std::string qUnits;
	double unitPrice;
	double totalPrice;

public:
	Item(); //default constructor
	Item(std::string name, int quantity, std::string qUnits, double unitPrice);
	~Item(); //destructor

	double getTotalPrice();
	void increaseQuantity(int quantity);

	bool operator==(Item a);
	bool operator==(std::string name);
	void operator+(Item a);

	friend std::ostream& operator<<(std::ostream &outs, const Item& foo);
};
#endif
