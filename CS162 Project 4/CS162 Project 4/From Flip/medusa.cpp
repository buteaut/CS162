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

Medusa::Medusa() : Fighter(2,6,1,6,3,8,"Medusa") //default constructor
{
	//intentionally left blank
}

Medusa::Medusa(std::string name) : Fighter(2, 6, 1, 6, 3, 8, name)
{
	//intentionally left blank
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