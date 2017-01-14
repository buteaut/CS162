/*********************************************************************************
** Program name: Lab1 (determinant Object File)
** Author: Thomas Buteau
** Date: 1-9-17
** Description: Object file for determinant function. Takes in 2D array and size.
**				Calculates and returns the determinant of the array.
*********************************************************************************/

#include "determinant.hpp"

/*********************************************************************************
**								determinant
** Description: Function which takes in a square array of ints and the size
**				dimension of the array as arguments then calculates and returns 
**				the determinant.
**
*********************************************************************************/
int determinant(const int m[][COLUMN], int size)
{
	if (size == 2)
	{
		return m[0][0]*m[1][1] - m[0][1]*m[1][0];
	}

	else if (size == 3)
	{
		//Hard coding is suboptimal, may come back later to redo
		return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
			   - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
				+ m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
	}

	else
	{
		return 0;
	}
}