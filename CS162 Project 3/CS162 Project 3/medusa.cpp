/*********************************************************************************
** Program name: Project 3 (Medusa Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Medusa implementation file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#include "medusa.hpp"

Medusa::Medusa() : Fighter() //default constructor
{
	this->attDieNum = 2;
	this->attDiePow = 6;
	this->defDieNum = 1;
	this->defDiePow = 6;
	this->armor = 3;
	this->health = 8;
	this->name = "Medusa";
}

Medusa::~Medusa() //deconstructor
{
	//intentionally left blank
}

void Medusa::attack(Fighter* opp)
{
	int damage = 0;
	for (int i = 0; i < attDieNum; i++)
	{
		damage += rollDice(attDiePow);
	}
	std::cout << name << " attacks for " << damage << "." << std::endl;
	if (damage == 12) //glare
	{
		std::cout << name << "'s eyes glow with power." << std::endl;
		opp->isDead();
	}

	else
	{
		opp->defense(damage);
	}
}

void Medusa::defense(int damage)
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

int Medusa::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

void Medusa::isDead()
{
	this->health = 0;
}

int Medusa::getHealth()
{
	return this->health;
}
