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

#ifndef STACK_H
#define STACK_H

class Stack
{
private:
	int sizeStack;
	string nameStack;
	Node* top;

public:
	Stack();
	Stack(string nameStack);
	~Stack();

	//getters
	int getSizeStack();
	string getNameStack();

	// setters
	void setSizeStack(int sizeStack);
	void setNameStack(string nameStack);

	bool pushStack(string id, int ticketNum); // should only fail if the stack doesn't exist
	bool popStack(); // fail if it is empty; call multiple times for mpop
	bool peekStack(string &id, int &ticketNum); // fail if it is empty

};

#endif 