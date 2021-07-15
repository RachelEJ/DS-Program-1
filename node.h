/*
Student Name: Rachel Jordan
Student NetID: rej168
Compiler Used: Visual Studio
Program Description: Program that manages stacks and queues and even loads up a file and uses its contents as its own input. Pretty cool.
*/

#pragma once
#include <string>

using std::string;

#ifndef NODE_H
#define INVENTORY_H

class Node
{
public:
	string id;
	int ticketNum;
	Node* next;

	// Uses the universal constructor formal from the lecture notes
	Node() : id(""), ticketNum(0), next(nullptr) {}
	Node(string id) : id(id), ticketNum(0), next(nullptr) {}
	Node(int ticketNum) : id(""), ticketNum(ticketNum), next(nullptr) {}
	Node(string id, int ticketNum): id(id), ticketNum(ticketNum), next(nullptr) {}
	Node(string id, int ticketNum, Node* next) : id(id), ticketNum(ticketNum), next(next) {}
};

#endif 