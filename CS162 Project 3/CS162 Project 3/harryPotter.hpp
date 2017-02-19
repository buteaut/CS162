/*********************************************************************************
** Program name: Project 3 (HarryPotter Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Harry Potter header file. Harry Potter is a faily generic
**				fighter with one exception. Attacks with 2D6, defends with 2D6, 
**				has no armor and 10	health. When health goes beneath 1 the first 
**				time the method resurrection restores health to 20.
**
*********************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "fighter.hpp"


class HarryPotter : public Fighter
{
protected:
	int attDieNum;
	int attDiePow;
	int defDieNum;
	int defDiePow;
	int armor;
	int health; //strength in assignment write up, health made more sense
	std::string name;
	bool hasDied;

public:
	HarryPotter(); //default constructor
	virtual ~HarryPotter(); //deconstructor

	virtual void attack(Fighter*);
	virtual void defense(int);
	virtual void isDead();
	virtual int rollDice(int);
	void resurrect();
	virtual const int getHealth();
	virtual const std::string getName();

};

#endif
