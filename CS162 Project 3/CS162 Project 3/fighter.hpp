/*********************************************************************************
** Program name: Project 3 (Fighter Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Fighter header file. Template class for all other creature
**				types. Has methods for attacking and defense as well as other's
**				that are needed for those two main methods.
**
*********************************************************************************/

#ifndef FIGHTER_HPP
#define FIGHTER_HPP

#include <iostream>
#include <string>
#include <random>
#include <time.h>


class Fighter
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
	Fighter(); //default constructor
	virtual ~Fighter() = 0; //deconstructor

	virtual void attack(Fighter*);
	virtual void defense(int);
	virtual void isDead();
	virtual int rollDice(int);
	virtual const int getHealth();
	virtual const std::string getName();

};

#endif