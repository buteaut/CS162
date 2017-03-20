/*********************************************************************************
** Program name: Project 5 (Engine Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Engine implementation file.
**
*********************************************************************************/

#include "engine.hpp"

std::string engineDes = "This is the engine room. The reactor appears to be "
+ std::string("fluctuating wildly. Likely caused by \nthe shorts in the system. A ")
+ std::string("reboot of the reactor will be required to resume normal \nbehavior.")
+ std::string("\nTo the east is an intersection.");

std::string engineAlt = "";

Engine::Engine() : Rooms(NULL, NULL, NULL, NULL, engineDes,
	engineAlt, "Engine Room") //constructor
{

}

Engine::~Engine() //destructor
{
	//left blank
}

/*********************************************************************************
**								Engine::hasAction
** Description: Returns the name of the item required to perform an action.
**
*********************************************************************************/
std::string Engine::hasAction()
{
	return "engine lockout key";
}

/*********************************************************************************
**								Engine::actionDescription
** Description: Returns a decription of the action available for this room.
**
*********************************************************************************/
std::string Engine::actionDescription()
{
	std::string actionDes = "The reactor will need to be restarted. If the short isn't"
		+ std::string(" fixed first, there's a large \nrisk the restart process will ")
		+ std::string("perminantly shut the reactor down. The engine lockout key is ")
		+ std::string("\nrequired to initiate the restart process.");

	return actionDes;
}

/*********************************************************************************
**								Engine::action
** Description: Method to get room information back to game class. Number
**				returned is used by Game::action to flip conditional triggers.
**
*********************************************************************************/
int Engine::action()
{
	finished = true;
	return 3;
}