/*********************************************************************************
** Program name: Project 3 (Fighter Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Fighter implementation file. Template class for all other creature
**				types. Has methods for attacking and defense as well as other's
**				that are needed for those two main methods.
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

Fighter::Fighter(int attDieNum, int attDiePow, int defDieNum, int defDiePow, int armor,
	int health, std::string name)
{
	this->attDieNum = attDieNum;
	this->attDiePow = attDiePow;
	this->defDieNum = defDieNum;
	this->defDiePow = defDiePow;
	this->armor = armor;
	this->health = health;
	this->maxHealth = health;
	this->name = name;
}
Fighter::~Fighter() //deconstructor
{
	//intentionally left blank
}

/*********************************************************************************
**								Fighter::attack
** Description: Rolls dice and sums their total for the damage of the attack.
**				Reports the outcome and returns an int for the damage.
**
*********************************************************************************/
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

/*********************************************************************************
**								Fighter::defense
** Description: Takes an int damage as an argument and reduces it with a dodge
**				roll then, if applicable, armor and finally reduces health by
**				the remaining damage amount. Reporting stats at each step.
**
*********************************************************************************/
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

/*********************************************************************************
**								Fighter::rollDice
** Description: Returns an int for a random dice roll of a die with diePow sides.
**
*********************************************************************************/
int Fighter::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

/*********************************************************************************
**								Fighter::isDead
** Description: Kill function that sets the Barbarian's health to 0.
**
*********************************************************************************/
void Fighter::isDead()
{
	this->health = 0;
}

/*********************************************************************************
**								Fighter::getHealth
** Description: Returns the health variable.
**
*********************************************************************************/
const int Fighter::getHealth()
{
	return this->health;
}

/*********************************************************************************
**								Fighter::getName
** Description: Returns the name variable.
**
*********************************************************************************/
const std::string Fighter::getName()
{
	return this->name;
}

/*********************************************************************************
**								Fighter::recoup
** Description: Regenerate a random percent of lost health.
**
*********************************************************************************/
void Fighter::recoup()
{
	int missing = maxHealth - health;
	int percent = rand() % 100 + 1;
	this->health += (missing * percent) / 100;
}