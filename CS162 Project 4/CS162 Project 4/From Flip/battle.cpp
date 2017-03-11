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
	//if (this->p1 != nullptr)
	//{	
		delStack(p1);
	//}
	//if (this->p2 != nullptr)
	//{
		delStack(p2);
	//}
	//if (this->lost != nullptr)
	//{
		delStack(lost);
	//}	
	//delete p1;
	//delete p2;
	//delete lost;
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
	std::string name;
	std::cout << "Welcome to the battle arena." << std::endl;
	do
	{
		std::cout << "Enter the number of fighters per team (up to 10)." 
			<< std::endl;
		int size = valIntPos(2, 1, 10);

		for (int i = 0; i < size; i++)
		{
			std::cout << "Choose fighter " << i+1 << " for team 1." << std::endl;
			std::cout << "1. Barbarian" << std::endl;
			std::cout << "2. Blue Men" << std::endl;
			std::cout << "3. Harry Potter" << std::endl;
			std::cout << "4. Medusa" << std::endl;
			std::cout << "5. Vampire" << std::endl;
			int p1Temp = valIntPos(1, 1, 5);
			std::cout << "Enter the name of this fighter." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, name);
			addBack(setP(p1Temp, name), 1);
		}

		for (int i = 0; i < size; i++)
		{
			std::cout << "Choose fighter " << i+1 << " for team 2." << std::endl;
			std::cout << "1. Barbarian" << std::endl;
			std::cout << "2. Blue Men" << std::endl;
			std::cout << "3. Harry Potter" << std::endl;
			std::cout << "4. Medusa" << std::endl;
			std::cout << "5. Vampire" << std::endl;
			int p2Temp = valIntPos(1, 1, 5);
			std::cout << "Enter the name of this fighter." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, name);
			addBack(setP(p2Temp, name), 2);
		}

		fight();

		delStack(p1);
		delStack(p2);
		delStack(lost);
		p1 = nullptr;
		p2 = nullptr;
		lost = nullptr;
		p1Wins = 0;
		p2Wins = 0;
		std::cout << "Would you like to play again? (Y/N)" << std::endl;
		
		std::cin >> cont;
		std::cout << std::endl;
	} while (toupper(cont) == 'Y');
}

/*********************************************************************************
**								Battle::fight
** Description: Has the top of the p1 and p2 stacks fight then puts the winner on
**				the bottom of their stack and the loser on the top of the lost 
**				stack. This loops until either p1 or p2 is empty, then reports the
**				winner as well as a list of dead fighters.
**
*********************************************************************************/
void Battle::fight()
{
	while (p1 != nullptr && p2 != nullptr)
	{
		int choice = rand() % 2;

		if (choice == 0)
		{
			do
			{
				(p1->person)->attack(p2->person);

				if ((p2->person)->getHealth() > 0)
				{
					(p2->person)->attack(p1->person);
				}
			} while ((p1->person)->getHealth() > 0 && (p2->person)->getHealth() > 0);
		}

		else
		{
			do
			{
				(p2->person)->attack(p1->person);

				if ((p1->person)->getHealth() > 0)
				{
					(p1->person)->attack(p2->person);
				}
			} while ((p1->person)->getHealth() > 0 && (p2->person)->getHealth() > 0);
		}

		if ((p1->person)->getHealth() > 0)
		{
			p1Wins++;
			std::cout << "******************************************" << std::endl;
			std::cout << "The fight between " << (p1->person)->getName() << " and "
				<< (p2->person)->getName() << " is over!" << std::endl;
			std::cout << "The winner this round is " << (p1->person)->getName() << std::endl;
			std::cout << "The current score is: " << std::endl;
			std::cout << "Team 1: " << p1Wins << "			Team 2: " << p2Wins << std::endl;
			std::cout << "******************************************" << std::endl;
			std::cout << std::endl;
			addBack(removeFront(p1), 1); //winner from p1 goes to bottom of p1 stack
			addFront(removeFront(p2));  //loser from p2 goes to top of lost stack
		}

		else
		{
			p2Wins++;
			std::cout << "******************************************" << std::endl;
			std::cout << "The fight between " << (p1->person)->getName() << " and "
				<< (p2->person)->getName() << " is over!" << std::endl;
			std::cout << "The winner this round is " << (p2->person)->getName() << std::endl;
			std::cout << "The current score is: " << std::endl;
			std::cout << "Team 1: " << p1Wins << "			Team 2: " << p2Wins << std::endl;
			std::cout << "******************************************" << std::endl;
			std::cout << std::endl;
			addBack(removeFront(p2), 2); //winner from p2 goes to bottom of p2 stack
			addFront(removeFront(p1));   //loser from p1 goes to top of lost stack
		}
	}
	if (p1Wins > p2Wins)
	{
		std::cout << std::endl;
		std::cout << "******************************************" << std::endl;
		std::cout << "Team 1 has won the tournament!" << std::endl;
		std::cout << "******************************************" << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "******************************************" << std::endl;
		std::cout << "Team 2 has won the tournament!" << std::endl;
		std::cout << "******************************************" << std::endl;
	}
	std::cout << "The warriors who have gone to Valhalla are:" << std::endl;
	Combatants* dead = lost;
	while (dead->next != nullptr)
	{
		std::cout << (dead->person)->getName() << std::endl;
		dead = dead->next;
	}
	std::cout << (dead->person)->getName() << std::endl;
	
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
**				lost stack.
**
*********************************************************************************/
void Battle::addFront(Combatants* toAdd)
{
	if (lost == nullptr)
	{
		lost = toAdd;
	}

	else
	{
		Combatants* second = lost;
		lost = toAdd;
		lost->next = second;
	}
}


/*********************************************************************************
**								Battle::addBack
** Description: Adds the Combatants pointer argument to the back of either the p1
**				or p2 Combatants stack depending on the int argument (1 for p1, 
**				2 for p2).
**
*********************************************************************************/
void Battle::addBack(Combatants* toAdd, int existing)
{
	if (existing == 1)
	{
		if (p1 == nullptr)
		{
			p1 = toAdd;
		}

		else
		{
			Combatants* end = p1;
			while (end->next != nullptr)
			{
				end = end->next;
			}
			end->next = toAdd;
		}
	}

	if (existing == 2)
	{
		if (p2 == nullptr)
		{
			p2 = toAdd;
		}

		else
		{
			Combatants* end = p2;
			while (end->next != nullptr)
			{
				end = end->next;
			}
			end->next = toAdd;
		}
	}
}

/*********************************************************************************
**								Battle::removeFront
** Description: Removes the head of the stack the argument points to, calls recoup
**				on that Combatants' Fighter, and returns the Combatants pointer.
**
*********************************************************************************/
Combatants* Battle::removeFront(Combatants* &foo)
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
	//delete head;
}
