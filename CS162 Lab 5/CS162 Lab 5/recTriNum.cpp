/*********************************************************************************
** Program name: Lab 4 (recTriNum Implementation File)
** Author: Thomas Buteau
** Date: 2-12-17
** Description: recTriNum implementation file. Recursive function that returns the
**				triangle number of the "n" argument entered.
**
*********************************************************************************/

#include "recTriNum.hpp"


/*****************************************************************************
**						recTriNum
** Description: Recursive function that returns the triangle number of the "n" 
**				argument entered.
**
*****************************************************************************/
int recTriNum(int n, int sum)
{
	if (n == 0)
	{
		return sum;
	}

	else
	{
		sum += n;
		return n, recTriNum(n - 1, sum);
	}
}