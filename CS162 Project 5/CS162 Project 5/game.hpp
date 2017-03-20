/*********************************************************************************
** Program name: Project 5 (Game Header File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Game header file. 
**
*********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "dataValidation.hpp"
#include "entrance.hpp"
#include "rooms.hpp"

class Game
{
protected:
	int air;
	int power;
	bool airpatch;
	bool elecpatch;
	bool gambling;
	bool exit;
	std::string clear;
	Rooms* currentLocation;
	std::vector<std::string> inventory;
	std::vector<std::string> exchange;
	std::string events;



public:
	Game();

	Game(Rooms* r);

	~Game();

	void tick();

	void clearScreen();

	void writeStatus();

	void writeDes();

	void writeEvents();

	void writeMenu();

	void endGame();

	void addItem();

	void exchangeItem(int);

	void travel(int);

	void search();

	void action();

	void menu();

	void play();

	void startup();
};

#endif