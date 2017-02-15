/*********************************************************************************
** Program name: Project 3 (Blue Men Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Blue Men header file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "fighter.hpp"


class BlueMen : public Fighter
{
protected:
	int attDieNum;
	int attDiePow;
	int defDieNum;
	int defDiePow;
	int armor;
	int health; //strength in assignment write up, health made more sense
	std::string name;

public:
	BlueMen(); //default constructor
	virtual ~BlueMen(); //deconstructor

	virtual void attack(Fighter*);
	virtual void defense(int);
	virtual void isDead();
	virtual int rollDice(int);
	virtual int getHealth();

};

#endif
