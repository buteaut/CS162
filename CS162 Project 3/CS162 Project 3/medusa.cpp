/*********************************************************************************
** Program name: Project 3 (Medusa Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Medusa implementation file. Attacks with 2D6, defends with 1D6, 
**				has 3 armor and 8 health. If Medusa gets max damage on attack 
**				glare is triggered which calls isDead() on opponent.
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

/*********************************************************************************
**								Medusa::attack
** Description: Rolls dice and sums their total for the damage of the attack.
**				Reports the outcome and returns an int for the damage. If max 
**				damage is rolled "Glare" occurs and calls isDead() on opponent.
**
*********************************************************************************/
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

/*********************************************************************************
**								Medusa::defense
** Description: Takes an int damage as an argument and reduces it with a dodge
**				roll then, if applicable, armor and finally reduces health by
**				the remaining damage amount. Reporting stats at each step.
**
*********************************************************************************/
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

/*********************************************************************************
**								Medusa::rollDice
** Description: Returns an int for a random dice roll of a die with diePow sides.
**
*********************************************************************************/
int Medusa::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

/*********************************************************************************
**								Medusa::isDead
** Description: Kill function that sets the Barbarian's health to 0.
**
*********************************************************************************/
void Medusa::isDead()
{
	this->health = 0;
}

/*********************************************************************************
**								Medusa::getHealth
** Description: Returns the health variable.
**
*********************************************************************************/
const int Medusa::getHealth()
{
	return this->health;
}

/*********************************************************************************
**								Medusa::getName
** Description: Returns the name variable.
**
*********************************************************************************/
const std::string Medusa::getName()
{
	return this->name;
}