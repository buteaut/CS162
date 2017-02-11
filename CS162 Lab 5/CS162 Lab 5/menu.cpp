/*********************************************************************************
** Program name: Lab 4 (Menu Implementation File)
** Author: Thomas Buteau
** Date: 2-10-17
** Description: Menu implementation file. General menu function to be adapted and 
**				reused in future projects.
**
*********************************************************************************/

#include "menu.hpp"


/*****************************************************************************
**						Menu()
** Description: Menu method provides user options and will call other methods
**				based on user input.
**
*****************************************************************************/
void menu()
{
	std::string strChoice;
	int choice;
	bool exit = false;

	std::cout << "CS162 Lab 5 'Recursive Recursions'" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Main Menu: " << std::endl;
		std::cout << "1. String reversal." << std::endl;
		std::cout << "2. Array summation." << std::endl;
		std::cout << "3. Triangle number." << std::endl;
		std::cout << "4. Exit program." << std::endl;

		choice = valIntPos(1, 1, 4);
		
		if (choice == 1) //String reversal
		{
			std::string recstr;
			std::cout << "Please enter a string to be reversed." << std::endl;
			std::cin.clear();
			std::cin.ignore();
			std::getline(std::cin, recstr);

			recString(recstr);
		}

		if (choice == 2) //Array summation
		{
			int length = 0;
			int capacity = 10;
			int *arr = new int[capacity];
			std::string strArr;

			do //generates the array from user data
			{
				std::cout << "Enter a number into the array or a non-number "
					<< "to finish." << std::endl;
				std::cin >> strArr;
				
				//doubles array if capacity is reached
				if ((length == capacity) && (intVal(strArr, 5)))
				{
					arr = arrayIncrease(arr, capacity);
					capacity *= 2;
				}

				//adds item
				if ((length < capacity) && (intVal(strArr, 5)))
				{
					length++;
					arr[length - 1] = std::stoi(strArr);
				}
			} while (intVal(strArr, 5));

			//recArrSum(arr, length);
			std::cout << recArrSum(arr, length) << std::endl;
			delete arr;
		}

		if (choice == 3) //Triangle number
		{
			int n;
			std::cout << "Please enter the number of rows in your triangle." 
				<< std::endl;
			n = valIntPos(2);
			std::cout << recTriNum(n, 0) << std::endl;
		}

		if (choice == 4) //exit
		{
			exit = true;
		}
	} while (exit == false);
}