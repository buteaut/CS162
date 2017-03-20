/*********************************************************************************
** Program name: Project 5 (Maintenance Implementation File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Maintenance implementation file.
**
*********************************************************************************/

#include "maintenance.hpp"

std::string maintenanceDes = "This is the maintenance room. Each wall is lined "
+ std::string("with shelves and workbenches. \nTo the east is the hallway.");


Maintenance::Maintenance() : Rooms(NULL, NULL, NULL, NULL, maintenanceDes,
	"", "Maintenance Room")
{

}

Maintenance::~Maintenance()
{
	//left blank
}
