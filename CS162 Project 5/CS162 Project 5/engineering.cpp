/*********************************************************************************
** Program name: Project 5 (Engineering Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Engineering implementation file.
**
*********************************************************************************/

#include "engineering.hpp"

std::string engineeringDes = "This is the engineering supply room. Each wall is "
+ std::string("lined with shelves and workbenches. ")
+ std::string("\nTo the south is an intersection.");


Engineering::Engineering() : Rooms(NULL, NULL, NULL, NULL, engineeringDes,
	"", "Engineering Supply Room")
{

}

Engineering::~Engineering()
{
	//left blank
}
