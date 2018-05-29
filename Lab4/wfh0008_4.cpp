// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// Name:    	William F. Hendrix
// Class:		COMP 2710 Section 001
// Date:    	December 8th, 2017
// E-Mail:  	wfh0008@auburn.edu
// User-ID: 	wfh0008
// Filename:	wfh0008_4.cpp
//
// Description: This program is a simple Register Application with 
//				Inheritance and Vitual Functions.
#include <iostream>
#include "SimpleCashRegister.hpp"

using namespace std;

// Function:      main
// Description:   Runs the program. 
int main() 
{
	SimpleCashRegister SCR = SimpleCashRegister();
	SCR.cashRegister();

	return 0;
}