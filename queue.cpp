/*
Student Name: Rachel Jordan
Student NetID: rej168
Compiler Used: Visual Studio
Program Description: Program that manages stacks and queues and even loads up a file and uses its contents as its own input. Pretty cool.
*/

#include <string>
#include <iostream>
#include "node.h"
#include "queue.h"

using std::cout;
using std::endl;

Queue::Queue()
{
	sizeQueue = 0;
	nameQueue = "";
	first = nullptr;
	last = nullptr;
}

Queue::Queue(string nameQueue)
{
	sizeQueue = 0;
	first = nullptr;
	this->nameQueue = nameQueue;
}

// Based on the deconstructor in the lecture notes
Queue::~Queue()
{
	Node* temp = first;

	while (temp != nullptr)
	{
		first = first->next;
		delete temp;
		temp = first;
	}

	last = nullptr;
}

// getters
int Queue::getSizeQueue()
{
	return sizeQueue;
}

string Queue::getNameQueue()
{
	return nameQueue;
}

// setters
void Queue::setSizeQueue(int sizeQueue)
{
	this->sizeQueue = sizeQueue;
}

void Queue::setNameQueue(string nameQueue)
{
	this->nameQueue = nameQueue;
}


// The next 3 functions were all based on their corresponding functions in the lecture notes

// Pushes a node onto a queue. EnQueue, if you will
bool Queue::pushQueue(string id, int ticketNum)
{
	Node* temp = new Node(id, ticketNum);
	if (first == nullptr)
	{
		first = temp;
	}

	else
	{
		last->next = temp;
	}

	last = temp;
	sizeQueue++;
	return true;
}

// Pops a node from a queue. DeQueue, if you will
bool Queue::popQueue()
{
	Node* temp = first;

	if (first == nullptr)
	{
		return false;
	}

	first = first->next;

	if (first == nullptr)
	{
		last = nullptr;
	}

	delete temp;
	sizeQueue--;
	return true;
}

// Peeks at the to-be-affected node in a queue
bool Queue::peekQueue(string &id, int &ticketNum)
{
	if (first == nullptr)
	{
		return false;
	}

	id = first->id;
	ticketNum = first->ticketNum;

	cout << "NetID: " << id << "\t";
	cout << "Ticket Number: " << ticketNum << endl;
	cout << endl << endl;

	return true;
}