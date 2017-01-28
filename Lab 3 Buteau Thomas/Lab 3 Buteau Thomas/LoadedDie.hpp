/*********************************************************************************
** Program name: Lab 3 (LoadedDie Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: LoadedDie header file for Lab 3. The LoadedDie class is a child
**				of the Die class and overloads the roll method to increase the 
**				likelyhood of a higher result.
*********************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include <random>
#include <iostream>
#include "Die.hpp"

class LoadedDie : public Die
{
public:
	LoadedDie(int numSides); //constructor with arguments
	virtual int roll(); //modified roll method

};

#endif

