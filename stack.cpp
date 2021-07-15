/*
Student Name: Rachel Jordan
Student NetID: rej168
Compiler Used: Visual Studio
Program Description: Program that manages stacks and queues and even loads up a file and uses its contents as its own input. Pretty cool.
*/

#include <string>
#include <iostream>
#include "node.h"
#include "stack.h"

using std::cout;
using std::endl;

Stack::Stack()
{
	sizeStack = 0;
	nameStack = "";
	top = nullptr;
}

Stack::Stack(string nameStack)
{
	sizeStack = 0;
	top = nullptr;
	this-> nameStack = nameStack;
}

// Based on the deconstructor in the lecture notes
Stack::~Stack()
{
	Node* temp = top;

	while (temp != nullptr)
	{
		top = top->next;
		delete temp;
		temp = top;
	}
}

// getters
int Stack::getSizeStack()
{
	return sizeStack;
}

string Stack::getNameStack()
{
	return nameStack;
}

// setters
void Stack::setSizeStack(int sizeStack)
{
	this->sizeStack = sizeStack;
}

void Stack::setNameStack(string nameStack)
{
	this->nameStack = nameStack;
}


// The next 3 functions were all based on their corresponding functions in the lecture notes

// Pushes a node onto a stack
bool Stack::pushStack(string id, int ticketNum)
{
	Node* temp = new Node(id, ticketNum);

	temp->next = top;
	top = temp;
	sizeStack++;

	return true;
}

// Pops a node from a stack
bool Stack::popStack()
{
	Node* temp = top;

	if (top == nullptr)
	{
		return false;
	}

	top = top->next;
	delete temp;
	sizeStack--;

	return true;
}

// Peeks at the to-be-affected node in a stack
bool Stack::peekStack(string &id, int &ticketNum)
{
	if (top == nullptr)
	{
		return false;
	}

	id = top->id;
	ticketNum = top->ticketNum;
	
	cout << "Net ID: " << id << "\t";
	cout << "Ticket Number: " << ticketNum << "\t";
	cout << endl << endl;

	return true;
}