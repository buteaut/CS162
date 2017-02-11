/*********************************************************************************
** Program name: Lab 4 (recString Implementation File)
** Author: Thomas Buteau
** Date: 2-12-17
** Description: recString implementation file. Recursive function that prints the 
**				string argument inverted.
**
*********************************************************************************/

#include "recString.hpp"


/*****************************************************************************
**						recString
** Description: Recursive function that prints the string argument inverted.
**
*****************************************************************************/
void recString(std::string recStr)
{
	int length = recStr.length();

	if (length == 0)
	{
		std::cout << std::endl;
	}

	else
	{
		std::cout << recStr.back();
		recStr.pop_back();
		recString(recStr);
	}
}