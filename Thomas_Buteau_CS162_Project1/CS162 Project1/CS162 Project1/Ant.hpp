/*********************************************************************************
** Program name: Project1 (Ant Header File)
** Author: Thomas Buteau
** Date: 1-17-17
** Description: Ant header file for project1. The Ant class is responsible for 
**				keeping track of the direction the ant is facing, its current 
**				tile location and symbol, the location and symbol of the tile it is 
**				pointing at, the current number of steps, and the maximum number 
**				of steps. It also holds a Board object. It has methods for
**				turning, checking if a tile is in bounds, changing tile symbols,
**				checking if end conditions are met, and moving tiles.
*********************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include "board.hpp"
#include <string>
#include <thread>
#include <chrono>

class Ant
{
private:
	Board grid;
	int stepMax;
	int stepActual;
	int rowCurrent;
	int columnCurrent;
	int rowFuture;
	int columnFuture;
	std::string symbolCurrent;
	std::string symbolFuture;
	int direction; //0=Left, 1=Up, 2=Right, 3=Down

public:
	void turn(); //changes Ant direction

	bool inBounds(); //checks if future location is on grid

	void move(); //moves the Ant until out of steps

	void flipTile(); //changes current tile

	void step(); //moves the ant one tile

	Ant(int row, int column, int steps, int bRows, int bColumns, std::string OS);

	~Ant();
};

#endif
