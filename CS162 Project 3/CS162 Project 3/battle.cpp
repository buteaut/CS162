/*********************************************************************************
** Program name: Project 3 (Battle Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Battle implementation file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#include "battle.hpp"

Battle::Battle() //default constructor
{

}

Battle::~Battle() //deconstructor
{
	delete p1;
	delete p2;
}

void Battle::menu()
{

}

void Battle::fight(Fighter* p1, Fighter* p2)
{
	do
	{
		p1->attack(p2);

		if (p2->getHealth() > 0)
		{
			p2->attack(p1);
		}
	} while (p1->getHealth() > 0 && p2->getHealth() > 0)


}