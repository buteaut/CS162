/*********************************************************************************
** Program name: Project 3 (Blue Men Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Blue Men header file. Blue Men are absolute beasts. 2D10
**				for attacks, up to 3D6 for dodge, 3 armor, and 12 health. The 
**				number of dodge dice are (health / 4) and calculated before each
**				defense. They basically always win.
**
*********************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "fighter.hpp"


class BlueMen : public Fighter
{
protected:
	int attDieNum;
	int attDiePow;
	int defDieNum;
	int defDiePow;
	int armor;
	int health; //strength in assignment write up, health made more sense
	std::string name;

public:
	BlueMen(); //default constructor
	virtual ~BlueMen(); //deconstructor

	virtual void attack(Fighter*);
	virtual void defense(int);
	virtual void isDead();
	virtual int rollDice(int);
	virtual const int getHealth();
	virtual const std::string getName();

};

#endif
