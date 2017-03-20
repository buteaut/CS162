/*********************************************************************************
** Program name: Project 5 (Engine Header File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Engine header file.
**
*********************************************************************************/

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "rooms.hpp"

class Engine : public Rooms
{
protected:

public:
	Engine();

	virtual ~Engine();

	virtual std::string hasAction();

	virtual std::string actionDescription();

	virtual int action();


};

#endif
