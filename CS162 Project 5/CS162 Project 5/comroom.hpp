/*********************************************************************************
** Program name: Project 5 (Comroom Header File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Comroom header file.
**
*********************************************************************************/

#ifndef COMROOM_HPP
#define COMROOM_HPP

#include "rooms.hpp"

class ComRoom : public Rooms
{
protected:

public:
	ComRoom();

	virtual ~ComRoom();

	virtual std::string hasAction();

	virtual std::string actionDescription();

	virtual int action();


};

#endif