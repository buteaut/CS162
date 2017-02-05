/*********************************************************************************
** Program name: Lab 3 (LoadedDie Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: LoadedDie header file for Lab 3. The LoadedDie class is a child
**				of the Die class and overloads the roll method to increase the
**				likelyhood of a higher result.
*********************************************************************************/

#ifndef UNIVERSITY_HPP
#define UNIVERSITY_HPP

#include <vector>
#include <string>
#include <iostream>
#include "building.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "dataValidation.hpp"

class University
{
private:
	std::string uniName;
	std::vector<Person*> people;
	std::vector<Building*> places;

public:
	University();
	~University();

	void pushPerson(Person*);
	
	void pushBuilding(Building*);
	
	void displayPeople();

	void displayBuildings();
	
	void menu();

	void peopleMenu();

};

#endif

