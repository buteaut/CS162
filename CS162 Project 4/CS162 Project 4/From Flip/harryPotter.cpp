/*********************************************************************************
** Program name: Project 3 (HarryPotter Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: HarryPotter implementation file. Harry Potter is a faily generic
**				fighter with one exception. Attacks with 2D6, defends with 2D6, 
**				has no armor and 10	health. When health goes beneath 1 the first 
**				time the method resurrection restores health to 20.
**
*********************************************************************************/

#include "harryPotter.hpp"

HarryPotter::HarryPotter() : Fighter(2,6,2,6,0,10,"Harry Potter") //default constructor
{
	this->hasDied = false;
}

HarryPotter::HarryPotter(std::string name) : Fighter(2, 6, 2, 6, 0, 10, name)
{
	this->hasDied = false;
}

HarryPotter::~HarryPotter() //deconstructor
{
	//intentionally left blank
}

/*********************************************************************************
**								HarryPotter::defense
** Description: Takes an int damage as an argument and reduces it with a dodge
**				roll then, if applicable, armor and finally reduces health by
**				the remaining damage amount. Reporting stats at each step. Will
**				call resurrect method on first death.
**
*********************************************************************************/
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

/*********************************************************************************
**								HarryPotter::isDead
** Description: Kill function that sets the HarryPotter's health to 0 then if 
**				this is the first death calls resurrect.
**
*********************************************************************************/
void HarryPotter::isDead()
{
	this->health = 0;
	if (!this->hasDied)
	{
		resurrect();
	}
}

/*********************************************************************************
**								HarryPotter::resurrect
** Description: Resets health to 20 and flips the bool hasDied.
**
*********************************************************************************/
void HarryPotter::resurrect()
{
	std::cout << "Death does not yet seek out " << this->name << "." << std::endl 
		<< std::endl;
	this->hasDied = true;
	this->health = 20;
	this->maxHealth = 20;
}