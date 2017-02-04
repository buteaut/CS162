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
	List  *testList = new List();
	testList->menu();
	delete testList;

	return 0;
}
