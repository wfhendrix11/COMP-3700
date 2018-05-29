// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        RegularSale.hpp
// Description: RegularSale class abstraction.

#ifndef RegularSale_hpp
#define RegularSale_hpp
#include "Sale.hpp"

using namespace std;

// Name:		RegularSale
// Description  Defines the RegularSale object. 
class RegularSale : public Sale
{
private:
public:
	RegularSale();
	void process_sale();
	void virtual process_payment() = 0;
	void virtual print_sale() = 0;
};

#endif // RegularSale.hpp