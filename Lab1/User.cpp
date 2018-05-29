// Lab 1:         TigerBook Social Network
// File:          User.cpp
// Description:   Class implementation of the User class.

#include <iostream>

using namespace std;

// Name:          User
// Description:   Creates users to be used by the program.
class User
{
   private:
      string userName;
      string groupName;        
   public:
      User(); 
      User(string userName);
      string getUserName();
      string getGroupName();
      void setGroupName(string groupName);
};

// Function:      User 
// Description:   DEFUALT constructor. 
//
User::User() 
{ 

} 

// Function:      User
// Description:   Constructor for the User object.
//
User::User(string userNameValue)
{ 
   userName = userNameValue;

}

// Function:      getUserName
// Description:   Returns the User's user name.
//
string User::getUserName()
{ 
   return userName;
}

// Function:      getGroupName
// Description:   Returns the User's group name.
//
string User::getGroupName()
{ 
   return groupName;
}

// Function:      setGroupName
// Description:   Sets the user's group name.
//
void User::setGroupName(string groupNameValue)
{ 
   groupName = groupNameValue;
} 

