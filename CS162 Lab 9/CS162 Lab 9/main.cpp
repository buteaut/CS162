/*********************************************************************************
** Program name: Lab 9
** Author: Thomas Buteau
** Date: 3-12-17
** Description: This program demostrates STL Containers by using a queue to 
**				simulate a buffer and using a stack to create a palindrome.
**
*********************************************************************************/

#include <iostream>
#include <string>
#include <queue>
#include <random>
#include <time.h>
#include "dataValidation.hpp"
#include "stack.hpp"
#include "queue.hpp"

void palindrome();

void aveQueue();

void menu();

int main() 
{
	srand(time(NULL));

	menu();

	return 0;
}

/*****************************************************************************
**						Palindrome()
** Description: Takes in a string from user and utilizes a stack to print out
**				a palindrome of said string.
**
*****************************************************************************/
void palindrome()
{
	std::string text;
	std::cout << "Enter text to be made into a palindrome." << std::endl;
	std::cin.clear();
	std::cin.ignore();
	std::getline(std::cin, text);

	//adds the string to the stack one char at a time
	for (int i = 0; i < text.length(); i++)
	{
		palin.push(text.at(i));
	}
	//adds the chars in the stack to the string
	while (!palin.empty())
	{
		text.push_back(palin.top());
		palin.pop();
	}
	std::cout << "The palindrome is " << text << std::endl;

}

/*****************************************************************************
**						aveQueue()
** Description: Asks the user for a percent chance to add and remove items as
**				well as how many rounds to run. It displays a running average
**				for each round of how many items are in the queue.
**
*****************************************************************************/
void aveQueue()
{
	int add;
	int remove;
	double average;
	int rounds;

	std::cout << "Enter the percent chance (0 to 100) to add an item."
		<< std::endl;
	add = valIntPos(3, 0, 100);

	std::cout << "Enter the percent chance (0 to 100) to remove an item."
		<< std::endl;
	remove = valIntPos(3, 0, 100);

	std::cout << "Enter the number of rounds (1 to 100)."
		<< std::endl;
	rounds = valIntPos(3, 1, 100);

	for (int i = 0; i < rounds; i++)
	{
		//percentage based chance to add an item
		if (rand() % 101 < add)
		{
			buffer.push(1);
		}

		//percentage based chance to remove an item
		if (!buffer.empty() && rand() % 101 < remove)
		{
			buffer.pop();
		}

		//calculates average
		if (i > 0)
		{
			average = (average*(i - 1) + buffer.size()) / i;
		}

		//average on original round
		else
		{
			average = buffer.size();
		}

		std::cout << "For round " << i + 1 << " the current buffer size is " 
			<< buffer.size() << " and the average is " << average << "." 
			<< std::endl;
	}

	//cleanup operations
	add = 0;
	remove = 0;
	average = 0;
	rounds = 0;
	while (!buffer.empty())
	{
		buffer.pop();
	}
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
		std::cout << "1. Create a palindrome." << std::endl;
		std::cout << "2. Queue average." << std::endl;
		std::cout << "3. Exit program." << std::endl;

		choice = valIntPos(1, 1, 4);

		if (choice == 1) //Linear search
		{
			palindrome();
		}

		if (choice == 2) //Array summation
		{
			aveQueue();
		}

		if (choice == 3) //exit
		{
			exit = true;
		}
	} while (exit == false);
}