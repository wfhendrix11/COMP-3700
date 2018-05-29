// Lab 3:      Snakes and Ladders Maze Game
// Name:       William F. Hendrix
// Class:      COMP 2710 Section 001
// Date:       November 15th, 2017
// E-Mail:     wfh0008@auburn.edu
// User-ID:    wfh0008
// Filename:	wfh0008_3.cpp
//
// Compiling instructions:
// From the terminal, navigate Documents/comp2710/Labs/Lab2
//
// To compile this program, type:
// "c++ -std=c++0x wfh0008_3.cpp"
// and hit enter. Once the program compiles, type "./a" and the program will
// begin, prompting the user to input the number of users.
//
// Description: This program is a simple Snakes and Ladders Maze Game.
#include <iostream>
#include "Maze.cpp"

using namespace std;

// Function:      main
// Description:   Runs the program. 
int main() 
{
	Maze Maze;
	Maze.userInterface();
	Maze.createMaze();
	return 0;
}