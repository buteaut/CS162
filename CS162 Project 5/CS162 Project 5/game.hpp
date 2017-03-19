/*********************************************************************************
** Program name: Project 5 (Game Header File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Game header file. 
**
*********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<vector>
#include"rooms.hpp"
#include"entrance.hpp"
#include "dataValidation.hpp"

class Game
{
protected:
	int air;
	int power;
	bool airpatch;
	bool elecpatch;
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
};

#endif