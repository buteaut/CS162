/*********************************************************************************
** Program name: Lab 4 (Person Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Person implementation file. Person is virtual class so only
**				constructors and destructors are defined here. Person has a name
**				and age.
*********************************************************************************/

#include "building.hpp"

//default constructor
Building::Building()
{
	name = "";
	sqrFootage = 0;
	address = "";
}

//full constructor
Building::Building(std::string name, int sqrFootage, std::string address)
{
	this->name = name;
	this->sqrFootage = sqrFootage;
	this->address = address;
}

//destructor
Building::~Building()
{
	//intentionally left blank
}

/*****************************************************************************
**						Building::<<
** Description: Outstream override for the Building class. Prints out a 
**				statement which contains the Building name and address.
**
*****************************************************************************/
std::ostream& operator<<(std::ostream &outs, const Building& foo)
{
	outs << foo.name << " is located at " << foo.address << std::endl;

	return outs;
}