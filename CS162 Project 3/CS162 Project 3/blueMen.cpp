/*********************************************************************************
** Program name: Project 3 (Blue Men Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Blue Men implementation file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#include "bluemen.hpp"

BlueMen::BlueMen() : Fighter() //default constructor
{
	this->attDieNum = 2;
	this->attDiePow = 10;
	this->defDieNum = 3;
	this->defDiePow = 6;
	this->armor = 3;
	this->health = 12;
	this->name = "Blue Men";
}

BlueMen::~BlueMen() //deconstructor
{
	//intentionally left blank
}

void BlueMen::attack(Fighter* opp)
{
	int damage = 0;
	for (int i = 0; i < attDieNum; i++)
	{
		damage += rollDice(attDiePow);
	}
	std::cout << name << " attacks for " << damage << "." << std::endl;
	opp->defense(damage);

}

void BlueMen::defense(int damage)
{
	int dodge = 0;
	this->defDieNum = health / 4;

	for (int i = 0; i < defDieNum; i++)
	{
		dodge += rollDice(defDiePow);
	}

	std::cout << name << " dodges " << dodge << " damage." << std::endl;

	damage -= dodge;

	if (damage > 0 && this->armor > 0)
	{
		std::cout << name << "'s armor absorbs " << armor << " damage."
			<< std::endl << std:: endl;
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

int BlueMen::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

void BlueMen::isDead()
{
	this->health = 0;
}

int BlueMen::getHealth()
{
	return this->health;
}