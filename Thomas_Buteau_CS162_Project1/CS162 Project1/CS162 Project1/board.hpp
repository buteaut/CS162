/*********************************************************************************
** Program name: Project1 (Board Header File)
** Author: Thomas Buteau
** Date: 1-16-17
** Description: Board header file for project1. The Board class generates,
**				modifies, and displays the grid for the simulation. It also
**				checks if a coordinate is in the grid or not.
*********************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Board
{
private:
	int rows;
	int columns;
	std::string** grid;
	std::string OS;

public:
	void draw(int steps);	//outputs the grid to the screen
	void draw(int steps, std::string message); //outputs the grid to the screen 
											  //with termination message
	
	bool onBoard(int row, int column); //checks if location is on the grid
	
	void edit(int row, int column, std::string value); //edits a location in 
													   //the grid
	std::string getSymbol(int row, int column); //returns the symbol at a location

	void setRows(int row);

	void setColumns(int column);

	void setOS(std::string OpSys);

	void initializeGrid(int row, int column, std::string OpSys); //generates grid

	Board();

	//Board(int rows, int columns, std::string OS); 

	~Board();
};


#endif