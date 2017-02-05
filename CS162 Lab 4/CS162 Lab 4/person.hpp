/*********************************************************************************
** Program name: Lab 3 (LoadedDie Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: LoadedDie header file for Lab 3. The LoadedDie class is a child
**				of the Die class and overloads the roll method to increase the
**				likelyhood of a higher result.
*********************************************************************************/

#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <iostream>
#include <random>
#include <time.h>

class Person
{
protected:
	std::string name;
	int age;

public:
	Person();
	Person(std::string name);
	Person(std::string name, int age);
	~Person();
	virtual void do_work() = 0;

	friend std::ostream& operator<<(std::ostream &outs, const Person& foo);
};

#endif
