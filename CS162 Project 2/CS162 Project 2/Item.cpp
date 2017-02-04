/*********************************************************************************
** Program name: Project 2 (Item Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Item implementation file for Project 2. 


*********************************************************************************/

#include "Item.hpp"

Item::Item() //default constructor
{
	this->name = "";
	this->quantity = 0;
	this->qUnits = "";
	this->unitPrice = 0.0;

	this->totalPrice = this->quantity * this->unitPrice;
}

Item::Item(std::string name, int quantity, std::string qUnits, double unitPrice)
{
	this->name = name;
	this->quantity = quantity;
	this->qUnits = qUnits;
	this->unitPrice = unitPrice;

	this->totalPrice = this->quantity * this->unitPrice;
}

Item::~Item() //destructor
{
	//intentionally left blank
}


double Item::getTotalPrice()
{
	return totalPrice;
}
/*****************************************************************************
**						Item::increaseQuantity
** Description: Generates and returns a random int from 1 to numSides.
**
*****************************************************************************/
void Item::increaseQuantity(int quantity)
{
	this->quantity += quantity;
	std::cout << "quantity is now " << this->quantity << std::endl;
}

/*****************************************************************************
**						Item::== (Item)
** Description: Comparision override for the Item class. Compares the name
**				string to the name string of the Item object pointer argument.
**
*****************************************************************************/
bool Item::operator==(Item a)
{
	return (this->name == a.name);
}

/*****************************************************************************
**						Item::== (String)
** Description: Comparision override for the Item class. Compares the name
**				string to the string argument.
**
*****************************************************************************/
bool Item::operator==(std::string name)
{
	return (this->name == name);
}

/*****************************************************************************
**						Item::+
** Description: Addition override for the Item class. Adds the quantity of 
**				the argument Item to the Item that calls the function. It
**				then updates the totalPrice.
**
*****************************************************************************/
void Item::operator+(Item a)
{
	this->quantity += a.quantity;
	this->totalPrice = (this->quantity * this->unitPrice);
}

/*****************************************************************************
**						Item::<<
** Description: Outstream override for the Item class. Prints out a statement
**				which contains all of the Item variables. 
**
*****************************************************************************/
std::ostream& operator<<(std::ostream &outs, const Item& foo)
{
	outs << foo.name << ": " << foo.quantity << " " << foo.qUnits << " at " << foo.unitPrice << " each for a total cost of " << foo.totalPrice << std::endl;

	return outs;
}