/*********************************************************************************
** Program name: Project 5 (Main File)
** Author: Thomas Buteau
** Date: 3-21-17
** Description: Main file for Project 5.
**
*********************************************************************************/

#include "game.hpp"
#include "entrance.hpp"

int main()

{
	/*
	std::string clear;
	std::string width;

#if defined(_WIN32)
	{
		clear = "cls";
	}
#endif

#if defined(__linux__)
	{
		clear = "clear";
	}
#endif

	std::cout << "You shouldn't see this." << std::endl;
	
	std::system(clear.c_str());
	std::cout.width(80);
	//std::setw(80);
	std::cout << std::left << "But you should see this." <<  std::right << "this too." << std::endl;
	std::cout << std::setw(89) << std::setfill('=') << std::right << "" << std::endl;
	std::cout << std::left << "But you should see this." << std::right << "this too." << std::endl;
	std::cout << std::setw(89) << std::setfill('=') << std::right << "" << std::endl;
	std::cout << "Air supply" << std::setw(40) << std::right << "Current location" << std::setw(40) << std::right << "Power remaining" << std::endl;
	std::cout << "The damage to the hull has been repaired, and the reactor "
		<< "has been stabilized. A sign of relief turns into a groan as you "
		<< "look at your watch and see your shift starts in 7 minutes."
		<< std::endl << std::endl << std::endl;
	std::cout << "Game over." << std::endl;
	
	std::string location = "Crew Quarters";
	std::cout << "Air supply" << std::setw(40) << std::right << "Current location"
		<< std::setw(40) << std::right << "Power remaining" << std::endl;
	std::cout << 100 << "%" << std::setw(46) << std::right
		<< location << std::setw(46 - location.length()) << std::right << 100
		<< "%" << std::endl;
	return 0;
	*/
	Entrance* e = new Entrance();
	Game* g = new Game(e);

	g->play();

	return 0;
}