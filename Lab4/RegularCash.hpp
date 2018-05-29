// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        RegularCash.hpp
// Description: RegularCash class abstraction.

#ifndef RegularCash_hpp
#define RegularCash_hpp
#include "RegularSale.hpp"

using namespace std;

// Name:		RegularCash
// Description:	Defines the RegularCash object.
class RegularCash : public RegularSale
{
private:
	double amountReceived;
	double change;
public:
	RegularCash();
	void process_payment();
	void print_sale();
};

#endif // RegularCash.hpp