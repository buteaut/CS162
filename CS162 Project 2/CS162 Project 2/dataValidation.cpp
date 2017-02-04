/*********************************************************************************
** Program name: Lab 3 (integerValidation Implementation File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: IntegerValidation header file. Validates the input as an integer 
**				and returns true or false.
**
**				Originally written for Project 1 in CS162 on 1-21-17
*********************************************************************************/

#include "dataValidation.hpp"

/*********************************************************************************
**								intVal
** Description: Takes in a string input and a maximum length. Verifies the string 
**				does not exceed maximum length then checks that each character in 
**				the string is a digit. One exception, if the length is greater
**				than 1 the first character can be '-' to denote a negative 
**				number. Returns true if all tests pass, false otherwise. 
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

/*********************************************************************************
**								intValPos
** Description: Takes in a string input and a maximum length. Verifies the string
**				does not exceed maximum length then checks that each character in
**				the string is a digit. Returns true if all tests pass, false
**				otherwise.
**
*********************************************************************************/
bool intValPos(std::string input, int length)
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
		}
	}

	return valid;
}

/*********************************************************************************
**								intValPos (Ranged)
** Description: Takes in a string input and a maximum length. Verifies the string
**				does not exceed maximum length then checks that each character in
**				the string is a digit. Finally checks if number is within range 
**				of min and max. Returns true if all tests pass, false otherwise.
**
*********************************************************************************/
bool intValPos(std::string input, int length, int min, int max)
{
	bool valid = false;
	int temp;

	if (input.length() <= length)
	{
		valid = true;
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input.at(i)))
			{
				valid = false;
			}
		}
	}

	if (valid == true)
	{
		temp = atoi(input.c_str());
		if (temp < min || temp > max)
		{
			valid = false;
		}

	}

	return valid;
}

/*********************************************************************************
**								doubleVal
** Description: Takes in a string input and a maximum length. Verifies the string
**				does not exceed maximum length then checks that each character in
**				the string is a digit. Two exceptions, if the length is greater
**				than 1 the first character can be '-' to denote a negative
**				number and up to one period are allowed. Returns true if all 
**				tests pass, false otherwise.
**
*********************************************************************************/
bool doubleVal(std::string input, int length)
{
	bool valid = false;
	int dotCount = 0;

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

			//allows for period in decimal number
			if (input.at(i) == '.' && input.length() > 1)
			{
				valid = true;
				dotCount++;
			}

		}
	}

	//ensures only one period in string input
	if (dotCount > 1)
	{
		valid = false;
	}

	return valid;
}

/*********************************************************************************
**								doubleValPos
** Description: Takes in a string input and a maximum length. Verifies the string
**				does not exceed maximum length then checks that each character in
**				the string is a digit. One exception, up to one period is 
**				allowed. Returns true if all tests pass, false otherwise.
**
*********************************************************************************/
bool doubleValPos(std::string input, int length)
{
	bool valid = false;
	int dotCount = 0;

	if (input.length() <= length)
	{
		valid = true;
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input.at(i)))
			{
				valid = false;
			}

			//allows for period in decimal number
			if (input.at(i) == '.' && input.length() > 1)
			{
				valid = true;
				dotCount++;
			}
		}
	}

	//ensures only one period in string input
	if (dotCount > 1)
	{
		valid = false;
	}

	return valid;
}

/*********************************************************************************
**								doubleValPos (Ranged)
** Description: Takes in a string input and a maximum length. Verifies the string
**				does not exceed maximum length then checks that each character in
**				the string is a digit. One exception, up to one period is 
**				allowed. Finally checks if number is within range of min and max. 
**				Returns true if all tests pass, false otherwise.
**
*********************************************************************************/
bool doubleValPos(std::string input, int length, double min, double max)
{
	bool valid = false;
	int dotCount = 0;
	double temp;

	if (input.length() <= length)
	{
		valid = true;
		for (int i = 0; i < input.length(); i++)
		{
			if (!isdigit(input.at(i)))
			{
				valid = false;
			}

			//allows for period in decimal number
			if (input.at(i) == '.' && input.length() > 1)
			{
				valid = true;
				dotCount++;
			}
		}

		
	}

	//ensures only one period in string input
	if (dotCount > 1)
	{
		valid = false;
	}

	//ensures number is within min/max range
	if (valid == true)
	{
		temp = atof(input.c_str());
		if (floor(temp - min) < 0 || ceil(temp - max) > 0)
		{
			
			valid = false;
		}

	}
	
	return valid;
}
