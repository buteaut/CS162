/*********************************************************************************
** Program name: Lab 3 (Die Implementation File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: Die implementation file for Lab 3. The Die class has an int 
**				numSides that holds the number of sides the die has. The Die 
**				class also has a roll method that generates a random number from 
**				1 to numSides and returns it.
*********************************************************************************/

#include "Die.hpp"

//default constructor
Die::Die()
{
	numSides = 0;
}

//constructor with argument
Die::Die(int numSides)
{
	this->numSides = numSides;
}

//destructor
Die::~Die()
{
	//intentionally left blank
}

/*****************************************************************************
**						Die::roll
** Description: Generates and returns a random int from 1 to numSides.
**
*****************************************************************************/
int Die::roll()
{
	//std::cout << "Die is rolling." << std::endl;   //test printout
	return (rand() % numSides + 1);
}