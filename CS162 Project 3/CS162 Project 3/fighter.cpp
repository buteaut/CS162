/*********************************************************************************
** Program name: Project 3 (Fighter Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Fighter implementation file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#include "fighter.hpp"

Fighter::Fighter() //default constructor
{
	this->attDieNum = 0;
	this->attDiePow = 0;
	this->defDieNum = 0;
	this->defDiePow = 0;
	this->armor = 0;
	this->health = 0;
	this->name = "Fighter";
}
Fighter::~Fighter() //deconstructor
{
	//intentionally left blank
}

void Fighter::attack(Fighter* opp)
{
	int damage = 0;
	for (int i = 0; i < attDieNum; i++)
	{
		damage += rollDice(attDiePow);
	}
	std::cout << this->name << " attacks for " << damage << "." << std::endl;
	opp->defense(damage);

}

void Fighter::defense(int damage)
{
	int dodge = 0;
	
	for (int i = 0; i < defDieNum; i++)
	{
		dodge += rollDice(defDiePow);
	}
	
	std::cout << name << " dodges " << dodge << " damage." << std::endl;
	
	damage -= dodge;
	
	if (damage > 0 && this->armor > 0)
	{
		std::cout << name << "'s armor absorbs " << armor << " damage." 
			<< std::endl << std::endl;
	}

	else
	{
		std::cout << std::endl;
	}

	damage -= armor;

	if (damage > 0)
	{
		health -= damage;
		std::cout << name << " takes " << damage << " and now has " <<
			health << " health." << std::endl << std::endl;
	}
}

int Fighter::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

void Fighter::isDead()
{
	this->health = 0;
}

int Fighter::getHealth()
{
	return this->health;
}