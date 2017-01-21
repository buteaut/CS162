/*********************************************************************************
** Program name: Project1 (Board Implementation File)
** Author: Thomas Buteau
** Date: 1-16-17
** Description: Board implementation file for project1. The Board class generates,
**				modifies, and displays the grid for the simulation. It also
**				checks if a coordinate is in the grid or not.
*********************************************************************************/

#include "board.hpp"

/*****************************************************************************
**						Board::draw
** Description: draw clears the screen then outputs the number of steps used 
**				as well as the grid to the screen.
**
*****************************************************************************/
void Board::draw(int steps)
{
	if (OS == "Windows")
	{
		std::system("cls");
	}

	else if (OS == "Linux")
	{
		std::system("clear");
	}

	std::cout << "Current step: " << steps << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
}

/*****************************************************************************
**						Board::draw
** Description: draw clears the screen, then outputs the number of steps used,
**				then the grid to the screen, finally the termination message.
**				program then waits for the user to hit enter to continue.
**
*****************************************************************************/
void Board::draw(int steps, std::string message)
{
	if (OS == "Windows")
	{
		std::system("cls");
	}

	else if (OS == "Linux")
	{
		std::system("clear");
	}

	std::cout << "Current step: " << steps << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << message << std::endl;
	std::cout << "Press enter to continue.";
	std::cin.get();	
}

/*****************************************************************************
**						Board::onBoard
** Description: onBoard compares the grid location from the arguments to the
**				grid actual. If the arguments are within the grid it returns
**				true. If not it returns false.
**
*****************************************************************************/
bool Board::onBoard(int yRow, int xColumn)
{
	bool onGrid = false;

	if (yRow < rows && yRow >= 0)
	{
		if (xColumn < columns && xColumn >= 0)
		{
			onGrid = true;
		}
	}

	return onGrid;
}

/*****************************************************************************
**						Board::edit
** Description: edit replaces the information stored in the grid array at the
**				argument location with the argument value.
**
*****************************************************************************/
void Board::edit(int row, int column, std::string value)
{
	grid[row][column] = value;
}

/*****************************************************************************
**						Board::getSymbol
** Description: returns the symbol at a location.
**
*****************************************************************************/
std::string Board::getSymbol(int row, int column)
{
	return grid[row][column];
}

/*****************************************************************************
**						Board::setRows
** Description: Sets the row.
**
*****************************************************************************/
void Board::setRows(int row)
{
	rows = row;
}

/*****************************************************************************
**						Board::setColumns
** Description: Sets the column.
**
*****************************************************************************/
void Board::setColumns(int column)
{
	columns = column;
}

/*****************************************************************************
**						Board::setOS
** Description: Sets the column.
**
*****************************************************************************/
void Board::setOS(std::string OpSys)
{
	OS = OpSys;
}

/*****************************************************************************
**						Board::initializeGrid
** Description: Sets the rows, columns, OS, and generates the grid.
**
*****************************************************************************/
void Board::initializeGrid(int row, int column, std::string OpSys)
{
	setRows(row);
	setColumns(column);
	setOS(OpSys);

	//generates 2D array of strings
	grid = new std::string*[rows];
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new std::string[columns];
	}

	//filling grid initially
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			grid[i][j] = "[]";
		}
	}

}

Board::Board()
{
	rows = 0;
	columns = 0;
	OS = "Windows";
}
/*
Board::Board(int initialRows, int initialColumns, std::string initialOS)
{
	rows = initialRows;
	columns = initialColumns;
	OS = initialOS;
	
	//dynamic generation of grid
	grid = new std::string*[rows];
	for (int i = 0; i < rows; i++)
	{
		grid[i] = new std::string[columns];
	}
	
	//filling grid initially
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			grid[i][j] = "[]";
		}
	}
}
*/
Board::~Board()
{
	for (int i = 0; i < rows; i++)
	{
		//for (int j = 0; j < columns; j++)
		//{
			delete [] grid[i];
			grid[i] = nullptr;
		//}
	}
	delete [] grid;
	grid = nullptr;
}