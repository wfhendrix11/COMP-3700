// Lab 1:      Distributed TigerBook Social Network
// Name:       William F. Hendrix
// Class:      COMP 2710 Section 1
// Date:       October 29th, 2017
// E-Mail:     wfh0008@auburn.edu
// User-ID:    wfh0008
// Filename:   wfh0008_2.cpp
//
// Compiling instructions:
// From the terminal, navigate to the directory where the following files are located:
//
// To compile this program, type:
// "g++ wfh0008_2.cpp"
// and hit enter. Once the program compiles, type "./a" and the program will
// begin, prompting the user to choose an option.
//
// Description: This program is a simple chat messaging system
//              that allows users to post messages, friend other users,
//              change users, display a home page, display
//              a wall page, and quit the application.
#include <iostream>
#include "Menu.cpp"

using namespace std;

// Function:      main
// Description:   Runs the program. 
int main() 
{
	Menu Menu;
	Menu.printMenu(); 
   return 0;
}