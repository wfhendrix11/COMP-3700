// Lab 2:			Distributed TigerBook Social Network
// File:				User.cpp
// Description:	Class implementation of the "User" class.

#include <iostream>

using namespace std;

// Name:				User
// Description:	A user of the program.
class User
{
   private:
      string userName;
      string groupName;        
   public:
      User(); 
      User(string userName);
      string getUserName();
      void setGroupName(string groupName);
      string getGroupName();
};

// Function:		User
// Description:	User defualt constructor.
User::User()
{ 

}

// Function:      User
// Description:   Constructor for the User object.
User::User(string userNameValue)
{ 
   userName = userNameValue;

}

// Function:      getUserName
// Description:   Returns the User's user name.
string User::getUserName()
{ 
   return userName;
}

// Function:      setGroupName
// Description:   Sets the user's group name.
//
void User::setGroupName(string groupNameValue)
{ 
   groupName = groupNameValue;
}

// Function:      getGroupName
// Description:   Returns the Group's name.
//
string User::getGroupName()
{ 
   return groupName;
}
