/*********************************************************************************
** Program name: Project1 (Main File)
** Author: Thomas Buteau
** Date: 1-16-17
** Description: Main file for Project1. Starts the Menu function.
**
*********************************************************************************/

#include "menu.hpp"
#include "board.hpp"
//#include "ant.hpp"

int main() {

	menu();
	Board testBoard = Board(20, 20, "Windows");
	testBoard.draw(2);
	if (testBoard.onBoard(2, 2))
	{
		std::cout << "onBoard works" << std::endl;
	}
	testBoard.edit(1, 1, "XX");
	testBoard.draw(3);
	//std::system("cls");
	return 0;
}