/*********************************************************************************
** Program name: Project 5 (Intersection Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Intersection implementation file.
**
*********************************************************************************/

#include "intersection.hpp"

std::string intersectionDes = "This is an intersection. There doesn't appear to "
+ std::string ("be anything of use here. \nTo the north is the engineering supplies.")
+ std::string ("\nTo the south is the hallway. ")
+ std::string ("\nTo the east is the communications room. ")
+ std::string ("\nTo the west is the engine room.");


Intersection::Intersection() : Rooms(NULL, NULL, NULL, NULL, intersectionDes,
	"", "Intersection") //constructor
{

}

Intersection::~Intersection() //destructor
{
	//left blank
}
