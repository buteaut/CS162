/*********************************************************************************
** Program name: Lab 4 (recArrSum Implementation File)
** Author: Thomas Buteau
** Date: 2-12-17
** Description: recArrSum implementation file. Recursive function that returns the
**				sum of the array entered.
**
*********************************************************************************/

#include "recArrSum.hpp"


/*****************************************************************************
**						recArrSum
** Description: Recursive function that returns the sum of the array entered.
**
*****************************************************************************/
int recArrSum(int sums[], int length)
{
	int count = 0;

	if (length == 0)
	{
		return 0;
	}

	else
	{
		return sums[length - 1] + recArrSum(sums, length - 1);
	}
	
}