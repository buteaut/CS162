/*********************************************************************************
** Program name: Project 5 (Entrance Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Entrance implementation file.
**
*********************************************************************************/

#include "entrance.hpp"

std::string entranceDes = "This is the crew quarters. Everything seems a bit disheveled."
+ std::string(" The lockers along the wall \nare partially open and clothings and misc items ")
+ std::string("are spilled out of some of them. \nTo the north is the hallway.");


Entrance::Entrance() : Rooms(NULL, NULL, NULL, NULL, entranceDes,
	"", "Crew Quarters")
{

}

Entrance::~Entrance()
{
	//left blank
}

