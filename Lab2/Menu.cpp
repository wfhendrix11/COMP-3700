// Lab 2:			Distributed TigerBook Social Network
// File:			Menu.cpp
// Description:		Class implementation of the "Menu" class.

#include <iostream>
#include "System.cpp"

using namespace std;

// Name:					Menu
// Description:		Management of the menu.
class Menu
{
	private:
	public:
		Menu();
		void printMenu();
};

// Function:      Menu
// Description:   Defualt constructor for the menu object.
//
Menu::Menu()
{ 

}

// Function:      printMenu
// Description:   Displays the menu.
//
void Menu::printMenu()
{
	string userChoice; // the user's input
   char choiceChar; // first character of user's input
   System System; // create new System object

   // print start welcome header
   cout <<"\n";
   cout << "             ====================================================================\n";
   cout << "             |                   Distributed TigerBook System!                  |\n";
   cout << "             ====================================================================\n";
   
   // create a new user
   System.newUser();

   do
   { 
      cout << "\nBroadcast (b), Multicast (m), Unicast (u), Wall (w), Home (h), Create Group (g),\n";
      cout << "Join group (j), Quit (q)\n\n";
 
      cout << "Please choose an option: ";
      cin >> userChoice;

      choiceChar = userChoice.at(0);
        
      switch (choiceChar)
      {
         case 'b':
            System.broadcast();
            break;
         case 'm':
            System.multicast();
            break;
         case 'u':
            System.unicast();
            break;
         case 'w':
            System.wall();
            break;
         case 'h':
            System.home();
            break;
         case 'g':
            System.newGroup();
            break;
         case 'j':
            System.joinGroup();
            break;
         case 'q':
            System.quit();
            break;
         default:
            cout << "\nInvalid input! Please try again!\n";
            break;
      }
      
   } while (choiceChar != 'q');
}

