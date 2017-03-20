/*********************************************************************************
** Program name: Project 5 (Rooms Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Rooms implementation file. Template class for other 'room' 
**				classes.
**
*********************************************************************************/

#include "rooms.hpp"

Rooms::Rooms()
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
	std::string altDes, std::string name)
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

Rooms::~Rooms()
{

}

void Rooms::setNorth(Rooms* N)
{
	this->north = N;
}

void Rooms::setSouth(Rooms* S)
{
	this->south = S;
}

void Rooms::setEast(Rooms* E)
{
	this->east = E;
}

void Rooms::setWest(Rooms* W)
{
	this->west = W;
}

Rooms* Rooms::getNorth()
{
	return this->north;
}

Rooms* Rooms::getSouth()
{
	return this->south;
}

Rooms* Rooms::getEast()
{
	return this->east;
}

Rooms* Rooms::getWest()
{
	return this->west;
}

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

int Rooms::action()
{
	return 0;
}

std::string Rooms::getDescription()
{
	if (finished)
	{
		return this->altDescription;
	}

	return this->description;
}

std::string Rooms::getName()
{
	return this->name;
}

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

void Rooms::setItem(std::string item)
{
	inventory.push_back(item);
}

int Rooms::itemReport()
{
	return inventory.size();
}

std::string Rooms::itemName()
{
		return inventory.back();
}