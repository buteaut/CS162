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

Vampire::Vampire() : Fighter(1,12,1,6,1,18,"Vampire") //default constructor
{
	//intentionally left blank
}

Vampire::Vampire(std::string name) : Fighter(1, 12, 1, 6, 1, 18, name)
{
	//intentionally left blank
}

Vampire::~Vampire() //deconstructor
{
	//intentionally left blank
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
**								Vampire::charm
** Description: Returns a bool for a random coin flip.
**
*********************************************************************************/
bool Vampire::charm()
{
	return rand() % 2; 
}
