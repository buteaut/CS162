/*********************************************************************************
** Program name: Lab 7 (Queue Implementation File)
** Author: Thomas Buteau
** Date: 2-26-17
** Description: Queue implementation file. Class designed the create a circular
**				linked list. Has methods to add values to the back of the list,
**				display the 'front' value, remove the 'front' node, and display
**				all values in the list.
**
*********************************************************************************/

#include "Queue.hpp"

Queue::Queue()
{
	first = new QueueNode(-1);
	first->next = first;
	first->previous = first;
	last = first;
}

Queue::~Queue()
{
	while (last->next != first)
	{
		last = last->next;
	}
	
	while (first != last)
	{
		QueueNode* trash = first;
		first = first->next;
		delete trash;
	}

	delete first;
}

/*********************************************************************************
**								Queue::addBack
** Description: Adds the int argument to the list. If the 'last' node is empty,
**				the argument is added at 'last'. If the node after last is empty,
**				sets that node to last and adds the argument there. If the node
**				after 'last' is 'first', adds a new node, sets it to 'last', and
**				adds argument to 'last'.
**
*********************************************************************************/
void Queue::addBack(int val)
{
	if (last->num == -1) //if last is an empty node
	{
		last->num = val;
	}

	else if (last->next == first) //if all nodes are full
	{
		QueueNode* temp = new QueueNode(val);
		last->next = temp;
		temp->next = first;
		last = temp;
	}

	else if ((last->next)->num == -1) //if node after last is empty
	{
		last = last->next;
		last->num = val;
	}

	else //might not be needed
	{
		QueueNode* temp = new QueueNode(val);
		temp->next = last->next;
		last->next = temp;
		last = temp;
	}
}

/*********************************************************************************
**								Queue::getFront
** Description: Returns the value stored in the 'front' node.
**
*********************************************************************************/
int Queue::getFront()
{
	int val = first->num;

	return val;
}

/*********************************************************************************
**								Queue::removeFront
** Description: Removes and returns the front node's value. Moves front node to 
**				the next node.
**
*********************************************************************************/
int Queue::removeFront()
{
	if (first->num != -1)
	{
		int val = first->num;
		first->num = -1;
		first = first->next;
		return val;
	}

	else
		return -1;
}

/*********************************************************************************
**								Queue::displayNodes
** Description: Displays the value stored in each node.
**
*********************************************************************************/
void Queue::displayNodes()
{
	QueueNode* disp = first;
	std::cout << "Values in the list: " << std::endl;

	while (disp != last)
	{
		std::cout << disp->num << " ";
		disp = disp->next;
	}
	
	std::cout << disp->num << "." << std::endl;
	disp = 0;
	delete disp;
}