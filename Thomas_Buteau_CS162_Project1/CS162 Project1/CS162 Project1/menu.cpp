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
	std::string strChoice;
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
		
		std::cin >> strChoice;
		while (!intVal(strChoice, 1))
		{
			std::cout << "User input invalid, please try again." << std::endl;
			strChoice = "";
			std::cin >> strChoice;
		}
		choice = atoi(strChoice.c_str());
		strChoice = "";
		
		if (choice > 0 && choice < 7)
		{
			if (choice == 1) //set up grid parameters
			{
				//get the number of rows for the grid
				std::cout << "Enter the number of rows or 0 for a random number."
					<< std::endl;
				std::cout << "For readability the maximum number of rows is 25."
					<< std::endl;
				std::cin >> strChoice;

				while (!intVal(strChoice, 2)) //verify integer is input
				{
					std::cout << "User input invalid, please try again." << std::endl;
					strChoice = "";
					std::cin >> strChoice;
				}
				rowsGrid = atoi(strChoice.c_str());
				strChoice = "";

				while ((rowsGrid < 0) || (rowsGrid > 25)) //verify input within range
				{
					std::cout << "Input outside of range. Please enter a number "
						<< "between 0 and 25." << std::endl;
					std::cin >> strChoice;
					while (!intVal(strChoice, 2))
					{
						std::cout << "User input invalid, please try again." << std::endl;
						strChoice = "";
						std::cin >> strChoice;
					}
					rowsGrid = atoi(strChoice.c_str());
					strChoice = "";	
				}
				if (rowsGrid == 0)
				{
					rowsGrid = rand() % 25 + 1;
				}

				//get the number of columns for the grid
				std::cout << "Enter the number of columns or 0 for a random number."
					<< std::endl;
				std::cout << "For readability the maximum number of columns is 25."
					<< std::endl;
				std::cin >> strChoice;

				while (!intVal(strChoice, 2)) //verify integer is input
				{
					std::cout << "User input invalid, please try again." << std::endl;
					strChoice = "";
					std::cin >> strChoice;
				}
				columnsGrid = atoi(strChoice.c_str());
				strChoice = "";

				while ((columnsGrid < 0) || (columnsGrid > 25)) //verify input within range
				{
					std::cout << "Input outside of range. Please enter a number "
						<< "between 0 and 25." << std::endl;
					std::cin >> strChoice;
					while (!intVal(strChoice, 2))
					{
						std::cout << "User input invalid, please try again." << std::endl;
						strChoice = "";
						std::cin >> strChoice;
					}
					columnsGrid = atoi(strChoice.c_str());
					strChoice = "";
				}
				
				if (columnsGrid == 0)
				{
					columnsGrid = rand() % 25 + 1;
				}
			}

			if (choice == 2) //set ant start position
			{
				//get the ant's row position
				std::cout << "Enter the starting row for the ant or -1 for a random number."
					<< std::endl;
				std::cin >> strChoice;

				while (!intVal(strChoice, 2)) //verify integer is input
				{
					std::cout << "User input invalid, please try again." << std::endl;
					strChoice = "";
					std::cin >> strChoice;
				}
				rowAnt = atoi(strChoice.c_str());
				strChoice = "";

				while ((rowAnt < -1) || (rowAnt >= rowsGrid)) //verify input within range
				{
					std::cout << "Input outside of range. Please enter a number "
						<< "between -1 and " << rowsGrid - 1 << "." << std::endl;
					std::cin >> strChoice;
					while (!intVal(strChoice, 2))
					{
						std::cout << "User input invalid, please try again." << std::endl;
						strChoice = "";
						std::cin >> strChoice;
					}
					rowAnt = atoi(strChoice.c_str());
					strChoice = "";
				}

				if (rowAnt == -1)
				{
					rowAnt = rand() % rowsGrid;
				}

				//get the ant's column position
				std::cout << "Enter the starting column for the ant or -1 for a random number."
					<< std::endl;
				std::cin >> strChoice;
				while (!intVal(strChoice, 2)) //verify integer is input
				{
					std::cout << "User input invalid, please try again." << std::endl;
					strChoice = "";
					std::cin >> strChoice;
				}
				columnAnt = atoi(strChoice.c_str());
				strChoice = "";

				while ((columnAnt < -1) || (columnAnt >= columnsGrid)) //verify input within range
				{
					std::cout << "Input outside of range. Please enter a number "
						<< "between -1 and " << columnsGrid - 1 << "." << std::endl;
					std::cin >> strChoice;
					while (!intVal(strChoice, 2))
					{
						std::cout << "User input invalid, please try again." << std::endl;
						strChoice = "";
						std::cin >> strChoice;
					}
					columnAnt = atoi(strChoice.c_str());
					strChoice = "";
				}
				
				if (columnAnt == -1)
				{
					columnAnt = rand() % columnsGrid;
				}
			}

			if (choice == 3) //set maximum number of steps
			{
				std::cout << "Enter the maximum number of steps for the ant." << std::endl;
				std::cin >> strChoice;
				while (!intVal(strChoice, 5)) //verify integer is input
				{
					std::cout << "User input invalid, please try again." << std::endl;
					strChoice = "";
					std::cin >> strChoice;
				}
				steps = atoi(strChoice.c_str());
				strChoice = "";

				while (steps < 1) //input validation
				{
					std::cout << "Input outside of range. Please enter a number "
						<< "greater than 0." << std::endl;
					std::cin >> strChoice;
					while (!intVal(strChoice, 5)) //verify integer is input
					{
						std::cout << "User input invalid, please try again." << std::endl;
						strChoice = "";
						std::cin >> strChoice;
					}
					steps = atoi(strChoice.c_str());
					strChoice = "";
				}
			}

			if (choice == 4) //set the operating system
			{
				int OpSys;
				std::cout << "Select the operating system in use:" << std::endl;
				std::cout << "1. Windows" << std::endl;
				std::cout << "2. Linux" << std::endl;
				std::cin >> strChoice;
				while (!intVal(strChoice, 1)) //verify integer is input
				{
					std::cout << "User input invalid, please try again." << std::endl;
					strChoice = "";
					std::cin >> strChoice;
				}
				OpSys = atoi(strChoice.c_str());
				strChoice = "";


				while ((OpSys < 1) || (OpSys > 2)) //input validation
				{
					std::cout << "Input outside of range. Please enter 1 for Windows "
						<< "or 2 for Linux." << std::endl;
					std::cin >> strChoice;
					while (!intVal(strChoice, 1)) //verify integer is input
					{
						std::cout << "User input invalid, please try again." << std::endl;
						strChoice = "";
						std::cin >> strChoice;
					}
					OpSys = atoi(strChoice.c_str());
					strChoice = "";
				}

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
			{
				if (rowAnt != -1 && columnAnt != -1 && steps != 0 && rowsGrid != 0
					&& columnsGrid != 0 && OS != "")
				{
					Ant a(rowAnt, columnAnt, steps, rowsGrid, columnsGrid, OS);
					a.move();
					
					//reset the variables to prevent user from changing grid and
					//having ant outside of grid bounds.
					rowAnt = -1;
					columnAnt = -1;
					steps = 0;
					rowsGrid = 0;
					columnsGrid = 0;
				}
				else
				{
					std::cout << "Please enter all required data before starting "
						<< "the simulation" << std::endl;
				}
			}

			if (choice == 6) //end program
			{
				exit = true;
			}
		}

		else
		{
			std::cout << "Input outside of range. Please enter a number "
				<< "between 1 and 6." << std::endl;
			
		}
	} while (exit == false);

}