/*********************************************************************************
** Program name: Project 3 (Vampire Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Vampire implementation file. Attacks with 1D12, defends with 1D6, 
**				has 1 armor and 18 health. Has "charm" ability which gives 50%
**				chance to dodge all damage (does not work against Medusa "glare").
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

/*********************************************************************************
**								Vampire::attack
** Description: Rolls dice and sums their total for the damage of the attack.
**				Reports the outcome and returns an int for the damage.
**
*********************************************************************************/
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

/*********************************************************************************
**								Vampire::defense
** Description: Takes an int damage as an argument and reduces it with a dodge
**				roll then, if applicable, armor and finally reduces health by
**				the remaining damage amount. Reporting stats at each step. Has a
**				50% chance to use charm and reduce damage to 0.
**
*********************************************************************************/
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
		std::cout << name << " uses Charm, it's super effective!" << std::endl
			<< std::endl;
}

/*********************************************************************************
**								Vampire::rollDice
** Description: Returns an int for a random dice roll of a die with diePow sides.
**
*********************************************************************************/
int Vampire::rollDice(int diePow)
{
	return rand() % diePow + 1;
}

/*********************************************************************************
**								Vampire::isDead
** Description: Kill function that sets the Barbarian's health to 0.
**
*********************************************************************************/
void Vampire::isDead()
{
	this->health = 0;
}

/*********************************************************************************
**								Vampire::charm
** Description: Returns a bool for a random coin flip.
**
*********************************************************************************/
bool Vampire::charm()
{
	return rand() % 2; 
}

/*********************************************************************************
**								Vampire::getHealth
** Description: Returns the health variable.
**
*********************************************************************************/
const int Vampire::getHealth()
{
	return this->health;
}

/*********************************************************************************
**								Vampire::getName
** Description: Returns the name variable.
**
*********************************************************************************/
const std::string Vampire::getName()
{
	return this->name;
}