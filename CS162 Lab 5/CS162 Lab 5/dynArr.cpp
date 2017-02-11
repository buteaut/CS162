/*********************************************************************************
** Program name: Array Utilities (Implementation File)
** Author: Thomas Buteau
** Date: 2-12-17
** Description: dynArr implementation file. Series of utility functions for array
**				manipulations.
**
**				Originally written for Lab 5 in CS162 on 2-12-17
*********************************************************************************/

#include "dynArr.hpp"

/*********************************************************************************
**								arrayIncrease
** Description: Takes in an array of ints and a capacity. Doubles the size of the
**				array and returns the now larger array.
**
*********************************************************************************/
int* arrayIncrease(int* arr, int capacity)
{

	int* temp = new int[capacity * 2];

	//copies the ints to temp array
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = arr[i];
	}

	//clears arr array
	delete[] arr;
	//arr = NULL;

	//makes arr a copy of temp
	arr = temp;

	//removes temp array
	temp = 0;
	delete temp;
	return arr;
}