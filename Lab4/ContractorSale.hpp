// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        ContractorSale.hpp
// Description: ContractorSale class abstraction.

#ifndef ContractorSale_hpp
#define ContractorSale_hpp
#include "Sale.hpp"

using namespace std;

// Name:		ContractorSale
// Description  Defines the ContractorSale object. 
class ContractorSale : public Sale
{
private:
	string contractorID;
	double discount;
public:
	ContractorSale();
	string getContractorID();
	void setContractorID(string contractorID);
	double getDiscount();
	void setDiscount(double discount);
	void process_sale();
	void virtual process_payment() = 0;
	void virtual print_sale() = 0;
};

#endif // ContractorSale.hpp