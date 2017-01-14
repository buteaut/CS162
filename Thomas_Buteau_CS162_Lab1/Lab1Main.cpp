/*********************************************************************************
** Program name: Lab1 (Main File)  
** Author: Thomas Buteau
** Date: 1-9-17
** Description: Main file for lab1. Takes in user input and calls functions 
**				readMatrix and determinant to generate a matrix then calculate 
**				and return its determinant.
*********************************************************************************/

#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"


int main() {
	int size;
	bool test = false;
	//If reworked to use a dynamically allocated array redo the following 2 lines.
	int matrix[3][3];
	const int COLUMN = 3;
	
	while (test == false)
	{
		std::cout << "Please enter a size for the matrix." << std::endl;
		std::cout << "2 for a 2X2 matrix or 3 for a 3X3 matrix." << std::endl;
		std::cin >> size;

		//data validation check
		if (size == 2 || size == 3)
		{
			readMatrix(*matrix, size);
			test = true;
		}

	}
	std::cout << "The matrix entered is:" << std::endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "The determinant is:" << std::endl;
	std::cout << determinant(matrix, size) << std::endl;

	return 0;
}