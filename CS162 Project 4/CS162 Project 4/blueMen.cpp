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

#include "blueMen.hpp"

BlueMen::BlueMen() : Fighter(2,10,3,6,3,12,"Blue Men") //default constructor
{
	//intentionally left blank
}

BlueMen::BlueMen(std::string name) : Fighter(2, 19, 3, 6, 3, 12, name)
{
	//intentionally left blank
}

BlueMen::~BlueMen() //deconstructor
{
	//intentionally left blank
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
	this->defDieNum = this->health / 4;

	for (int i = 0; i < this->defDieNum; i++)
	{
		dodge += rollDice(this->defDiePow);
	}

	std::cout << this->name << " dodges " << dodge << " damage." << std::endl;

	damage -= dodge;

	if (damage > 0 && this->armor > 0)
	{
		std::cout << this->name << "'s armor absorbs " << this->armor << " damage."
			<< std::endl << std:: endl;
	}

	else
	{
		std::cout << std::endl;
	}

	damage -= this->armor;

	if (damage > 0)
	{
		this->health -= damage;
		std::cout << this->name << " takes " << damage << " and now has " <<
			this->health << " health." << std::endl << std::endl;
	}
}
