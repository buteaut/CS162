/*********************************************************************************
** Program name: Project 5 (Rooms Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Rooms implementation file. Template class for other 'room' 
**				classes.
**
*********************************************************************************/

#include "rooms.hpp"

Rooms::Rooms() //default constructor
{
	this->north = NULL;
	this->south = NULL;
	this->east = NULL;
	this->west = NULL;

	this->finished = false;

	this->description = "";
	this->altDescription = "";
	this->name = "";

}

Rooms::Rooms(Rooms* N, Rooms* S, Rooms* E, Rooms* W, std::string des,
	std::string altDes, std::string name) //constructor
{
	this->north = N;
	this->south = S;
	this->east = E;
	this->west = W;

	this->finished = false;

	this->description = des;
	this->altDescription = altDes;
	this->name = name;
}

Rooms::~Rooms() //destructor
{

}

/*********************************************************************************
**								Rooms::setNorth
** Description: Sets the pointer to the room to the north.
**
*********************************************************************************/
void Rooms::setNorth(Rooms* N)
{
	this->north = N;
}

/*********************************************************************************
**								Rooms::setSouth
** Description: Sets the pointer to the room to the south.
**
*********************************************************************************/
void Rooms::setSouth(Rooms* S)
{
	this->south = S;
}

/*********************************************************************************
**								Rooms::setEast
** Description: Sets the pointer to the room to the east.
**
*********************************************************************************/
void Rooms::setEast(Rooms* E)
{
	this->east = E;
}

/*********************************************************************************
**								Rooms::setWest
** Description: Sets the pointer to the room to the west.
**
*********************************************************************************/
void Rooms::setWest(Rooms* W)
{
	this->west = W;
}

/*********************************************************************************
**								Rooms::getNorth
** Description: Returns the pointer to the room to the north.
**
*********************************************************************************/
Rooms* Rooms::getNorth()
{
	return this->north;
}

/*********************************************************************************
**								Rooms::getSouth
** Description: Returns the pointer to the room to the south.
**
*********************************************************************************/
Rooms* Rooms::getSouth()
{
	return this->south;
}

/*********************************************************************************
**								Rooms::getEast
** Description: Returns the pointer to the room to the east.
**
*********************************************************************************/
Rooms* Rooms::getEast()
{
	return this->east;
}

/*********************************************************************************
**								Rooms::getWest
** Description: Returns the pointer to the room to the west.
**
*********************************************************************************/
Rooms* Rooms::getWest()
{
	return this->west;
}

/*********************************************************************************
**								Rooms::hasAction
** Description: Returns the name of the item required to perform an action.
**
*********************************************************************************/
std::string Rooms::hasAction()
{
	return "";
}

/*********************************************************************************
**								Rooms::actionDescription
** Description: Returns a decription of the action available for this room.
**
*********************************************************************************/
std::string Rooms::actionDescription()
{
	std::string des = "";
	return des;
}

/*********************************************************************************
**								Rooms::action
** Description: Method to get room information back to game class. Number 
**				returned is used by Game::action to flip conditional triggers.
**
*********************************************************************************/
int Rooms::action()
{
	return 0;
}

/*********************************************************************************
**								Rooms::getDescription
** Description: Returns a decription of the room. Will return altDescription if
**				finished=true.
**
*********************************************************************************/
std::string Rooms::getDescription()
{
	if (finished)
	{
		return this->altDescription;
	}

	return this->description;
}

/*********************************************************************************
**								Rooms::getName
** Description: Returns the room name.
**
*********************************************************************************/
std::string Rooms::getName()
{
	return this->name;
}

/*********************************************************************************
**								Rooms::getItem
** Description: If the room has an item it is popped and returned. If not returns
**				an empty string.
**
*********************************************************************************/
std::string Rooms::getItem()
{
	if (!inventory.empty())
	{
		std::string item = inventory.back();
		inventory.pop_back();
		return item;
	}

	return "";
}

/*********************************************************************************
**								Rooms::setItem
** Description: Adds an item to the room.
**
*********************************************************************************/
void Rooms::setItem(std::string item)
{
	inventory.push_back(item);
}

/*********************************************************************************
**								Rooms::itemReport
** Description: Returns the size of the room inventory.
**
*********************************************************************************/
int Rooms::itemReport()
{
	return inventory.size();
}

/*********************************************************************************
**								Rooms::itemName
** Description: Returns the name of the last item in the room inventory.
**
*********************************************************************************/
std::string Rooms::itemName()
{
		return inventory.back();
}