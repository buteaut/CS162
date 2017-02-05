/*********************************************************************************
** Program name: Lab 4 (Person Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Person implementation file. Person is virtual class so only 
**				constructors and destructors are defined here. Person has a name
**				and age.
*********************************************************************************/

#include "person.hpp"

//default constructor
Person::Person()
{
	name = "";
	age = 0;
}

//constructor with name
Person::Person(std::string name)
{
	this->name = name;
	age = rand() % 75 + 18;
}

//full constructor
Person::Person(std::string name, int age)
{
	this->name = name;
	this->age = age;
}

//destructor
Person::~Person()
{
	//intentionally left blank
}



/*****************************************************************************
**						Person::<<
** Description: Outstream override for the Person class. Prints out a statement
**				which contains the Person's name.
**
*****************************************************************************/
std::ostream& operator<<(std::ostream &outs, const Person& foo)
{
	outs << foo.name << std::endl;

	return outs;
}