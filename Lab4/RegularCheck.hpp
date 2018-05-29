// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        RegularCheck.hpp
// Description: RegularCheck class abstraction.

#ifndef RegularCheck_hpp
#define RegularCheck_hpp
#include "RegularSale.hpp"

using namespace std;

// Name:		RegularCash
// Description:	Defines the RegularCash object.
class RegularCheck : public RegularSale
{
private:
	string checkName;
	int licenseNumber;
public:
	RegularCheck();
	string getCheckName();
	void setCheckName(string checkName);
	int getLicenseNumber();
	void setLicenseNumber(int licenseNumber);
	void process_payment();
	void print_sale();
};

#endif // RegularCheck.hpp