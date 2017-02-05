/*********************************************************************************
** Program name: Lab 3 (LoadedDie Header File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: LoadedDie header file for Lab 3. The LoadedDie class is a child
**				of the Die class and overloads the roll method to increase the
**				likelyhood of a higher result.
*********************************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <string>
#include <iostream>

class Building
{
private:
	std::string name;
	int sqrFootage;
	std::string address;

public:
	Building();
	Building(std::string name, int sqrFootage, std::string address);
	~Building();

	friend std::ostream& operator<<(std::ostream &outs, const Building& foo);
};
#endif

