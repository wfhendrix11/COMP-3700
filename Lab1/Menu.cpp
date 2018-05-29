// Lab 1:         TigerBook Social Network
// File:          Menu.cpp
// Description:   Class implementation of the Menu class.

#include <iostream>
#include <array>
#include <string>
#include "Group.cpp"

using namespace std;

User currentUser("");  // current user of program.
int numberOfUsers = 0;
int numberOfGroups = 0;
int numberOfMessages = 0;
//array<User, 10> userList; // list of users
User userList[10];
//array<Group, 10> groupList; // list of groups
Group groupList[10]; 

// Name:          Menu
// Description:   This class deals with providing a user interface by taking input
//                from the user.
class Menu
{  
   private:
      //array<User, 10> userList; // list of users
      //array<Group, 10> groupList; // list of groups
      //int numberOfGroups = 0; 
      string message_buffer;
      //int numberOfMessages = 0;     
   public: 
      Menu();
      void displayMenu();
      void createNewUser();
      void createNewGroup();
      void joinGroup();
      void broadcast();
      void multicast();
      void unicast();
      void wallPage();
      void homePage();
      void switchUser();
      void quit();
};

// Function:      Menu
// Description:   Constructor for the menu object.
//
Menu::Menu()
{ 

}

// Function:      displayMenuHeader
// Description:   Print out the header for the menu.
//
void Menu::displayMenu()
{ 
   cout << "             ==========================================================\n";
   cout << "             |             The TigerBook Social Network!              |\n";
   cout << "             ==========================================================\n";
   
   string userChoice;
   char choiceChar;
      
   do
   { 
      cout << "\nCreate new user (n), Broadcast (b), Multicast (m), Unicast (u), Wall page (w), Home page (h), Create new group (g),\n";
      cout << "Join a group (j), Switch user (s), Quit (q)\n\n";
 
      cout << "Please choose an option: ";
      cin >> userChoice;

      choiceChar = userChoice.at(0);
        
      switch (choiceChar)
      { 
         case 'n':
            createNewUser();
            break;
         case 'b':
            broadcast();
            break;
         case 'm':
            multicast();
            break;
         case 'u':
            unicast();
            break;
         case 'w':
            wallPage();
            break;
         case 'h':
            homePage();
            break;
         case 'g':
            createNewGroup();
            break;
         case 'j':
            joinGroup();
            break;
         case 's':
            switchUser();
            break;
         case 'q':
            quit();
            break;
         default:
            cout << "\nInvalid input! Please try again!\n";
            break;
      }
      
   } while (choiceChar != 'q');
}

// Function:      newUser
// Description:   Create a new user with a name, group and message.
// 
void Menu::createNewUser()
{
   string userName;
   cout << "\nPlease enter a user name: ";
   cin >> userName;
   
   User newUser(userName); // load info into new User object
   currentUser = newUser; // set this user to current user
   userList[numberOfUsers] = currentUser; // Add User to list of Users 
   
   cout << "\n";
   cout << "             ==========================================================\n";
   cout << "             |      Welcome to TigerBook Social Network, " + userName + "!      |\n";
   cout << "             ==========================================================\n";
   
   numberOfUsers++;
}

// Function:      newGroup
// Description:   Create a new group.
//
void Menu::createNewGroup()
{
   string groupName;
   cout << "\nPlease enter the group name: ";
   cin >> groupName;
   
   Group newGroup(groupName); // load info into new Group object
   groupList[numberOfGroups] = newGroup; // Add group to groupList
   numberOfGroups++;
   
   cout << "\n";
   cout << "             ==========================================================\n";
   cout << "             |                  " + groupName + " group created                 |\n";
   cout << "             ==========================================================\n";
}

// Function:      joinGroup
// Description:   Adds a user to a group. 
//
void Menu::joinGroup()
{   
   string groupName;
   cout << "\nPlease enter the group name: ";
   cin >> groupName;
   currentUser.setGroupName(groupName); // set the group name
     
   for (int i = 0; numberOfGroups >= i; i++)
   {
      if (groupList[numberOfGroups].getGroupName() == groupName) 
      {
         groupList[numberOfGroups].addToGroup(currentUser);
      }              
   }
   
   cout << "\n";
   cout << "             ==========================================================\n";
   cout << "             |              " + currentUser.getUserName() + " is in " + groupName + " group                |\n";
   cout << "             ==========================================================\n";   
}

// Function:   Broadcast
// Description:   Sends a message to every user. 
//
void Menu::broadcast()
{ 
   string message, line;
   cout << "\nEnter message: ";
   while (getline(cin, line)) 
   {
      if (line == "^!")
      {
         break;
      } 
      message += line + "\n";
   }
   message_buffer = "<!" + currentUser.getUserName() + ":" + "#ALL" + "!>" + message + message_buffer;
   numberOfMessages++;
}

// Function:      multicast
// Description:   Sends a message to a group.
//
void Menu::multicast()
{
   string groupName, message, line;
   cout << "\nPlease enter the group name: ";
   cin >> groupName;
   cout << "\nEnter message: ";
   while (getline(cin, line)) 
   {
      if (line == "^!")
      {
         break;
      } 
      message += line + "\n";
   }
   message_buffer = "<!" + currentUser.getUserName() + ":" + groupName + "!>" + message + message_buffer;
   numberOfMessages++;
} 

// Function:      unicast
// Description:   Sends a message to a group.
//
void Menu::unicast()
{
   string recipientName, message, line;
   cout << "\nEnter the recipient user name: ";
   cin >> recipientName;
   cout << "\nEnter message: ";
   while (getline(cin, line)) 
   {
      if (line == "^!")
      {
         break;
      } 
      message += line + "\n";
   }
   
   message_buffer = "<!" + currentUser.getUserName() + ":" + recipientName + "!>" + message + message_buffer;
   numberOfMessages++;

}

// Function:      wallPage
// Description:   Displays the user's wall page.
//
void Menu::wallPage()
{
   cout << "             ==========================================================\n";
   cout << "             |                   " + currentUser.getUserName() + "'s Wall Page                   |\n";
   cout << "             ==========================================================\n"; 
   
   int index = numberOfMessages;
   int prevIndexOfCarrot_open = 0;
   int prevIndexOfCarrot_close = 0;
   int prevIndexOfColon = 0;
   int printedMessages = 0;
      
   while (index > 0) 
   {
      if (printedMessages == 2)
      {
         string input; 
         cout << "                  More messages? (yes/no): ";
         cin >> input;
         
         if (input == "no")
         { 
            return;
         }
      }
      
      string userName, group, message;
      
      int indexOfCarrot_open = message_buffer.find("<!", prevIndexOfCarrot_open) + 2;
      int indexOfCarrot_close = message_buffer.find("!>", prevIndexOfCarrot_close) + 2; 
      int indexOfColon = message_buffer.find(":", prevIndexOfColon) + 2;
      int indexOfCarrot_next = message_buffer.find("<!", indexOfCarrot_open) + 2;
        
      // find user name
      userName = message_buffer.substr(indexOfCarrot_open, indexOfColon - indexOfCarrot_open - 2);
      
      if (userName.compare(currentUser.getUserName()) == 0)
      {
         // print group
         group = "(" + message_buffer.substr(indexOfColon - 1, indexOfCarrot_close - indexOfColon - 1) + ") >";
         cout << group;
         
         // print message
         message = message_buffer.substr(indexOfCarrot_close, indexOfCarrot_next - indexOfCarrot_close - 2) + "\n";
         cout << message;
         
         printedMessages++;
      }
      
      int prevIndexOfCarrot_next = indexOfCarrot_next;
      prevIndexOfCarrot_open = indexOfCarrot_open;
      prevIndexOfCarrot_close = indexOfCarrot_close;
      prevIndexOfColon = indexOfColon;
      index--;
   }
}

// Function:      homePage
// Description:   Displays the users home page. 
// 
void Menu::homePage()
{
   cout << "             ==========================================================\n";
   cout << "             |                   " + currentUser.getUserName() + "'s Home Page                   |\n";
   cout << "             ==========================================================\n\n";
   
   int index = numberOfMessages;
   int prevIndexOfCarrot_open = 0;
   int prevIndexOfCarrot_close = 0;
   int prevIndexOfColon = 0;
   int printedMessages = 0;
   
   while (index > 0) 
   {
      if (printedMessages == 2)
      {
         string input; 
         cout << "                  More messages? (yes/no): ";
         cin >> input;
         
         if (input == "no")
         { 
            return;
         }
      }
  
      string userName, groupName, message; 
      
      int indexOfCarrot_open = message_buffer.find("<!", prevIndexOfCarrot_open) + 2;
      int indexOfCarrot_close = message_buffer.find("!>", prevIndexOfCarrot_close) + 2; 
      int indexOfColon = message_buffer.find(":", prevIndexOfColon) + 2;
      int indexOfCarrot_next = message_buffer.find("<!", indexOfCarrot_open) + 2;
        
      // get user name
      userName = message_buffer.substr(indexOfCarrot_open, indexOfColon - indexOfCarrot_open - 2);
      // get group name
      groupName =  message_buffer.substr(indexOfColon - 1, indexOfCarrot_close - indexOfColon - 1);
      // get message
      message =  message_buffer.substr(indexOfCarrot_close, indexOfCarrot_next - indexOfCarrot_close - 2);
      
      if (groupName == "#ALL" || groupName == currentUser.getGroupName() || groupName == currentUser.getUserName() || userName == currentUser.getUserName())
      { 
         cout << userName + "(" + groupName + ")" + " >";
         cout << message + "\n";
         printedMessages++;
      }
      
      int prevIndexOfCarrot_next = indexOfCarrot_next;
      prevIndexOfCarrot_open = indexOfCarrot_open;
      prevIndexOfCarrot_close = indexOfCarrot_close;
      prevIndexOfColon = indexOfColon;
      index--;
   } 
}

// Function:      switchUser
// Description:   Switches current user to another user. 
//
void Menu::switchUser()
{
   string userName;
   cout << "\nPlease enter a user name: ";
   cin >> userName;
   bool validUser = false;
   
   for (int i = 0; numberOfUsers >= i; i++)
   {
      if (userList[i].getUserName() == userName) 
      { 
         currentUser = userList[i];
         cout << "\n";
         cout << "             ==========================================================\n";
         cout << "             |    Welcome back to TigerBook Social Network, " + userName+ "        |\n";
         cout << "             ==========================================================\n";
         return;
      }
   }
   
   cout << "\nNot a valid user!\n";       
}

//Function:     quit
//Description:  Displays a closing message, and gracefully exits the program.
//
void Menu::quit() 
{
   cout << "             ==========================================================\n";
   cout << "             |      Thank you for using TigerBook Social Network      |\n";
   cout << "             ==========================================================\n";
    
} 
