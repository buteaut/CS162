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

#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "barbarian.hpp"
#include "harryPotter.hpp"
#include "vampire.hpp"
#include "blueMen.hpp"
#include "medusa.hpp"
#include "dataValidation.hpp"
#include "combatants.hpp"

class Battle
{
private:
	Combatants* p1;
	Combatants* p2;
	Combatants* lost;
	int p1Wins;
	int p2Wins;
	int size;

public:
	Battle(); //default constructor
	~Battle(); //destructor

	void menu();
	void fight();
	Combatants* setP(int, std::string);
	void addFront(Combatants* toAdd, Combatants* existing);
	void addBack(Combatants* toAdd, Combatants* existing);
	Combatants* removeFront(Combatants* foo);
	void delStack(Combatants*);

};


#endif
