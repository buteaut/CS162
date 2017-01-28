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

	//test block for Game class
	Game *gameDie = new Game();
	gameDie->menu();
	/*
	gameDie->setDie(20, false, 1);
	gameDie->setDie(20, true, 2);
	gameDie->play(20);
	
	//test block for Die class
	Die *testDie = new Die(100);
	int dieTotal = 0;
	for (int i = 0; i < 20; i++)
	{
		int temp = testDie->roll();
		std::cout << "Die roll " << i << " is: " << temp << std::endl;
		dieTotal += temp;
	}
	std::cout << "The total for the regular die is: " << dieTotal << std::endl;
	std::cout << std::endl;

	//test block for LoadedDie class
	Die *funDie = new LoadedDie(20);
	dieTotal = 0;
	for (int i = 0; i < 20; i++)
	{
		int temp = funDie->roll();
		std::cout << "LoadedDie roll " << i << " is: " << temp << std::endl;
		dieTotal += temp;
	}
	std::cout << "The total for the loaded die is: " << dieTotal << std::endl;
	std::cout << std::endl;
	
	delete testDie;
	delete funDie;
	delete gameDie;
	*/
	return 0;
}