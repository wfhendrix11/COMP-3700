// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    Sale.hpp
// Description:	Sale class abstraction.

#ifndef Sale_hpp
#define Sale_hpp
#include <string>
#include <vector>

#include "Item.hpp"

using namespace std;

// Name:		Sale
// Description:	Defines the Sale object.
class Sale
{
private:
	vector<Item> itemlist;
	double salesTax;
	double subTotal;
	double totalAmount;
public:
	Sale();
	double getSalesTax();
	void setSalesTax(double salesTax);
	double getTotalAmount();
	void setTotalAmount(double totalAmount);
	double getSubTotal();
	void setSubTotal(double subTotal);
	void addItem(Item item);
	void printItems();
	void virtual process_sale() = 0;
	void virtual process_payment() = 0;
	void virtual print_sale() = 0;
};

#endif // Sale.hpp