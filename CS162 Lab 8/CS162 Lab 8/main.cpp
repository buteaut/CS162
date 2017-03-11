/*********************************************************************************
** Program name: Lab 8
** Author: Thomas Buteau
** Date: 3-5-17
** Description: This program demostrates a search function, a sort function, and 
**				a binary search function.
**
*********************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

#include "dataValidation.hpp"

void menu();

int search();

int sort();

int binary();

int main()
{
	menu();

	return 0;
}

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

	std::cout << "CS162 Lab 8 'Searching and Sorting algorithmically'" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Main Menu: " << std::endl;
		std::cout << "1. Search function." << std::endl;
		std::cout << "2. Sort function." << std::endl;
		std::cout << "3. Binary Search function." << std::endl;
		std::cout << "4. Exit program." << std::endl;

		choice = valIntPos(1, 1, 4);

		if (choice == 1) //Linear search
		{
			search();
		}

		if (choice == 2) //Array summation
		{
			sort();
		}

		if (choice == 3) //Triangle number
		{
			binary();
		}

		if (choice == 4) //exit
		{
			exit = true;
		}
	} while (exit == false);
}

/*****************************************************************************
**						Search()
** Description: Search function utilizes the linear search as found on slide
**				6 of the Searching slides for week 8 of this course. This 
**				function asks the user for a file to search, searches that
**				file for the value '0' and reports its location if present or
**				a message stating it isn't there if not found.
**
*****************************************************************************/
int search()
{
	int list[10];
	int size = 10;
	std::string infile;
	int location = -1;
	bool isFound = false;

	std::cout << "Enter the filename to sort. (Files included with this "
		<< "program are original.txt early.txt middle.txt late.txt"
		<< std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, infile);

	//generate the array of ints from the input file
	std::ifstream input(infile);
	if (!input)
	{
		std::cout << "Error opening file." << std::endl;
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		input >> list[i];
	}
	input.close();

	//search the array via linear search as found on slide 6 of the Searching
	//slides for the value 0
	for (int i = 0; i < size; i++)
	{
		if (list[i] == 0 && isFound == false)
		{
			location = i;
		}
	}

	if (location != -1)
	{
		std::cout << "The first instance of 0 was found at index " << location
			<< "." << std::endl;
		return 0;
	}

	else
	{
		std::cout << "The value 0 was not found in the file searched." 
			<< std::endl;

		return 0;
	}

	return 0;
}

/*****************************************************************************
**						Sort()
** Description: Sort function utilizes the bubble sort as found on slide 5 of
**				the Sort-Bubble slides for week 8 of this course. This 
**				function asks the user for a file to sort and the name of the
**				file it should output to, then sorts the numbers from the 
**				input file and returns them to the output file.
**
*****************************************************************************/
int sort()
{
	int list[10];
	int size = 10;
	int temp;
	std::string infile;
	std::ofstream output;

	std::cout << "Enter the filename to sort. (Files included with this "
		<< "program are original.txt early.txt middle.txt late.txt"
		<< std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, infile);

	//generate the array of ints from the input file
	std::ifstream input(infile);
	if (!input)
	{
		std::cout << "Error opening file." << std::endl;
		return 0;
	}
	for (int i = 0; i < size;i++)
	{
		input >> list[i];
	}
	input.close();

	//sort the array via bubble sort as shown on slide 5 of Sort-Bubble slides
	for (int i = (size - 1); i > 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (list[j - 1] > list[j])
			{
				int temp = list[j - 1];
				list[j - 1] = list[j];
				list[j] = temp;
			}
		}
	}

	//generate the output file
	output.open("sorted.txt");
	for (int i = 0; i < size; i++)
	{
		output << list[i] << " ";
	}
	output.close();

	return 0;
}

/*****************************************************************************
**						Binary()
** Description: Search function utilizes the binary search as found on slide
**				11 of the Searching slides for week 8 of this course. This 
**				function asks the user for a file to search, searches that
**				file for the value '0' and reports its location if present or
**				a message stating it isn't there if not found.
**
*****************************************************************************/
int binary()
{
	int list[10];
	int size = 10;
	int low = 0;
	int high = size;
	std::string infile;
	int location = -1;
	bool isFound = false;

	std::cout << "Enter the filename to sort. (Files included with this "
		<< "program are original.txt early.txt middle.txt late.txt"
		<< std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, infile);

	//generate the array of ints from the input file
	std::ifstream input(infile);
	if (!input)
	{
		std::cout << "Error opening file." << std::endl;
		return 0;
	}
	for (int i = 0; i < size; i++)
	{
		input >> list[i];
	}
	input.close();

	//search the array via binary search as found on slide 11 of the Searching
	//slides for the value 0
	while (low <= high)
	{
		int mid = (low + high) / 2;
		int dif = list[mid];
		if (dif == 0)
		{
			location = mid;
			std::cout << "The first instance of 0 was found at index " 
				<< location << "." << std::endl;
			return 0;
		}

		else if (dif < 0)
		{
			low = mid + 1;
		}

		else
		{
			high = mid - 1;
		}
	}

	
	std::cout << "The value 0 was not found in the file searched."
		<< std::endl;

	return 0;
	
}