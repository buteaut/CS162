/*********************************************************************************
** Program name: Project 3 (Battle Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Battle header file. The Battle class is the driver class
**				for this program. It allows the user to pick fighters and then
**				makes them fight until one has died, reporting the stats for the
**				duration of the fight.
**
*********************************************************************************/

#ifndef COMBATANTS_HPP
#define COMBATANTS_HPP

#include "fighter.hpp"

struct Combatants
{
	Fighter* person;
	Combatants* next;

	Combatants(Fighter* person)
	{
		this->person = person;
		this->next = nullptr;
	}

	~Combatants()
	{
		delete person;
	}
};

#endif