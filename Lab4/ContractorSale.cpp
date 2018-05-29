// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    ContractorSale.cpp
// Description:	ContractorSale class implementation.
#include <iostream>

#include "ContractorSale.hpp"

// default constructor
ContractorSale::ContractorSale() : Sale()
{
	string contractorID = ""; 
	double discount = 0;
}

string ContractorSale::getContractorID()
{	
	return contractorID;
}

void ContractorSale::setContractorID(string contractorID)
{
	this->contractorID = contractorID;
}

double ContractorSale::getDiscount()
{	
	return discount;
}

void ContractorSale::setDiscount(double discount)
{
	this->discount= discount;
}

// // override process_sale function
void ContractorSale::process_sale()
{
	// print sale type
	cout << endl;
	cout << "Contract Sale" << endl;
	cout << endl;

	// get contractor ID
	cout << "Contractor ID: ";
	cin >> contractorID;
	this->setContractorID(contractorID);
	cout << endl;

	// calculate and print discount 
	discount = this->getTotalAmount() * 0.15;
	cout << "Discount: $ " << discount << endl;
	this->setDiscount(discount);
	cout << endl;

	// calculate and print the sub-total
	double subtotal = this->getTotalAmount() - discount;
	this->setSubTotal(subtotal);
	cout << "Sub-Total: $ " << subtotal << endl;
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