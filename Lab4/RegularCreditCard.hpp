// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        RegularCreditCard.hpp
// Description: RegularCreditCard class abstraction.

#ifndef RegularCreditCard_hpp
#define RegularCreditCard_hpp
#include "RegularSale.hpp"

using namespace std;

// Name:		RegularCash
// Description:	Defines the RegularCash object.
class RegularCreditCard : public RegularSale
{
private:
	string creditCardName;
	string creditCardNumber;
	string expirationDate;
public:
	string getCreditCardName();
	void setCreditCardName(string creditCardName);
	string getCreditCardNumber();
	void setCreditCardNumber(string creditCardNumber);
	string getExpirationDate();
	void setExpirationDate(string expirationDate);
	RegularCreditCard();
	void process_payment();
	void print_sale();
};

#endif // RegularCreditCard.hpp