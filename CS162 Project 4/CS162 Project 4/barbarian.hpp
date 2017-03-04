/*********************************************************************************
** Program name: Project 3 (Barbarian Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Barbarian header file. The barbarian is a faily generic
**				fighter. Attacks with 2D6, defends with 2D6, has no armor and 12
**				health. No special abilities. More city guard than dragonborn.
**
*********************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "fighter.hpp"


class Barbarian : public Fighter
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
	Barbarian(); //default constructor

	Barbarian(std::string name);

	virtual ~Barbarian(); //deconstructor
	
};

#endif
