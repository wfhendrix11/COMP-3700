// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    RegularCash.cpp
// Description:	RegularCash class implementation.
#include <iostream>

#include "RegularCash.hpp"

// default constructor
RegularCash::RegularCash() : RegularSale()
{
	double amountReceived = 0;
	double change = 0;
}

// override process_sale function
void RegularCash::process_payment()
{
	// get amount received 
    cout << "Amount received: $ ";
    cin >> amountReceived;
    cout << endl;

    // calculate and print change
    change = amountReceived - this->getTotalAmount();
    cout << "Change: $ " << change  << endl;
}

// override print_sale function
void RegularCash::print_sale()
{
	// print out all the items
	printItems();

	// print out sub total
	cout << "   Sub-Total: $ " << this->getSubTotal() << endl;

	cout << "   Regular Sale" << endl;

	cout << "   Tax: $" << this->getSalesTax() * this->getSubTotal()  << endl;

	cout << "   Total amount: $ " << this->getTotalAmount() << endl;

	cout << "   CASH" << endl;

	cout << "   Amount received: $ " << amountReceived << endl;

	cout << "   Change: $ " << change << endl;
}