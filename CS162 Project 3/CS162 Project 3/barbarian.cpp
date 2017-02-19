/*********************************************************************************
** Program name: Project 3 (Barbarian Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Barbarian implementation file. The barbarian is a faily generic
**				fighter. Attacks with 2D6, defends with 2D6, has no armor and 12
**				health. No special abilities. More city guard than dragonborn.
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

/*********************************************************************************
**								Barbarian::attack
** Description: Rolls dice and sums their total for the damage of the attack.
**				Reports the outcome and returns an int for the damage.
**
*********************************************************************************/
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

/*********************************************************************************
**								Barbarian::defense
** Description: Takes an int damage as an argument and reduces it with a dodge
**				roll then, if applicable, armor and finally reduces health by
**				the remaining damage amount. Reporting stats at each step.
**
*********************************************************************************/
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

/*********************************************************************************
**								Barbarian::rollDice
** Description: Returns an int for a random dice roll of a die with diePow sides.
**
*********************************************************************************/
int Barbarian::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

/*********************************************************************************
**								Barbarian::isDead
** Description: Kill function that sets the Barbarian's health to 0.
**
*********************************************************************************/
void Barbarian::isDead()
{
	this->health = 0;
}

/*********************************************************************************
**								Barbarian::getHealth
** Description: Returns the health variable.
**
*********************************************************************************/
const int Barbarian::getHealth()
{
	return this->health;
}

/*********************************************************************************
**								Barbarian::getName
** Description: Returns the name variable.
**
*********************************************************************************/
const std::string Barbarian::getName()
{
	return this->name;
}