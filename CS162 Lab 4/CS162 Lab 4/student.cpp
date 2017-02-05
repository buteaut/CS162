/*********************************************************************************
** Program name: Lab 4 (Person Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Person implementation file. Person is virtual class so only
**				constructors and destructors are defined here. Person has a name
**				and age.
*********************************************************************************/

#include "student.hpp"

//default constructor
Student::Student() : Person()
{
	gpa = 0.0;
}

//constructor with name
Student::Student(std::string name) : Person(name)
{
	gpa = (rand() % 400) / 100.0;
}

//constructor with name and age
Student::Student(std::string name, int age) : Person(name, age)
{
	gpa = (rand() % 400) / 100.0;
}

//full constructor
Student::Student(std::string name, int age, double gpa) : Person(name, age)
{
	this->gpa = gpa;
}

//destructor
Student::~Student()
{
	//intentionally left blank
}

/*****************************************************************************
**						Student::do_work
** Description: Generates a random number than returns a statement saying the
**				student did homework for that many hours.
**
*****************************************************************************/
void Student::do_work()
{
	int work = rand() % 6;

	std::cout << name << " did " << work << " hours of homework." << std::endl;
}