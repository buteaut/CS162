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

class Battle
{
private:
	Fighter* p1;
	Fighter* p2;

public:
	Battle(); //default constructor
	~Battle(); //destructor

	void menu();
	void fight();
	Fighter* setP(int);

};


#endif
