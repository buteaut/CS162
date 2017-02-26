/*********************************************************************************
** Program name: Lab 7 (Queue Header File)
** Author: Thomas Buteau
** Date: 2-26-17
** Description: Queue header file. Class designed the create a circular
**				linked list. Has methods to add values to the back of the list,
**				display the 'front' value, remove the 'front' node, and display
**				all values in the list.
**
*********************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue
{
private:
	struct QueueNode
	{
		int num;
		QueueNode* next;
		QueueNode* previous;

		QueueNode(int num)
		{
			this->num = num;
			//next = nullptr;
			//previous = nullptr;
		}
	};

	QueueNode* first;
	QueueNode* last;

public:

	Queue();
	~Queue();

	void addBack(int);
	int getFront();
	int removeFront();
	void displayNodes();

};

#endif

