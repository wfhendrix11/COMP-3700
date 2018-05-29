// Lab 2:			Distributed TigerBook Social Network
// File:			NetworkFileServer.cpp
// Description:		Class implementation of the "System" class.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Name:				System
// Description:			Management of the overall program.
class NetworkFileServer
{
	private:
		int time;
	public:
      // constructor
		NetworkFileServer();

      // member functions
		void newFile(string fileName);
		void writeToFile(string fileName, string message);
		string timeStamp();
		string convertFileToString(string fileName);
		void addToFiles(string fileName);
      int getNumberOfMessages();

      // helper functions
      bool fileExists(const std::string& name);
      void incrementNumberOfMessages();
};

// Function:      Menu
// Description:   Defualt constructor for the NetworkFileServer object.
NetworkFileServer::NetworkFileServer()
{
	time = 0;
}

// Funtion:       newFile
// Description: 	Creates a new .txt file. 
void NetworkFileServer::newFile(string fileName)
{
	fileName.erase(0, 1); // trim '#' from the file name
	fileName = "_" + fileName + ".txt"; // add to the string

	ofstream outStream; // output file stream
	outStream.open(fileName.c_str()); // create file
	outStream.close();
}

// Function: 		writeToFile
// Description:	Writes a message to a file. 
void NetworkFileServer::writeToFile(string fileName, string message)
{	

	ofstream outStream; // output file stream
	outStream.open(fileName.c_str(), ios::app); // create file
	outStream << message; // writes message to the file
	outStream.close();
}

// Function:		timeStamp
// Description: 	Returns a string of the time stamp.
string NetworkFileServer::timeStamp()
{
   string fileName = "Time.txt";
   
   // write new time
   ofstream outStream; // output file stream
   outStream.open(fileName.c_str()); // open file
   outStream << time; // write time to file
   outStream.close();
   
   // read the time
   char next, result;
   ifstream inStream; // input file stream
   inStream.open(fileName.c_str()); // open file
   
   inStream.get(next);
   while (!inStream.eof())
   {
   	result = next;
   	inStream.get(next);
   }

   // convert char to string
   string s(1, result);

   inStream.close(); // close file 

   time++;

	return s;
}

// Function:		getNextMesssage
// Description: 	Returns a string of the entire file.
string NetworkFileServer::convertFileToString(string fileName)
{
	// read in file contents and store them in a string 
	fstream f(fileName, fstream::in );
   string s;
   getline( f, s, '\0');
   f.close();

   return s;
}

// Function:		addToFiles
// Description:	Adds the filename to the file "Files.txt"
void NetworkFileServer::addToFiles(string fileName)
{
	string file = "Files.txt";
	ofstream outStream; // output file stream
   outStream.open(file.c_str(), ios::app); // open file
   outStream << fileName + "\n"; // write time to file
   outStream.close();

}

// Function:      getNumbgerOfMessages
// Description:   Returns the number of messages.
int NetworkFileServer::getNumberOfMessages()
{
   string fileName = "numberOfMessages.txt";
   
   
   // check if NumbgerOfMessages.txt exists
   if (fileExists(fileName) == false)
   {
      // cerate a file and insert 0
      int numberOfMessages = 0;
      ofstream outStream; // output file stream
      outStream.open(fileName.c_str()); // open file
      outStream << numberOfMessages; // write time to file
      outStream.close();
      return 0;
   }
   else 
   {
      // read the numberOfMessages
      char next;
      int result;
      ifstream inStream; // input file stream
      inStream.open(fileName.c_str()); // open file
      
      inStream.get(next);
      while (!inStream.eof())
      {
         result = next - '0';
         inStream.get(next);
      }

      inStream.close(); // close file 
      return result;
   }
}

// Function:      incrementNumberOfMessages
// Description:   Increments the number of messages.
void NetworkFileServer::incrementNumberOfMessages()
{
   string fileName = "numberOfMessages.txt";

   // check if NumbgerOfMessages.txt exists
   if (fileExists(fileName) == false)
   {
      // cerate a file and insert 0
      int numberOfMessages = 0;
      ofstream outStream; // output file stream
      outStream.open(fileName.c_str()); // open file
      outStream << numberOfMessages; // write time to file
      outStream.close();
   }
   else 
   {
      // read the numberOfMessages
      char next;
      int numberOfMessages;

      ifstream inStream; // input file stream
      inStream.open(fileName.c_str()); // open file
      
      inStream.get(next);
      while (!inStream.eof())
      {
         numberOfMessages = next - '0';
         inStream.get(next);
      }

      inStream.close(); // close file 

      numberOfMessages++;

      // write new numberOfMessages
      ofstream outStream; // output file stream
      outStream.open(fileName.c_str()); // open file
      outStream << numberOfMessages; // write time to file
      outStream.close();
   }
}

// ----------------Helper-Functions---------------

// Function:      fileExists
// Description:   Checks that this file exists.
bool NetworkFileServer::fileExists(const std::string& name)
{
   ifstream f(name.c_str());
   return f.good();
}