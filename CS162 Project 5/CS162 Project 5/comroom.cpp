/*********************************************************************************
** Program name: Project 5 (Comroom Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Comroom implementation file.
**
*********************************************************************************/

#include "comroom.hpp"

std::string comroomDes = "This is the communications room. The the displays "
+ std::string("flicker occasionally as the power surges \nand shorts.")
+ std::string("\nTo the west is an intersection.");

std::string comroomAlt = "This is the communications room. The diplays glow "
+ std::string("brightly and show that there are no \nships or stations in ")
+ std::string("communication range.")
+ std::string("\nTo the west is an intersection.");

ComRoom::ComRoom() : Rooms(NULL, NULL, NULL, NULL, comroomDes,
	comroomAlt, "Communications Room") //constructor
{

}

ComRoom::~ComRoom() //destructor
{
	//left blank
}

/*********************************************************************************
**								ComRoom::hasAction
** Description: Returns the name of the item required to perform an action.
**
*********************************************************************************/
std::string ComRoom::hasAction()
{
	return "tool kit";
}

/*********************************************************************************
**								ComRoom::actionDescription
** Description: Returns a decription of the action available for this room.
**
*********************************************************************************/
std::string ComRoom::actionDescription()
{
	std::string actionDes = "You see the source of the electrical short and "
		+ std::string("know that you can repair it if you have \nyour tool ")
		+ std::string("kit.");

	return actionDes;
}

/*********************************************************************************
**								ComRoom::action
** Description: Method to get room information back to game class. Number
**				returned is used by Game::action to flip conditional triggers.
**
*********************************************************************************/
int ComRoom::action()
{
	finished = true;
	return 2;
}