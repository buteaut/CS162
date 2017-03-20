/*********************************************************************************
** Program name: Project 5 (Rooms Header File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Rooms header file. Template class for other 'room' classes.
**
*********************************************************************************/

#ifndef ROOMS_HPP
#define ROOMS_HPP

#include <string>
#include <vector>

class Rooms
{
protected:
	Rooms* north;
	Rooms* south;
	Rooms* east;
	Rooms* west;

	bool finished;

	std::string description;
	std::string altDescription;
	std::string name;
	std::vector<std::string> inventory;

public:
	Rooms();

	Rooms(Rooms* N, Rooms* S, Rooms* E, Rooms* W, std::string des,
		std::string altDes, std::string name);

	virtual ~Rooms() = 0;

	virtual void setNorth(Rooms*);
	virtual void setSouth(Rooms*);
	virtual void setEast(Rooms*);
	virtual void setWest(Rooms*);

	virtual Rooms* getNorth();
	virtual Rooms* getSouth();
	virtual Rooms* getEast();
	virtual Rooms* getWest();

	virtual std::string hasAction();
	virtual std::string actionDescription();
	virtual int action();
	virtual std::string getDescription();
	virtual std::string getName();
	virtual int itemReport();
	virtual std::string getItem();
	virtual std::string itemName();
	virtual void setItem(std::string);




};

#endif
