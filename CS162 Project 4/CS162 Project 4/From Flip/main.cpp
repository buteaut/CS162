/*********************************************************************************
** Program name: Project 3 (Main File)
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Main file for Project 3. 
**
*********************************************************************************/

#include "battle.hpp"

int main()
{
	srand(time(NULL));

	Battle* b1 = new Battle();
		
	b1->menu();
		
	delete b1;

	return 0;
}
