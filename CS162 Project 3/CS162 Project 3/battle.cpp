/*********************************************************************************
** Program name: Project 3 (Battle Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Battle implementation file. The Battle class is the driver class
**				for this program. It allows the user to pick fighters and then
**				makes them fight until one has died, reporting the stats for the
**				duration of the fight.
**
*********************************************************************************/

#include "battle.hpp"

Battle::Battle() //default constructor
{

}

Battle::~Battle() //deconstructor
{
	delete p1;
	delete p2;
}

/*********************************************************************************
**								Battle::menu
** Description: Asks the user which fighters should fight, calls setP to create 
**				them, calls fight to make them fight, deletes them, and asks the
**				user if he or she would like to play again.
**
*********************************************************************************/
void Battle::menu()
{
	char cont;
	std::cout << "Welcome to the battle arena." << std::endl;
	do
	{
		std::cout << "Choose the first fighter." << std::endl;
		std::cout << "1. Barbarian" << std::endl;
		std::cout << "2. Blue Men" << std::endl;
		std::cout << "3. Harry Potter" << std::endl;
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Vampire" << std::endl;
		int p1Temp = valIntPos(1, 1, 5);

		p1 = setP(p1Temp);

		std::cout << "Choose the second fighter." << std::endl;
		std::cout << "1. Barbarian" << std::endl;
		std::cout << "2. Blue Men" << std::endl;
		std::cout << "3. Harry Potter" << std::endl;
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Vampire" << std::endl;
		int p2Temp = valIntPos(1, 1, 5);

		p2 = setP(p2Temp);

		fight();

		delete p1;
		delete p2;
		std::cout << "Would you like to play again? (Y/N)" << std::endl;
		
		std::cin >> cont;
		std::cout << std::endl;
	} while (toupper(cont) == 'Y');
}

/*********************************************************************************
**								Battle::fight
** Description: fight has the two fighter objects attack each other until one has
**				died. It reports each attack, damage dealt, dodged, and aborbed.
**				As well as remaining health. Finally it reports the winner.
**
*********************************************************************************/
void Battle::fight()
{
	int choice = rand() % 2;

	if (choice == 0)
	{
		do
		{
			p1->attack(p2);

			if (p2->getHealth() > 0)
			{
				p2->attack(p1);
			}
		} while (p1->getHealth() > 0 && p2->getHealth() > 0);
	}

	else
	{
		do
		{
			p2->attack(p1);

			if (p1->getHealth() > 0)
			{
				p1->attack(p2);
			}
		} while (p1->getHealth() > 0 && p2->getHealth() > 0);
	}

	if (p1->getHealth() > 0)
	{
		std::cout << "The winner is " << p1->getName() << std::endl;
	}

	else
	{
		std::cout << "The winner is " << p2->getName() << std::endl;
	}
	
}

/*********************************************************************************
**								Battle::setP
** Description: setP takes in an int as an argument to determine which creature
**				type to use. Returns a new creature object of the chosen type.
**
*********************************************************************************/
Fighter* Battle::setP(int fighter)
{
	if (fighter == 1)
	{
		return new Barbarian();
	}
	if (fighter == 2)
	{
		return new BlueMen();
	}
	if (fighter == 3)
	{
		return new HarryPotter();
	}
	if (fighter == 4)
	{
		return new Medusa();
	}
	if (fighter == 5)
	{
		return new Vampire();
	}
}