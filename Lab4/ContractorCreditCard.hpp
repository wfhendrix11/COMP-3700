// Lab 4:       Simple CreditCard Register Application with 
//              Inheritance and Vitual Functions
// File:        ContractCreditCard.hpp
// Description: ContractCreditCard class abstraction.

#ifndef ContractorCreditCard_hpp
#define ContractorCreditCard_hpp
#include "ContractorSale.hpp"

using namespace std;

// Name:		ContractCreditCard
// Description:	Defines the ContractCreditCard object.
class ContractorCreditCard : public ContractorSale
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
	ContractorCreditCard();
	void process_payment();
	void print_sale();
};

#endif // ContractCreditCard.hpp