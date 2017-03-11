/*********************************************************************************
** Program name: Project 3 (Medusa Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Medusa header file. Attacks with 2D6, defends with 1D6, 
**				has 3 armor and 8 health. If Medusa gets max damage on attack 
**				glare is triggered which calls isDead() on opponent.
**
*********************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "fighter.hpp"


class Medusa : public Fighter
{
protected:
	

public:
	Medusa(); //default constructor
	Medusa(std::string name);
	virtual ~Medusa(); //deconstructor

	virtual void attack(Fighter*);
	
};

#endif

