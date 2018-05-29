// Lab 1:      TigerBook Social Network
// Name:       William F. Hendrix
// Class:      COMP 2710 Section 1
// Date:       October 2, 2017
// E-Mail:     wfh0008@auburn.edu
// User-ID:    wfh0008
// Filename:   wfh0008_1.cpp
//
// Compiling instructions:
// From the terminal, navigate to the directory where the following files are located:
//
// To compile this program, type:
// "g++ wfh0008_1.cpp User.cpp Menu.cpp WallPage.cpp HomePage.cpp -o aew0056_1.out"
// and hit enter. Once the program compiles, type "./wfh0008.out" and the program will
// begin, prompting the user to choose an option.
//
// Description: This program is a simple chat messaging system
//              that allows users to post messages, friend other users,
//              follow hashtags, change users, display a home page, display
//              a wall page, and quit the application.
#include <iostream>
#include "Menu.cpp"
//#include "User.cpp"
//#include "Group.cpp"
//#include "MessageBuffer.cpp"

using namespace std;

// Function:      main
// Description:   Instantiates a Menu object, and uses it to display the user menu for
//                the TigerBook Social Network.
int main() 
{ 
   Menu menu;
   menu.displayMenu();

   return 0;
}