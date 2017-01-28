/*********************************************************************************
** Program name: Lab 3 (Die Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: Die header file for Lab 3. The Die class has an int numSides that
**				holds the number of sides the die has. The Die class also has a 
**				roll method that generates a random number from 1 to numSides and
**				returns it.
*********************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <random>
#include <iostream>

class Die
{
protected:
	int numSides;

public:
	Die(); //default constructor
	Die(int numSides); //constructor with argument
	~Die(); //destructor
	
	
	virtual int roll();


};

#endif
