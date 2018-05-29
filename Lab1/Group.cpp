// Lab 1:         TigerBook Social Network
// File:          Group.cpp
// Description:   Class implementation of the Group class.

#include <iostream>
#include <array>
#include "User.cpp" 

using namespace std;

// Name:          Group
// Description:   
class Group
{
   private: 
      string groupName;
      User groupMembers[10]; // members of group
      int numberOfMembers = 0;
   public:
      Group(); 
      Group(string groupName);
      string getGroupName();
      void addToGroup(User currentUser);
};

// Function:      Group 
// Description:   DEFUALT constructor. 
//
Group::Group() 
{ 

}

// Function:      Group
// Description:   Constructor for the Group object.
//
Group::Group(string groupNameValue)
{ 
   groupName = groupNameValue;   
}

// Function:      getGroupName
// Description:   Returns the Group's name.
//
string Group::getGroupName()
{ 
   return groupName;
}

// Function:      addToGroup
// Description:   Adds the current user to the group.
//
void Group::addToGroup(User currentUser)
{
   groupMembers[numberOfMembers] = currentUser;
   numberOfMembers++;   
}