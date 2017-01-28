/*********************************************************************************
** Program name: Lab 3 (LoadedDie Implementation File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: LoadedDie implementation file for Lab 3. LoadedDie has a roll 
**				method that overrides the Die class roll method. LoadedDie's roll
**				actually rolls twice and returns the higher of the two values.
*********************************************************************************/

#include "LoadedDie.hpp"

//constructor with arguments
LoadedDie::LoadedDie(int numSides) : Die(numSides)
{
	//intentionally left blank
}

/*****************************************************************************
**						LoadedDie::roll
** Description: Generates two random integers from 1 to numSides and returns 
**				the larger number.
**
*****************************************************************************/
int LoadedDie::roll()
{
	//std::cout << "Loaded die is rolling." << std::endl; //test printout
	int temp1 = rand() % numSides + 1;
	int temp2 = rand() % numSides + 1;

	if (temp1 >= temp2)
	{
		return temp1;
	}

	else if (temp2 > temp1)
	{
		return temp2;
	}

	//else statement will show bad value for testing purposes
	else
	{
		return -1;
	}
}
