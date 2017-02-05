/*********************************************************************************
** Program name: Lab 3 (LoadedDie Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: LoadedDie header file for Lab 3. The LoadedDie class is a child
**				of the Die class and overloads the roll method to increase the
**				likelyhood of a higher result.
*********************************************************************************/

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "person.hpp"


class Student : public Person
{
protected:
	double gpa;

public:
	Student();
	Student(std::string name);
	Student(std::string name, int age);
	Student(std::string name, int age, double gpa);
	~Student();

	void do_work();

};
#endif
