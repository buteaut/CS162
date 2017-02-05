/*********************************************************************************
** Program name: Lab 4 (Person Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Person implementation file. Person is virtual class so only
**				constructors and destructors are defined here. Person has a name
**				and age.
*********************************************************************************/

#include "instructor.hpp"

//default constructor
Instructor::Instructor() : Person() 
{
	instructorRating = 0.0;
}

//constructor with name
Instructor::Instructor(std::string name) : Person(name) 
{
	instructorRating = (rand() % 500) / 100.0;
}

//constructor with name and age
Instructor::Instructor(std::string name, int age) : Person(name, age) 
{
	instructorRating = (rand() % 500) / 100.0;
}

//full constructor
Instructor::Instructor(std::string name, int age, double instructorRating) 
	: Person(name, age) 
{
	this->instructorRating = instructorRating;
}

//destructor
Instructor::~Instructor()
{
	//intentionally left blank
}

/*****************************************************************************
**						Instructor::do_work
** Description: Generates a random number than returns a statement saying the
**				instructor graded papers for that many hours.
**
*****************************************************************************/
void Instructor::do_work()
{
	int work = rand() % 6;

	std::cout << "Instructor " << name << " graded papers for " << work << " hours." << std::endl;
}