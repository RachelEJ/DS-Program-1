/*
Student Name: Rachel Jordan
Student NetID: rej168
Compiler Used: Visual Studio
Program Description: Program that manages stacks and queues and even loads up a file and uses its contents as its own input. Pretty cool.
*/

/*
NOTE: Pretty much everything I've coded has been adapted from the lectures.
*/

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "node.h"
#include "stack.h"
#include "queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ifstream;
using std::stringstream;

// Display Containers Function
void displayContainers(vector<Stack *>stackList, vector<Queue *>queueList)
{
	cout << "List of Containers" << endl << endl;

	// When there's no containers
	if (stackList.size() == 0 && queueList.size() == 0)
	{
		cout << "\t No containers found" << endl << endl;
	}

	// When there are containers
	else
	{ 
		// prints out all the info for each container
		for (int i = 0; i < stackList.size(); i++)
		{
			if (stackList[i]->getSizeStack() == 1)
			{
				cout << "\t stack " << stackList[i]->getNameStack() << " containing " << stackList[i]->getSizeStack() << " element " << endl << endl;
			}
			else
			{
				cout << "\t stack " << stackList[i]->getNameStack() << " containing " << stackList[i]->getSizeStack() << " elements " << endl << endl;
			}
		}

		for (int i = 0; i < queueList.size(); i++)
		{
			if (queueList[i]->getSizeQueue() == 1)
			{
				cout << "\t queue " << queueList[i]->getNameQueue() << " containing " << queueList[i]->getSizeQueue() << " element " << endl << endl;
			}
			else
			{
				cout << "\t queue " << queueList[i]->getNameQueue() << " containing " << queueList[i]->getSizeQueue() << " elements " << endl << endl;
			}
		}
	}
}


// Search Containers Function. I use this one a lot
int searchContainers(const vector<Stack *>&stackList, const vector<Queue *>&queueList, string key)
{
	// Welcome to my very convoluted "searching for existence" function
	int exist = 0;
	int stackExist = 0;
	int queueExist = 0;

	// Searches through each container and adds 1 to exist and containerExist if it's there
	for (int i = 0; i < stackList.size(); i++)
	{
		if (stackList[i]->getNameStack() == key)
		{
			exist++;
			stackExist++;
		}
	}

	for (int j = 0; j < queueList.size(); j++)
	{
		if (queueList[j]->getNameQueue() == key)
		{
			exist++;
			queueExist++;
		}
	}

	// Checks the exist and containerExist values and returns a value for use later
	if (exist == 0)
	{
		return 0;
	}
	
	else if (exist == 1)
	{
		if (stackExist == 1)
		{
			return 1;
		}

		else if(queueExist == 1)
		{
			return 2;
		}

		else
		{
			return 3;
		}
	}

	else
	{
		return 4;
	}
}

// Create Stack Function
bool createStack(vector<Stack *>&stackList, vector<Queue *>&queueList, string newStack)
{
	// Checks if the name has already been used before
	int preexist = searchContainers(stackList, queueList, newStack);

	// For searchContainers(), 0 means the container doesn't exist
	if (preexist == 0)
	{
		Stack* temp = new Stack(newStack);
		stackList.push_back(temp);

		cout << "Successfully created the stack " << newStack << endl << endl;
		return true;
	}

	// 1 means the container exists as a stack
	else if (preexist == 1)
	{
		cout << "The container " << newStack << " already exists." << endl << endl;
		return false;
	}

	// 2 means the container exists as a queue
	else if (preexist == 2)
	{
		cout << "The container " << newStack << " already exists." << endl << endl;
		return false;
	}

	// Something wrong happened. I actually don't know if this one will ever print, but I wanted it there just in case
	else
	{
		cout << "An error has occurred. Please try again." << endl << endl;
		return false;
	}

	// This 
}

// Create Queue Function
bool createQueue(vector<Stack*>& stackList, vector<Queue*>& queueList, string newQueue)
{
	// Checks if the name has already been used before
	int preexist = searchContainers(stackList, queueList, newQueue);

	// Container doesn't exist
	if (preexist == 0)
	{
		Queue* temp = new Queue(newQueue);
		queueList.push_back(temp);

		cout << "Successfully created the queue " << newQueue << endl << endl;


		return true;
	}
	
	// That stack already exists
	else if (preexist == 1)
	{
		cout << "The container " << newQueue << " already exists." << endl << endl;
		return false;
	}

	// That queue already exists
	else if (preexist == 2)
	{
		cout << "The container " << newQueue << " already exists." << endl << endl;
		return false;
	}

	// In case something wrong happens
	else
	{
		cout << "An error has occurred. Please try again." << endl << endl;
		return false;
	}
}

// Remove Container Function
bool removeContainer(vector<Stack*>& stackList, vector<Queue*>& queueList, string key)
{
	// Checks if the container actually exists or not
	int find = searchContainers(stackList, queueList, key);

	// Container doesn't exist
	if (find == 0)
	{
		cout << "The container " << key << " does not exist." << endl << endl;
		return false;
	}

	// Removes a stack
	else if (find == 1)
	{
		int index = 0;
		for (int i = 0; i < stackList.size(); i++)
		{
			if (stackList[i]->getNameStack() == key)
			{
				delete stackList[index];
				stackList.erase(stackList.begin() + index);
				break;
			}
		}

		return true;
	}

	// Removes a queue
	else if (find == 2)
	{
		int index = 0;
		for (int i = 0; i < queueList.size(); i++)
		{
			if (queueList[i]->getNameQueue() == key)
			{
				delete queueList[index];
				queueList.erase(queueList.begin() + index);
				break;
			}
		}
		return true;
	}

	// In case something wrong happens
	else
	{
		cout << "An error has occurred. Please try again." << endl << endl;
		return false;
	}
}

// Push Into Container Function
bool pushIntoContainer(vector<Stack*>& stackList, vector<Queue*>& queueList, string id, int ticketNum, string key)
{
	// Checks if the container actually exists or not
	int find = searchContainers(stackList, queueList, key);

	// Container doesn't exist
	if (find == 0)
	{
		cout << "The container " << key << " does not exist." << endl << endl;
		return false;
	}

	// Pushes onto a stack
	else if (find == 1)
	{
		// Because I can't do key.pushStack(), I have to iterate through the vector and get the index so I can actually use the container in its command
		int index = 0;
		for (int i = 0; i < stackList.size(); i++)
		{
			if (stackList[i]->getNameStack() == key)
			{
				index = i;
			}
		}

		// Here I call the pushStack() function
		int pushCheck = stackList[index]->pushStack(id, ticketNum);
		if (pushCheck == 0)
		{
			cout << "An error has occurred. Please try again." << endl << endl;
			return false;
		}

		else
		{
			cout << "Pushed user " << id << " @ ticket " << ticketNum << " into container " << stackList[index]->getNameStack() << endl << endl;
			return true;
		}
	}

	// Pushes onto a queue
	else if (find == 2)
	{
		int index = 0;
		for (int i = 0; i < queueList.size(); i++)
		{
			if (queueList[i]->getNameQueue() == key)
			{
				index = i;
			}
		}
		int pushCheck = queueList[index]->pushQueue(id, ticketNum);
		if (pushCheck == 0)
		{
			cout << "An error has occurred. Please try again." << endl << endl;
			return false;
		}

		else
		{
			cout << "Pushed user " << id << " @ ticket " << ticketNum << " into container " << queueList[index]->getNameQueue() << endl << endl;
			return true;
		}
	}

	// In case something goes wrong
	else
	{
		cout << "An error has occurred. Please try again." << endl << endl;
		return false;
	}

}

// The Parsing Function from Mr. Knight's example that he emailed me. Only altered to fit the program requirements
void readLines(istream& is, bool isFile, vector<Stack*>&stackList, vector<Queue*>&queueList)
{
	string line;
	string cmd;
	string arg1;
	string type;

	while (true)
	{
		if (isFile && is.eof()) return;
		getline(is, line);
		stringstream ss(line);
		getline(ss, cmd, ' ');

		// Exits the command line interface
		if (cmd == "exit") return;

		// Loads up a file if the user enters it correctly. Also takes the contents and uses it as input
		if (cmd == "load")
		{
			ifstream inFile;
			getline(ss, arg1, ' ');
			cout << endl;
			inFile.open(arg1);
			if (inFile.is_open())
			{
				readLines(inFile, true, stackList, queueList);
			}
			else
			{
				cout << "Failed to open the file" << endl;
			}
			inFile.close();
		}

		// Displays the containers
		if (cmd == "display")
		{
			displayContainers(stackList, queueList);
		}

		// Creates the containers
		if (cmd == "create")
		{
			// Reads what type of container before creating it with the entered name
			getline(ss, type, ' ');
			if (type == "stack")
			{
				getline(ss, arg1);
				int testCStack = createStack(stackList, queueList, arg1);
			}
			if (type == "queue")
			{
				getline(ss, arg1, ' ');
				int testCQueue = createQueue(stackList, queueList, arg1);
			}
		}

		// The full-fledged Search Containers command but more descriptive
		if (cmd == "find")
		{
			getline(ss, arg1);

			// Checks if the container actually exists or not
			int findContainer = searchContainers(stackList, queueList, arg1);

			// Container doesn't exist
			if (findContainer == 0)
			{
				cout << "The container " << arg1 << " doesn't exist" << endl << endl;
			}

			// Found a stack
			else if (findContainer == 1)
			{
				int index = 0;
				for (int i = 0; i < stackList.size(); i++)
				{
					if (stackList[i]->getNameStack() == arg1)
					{
						index = i;
					}
				}

				if (stackList[index]->getSizeStack() == 1)
				{
					cout << "The container " << arg1 << " contains " << stackList[index]->getSizeStack() << " element and is a stack" << endl << endl;
				}
				else
				{
					cout << "The container " << arg1 << " contains " << stackList[index]->getSizeStack() << " elements and is a stack" << endl << endl;
				}
			}

			// Found a queue
			else if (findContainer == 2)
			{
				int index = 0;
				for (int i = 0; i < queueList.size(); i++)
				{
					if (queueList[i]->getNameQueue() == arg1)
					{
						index = i;
					}
				}

				if (queueList[index]->getSizeQueue() == 1)
				{
					cout << "The container " << arg1 << " contains " << queueList[index]->getSizeQueue() << " element and is a queue" << endl << endl;
				}
				else
				{
					cout << "The container " << arg1 << " contains " << queueList[index]->getSizeQueue() << " elements and is a queue" << endl << endl;
				}

			}

			// In case something goes wrong
			else
			{
				cout << "An error has occurred. Please try again" << endl << endl;
			}
		}

		// Removes containers from the list and deletes them
		if (cmd == "remove")
		{
			getline(ss, arg1);
			bool checkRemove = removeContainer(stackList, queueList, arg1);
			if (checkRemove == true)
			{
				cout << "The container " << arg1 << " was deleted" << endl << endl;
			}
		}

		// Pushes the user-inputted info into the container of choice
		if (cmd == "push")
		{
			// Learned how to use the stoi() function thingy from GeeksforGeeks
			// https://www.geeksforgeeks.org/converting-strings-numbers-cc/
			string pushID;
			string pushTNumString;
			string filler;

			// Reads all the info
			getline(ss, pushID, ' ');
			getline(ss, pushTNumString, ' ');
			getline(ss, filler, ' ');
			getline(ss, arg1);

			// Converts the string into an int
			int pTNumInt = stoi(pushTNumString);
			int checkPush = pushIntoContainer(stackList, queueList, pushID, pTNumInt, arg1);
		}

		// Allows you to peek at the to-be-affected node of the container
		if (cmd == "peek")
		{
			getline(ss, arg1);

			// Checks if the container actually exists or not
			int determineType = searchContainers(stackList, queueList, arg1);
			string peekID;
			int peekTNum = 0;

			// Container doesn't exist
			if (determineType == 0)
			{
				cout << "The container " << arg1 << " doesn't exist" << endl << endl;
			}

			// Peek at stack
			else if (determineType == 1)
			{
				int index = 0;
				for (int i = 0; i < stackList.size(); i++)
				{
					if (stackList[i]->getNameStack() == arg1)
					{
						index = i;
					}
				}

				bool checkPeek = stackList[index]->peekStack(peekID, peekTNum);
				if (checkPeek == false)
				{
					cout << "The container " << arg1 << " is empty." << endl << endl;
				}
			}

			// Peek at queue
			else if (determineType == 2)
			{
				int index = 0;
				for (int i = 0; i < queueList.size(); i++)
				{
					if (queueList[i]->getNameQueue() == arg1)
					{
						index = i;
					}
				}
				queueList[index]->peekQueue(peekID, peekTNum);
			}

			// In case something wrong happens
			else 
			{
				cout << "An error has occurred. Please try again" << endl << endl;
			}
		}

		// Pops the to-be-affected node from the container of choice
		if (cmd == "pop")
		{
			getline(ss, arg1);
			int determineType = searchContainers(stackList, queueList, arg1);

			// Container doesn't exist
			if (determineType == 0)
			{
				cout << "The container " << arg1 << " doesn't exist" << endl << endl;
			}

			// Pops from stack
			else if (determineType == 1)
			{
				int index = 0;
				for (int i = 0; i < stackList.size(); i++)
				{
					if (stackList[i]->getNameStack() == arg1)
					{
						index = i;
					}
				}

				int checkSPop = stackList[index]->popStack();
				if (checkSPop == true)
				{
					cout << "Successfully pop'd from the container " << arg1 << endl << endl;
				}
				else
				{
					cout << "The container " << arg1 << " is empty" << endl << endl;
				}
			}

			// Pops from queue
			else if (determineType == 2)
			{
				int index = 0;
				for (int i = 0; i < queueList.size(); i++)
				{
					if (queueList[i]->getNameQueue() == arg1)
					{
						index = i;
					}
				}
				int checkQPop = queueList[index]->popQueue();
				if (checkQPop == true)
				{
					cout << "Successfully pop'd from the container " << arg1 << endl << endl;
				}
				else
				{
					cout << "The container " << arg1 << " is empty" << endl << endl;
				}
			}

			// In case something horribly wrong happens
			else
			{
				cout << "An error has occurred. Please try again" << endl << endl;
			}
		}

		// MPop, which calls Pop multiple times
		if (cmd == "mpop")
		{
			string m;
			int successfulPop = 0;
			getline(ss, arg1, ' ');
			getline(ss, m);
			int mInt = stoi(m);
			int determineType = searchContainers(stackList, queueList, arg1);

			// Container doesn't exist
			if (determineType == 0)
			{
				cout << "The container " << arg1 << " doesn't exist" << endl << endl;
			}

			// MPop on stack
			else if (determineType == 1)
			{
				int index = 0;
				for (int i = 0; i < stackList.size(); i++)
				{
					if (stackList[i]->getNameStack() == arg1)
					{
						index = i;
					}
				}

				// Does pop until it can't or until it finishes and then tallies up successful pops
				for (int j = 0; j < mInt; j++)
				{
					bool checkPop = stackList[index]->popStack();
					if (checkPop == true)
					{
						successfulPop++;
					}
					else
					{
						break;
					}
					
				}
				cout << "Successfully pop'd from the container " << arg1 << " " << successfulPop << " times" << endl << endl;
			}

			// MPop on queue
			else if (determineType == 2)
			{
				int index = 0;
				for (int i = 0; i < queueList.size(); i++)
				{
					if (queueList[i]->getNameQueue() == arg1)
					{
						index = i;
					}
				}

				// Does pop until it can't or until it finishes and then tallies up successful pops
				for (int j = 0; j < mInt; j++)
				{
					bool checkPop = queueList[index]->popQueue();
					if (checkPop == true)
					{
						successfulPop++;
					}
					else
					{
						break;
					}

				}
				cout << "Successfully pop'd from the container " << arg1 << " " << successfulPop << " times" << endl << endl;
			}

			// In case something wrong happens
			else
			{
				cout << "An error has occurred. Please try again" << endl << endl;
			}
		}
	}
}

// My surprisingly empty main function that only serves to create the vectors and call 1 function.
int main()
{
	vector<Stack*>stackList;
	vector<Queue*>queueList;

	readLines(cin, false, stackList, queueList);

	return 0;
}
