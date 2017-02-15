/*********************************************************************************
** Program name: Project 3 (Barbarian Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Barbarian implementation file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#include "barbarian.hpp"

Barbarian::Barbarian() : Fighter() //default constructor
{
	this->attDieNum = 2;
	this->attDiePow = 6;
	this->defDieNum = 2;
	this->defDiePow = 6;
	this->armor = 0;
	this->health = 12;
	this->name = "Barbarian";
}

Barbarian::~Barbarian() //deconstructor
{
	//intentionally left blank
}

void Barbarian::attack(Fighter* opp)
{
	int damage = 0;
	for (int i = 0; i < attDieNum; i++)
	{
		damage += rollDice(attDiePow);
	}
	std::cout << name << " attacks for " << damage << "." << std::endl;
	opp->defense(damage);

}

void Barbarian::defense(int damage)
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

int Barbarian::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

void Barbarian::isDead()
{
	this->health = 0;
}

int Barbarian::getHealth()
{
	return this->health;
}