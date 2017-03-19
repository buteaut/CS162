/*********************************************************************************
** Program name: Project 5 (Entrance Header File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Entrance header file. 
**
*********************************************************************************/

#ifndef ENTRANCE_HPP
#define ENTRANCE_HPP

#include "rooms.hpp"

class Entrance : public Rooms
{
protected:

public:
	Entrance();

	virtual ~Entrance();

	virtual void test();
};

#endif