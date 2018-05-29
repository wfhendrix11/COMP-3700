// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    RegularCheck.cpp
// Description:	RegularCheck. class implementation.
#include <iostream>
#include <string>

#include "RegularCheck.hpp"

// default constructor
RegularCheck::RegularCheck() : RegularSale()
{
    string checkName = "";
    int licenseNumber = 0;
}

string RegularCheck::getCheckName()
{
    return checkName;
}

void RegularCheck::setCheckName(string checkName)
{   
    this->checkName = checkName;
}

int RegularCheck::getLicenseNumber()
{
    return licenseNumber;
}

void RegularCheck::setLicenseNumber(int licenseNumber)
{
    this->licenseNumber = licenseNumber;
}

// override process_payment function
void RegularCheck::process_payment()
{
	// get name on check 
    cout << "Enter name on the check: ";
    cin.ignore();
    this->setCheckName(checkName);
    cout << endl;

    // get the drivers license number
    cout << "Enter driver's license number: ";
    cin >> licenseNumber;
    this->setLicenseNumber(licenseNumber);
    cout << endl;
}

// override print_sale function
void RegularCheck::print_sale()
{
    // print out all the items
    printItems();

    // print out sub total
    cout << "   Sub-Total: $ " << this->getSubTotal() << endl;

    cout << "   Regular Sale" << endl;

    cout << "   Tax: $" << this->getSalesTax() * this->getSubTotal()  << endl;

    cout << "   Total amount: $ " << this->getTotalAmount() << endl;

    cout << "   CHECK " << this->getCheckName() << " " <<  this->getLicenseNumber() << endl;
	
}