/*********************************************************************************
** Program name: Project 3 (Barbarian Implementation File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Barbarian implementation file. The barbarian is a faily generic
**				fighter. Attacks with 2D6, defends with 2D6, has no armor and 12
**				health. No special abilities. More city guard than dragonborn.
**
*********************************************************************************/

#include "barbarian.hpp"

Barbarian::Barbarian() : Fighter(2,6,2,6,0,12,"Barbarian") //default constructor
{
	//intentionally left blank
}

Barbarian::Barbarian(std::string name) : Fighter(2, 6, 2, 6, 0, 12, name)
{
	//intentionally left blank
}

Barbarian::~Barbarian() //deconstructor
{
	//intentionally left blank
}
