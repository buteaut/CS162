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
	this->p1Wins = 0;
	this->p2Wins = 0;
	this->p1 = nullptr;
	this->p2 = nullptr;
	this->lost = nullptr;
}

Battle::~Battle() //deconstructor
{
	delStack(p1);
	delStack(p2);
	delStack(lost);
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
		std::cout << "Enter the number of fighters per team (up to 10)." 
			<< std::endl;
		int size = valIntPos(2, 1, 10);
		std::cout << "Choose the first fighter." << std::endl;
		std::cout << "1. Barbarian" << std::endl;
		std::cout << "2. Blue Men" << std::endl;
		std::cout << "3. Harry Potter" << std::endl;
		std::cout << "4. Medusa" << std::endl;
		std::cout << "5. Vampire" << std::endl;
		int p1Temp = valIntPos(1, 1, 5);
		std::string name;
		std::cout << "Enter the name of this fighter." << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::getline(std::cin, name);
		p1 = setP(p1Temp, name);

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
Combatants* Battle::setP(int fighter, std::string name)
{
	if (fighter == 1)
	{
		return new Combatants(new Barbarian(name));
	}
	if (fighter == 2)
	{
		return new Combatants(new BlueMen(name));
	}
	if (fighter == 3)
	{
		return new Combatants(new HarryPotter(name));
	}
	if (fighter == 4)
	{
		return new Combatants(new Medusa(name));
	}
	if (fighter == 5)
	{
		return new Combatants(new Vampire(name));
	}
}

/*********************************************************************************
**								Battle::addFront
** Description: Adds the first Combatants pointer argument to the front of the
**				stack pointed to by the second Combatants pointer argument.
**
*********************************************************************************/
void Battle::addFront(Combatants* toAdd, Combatants* existing)
{
	if (existing == nullptr)
	{
		existing = toAdd;
	}

	else
	{
		Combatants* second = existing;
		existing = toAdd;
		existing->next = second;
	}
}

/*********************************************************************************
**								Battle::addBack
** Description: Adds the first Combatants pointer argument to the back of the 
**				stack pointed to by the second Combatants pointer argument.
**
*********************************************************************************/
void Battle::addBack(Combatants* toAdd, Combatants* existing)
{
	if (existing == nullptr)
	{
		existing = toAdd;
	}

	else
	{
		Combatants* end = existing;
		while (end->next != nullptr)
		{
			end = end->next;
		}
		end->next = toAdd;
	}
}

/*********************************************************************************
**								Battle::removeFront
** Description: Removes the head of the stack the argument points to, calls recoup
**				on that Combatants' Fighter, and returns the Combatants pointer.
**
*********************************************************************************/
Combatants* Battle::removeFront(Combatants* foo)
{
	Combatants* head = foo;
	foo = foo->next;
	head->next = nullptr;
	(head->person)->recoup();
	return head;
}

/*********************************************************************************
**								Battle::delStack
** Description: Deletes the stack pointed to by the argument.
**
*********************************************************************************/
void Battle::delStack(Combatants* head)
{
	if (head != nullptr) //trash collection
	{
		Combatants* endPnt = head;
		while (endPnt->next != nullptr)
		{
			Combatants* trash = endPnt;
			endPnt = endPnt->next;
			delete trash;
		}
	}
	delete head;
}