/*********************************************************************************
** Program name: Lab 3 (integerValidation Implementation File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: IntegerValidation header file. Validates the input as an integer 
**				and returns true or false.
**
**				Originally written for Project 1 in CS162 on 1-21-17
*********************************************************************************/

#include "integerValidation.hpp"

/*********************************************************************************
**								intVal
** Description: Takes in a string input and a maximum length. Verifies the string 
**				does not exceed maximum length then checks that each character in 
**				the string is a digit. Returns true if all tests pass, false 
**				otherwise. 
**
*********************************************************************************/
bool intVal(std::string input, int length)
{
	bool valid = false;

	if (input.length() <= length)
	{
		valid = true;
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input.at(i)))
			{
				valid = false;
			}
			
			//allows for negative numbers
			if (i == 0 && input.length() > 1)
			{
				if (input.at(i) == '-')
				{
					valid = true;
				}
			}
			
		}
	}

	return valid;
}