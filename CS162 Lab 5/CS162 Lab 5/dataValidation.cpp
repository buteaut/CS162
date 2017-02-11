/*********************************************************************************
** Program name: Data Validation Utilities (Implementation File)
** Author: Thomas Buteau
** Date: 2-12-17
** Description: dataValidation implementation file. Series of functions to handle
**				data validation which either return true/false or the desired
**				data.
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
**								valInt
** Description: Reads in a string input. Verifies the string does not exceed 
**				maximum length then checks that each character in the string is a
**				digit. One exception, if the length is greater than 1 the first
**				character can be '-' to denote a negative number. Returns an int.
**
*********************************************************************************/
int valInt(int length)
{
	std::string strChoice;
	bool valid = false;

	do
	{
		std::cin >> strChoice;
		if (strChoice.length() <= length)
		{
			valid = true;
			for (int i = 0; i < strChoice.length(); i++)
			{
				if (!isdigit(strChoice.at(i)))
				{
					valid = false;
				}

				//allows for negative numbers
				if (i == 0 && strChoice.length() > 1)
				{
					if (strChoice.at(i) == '-')
					{
						valid = true;
					}
				}

			}
		}
		if (!valid)
		{
			std::cout << "User input invalid, please try again." << std::endl;
		}
	} while (!valid);
	
	return atoi(strChoice.c_str());
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
**								valIntPos
** Description: Reads in a string input then verifies the string does not exceed 
**				maximum length then checks that each character in the string is a 
**				digit. Returns an int.			
**
*********************************************************************************/
int valIntPos(int length)
{
	std::string strChoice;
	bool valid = false;


	do
	{
		std::cin >> strChoice;
		if (strChoice.length() <= length)
		{
			valid = true;
			for (int i = 0; i < strChoice.length(); i++)
			{
				if (!isdigit(strChoice.at(i)))
				{
					valid = false;
				}
			}
		}

		if (!valid)
		{
			std::cout << "User input invalid, please try again." << std::endl;
		}

	} while (!valid);

	return atoi(strChoice.c_str());
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
**								valIntPos (Ranged)
** Description: Reads in a string input then verifies the string does not exceed 
**				maximum length. Then checks that each character in the string is 
**				a digit. Finally checks if number is within range of min and max. 
**				Returns an int.
**
*********************************************************************************/
int valIntPos(int length, int min, int max)
{
	std::string strChoice;
	bool valid = false;
	int temp;
	do
	{
		std::cin >> strChoice;
		if (strChoice.length() <= length)
		{
			valid = true;
			for (int i = 0; i < strChoice.length(); i++)
			{
				if (!isdigit(strChoice.at(i)))
				{
					valid = false;
				}
			}
		}

		if (valid == true)
		{
			temp = atoi(strChoice.c_str());
			if (temp < min || temp > max)
			{
				valid = false;
			}

		}

		if (!valid)
		{
			std::cout << "User input invalid, please try again." << std::endl;
		}
	} while (!valid);

	return temp;

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
**								valDouble
** Description: Reads a string input and verifies the string does not exceed 
**				maximum length then checks that each character in the string is a 
**				digit. Two exceptions, if the length is greater
**				than 1 the first character can be '-' to denote a negative
**				number and up to one period are allowed. Returns a double.
**
*********************************************************************************/
double valDouble(int length)
{
	std::string strChoice;
	bool valid = false;
	int dotCount = 0;
	double temp;

	do
	{
		dotCount = 0;
		std::cin >> strChoice;
		if (strChoice.length() <= length)
		{
			valid = true;
			for (int i = 0; i < strChoice.length(); i++)
			{
				if (!isdigit(strChoice.at(i)))
				{
					valid = false;
				}

				//allows for negative numbers
				if (i == 0 && strChoice.length() > 1)
				{
					if (strChoice.at(i) == '-')
					{
						valid = true;
					}
				}

				//allows for period in decimal number
				if (strChoice.at(i) == '.' && strChoice.length() > 1)
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

		if (!valid)
		{
			std::cout << "User input invalid, please try again." << std::endl;
		}
	} while (!valid);

	return atof(strChoice.c_str());
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
**								valDoublePos
** Description: Reads a string input and verifies the string does not exceed
**				maximum length then checks that each character in the string is a
**				digit. One exception, up to one period is allowed. Returns a 
**				double.
**
*********************************************************************************/
double valDoublePos(int length)
{
	std::string strChoice;
	bool valid = false;
	int dotCount = 0;
	
	do
	{
		dotCount = 0;
		std::cin >> strChoice;
		if (strChoice.length() <= length)
		{
			valid = true;
			for (int i = 0; i < strChoice.length(); i++)
			{
				if (!isdigit(strChoice.at(i)))
				{
					valid = false;
				}

				//allows for period in decimal number
				if (strChoice.at(i) == '.' && strChoice.length() > 1)
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

		if (!valid)
		{
			std::cout << "User input invalid, please try again." << std::endl;
		}
	} while (!valid);

	return atof(strChoice.c_str());
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

/*********************************************************************************
**								valDoublePos (Ranged)
** Description: Reads a string input and verifies the string does not exceed
**				maximum length then checks that each character in the string is a
**				digit. One exception, up to one period is allowed. Finally checks 
**				if number is within range of min and max. Returns a double.
**
*********************************************************************************/
double valDoublePos(int length, double min, double max)
{
	std::string strChoice;
	bool valid = false;
	int dotCount = 0;
	double temp;

	do
	{
		dotCount = 0;
		std::cin >> strChoice;
		if (strChoice.length() <= length)
		{
			valid = true;
			for (int i = 0; i < strChoice.length(); i++)
			{
				if (!isdigit(strChoice.at(i)))
				{
					valid = false;
				}

				//allows for period in decimal number
				if (strChoice.at(i) == '.' && strChoice.length() > 1)
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
			temp = atof(strChoice.c_str());
			if (floor(temp - min) < 0 || ceil(temp - max) > 0)
			{

				valid = false;
			}

		}

		if (!valid)
		{
			std::cout << "User input invalid, please try again." << std::endl;
		}
	} while (!valid);

	return temp;
}