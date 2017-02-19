/*********************************************************************************
** Program name: Project 3 (Blue Men Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Blue Men implementation file. Blue Men are absolute beasts. 2D10
**				for attacks, up to 3D6 for dodge, 3 armor, and 12 health. The 
**				number of dodge dice are (health / 4) and calculated before each
**				defense. They basically always win.
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

/*********************************************************************************
**								BlueMen::attack
** Description: Rolls dice and sums their total for the damage of the attack.
**				Reports the outcome and returns an int for the damage.
**
*********************************************************************************/
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

/*********************************************************************************
**								BlueMen::defense
** Description: Takes an int damage as an argument and then calculates the number 
**				of dodge dice based on current health (dice = health / 4). It 
**				rolls dodge to reduce damage then, if applicable, reduces again 
**				via armor and finally reduces health by the remaining damage 
**				amount. Reporting stats at each step.
**
*********************************************************************************/
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

/*********************************************************************************
**								BlueMen::rollDice
** Description: Returns an int for a random dice roll of a die with diePow sides.
**
*********************************************************************************/
int BlueMen::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

/*********************************************************************************
**								BlueMen::isDead
** Description: Kill function that sets the BlueMen's health to 0.
**
*********************************************************************************/
void BlueMen::isDead()
{
	this->health = 0;
}

/*********************************************************************************
**								BlueMen::getHealth
** Description: Returns the health variable.
**
*********************************************************************************/
const int BlueMen::getHealth()
{
	return this->health;
}

/*********************************************************************************
**								BlueMen::getName
** Description: Returns the name variable.
**
*********************************************************************************/
const std::string BlueMen::getName()
{
	return this->name;
}