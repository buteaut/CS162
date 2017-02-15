/*********************************************************************************
** Program name: Project 3 (Battle Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Battle header file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "barbarian.hpp"
#include "harryPotter.hpp"
#include "vampire.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"

class Battle
{
private:
	Fighter* p1;
	Fighter* p2;

public:
	Battle(); //default constructor
	~Battle(); //destructor

	void menu();
	void fight(Fighter*, Fighter*);

};


#endif
