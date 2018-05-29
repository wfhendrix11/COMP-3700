// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    ContractCash.cpp
// Description:	ContractCash class implementation.
#include <iostream>

#include "ContractorCash.hpp"

// default constructor
ContractorCash::ContractorCash() : ContractorSale()
{
	double amountReceived = 0;
	double change = 0;
}

// override process_sale function
void ContractorCash::process_payment()
{
	 // get amount received 
    cout << "Amount received: $ ";
    cin >> amountReceived;
    cout << endl;

    // calculate and print change
    change = amountReceived - this->getTotalAmount();
    cout << "Change: $ " << change  << endl;
}

void ContractorCash::print_sale()
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

	cout << "   CASH" << endl;

	cout << "   Amount received: $ " << amountReceived << endl;

	cout << "   Change: $ " << change << endl;
}