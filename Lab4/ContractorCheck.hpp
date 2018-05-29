// Lab 4:       Simple Check Register Application with 
//              Inheritance and Vitual Functions
// File:        ContractCheck.hpp
// Description: ContractCheck class abstraction.

#ifndef ContractorCheck_hpp
#define ContractorCheck_hpp
#include "ContractorSale.hpp"

using namespace std;

// Name:		ContractCheck
// Description:	Defines the ContractCheck object.
class ContractorCheck : public ContractorSale
{
private:
	string checkName;
	int licenseNumber;
public:
	ContractorCheck();
	string getCheckName();
	void setCheckName(string checkName);
	int getLicenseNumber();
	void setLicenseNumber(int licenseNumber);
	void process_payment();
	void print_sale();
};

#endif // ContractCheck.hpp