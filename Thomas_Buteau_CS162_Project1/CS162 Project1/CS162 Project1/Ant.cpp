/*********************************************************************************
** Program name: Project1 (Ant Implementation File)
** Author: Thomas Buteau
** Date: 1-17-17
** Description: Ant implementation file for project1. The Ant class is responsible 
**				for keeping track of the direction the ant is facing, its current
**				tile location and symbol, the location and symbol of the tile it 
**				is pointing at, the current number of steps, and the maximum number
**				of steps. It also holds a Board object. It has methods for
**				turning, checking if a tile is in bounds, changing tile symbols,
**				and moving tiles.
*********************************************************************************/

#include "Ant.hpp"

/*****************************************************************************
**						Ant::turn
** Description: turn changes the direction of the ant based on the symbol of
**				tile it is standing on. If on a "[]" tile turn clockwise. If
**				on a "<>" tile turn counter-clockwise. Then updates future
**				row, column, and symbol.
**
*****************************************************************************/
void Ant::turn()
{
	do
	{
		if (symbolCurrent == "[]") //on a "white" tile turn clockwise
		{
			if (direction == 3)
			{
				direction = 0;
			}

			else
			{
				direction++;
			}
		}

		else if (symbolCurrent == "<>") //on a "black" tile turn
		{								//counterclockwise
			if (direction == 0)
			{
				direction = 3;
			}

			else
			{
				direction--;
			}
		}

		if (direction == 0) //facing left
		{
			rowFuture = rowCurrent;
			columnFuture = columnCurrent - 1;
		}

		else if (direction == 1) //facing up
		{
			rowFuture = rowCurrent - 1;
			columnFuture = columnCurrent;
		}

		else if (direction == 2) //facing right
		{
			rowFuture = rowCurrent;
			columnFuture = columnCurrent + 1;
		}

		else if (direction == 3) //facing down
		{
			rowFuture = rowCurrent + 1;
			columnFuture = columnCurrent;
		}
	}
	while (!inBounds());

	symbolFuture = grid.getSymbol(rowFuture, columnFuture);
	
}

/*****************************************************************************
**						Ant::inBounds
** Description: Checks if the future row and column are on the grid.
**
*****************************************************************************/
bool Ant::inBounds()
{
	return grid.onBoard(rowFuture, columnFuture);
}

/*****************************************************************************
**						Ant::flipTile
** Description: Changes the current tile from "[]" to "<>" or vice versa.
**
*****************************************************************************/
void Ant::flipTile()
{
	if (symbolCurrent == "[]") //goes from "white" tile to "black"
	{
		grid.edit(rowCurrent, columnCurrent, "<>");
	}

	else if (symbolCurrent == "<>") //goes from "black" tile to "white"
	{
		grid.edit(rowCurrent, columnCurrent, "[]");
	}
}

/*****************************************************************************
**						Ant::step
** Description: Moves the ant one step and updates the symbolCurrent variable 
**				as well as the grid array.
**
*****************************************************************************/
void Ant::step()
{
	rowCurrent = rowFuture;
	columnCurrent = columnFuture;
	symbolCurrent = grid.getSymbol(rowCurrent, columnCurrent);
	grid.edit(rowCurrent, columnCurrent, "##");
}

/*****************************************************************************
**						Ant::move
** Description: Turns the ant, flips tiles, and moves the ant until the 
**				maximum number of steps is reached.
**
*****************************************************************************/
void Ant::move()
{
	while (stepActual < stepMax)
	{
		turn();
		flipTile();
		step();
		grid.draw(stepActual);
		stepActual++;
		//sleep function taken from http://www.cplusplus.com/reference/thread/this_thread/sleep_for/?kw=sleep_for
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	grid.draw(stepActual, "Maximum number of steps reached.");
}

Ant::Ant(int row, int column, int steps, int bRows, int bColumns, std::string OS)
{
	stepMax = steps;
	stepActual = 0;
	rowCurrent = row;
	columnCurrent = column;
	grid.initializeGrid(bRows, bColumns, OS);
	direction = 0;
	symbolCurrent = grid.getSymbol(rowCurrent, columnCurrent);
	grid.edit(rowCurrent, columnCurrent, "##");
	grid.draw(stepActual);
	turn();

}

Ant::~Ant()
{

}