/*********************************************************************************
** Program name: Project 2 (Main File)
** Author: Thomas Buteau
** Date: 2-5-17
** Description: Main file for project 2. Generates a List object and calls the List
**				menu method.
*********************************************************************************/

#include "List.hpp"
#include "Item.hpp"
#include "dataValidation.hpp"

int main() {
	List *testList = new List();
	testList->menu();
	delete testList;

	//Item class tests
	/*
	Item *test = new Item("testItem", 5, "disks", 2.500);
	Item *test2 = new Item("testItem", 10, "disks", 7.25);

	test->increaseQuantity(10);
	
	if (*test == *test2)
	{
		std::cout << "The two Items are equal" << std::endl;
	}

	else
	{
		std::cout << "false." << std::endl;
	}
	
	std::cout << *test << *test2;

	*test + *test2;

	std::cout << *test;

	std::cout << (*test == "testitem") << std::endl;

	std::cout << "Should fail " << doubleValPos("2.35", 4, 0.1, 2.34) << std::endl;
	*/
	return 0;
}