/*********************************************************************************
** Program name: Project1 (Menu Implementation File)
** Author: Thomas Buteau
** Date: 1-16-17
** Description: Menu header file for project1. Menu function displays options to
**				the user and takes in user inputs with input validation.
*********************************************************************************/

#include "menu.hpp"

/*********************************************************************************
**								menu
** Description: Function which displays options to the user and takes in user
**				inputs with input validation.
**
*********************************************************************************/
void menu()
{
	int rowAnt = -1;
	int columnAnt = -1;
	int steps = 0; 
	int rowsGrid = 0;
	int columnsGrid = 0;
	std::string OS = "";
	int choice;
	srand(time(NULL));
	bool exit = false;

	std::cout << "CS162 Project 1 'Langston's Ant' simulation" << std::endl;
	std::cout << std::endl;
	do
	{
		std::cout << "Main Menu: " << std::endl;
		std::cout << "1. Set grid size." << std::endl;
		std::cout << "2. Set ant start position." << std::endl;
		std::cout << "3. Select maximum number of steps." << std::endl;
		std::cout << "4. Select operating system environment." << std::endl;
		std::cout << "5. Start simulation." << std::endl;
		std::cout << "6. Exit program." << std::endl;

		std::cin >> choice;

		if (choice > 0 && choice < 7)
		{
			if (choice == 1) //set up grid parameters
			{
				std::cout << "Enter the number of rows or 0 for a random number."
					<< std::endl;
				std::cout << "For readability the maximum number of rows is 25."
					<< std::endl;
				std::cin >> rowsGrid;
				if (rowsGrid == 0)
				{
					rowsGrid = rand() % 25 + 1;
				}

				std::cout << "Enter the number of columns or 0 for a random number."
					<< std::endl;
				std::cout << "For readability the maximum number of columns is 25."
					<< std::endl;
				std::cin >> columnsGrid;
				if (columnsGrid == 0)
				{
					columnsGrid = rand() % 25 + 1;
				}
			}

			if (choice == 2) //set ant start position
			{
				std::cout << "Enter the starting row for the ant or -1 for a random number."
					<< std::endl;
				std::cin >> rowAnt;
				if (rowAnt == -1)
				{
					rowAnt = rand() % (rowsGrid + 1);
				}

				std::cout << "Enter the starting column for the ant or -1 for a random number."
					<< std::endl;
				std::cin >> columnAnt;
				if (columnAnt == -1)
				{
					columnAnt = rand() % (columnsGrid + 1);
				}
			}

			if (choice == 3) //set maximum number of steps
			{
				std::cout << "Enter the maximum number of steps for the ant." << std::endl;
				std::cin >> steps;
			}

			if (choice == 4) //set the operating system
			{
				int OpSys;
				std::cout << "Select the operating system in use:" << std::endl;
				std::cout << "1. Windows" << std::endl;
				std::cout << "2. Linux" << std::endl;
				std::cin >> OpSys;

				if (OpSys == 1)
				{
					OS = "Windows";
				}

				else if (OpSys == 2)
				{
					OS = "Linux";
				}
			}

			if (choice == 5) //start the simulation
				if (rowAnt != -1 && columnAnt != -1 && steps != 0 && rowsGrid != 0
					&& columnsGrid != 0 && OS != "")
				{
					Ant a(rowAnt, columnAnt, steps, rowsGrid, columnsGrid, OS);
					a.move();
				}

			if (choice == 6) //end program
			{
				exit = true;
			}
		}

		else
		{
			std::cout << "User input invalid, please try again." << std::endl;
		}
	} while (exit == false);

}