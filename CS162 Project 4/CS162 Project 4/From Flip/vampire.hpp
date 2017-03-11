/*********************************************************************************
** Program name: Project 3 (Vampire Header File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Vampire header file. Attacks with 1D12, defends with 1D6, 
**				has 1 armor and 18 health. Has "charm" ability which gives 50%
**				chance to dodge all damage (does not work against Medusa "glare").
**
*********************************************************************************/

#ifndef VAMPIRE_HPP
#define Vampire_HPP

#include "fighter.hpp"


class Vampire : public Fighter
{
protected:
	

public:
	Vampire(); //default constructor

	Vampire(std::string name);

	virtual ~Vampire(); //deconstructor

	virtual void defense(int);
	bool charm();
};

#endif
