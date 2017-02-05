/*********************************************************************************
** Program name: Lab 4 (Main Implementation File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Main implementation file. 
**
*********************************************************************************/

#include "university.hpp"


int main()
{
	srand(time(NULL));

	University* uni = new University();
	Student* s1 = new Student("Linus Torvold", 47, 3.9);
	Instructor* i1 = new Instructor("John Draper", 73, 4.5);
	Building* b1 = new Building("Adams Hall", 9875, "606 SW 15TH ST");
	Building* b2 = new Building("Finley Hall", 74473, "2100 SW MAY MAY");
	
	uni->pushPerson(s1);
	uni->pushPerson(i1);
	uni->pushBuilding(b1);
	uni->pushBuilding(b2);
	uni->menu();
	delete uni;
	delete s1;
	delete i1;
	delete b1;
	delete b2;	
	
	return 0;
}
