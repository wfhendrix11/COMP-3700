// Lab 2:			Distributed TigerBook Social Network
// File:				Group.cpp
// Description:	Class implementation of the "Group" class.

#include <iostream>
#include <vector>
#include "User.cpp"

using namespace std;

// Name:				Group
// Description:	A group of Users. 
class Group
{ 
	private:
		string groupName; // name of the group
		User members[10]; // members of the group
		int numberOfMembers;
	public:
		Group();
		Group(string groupNameValue);
      	void addToGroup(User currentUser);
      	string getGroupName();
};

// ------------------Constructors--------------------

// Function:		Group
// Description:	Group defualt constructor.
Group::Group()
{
	numberOfMembers = 0;

}

// Function:      Group
// Description:   Constructor for the Group object.
Group::Group(string groupNameValue)
{
	numberOfMembers = 0; 
   groupName = groupNameValue;
}

// Function:      addToGroup
// Description:   Adds the currentUser to the group.
void Group::addToGroup(User currentUser)
{
   members[numberOfMembers] = currentUser;
   numberOfMembers++;   
}

// Function:      getGroupName
// Description:   Returns the Group's name.
//
string Group::getGroupName()
{ 
   return groupName;
}