// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    RegularSale.cpp
// Description:	RegulaSale class implementation.
#include <iostream>

#include "RegularSale.hpp"

// default constructor
RegularSale::RegularSale() : Sale()
{
	
}

// override process_sale function
void RegularSale::process_sale()
{
	// print sale type
	cout << endl;
	cout << "Regular Sale" << endl;
	cout << endl;

	// set and print the sale tax
	this->setSalesTax(0.08);
	double tax = this->getSalesTax() * this->getSubTotal();
	cout << "Tax: $ " << tax << endl;
	cout << endl;

	// set and print the total amount
	double totalAmount = tax + this->getSubTotal();
	this->setTotalAmount(totalAmount);
	cout << "Total amount: $ " << totalAmount << endl;
	cout << endl;
}