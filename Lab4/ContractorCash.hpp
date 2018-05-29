// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        ContractorCash.hpp
// Description: ContractorCash class abstraction.

#ifndef ContractorCash_hpp
#define ContractorCash_hpp
#include "ContractorSale.hpp"

using namespace std;

// Name:		ContractCash
// Description:	Defines the ContractCash object.
class ContractorCash : public ContractorSale
{
private:
	double amountReceived;
	double change;
public:
	ContractorCash();
	void process_payment();
	void print_sale();
};

#endif // ContractCash.hpp