/*********************************************************************************
** Program name: Project 5 (Hallway Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Hallway implementation file.
**
*********************************************************************************/

#include "hallway.hpp"

std::string hallwayDes = "This is the hallway. The sound of air rushing out of the ship"
+ std::string(" is deafening. Thankfully the \nholes in the wall look small enough")
+ std::string(" to patch.\nTo the north is an intersection. \nTo the south is the crew")
+ std::string(" quarters. \nTo the west is the maintenance room.");

std::string hallwayAlt = "This is the hallway. An inspection of the patch shows it is "
+ std::string("fairly stable for now. You can \nstill hear the leak however. ")
+ std::string("Someone will have to go outside the ship to finish this patch.\nTo the ")
+ std::string("north is an intersection. \nTo the south is the crew quarters. \n")
+ std::string("To the west is the maintenance room.");

Hallway::Hallway() : Rooms(NULL, NULL, NULL, NULL, hallwayDes,
	hallwayAlt, "Hallway") //constructor
{

}

Hallway::~Hallway() //destructor
{
	//left blank
}

/*********************************************************************************
**								Hallway::hasAction
** Description: Returns the name of the item required to perform an action.
**
*********************************************************************************/
std::string Hallway::hasAction()
{
	return "patch kit";
}

/*********************************************************************************
**								Hallway::actionDescription
** Description: Returns a decription of the action available for this room.
**
*********************************************************************************/
std::string Hallway::actionDescription()
{
	std::string actionDes = "With a proper patch kit this leak could be significantly"
		+ std::string(" lessened.");

	return actionDes;
}

/*********************************************************************************
**								Hallway::action
** Description: Method to get room information back to game class. Number
**				returned is used by Game::action to flip conditional triggers.
**
*********************************************************************************/
int Hallway::action()
{
	finished = true;
	return 1;
}