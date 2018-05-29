// Lab 3:			Snakes and Ladders Maze Game
// File:	    		Node.cpp
// Description:	Manages the Nodes of the program.

#include <iostream>

using namespace std;

// Name:				Node
// Description:	Defines the Node object.
class Node
{
private:
	// memeber variables
	string name;
   Node* attachedNodes[4];
   Node* snakeOrLadderNodes;
public:
	// constructors
	Node();
   Node(string newname);

   // memeber functions
	void setNodeName(string newname);
	string getNodeName();
	void attachNewNode(Node *newNode, int direction);
	Node* getAttachedNode(int direction);
	void attachSnakeLadderNode(Node *newNode);
	Node* getSnakeLadderNode();
	string toString();
	string printAvailableDirections();
};

// ---------------------------Constructors------------------------------------

// Name:				Node
// Description:	Defualt constructor for Node.
Node::Node()
{
	name = "NULL";
	//attachedNodes[0] = NULL; // North
   //attachedNodes[1] = NULL; // East
   //attachedNodes[2] = NULL; // South
   //attachedNodes[3] = NULL; // West
   //snakeOrLadderNodes = NULL;	
}

// Name:				Node
// Description:	constructor with a string for Node.
Node::Node(string newname)
{
    name = newname;
    attachedNodes[0] = NULL;
    attachedNodes[1] = NULL;
    attachedNodes[2] = NULL;
    attachedNodes[3] = NULL;
    snakeOrLadderNodes = NULL;
}

// ---------------------------Memeber-functions---------------------------------

//Function:    	setNodeName
//Description: 	sets the name of the Node.
void Node::setNodeName(string newname)
{
    name = newname;
}

//Function:    	getName
//Description: 	returns the name of the node.
string Node::getNodeName()
{
    return name;
}

//Function:    	attachNewNode
//Description: 	attaches a node to the current node in the specified direction
void Node::attachNewNode(Node *newNode, int direction)
{
    attachedNodes[direction] = newNode;
}

//Function:    	getAttachedNode
//Description: 	returns the node that is attached to the current node 
//						in the specified direction.
Node* Node::getAttachedNode(int direction)
{
    return attachedNodes[direction];
}

//Function:    	attachSnakeLadderNode
//Description: 	attaches the ladder or chute node to the current node.
void Node::attachSnakeLadderNode(Node *newNode)
{
    snakeOrLadderNodes = newNode;
}

//Function:    	getSnakeLadderNode
//Description: 	returns the ladder or chute node.
Node* Node::getSnakeLadderNode()
{
    return snakeOrLadderNodes;
}

// -------------------------helper-functions----------------

string Node::toString()
{
	string north, east, south, west, snakeOrLadder, result;

	/// set north
	if (attachedNodes[0] == NULL)
	{
		north = "*";
	}
	else 
	{
		north = attachedNodes[0]->getNodeName();
	}

	// set east
	if (attachedNodes[1] == NULL)
	{
		east = "*";
	}
	else 
	{
		east = attachedNodes[1]->getNodeName();
	}
	
	// set south
	if (attachedNodes[2] == NULL)
	{
		south = "*";
	}
	else 
	{
		south = attachedNodes[2]->getNodeName();
	}
	
	// set west
	if (attachedNodes[3] == NULL)
	{
		west = "*";
	}
	else 
	{
		west = attachedNodes[3]->getNodeName();
	}
	
	// set snakeOrLadder
	if (attachedNodes[4] == NULL)
	{
		snakeOrLadder = "*";
	}
	else 
	{
		snakeOrLadder = attachedNodes[4]->getNodeName();
	}

	result = name + " " + north + " " + east + " " + south + " " + west + " " + snakeOrLadder;
	return result;
}

string Node::printAvailableDirections()
{
	string result;

	if (attachedNodes[0] != NULL)
	{
		result += "North ";
	}

	if (attachedNodes[1] != NULL)
	{
		result += "East ";
	}

	if (attachedNodes[2] != NULL)
	{
		result += "South ";
	}

	if (attachedNodes[3] != NULL)
	{
		result += "West ";
	}

	return result;
}