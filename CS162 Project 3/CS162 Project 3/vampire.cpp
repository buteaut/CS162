/*********************************************************************************
** Program name: Project 3 (Vampire Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Vampire implementation file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#include "vampire.hpp"

Vampire::Vampire() : Fighter() //default constructor
{
	this->attDieNum = 1;
	this->attDiePow = 12;
	this->defDieNum = 1;
	this->defDiePow = 6;
	this->armor = 1;
	this->health = 18;
	this->name = "Vampire";
}

Vampire::~Vampire() //deconstructor
{
	//intentionally left blank
}

void Vampire::attack(Fighter* opp)
{
	int damage = 0;
	for (int i = 0; i < attDieNum; i++)
	{
		damage += rollDice(attDiePow);
	}
	std::cout << name << " attacks for " << damage << "." << std::endl;
	opp->defense(damage);

}

void Vampire::defense(int damage)
{
	int dodge = 0;
	if (!charm())
	{
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
	else
		std::cout << name << " uses Charm, it's super effective!" << std::endl;
}

int Vampire::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

void Vampire::isDead()
{
	this->health = 0;
}

bool Vampire::charm()
{
	return rand() % 2; 
}

int Vampire::getHealth()
{
	return this->health;
}