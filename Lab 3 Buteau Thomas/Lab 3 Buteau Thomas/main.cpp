/*********************************************************************************
** Program name: Lab3 (Main File)
** Author: Thomas Buteau
** Date: 1-29-17
** Description: Main file for lab 3. Generates a Game object and calls the Game
**				menu method to start the game.
*********************************************************************************/

#include <iostream>
#include <random>
#include <time.h>
#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

int main() {
	std::srand(time(NULL));

	Game *gameDie = new Game();
	gameDie->menu();
	delete gameDie;
	
	return 0;
}