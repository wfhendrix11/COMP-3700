// Lab 3:			Snakes and Ladders Maze Game
// File:	    		Maze.cpp
// Description:	Manages the maze of the program.

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.cpp"

using namespace std;

// Name:				Maze
// Description:	Defines the Maze object.
class Maze
{
	private:
		// member variables
		Node* nodes[48];
		Node* currentNode;
		Node* start;
		Node* finish;
		Node* player1;
		Node* player2;
		bool firstPass;
		int numberOfNodes;
	public:
		Maze();
		void userInterface();
		void createMaze();
		void player1TakeTurn(string player1Name);
		int indexOf(string nodeName);
};

// Function:      Maze
// Description:   Defualt constructor for the Maze object.
Maze::Maze()
{	
	firstPass = true;
	int numberOfNodes = 0; 
}

// Function:		printBanner
// Description:	prints the welcome banner at the start of the program.
void Maze::userInterface()
{
	cout << "		=========================================================================" << endl;
   cout << "		|              Welcome to the Snakes and Ladders Maze Game              |" << endl;
   cout << "		=========================================================================" << endl << endl;

   int numberOfPlayers = 0;
   cout << "Enter the number of players: ";
   cin >> numberOfPlayers;

   string player1Name;
   cout << "Enter the name of player #1: ";
   cin >> player1Name;

   string player2Name;
   cout << "Enter the name of player #2: ";
   cin >> player2Name;
   cout << endl;

   createMaze(); // setup the maze

   // setup
   bool mazeSolved = false;
	start = nodes[indexOf("A1")];
	finish = nodes[indexOf("H6")];
   player1 = nodes[0];
   player2 = nodes[0];

   while (mazeSolved == false)
   {
   	player1TakeTurn(player1Name);

		if (player1->getNodeName() == finish->getNodeName() || player2->getNodeName() == finish->getNodeName())
		{
			mazeSolved = true;
		}
   }

}

// Function:		createMaze
// Description:	creates a maze from a file.
void Maze::createMaze()
{
	string fileName, name, north, south, east, west, snakesOrLadder;

	// creates 48 Nodes
	for (int i = 0; i < 48; i++)
	{
		nodes[i] = new Node();
	}

	ifstream inStream; // file reading
	fileName = "maze1.txt";
	inStream.open(fileName.c_str()); //open the file

	int currentNodeIndex = 0;

	while (!inStream.eof() && currentNodeIndex < 48)
	{
		// read & set the name of the Node
		inStream >> name;
		// if the node does NOT exist...
		if (indexOf(name) < 0)
		{
			currentNodeIndex = numberOfNodes;
			nodes[currentNodeIndex]->setNodeName(name); // then make a new node
			numberOfNodes++;
		}
		// if the node DOES exist...
		else 
		{
			currentNodeIndex = indexOf(name);
		}

		// // read & set the NORTH Node
		inStream >> north;
		if (north != "*")
		{
			// if the node does NOT exist...
			if (indexOf(north) < 0)
			{
				nodes[numberOfNodes]->setNodeName(north); // then make a new node
				numberOfNodes++;
				nodes[currentNodeIndex]->attachNewNode(new Node(north), 0);
			}
			else 
			{
				nodes[currentNodeIndex]->attachNewNode(nodes[indexOf(north)], 0);
			}
		}

		// // read & set the EAST Node
		inStream >> east;
		if (east != "*") 
		{
			if (indexOf(east) < 0)
			{
				nodes[numberOfNodes]->setNodeName(east); // then make a new node
				numberOfNodes++;
				nodes[currentNodeIndex]->attachNewNode(new Node(east), 1);
			}
			else
			{
				nodes[currentNodeIndex]->attachNewNode(nodes[indexOf(east)], 1);	
			}	
		}

		// read and set the SOUTH Node
		inStream >> south;
		if (south != "*")
		{
			if (indexOf(south) < 0)
			{	
				nodes[numberOfNodes]->setNodeName(south); // then make a new node
				numberOfNodes++;
				nodes[currentNodeIndex]->attachNewNode(new Node(name), 2);
			}
			else 
			{
				nodes[currentNodeIndex]->attachNewNode(nodes[indexOf(south)], 2);
			}
		}

		// read & set the WEST Node
		inStream >> west;
		if (west != "*")
		{
			if (indexOf(west) < 0)
			{
				nodes[numberOfNodes]->setNodeName(west); // then make a new node
				numberOfNodes++;
				nodes[currentNodeIndex]->attachNewNode(new Node(west), 3);
			}
			else 
			{
				nodes[currentNodeIndex]->attachNewNode(nodes[indexOf(west)], 3);	
			}
		}

		// // read & set the snakesOrLadder Node
		inStream >> snakesOrLadder;
		if (snakesOrLadder != "*")
		{
			if (indexOf(snakesOrLadder) < 0)
			{
				nodes[numberOfNodes]->setNodeName(snakesOrLadder); // then make a new node
				numberOfNodes++;
				nodes[currentNodeIndex]->attachNewNode(new Node(snakesOrLadder), 4);	
			}
			else
			{
				nodes[currentNodeIndex]->attachNewNode(nodes[indexOf(snakesOrLadder)], 4);
			}
		}
		currentNodeIndex++;
	}

	// UNCOMMENT TO PRINT ENTIRE MAZE...
	// for (int i = 0; i < numberOfNodes; i++)
	// {
	// 	cout << nodes[i]->toString() << endl;
	// }

}

void Maze::player1TakeTurn(string player1Name)
{
	cout << "		=========================================================================" << endl;
	cout << "		|                              " + player1Name + "'s turn                              |" << endl;
	cout << "		=========================================================================" << endl << endl;

	cout << player1Name << "'s turn to throw the dice, just hit enter...";

	// continue when enter is pressed
	if (firstPass)
	{
		cin.ignore();
		firstPass = false;
	}
	bool enterPressed = false;
	while (enterPressed == false)
	{
		if (cin.get() == '\n')
		{
			enterPressed = true;
	   }
	}

	// get random dice roll
	srand(time(0));
	int diceRoll = rand() % 6 + 1;
	cout << player1Name + "'s Dice throw is " << diceRoll << endl;
	cout << player1Name + " can move to " << diceRoll << " nodes" << endl;
	cout << endl;

	string userChoice;
	for (int i = 0; i < diceRoll; i++)
	{
		cout << player1Name << " is currently in Node " << player1->getNodeName() << " of the Maze Game" << endl;
		cout << "current node: " << player1->toString() << endl;
		cout << "You can go " << player1->printAvailableDirections() << ".What is your choice? ";
		cin >> userChoice;
		cout << endl;

		if (userChoice == "N")
		{
			player1 = nodes[indexOf(player1->getAttachedNode(0)->getNodeName())];
		}

		if (userChoice == "E")
		{
			player1 = nodes[indexOf(player1->getAttachedNode(1)->getNodeName())];
		}

		if (userChoice == "S")
		{
			player1 = nodes[indexOf(player1->getAttachedNode(2)->getNodeName())];
		}

		if (userChoice == "W")
		{
			player1 = nodes[indexOf(player1->getAttachedNode(3)->getNodeName())];
		}
	}
}

//----------------------------helper-functions-------------------------------
int Maze::indexOf(string nodeName)
{
	for (int i = 0; i < 48; i++)
	{
		if (nodes[i]->getNodeName() == nodeName)
		{
			return i;
		}
	}
	return -1;
}


	