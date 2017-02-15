/*********************************************************************************
** Program name: Project 3 (HarryPotter Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: HarryPotter implementation file. The Item class has variables for
**				item name, unit name, unit quantity, unit price, and total price.
**				There is a getTotalPrice method that returns totalPrice, an
**				increaseQuantity method that adds the quantity argument to the
**				object quantity, and operator overloads for == and +. There is
**				also a friend function to overload the << operator.
**
*********************************************************************************/

#include "harryPotter.hpp"

HarryPotter::HarryPotter() : Fighter() //default constructor
{
	this->attDieNum = 2;
	this->attDiePow = 6;
	this->defDieNum = 2;
	this->defDiePow = 6;
	this->armor = 0;
	this->health = 10;
	this->name = "HarryPotter";
	this->hasDied = false;
}

HarryPotter::~HarryPotter() //deconstructor
{
	//intentionally left blank
}

void HarryPotter::attack(Fighter* opp)
{
	int damage = 0;
	for (int i = 0; i < attDieNum; i++)
	{
		damage += rollDice(attDiePow);
	}
	std::cout << this->name << " attacks for " << damage << "." << std::endl;
	opp->defense(damage);

}

void HarryPotter::defense(int damage)
{
	int dodge = 0;

	for (int i = 0; i < defDieNum; i++)
	{
		dodge += rollDice(defDiePow);
	}

	std::cout << this->name << " dodges " << dodge << " damage." << std::endl;

	damage -= dodge;

	if (damage > 0 && this->armor > 0)
	{
		std::cout << this->name << "'s armor absorbs " << this->armor
			<< " damage." << std::endl << std::endl;
	}

	else
	{
		std::cout << std::endl;
	}

	damage -= armor;

	if (damage > 0)
	{
		this->health -= damage;
		std::cout << this->name << " takes " << damage << " and now has " <<
			this->health << " health." << std::endl << std::endl;

		if (this->health < 1 && !this->hasDied)
		{
			resurrect();
		}
	}
}

int HarryPotter::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

void HarryPotter::isDead()
{
	this->health = 0;
	if (!this->hasDied)
	{
		resurrect();
	}
}

void HarryPotter::resurrect()
{
	std::cout << "Death does not yet seek out this one." << std::endl 
		<< std::endl;
	this->hasDied = true;
	this->health = 20;
}

int HarryPotter::getHealth()
{
	return this->health;
}
