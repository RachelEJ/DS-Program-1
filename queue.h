/*
Student Name: Rachel Jordan
Student NetID: rej168
Compiler Used: Visual Studio
Program Description: Program that manages stacks and queues and even loads up a file and uses its contents as its own input. Pretty cool.
*/

#pragma once
#include <string>
#include "node.h"

using std::string;

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
	int sizeQueue;
	string nameQueue;
	Node* first, * last;

public:
	Queue();
	Queue(string nameQueue);
	~Queue();

	//getters
	int getSizeQueue();
	string getNameQueue();

	// setters
	void setSizeQueue(int sizeQueue);
	void setNameQueue(string nameQueue);
	
	bool pushQueue(string id, int ticketNum); // should only fail if the stack doesn't exist
	bool popQueue(); // fail if it is empty; call multiple times for mpop
	bool peekQueue(string &id, int &ticketNum); // fail if it is empty

};

#endif 