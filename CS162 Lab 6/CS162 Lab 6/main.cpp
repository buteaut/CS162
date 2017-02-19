/*********************************************************************************
** Program name: Lab 6
** Author: Thomas Buteau
** Date: 2-19-17
** Description: Lab 6 is a demonstration of linked lists.
**
*********************************************************************************/

#include <iostream>


struct LinkedList
{
	int num;
	LinkedList* next;

	LinkedList(int num)
	{
		this->num = num;
		next = nullptr;
	}
};


int main()
{
	LinkedList* head = nullptr;
	char cont;
	int userInt;

	std::cout << "Lab 6: Linked Lists" << std::endl;

	//add items to list
	do
	{
		std::cout << "Enter a number : ";
		std::cin >> userInt;

		//adds first node if list is empty
		if (head == nullptr)
		{
			head = new LinkedList(userInt);
		}
		
		else
		{
			//adds to tail if list is not empty
			LinkedList* end = head;
			while (end->next != nullptr)
			{
				end = end->next;
			}
			end->next = new LinkedList(userInt);
		}
		std::cout << "Add another item? Y/N: " << std::endl;
		std::cin >> cont;
	} while (toupper(cont) == 'Y');

	std::cout << "The linked list is currently: ";
	LinkedList* report = head;
	
	//if empty list
	if (report->next == nullptr)
	{
		std::cout << "empty." << std::endl;
	}
	//prints list
	while (report)
	{
		std::cout << report->num << " ";
		report = report->next;
	}
	
	std::cout << std::endl;

	std::cout << "Enter 'h' to see the head value or 't' to see the tail value."
		<< std::endl;
	std::cin >> cont;

	if (toupper(cont) == 'T')
	{
		LinkedList* end = head;
		while (end->next != nullptr)
		{
			end = end->next;
		}
		std::cout << end->num << std::endl;
	}
	
	if (toupper(cont) == 'H')
	{
		std::cout << head->num << std::endl;
	}
	do
	{
		std::cout << "Enter 'h' to delete the head or 't' to delete the tail."
			<< std::endl;
		std::cin >> cont;

		if (toupper(cont) == 'H') //remove the head node
		{
			if (head == nullptr) //checks if list is empty first
			{
				std::cout << "The list is empty." << std::endl;
			}
			else
			{
				LinkedList* holder = head->next; //points to next node
				delete head; //deletes head node
				head = holder; //adjusts head node label

				if (head == nullptr) //if deleted head was last node list is now empty
				{
					std::cout << "The list is empty." << std::endl;
				}
				else //deleted head was not last node
				{
					std::cout << "The head is now " << head->num << std::endl;
				}
			}
		}

		if (toupper(cont) == 'T') //remove the tail node
		{
			if (head == nullptr) //checks if list is empty first
			{
				std::cout << "The list is empty." << std::endl;
			}

			else if (head->next == nullptr) //head only node
			{
				delete head;
				head = nullptr;
				std::cout << "The list is now empty." << std::endl;
			}

			else //head not only node in list
			{
				LinkedList* curTail = head->next;
				LinkedList* newTail = head;

				while (curTail->next != nullptr) //finds end of list
				{
					curTail = curTail->next;
					newTail = newTail->next;
				}
				delete curTail;
				newTail->next = nullptr;
				std::cout << "The new tail is " << newTail->num
					<< std::endl;
			}
		}
		std::cout << "Would you like to do this again (y/n)" << std::endl;
		std::cin >> cont;
	} while (toupper(cont) == 'Y');

	if (head != nullptr) //trash collection
	{
		LinkedList* endPnt = head;
		while (endPnt->next != nullptr)
		{
			LinkedList* trash = endPnt;
			endPnt = endPnt->next;
			delete trash;
		}
	}
	delete head;
	return 0;
}
