// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    ContractorCheck.cpp
// Description:	ContractorCheck class implementation.
#include <iostream>

#include "ContractorCheck.hpp"

// default constructor
ContractorCheck::ContractorCheck() : ContractorSale()
{
    string checkName = "";
    int licenseNumber = 0;
}

string ContractorCheck::getCheckName()
{
    return checkName;
}

void ContractorCheck::setCheckName(string checkName)
{   
    this->checkName = checkName;
}

int ContractorCheck::getLicenseNumber()
{
    return licenseNumber;
}

void ContractorCheck::setLicenseNumber(int licenseNumber)
{
    this->licenseNumber = licenseNumber;
}

// override process_payment function
void ContractorCheck::process_payment()
{
	// get name on check 
    checkName;
    cout << "Enter name on the check: ";
    cin.ignore();
    getline(cin, checkName);
    this->setCheckName(checkName);
    cout << endl;


    // get the drivers license number
    licenseNumber;
    cout << "Enter driver's license number: ";
    cin >> licenseNumber;
    this->setLicenseNumber(licenseNumber);
    cout << endl;
}

// override process_payment function
void ContractorCheck::print_sale()
{
    // print out all the items
    printItems();

    // print out sub total
    cout << "   Sub-Total: $ " << this->getSubTotal() << endl;

    cout << "   Contractor Sale" << endl;

    cout << "   Contractor ID: " << this->getContractorID() << endl;

    cout << "   Discount: $: " << this->getDiscount() << endl;

    cout << "   Sub-Total: $ " << this->getSubTotal() << endl;

    cout << "   Tax: $" << this->getSalesTax() * this->getSubTotal()  << endl;

    cout << "   Total amount: $ " << this->getTotalAmount() << endl;

    cout << "   CHECK " << this->getCheckName() << " " <<  this->getLicenseNumber() << endl;
}