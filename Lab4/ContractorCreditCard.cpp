// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    ContractorCreditCard.cpp
// Description:	ContractorCreditCard class implementation.
#include <iostream>

#include "ContractorCreditCard.hpp"

// default constructor
ContractorCreditCard::ContractorCreditCard() : ContractorSale()
{
	string creditCardName = "";
	string creditCardNumber = "";
	string expirationDate = "";
}

string ContractorCreditCard::getCreditCardName()
{
	return creditCardName;
}

void ContractorCreditCard::setCreditCardName(string creditCardName)
{	
	this->creditCardName = creditCardName;
}

string ContractorCreditCard::getCreditCardNumber()
{	
	return creditCardNumber;
}

void ContractorCreditCard::setCreditCardNumber(string creditCardNumber)
{
	this->creditCardNumber = creditCardNumber;
}

string ContractorCreditCard::getExpirationDate()
{	
	return expirationDate;
}

void ContractorCreditCard::setExpirationDate(string expirationDate)
{
	this->expirationDate = expirationDate;
}

// override process_payment function
void ContractorCreditCard::process_payment()
{
	// get the credit card name
	cout << "Enter name on the credit card: ";
	cin.ignore(); 
	getline(cin, creditCardName);
	this->setCreditCardName(creditCardName);
	cout << endl;

	// get the credit card number
	cout << "Enter credit card number: ";
	cin.ignore(); 
	getline(cin, creditCardNumber);
	this->setCreditCardNumber(creditCardNumber);
	cout << endl;

	// get expiration date 
	cout << "Enter expiration date: ";
	cin.ignore(); 
	getline(cin, expirationDate); 
	this->setExpirationDate(expirationDate);
}

// override print_sale function
void ContractorCreditCard::print_sale()
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

    cout << "   CREDIT CARD " << this->getCreditCardName() << " " <<  this->getCreditCardNumber() << " " << this->getExpirationDate() << endl;
}