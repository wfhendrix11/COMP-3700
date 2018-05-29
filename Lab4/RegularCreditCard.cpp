// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    RegularCreditCard.cpp
// Description:	RegularCreditCard. class implementation.
#include <iostream>

#include "RegularCreditCard.hpp"

// // default constructor
RegularCreditCard::RegularCreditCard() : RegularSale()
{
	string creditCardName = "";
	string creditCardNumber = "";
	string expirationDate = "";
}

string RegularCreditCard::getCreditCardName()
{
	return creditCardName;
}

void RegularCreditCard::setCreditCardName(string creditCardName)
{	
	this->creditCardName = creditCardName;
}

string RegularCreditCard::getCreditCardNumber()
{	
	return creditCardNumber;
}

void RegularCreditCard::setCreditCardNumber(string creditCardNumber)
{
	this->creditCardNumber = creditCardNumber;
}

string RegularCreditCard::getExpirationDate()
{	
	return expirationDate;
}

void RegularCreditCard::setExpirationDate(string expirationDate)
{
	this->expirationDate = expirationDate;
}

// // override process_payment function
void RegularCreditCard::process_payment()
{	
	// get the credit card name
	cout << "Enter name on the credit card: ";
	cin.ignore(); 
	getline(cin, creditCardName);
	this->setCreditCardName(creditCardName);
	cout << endl;

	// get the credit card number
	cout << "Enter credit card number: ";
	getline(cin, creditCardNumber);
	this->setCreditCardNumber(creditCardNumber);
	cout << endl;

	// get expiration date 
	cout << "Enter expiration date: ";
	getline(cin, expirationDate); 
	this->setExpirationDate(expirationDate);
}

// override print_sale function
void RegularCreditCard::print_sale()
{
	// print out all the items
    printItems();

    // print out sub total
    cout << "   Sub-Total: $ " << this->getSubTotal() << endl;

    cout << "   Regular Sale" << endl;

    cout << "   Tax: $" << this->getSalesTax() * this->getSubTotal()  << endl;

    cout << "   Total amount: $ " << this->getTotalAmount() << endl;

    cout << "   CREDIT CARD " << this->getCreditCardName() << " " <<  this->getCreditCardNumber() << " " << this->getExpirationDate() << endl;
}
