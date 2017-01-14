/*********************************************************************************
** Program name: Lab1 (readMatrix Object File)
** Author: Thomas Buteau
** Date: 1-9-17
** Description: Object file for readMatrix function. Takes in user inputs and 
**				fills in matrix argument with them. 
*********************************************************************************/

#include "readMatrix.hpp"

/*********************************************************************************
**								readMatrix
** Description: Function which takes in a pointer to a square array of ints and  
**				the size dimension of the array as arguments then asks the user
**				for an appropriate amount of inputs to populate the array.
**
*********************************************************************************/
void readMatrix(int* matrix, int size)
{
	std::cout << "Please enter " << size * size << " inputs." << std::endl;
	if (size == 3)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cin >> *(matrix + size*i + j);
			}
		}
	}

	else if (size == 2)
	{
		int z = 0;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				std::cin >> *(matrix + size*i + j+ z);
			}
			z++;
		}
	}
}
