// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    Sale.cpp
// Description:	Sale class implementation.
#include <iostream>

#include "Sale.hpp"

// default constructor
Sale::Sale()
{
	double salesTax = 0;
	double subTotal = 0;
	double totalAmount = 0;
}

// return the sales tax
double Sale::getSalesTax()
{
	return salesTax;
}

// set the sales tax
void Sale::setSalesTax(double salesTax)
{
	this->salesTax = salesTax;
}

// return the total amount
double Sale::getTotalAmount()
{
	return totalAmount;
}

// set the total amount
void Sale::setTotalAmount(double totalAmount)
{
	this->totalAmount = totalAmount;
}

// return the sub total
double Sale::getSubTotal()
{
	return subTotal;
}

// set the sub total
void Sale::setSubTotal(double subTotal)
{
	this->subTotal = subTotal;
}

// add item
void Sale::addItem(Item item)
{
	itemlist.push_back(item);
}

// print all the items
void Sale::printItems()
{	
	for (int i = 0; i < itemlist.size(); i++)
	{	
		string name = itemlist[i].getName();
		double price = itemlist[i].getPrice();
		cout << i + 1 << ". " << name << " $ " << price << endl;	
	}
}

