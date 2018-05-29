// Lab 2:			Distributed TigerBook Social Network
// File:				System.cpp
// Description:	Class implementation of the "System" class.

#include <iostream>
#include <array>
#include "Group.cpp"
#include "NetworkFileServer.cpp" 

using namespace std;

// Name:				System
// Description:	Management of the overall program.
class System
{
	private:
		User currentUser; // the current User of the program
      User users[10]; // list of Users
      Group groups[10]; // list of Groups
      int numberOfUsers; // number of Users
      int numberOfGroups; // number of groups
      string files[10]; // array of file names
      int numberOfFiles; // number of files
      string message_buffer;
	public:
		// Constructor
		System();

		// Menu functions
		void newUser();
		void newGroup();
		void joinGroup();
		void broadcast();
		void multicast();
		void unicast();
		void wall();
		void home();
		void quit();

		// Helper functions
      void createArrayOfFileNames();
      void createMessageBuffer();
};

NetworkFileServer NetworkFileServer; // creates a NetworkFileSystem object

// --------------------Constructors-------------------------

// Function:		System
// Description:	Defualt constructor for System. 
System::System()
{
   numberOfGroups = 0;
   numberOfUsers = 0;
   numberOfFiles = 0;

}

// ----------------------Functions--------------------------

// Function:		createNewUser
// Description:	Creates a new "User" object. 
void System::newUser()
{
	string userName;
   cout << "\nPlease enter a user name: ";
   cin >> userName;

   // check if this is a valid User

   // create a new User
   User newUser(userName); // load into new User object
   currentUser = newUser; // make this User the current User

   // print new User welcome banner
   cout << "\n";
	cout << "             ====================================================================\n";
	cout << "             |    Welcome to Distributed TigerBook Social Network, " + userName + "!      |\n";
	cout << "             ====================================================================\n";
}

// Function:			createNewGroup
// Description:		Creates a new "Group" object. 
void System::newGroup()
{
	string groupName;
   cout << "\nPlease enter the group name: ";
   cin >> groupName;
	
   // create a new Group
   Group newGroup(groupName); // load into new Group object

   // make file name
   string fileName = groupName;
   fileName.erase(0, 1); // trim '#' from the file name
   fileName = "_" + fileName + ".txt"; // add to the string

   NetworkFileServer.newFile(groupName); // create new file
   NetworkFileServer.addToFiles(fileName); // add file to Files.txt

   // display new group banner
   cout << "\n";
	cout << "             ====================================================================\n";
	cout << "             |                      New Group " + groupName + " created                   |\n";
	cout << "             ====================================================================\n";
}

// Function:		joinGroup
// Description:	Adds the current User to a group. 
void System::joinGroup()
{
	string groupName;
   cout << "\nPlease enter the group name: ";
   cin >> groupName;
	currentUser.setGroupName(groupName);
   
   for (int i = 0; numberOfGroups >= i; i++)
   {
      if (groups[numberOfGroups].getGroupName() == groupName) 
      {
         groups[numberOfGroups].addToGroup(currentUser);
      }              
   }
   
   cout << "\n";
   cout << "             ====================================================================\n";
   cout << "             |                   " + currentUser.getUserName() + " has joined group " + groupName + "                |\n";
   cout << "             ====================================================================\n";   
}

// Function:   	broadcast
// Description:   Sends a message to every user. 
//
void System::broadcast()
{
	string message, line, message_buffer;
   cout << "\nEnter message: ";

   // get message from User
   while (getline(cin, line)) 
   {
      if (line == "^!")
      {
         break;
      } 
      message += line + "\n";
   }
   message_buffer = "<!" + currentUser.getUserName() + ":" + "#ALL" + "!>" + message + message_buffer;

   // add this message to "_All" file
   NetworkFileServer.writeToFile("_All.txt", message_buffer);

   // increment the number of messages
   NetworkFileServer.incrementNumberOfMessages(); 

   // display new broadcast banner
   cout << "\n";
	cout << "             ====================================================================\n";
	cout << "             |                 " + currentUser.getUserName() + " has broadcasted a new message             |\n";
	cout << "             ====================================================================\n";

}

// Function:      multicast
// Description:   Sends a message to a group.
//
void System::multicast()
{
   // read in message
   string groupName, message, line, message_buffer, fileName;
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
   
   // add this message to groupName file
   fileName = groupName;
   fileName.erase(0, 1); // trim '#' from the file name
   fileName = "_" + fileName + ".txt"; // add to the string
   NetworkFileServer.writeToFile(fileName, message_buffer);

   // increment the number of messages
   NetworkFileServer.incrementNumberOfMessages(); 
   
   // display header
   cout << "\n";
   cout << "             ====================================================================\n";
   cout << "             |     " + currentUser.getUserName() + " has multicasted a message to group " + groupName + "            |\n";
   cout << "             ====================================================================\n";

}

// Function:      unicast
// Description:   Sends a message to a user.
//
void System::unicast()
{
   // get message
   string recipientName, message, line, message_buffer, fileName;
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

   // add this message to recipientName file
   fileName = recipientName;
   fileName = "_" + fileName + ".txt"; // add to the string
   NetworkFileServer.writeToFile(fileName, message_buffer);
   NetworkFileServer.addToFiles(fileName); // add this file to Files.txt

   // increment the number of messages
   NetworkFileServer.incrementNumberOfMessages(); 

   // display header
   cout << "\n";
   cout << "             ====================================================================\n";
   cout << "             |        " + currentUser.getUserName() + " has unicasted a message to  " + recipientName + "              |\n";
   cout << "             ====================================================================\n";
}

// Function:      wall
// Description:   Displays the user's wall page (All the messages sent by the User)
void System::wall()
{
   // display banner
   cout << "\n             ====================================================================\n";
   cout << "             |                        " + currentUser.getUserName() + "'s Wall Page                        |\n";
   cout << "             ====================================================================\n\n";

   // find all file names and put them in an array
   createArrayOfFileNames();

   // for each file in the array, convert to string and append to message_buffer
   createMessageBuffer();

   // parse up the message_buffer
   int prevIndexOfCarrot_open = 0;
   int prevIndexOfCarrot_close = 0;
   int prevIndexOfColon = 0;

   int index = 0;
   int numberOfMessages = NetworkFileServer.getNumberOfMessages();
   while (index <= numberOfMessages)
   {
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

      }
      
      int prevIndexOfCarrot_next = indexOfCarrot_next;
      prevIndexOfCarrot_open = indexOfCarrot_open;
      prevIndexOfCarrot_close = indexOfCarrot_close;
      prevIndexOfColon = indexOfColon;
      
      index++;
   }

   std::fill_n(files, numberOfFiles, 0); // reset files array!

   // display banner
   cout << "             ====================================================================\n";
   cout << "             |                    End of " + currentUser.getUserName() + "'s Wall Page                     |\n";
   cout << "             ====================================================================\n";\


}

// Function:      home
// Description:   Displays the users home page (All the messages received by the User, 
//                and all the messages sent by the User.)
void System::home()
{
   cout << "\n             ====================================================================\n";
   cout << "             |                          " + currentUser.getUserName() + "'s Home Page                      |\n";
   cout << "             ====================================================================\n";

   // find all file names and put them in an array
   createArrayOfFileNames();

   // for each file in the array, convert to string and append to message_buffer
   createMessageBuffer();

   // parse up the message_buffer
   int prevIndexOfCarrot_open = 0;
   int prevIndexOfCarrot_close = 0;
   int prevIndexOfColon = 0;

   int index = 0;
   int numberOfMessages = NetworkFileServer.getNumberOfMessages();
   while (index <= numberOfMessages)
   {
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
      }
      
      int prevIndexOfCarrot_next = indexOfCarrot_next;
      prevIndexOfCarrot_open = indexOfCarrot_open;
      prevIndexOfCarrot_close = indexOfCarrot_close;
      prevIndexOfColon = indexOfColon;

      index++;
   }
   cout << "\n";
   cout << "             ====================================================================\n";
   cout << "             |                    End of " + currentUser.getUserName() + "'s Home Page                     |\n";
   cout << "             ====================================================================\n\n";
}

//Function:     quit
//Description:  Displays a closing message, and gracefully exits the program.
//
void System::quit() 
{
   cout << "\n";
   cout << "             ====================================================================\n";
   cout << "             |       Thank you for using the Distributed TigerBook System       |\n";
   cout << "             ====================================================================\n";
   cout << "\n";
}

// --------------------Helper-Functions-------------------------

// find all file names and put them in an array
void System::createArrayOfFileNames()
{  
   std::ifstream input( "Files.txt" ); 
   for( std::string line; getline( input, line ); )
   {
      files[numberOfFiles] = line;
      numberOfFiles++;
   }
}

// for each file in the array, convert to string and append to message_buffer
void System::createMessageBuffer()
{
   int index = 0;
   message_buffer = NetworkFileServer.convertFileToString("_All.txt");
   while (index < numberOfFiles)
   {
      message_buffer = NetworkFileServer.convertFileToString(files[index]) + message_buffer;
      index++;
   } 
}