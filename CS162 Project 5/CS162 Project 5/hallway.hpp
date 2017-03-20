/*********************************************************************************
** Program name: Project 5 (Hallway Header File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Entrance header file.
**
*********************************************************************************/

#ifndef HALLWAY_HPP
#define HALLWAY_HPP

#include "rooms.hpp"

class Hallway : public Rooms
{
protected:

public:
	Hallway();

	virtual ~Hallway();

	virtual std::string hasAction();

	virtual std::string actionDescription();

	virtual int action();

	
};

#endif