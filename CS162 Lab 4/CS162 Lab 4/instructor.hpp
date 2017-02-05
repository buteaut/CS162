/*********************************************************************************
** Program name: Lab 3 (LoadedDie Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: LoadedDie header file for Lab 3. The LoadedDie class is a child
**				of the Die class and overloads the roll method to increase the
**				likelyhood of a higher result.
*********************************************************************************/

#ifndef INSTRUCTOR_HPP
#define INSTRUCTOR_HPP

#include "person.hpp"
#include <iostream>


class Instructor : public Person
{
protected:
	double instructorRating;

public:
	Instructor();
	Instructor(std::string name);
	Instructor(std::string name, int age);
	Instructor(std::string name, int age, double instructorRating);
	~Instructor();

	void do_work();

};

#endif
