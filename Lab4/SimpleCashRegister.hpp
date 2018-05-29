// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        SimpleCashRegister.hpp
// Description: SimpleCashRegister class abstraction.

#ifndef SimpleCashRegister_hpp
#define SimpleCashRegister_hpp

#include "Sale.hpp"
#include "RegularSale.hpp"
#include "ContractorSale.hpp"
#include "RegularCash.hpp"
#include "RegularCheck.hpp"
#include "RegularCreditCard.hpp"
#include "ContractorCash.hpp"
#include "ContractorCheck.hpp"
#include "ContractorCreditCard.hpp"

#include <vector>

// Name:		SimpleCashRegister
// Description:	Defines the SimpleCashRegister object.
class SimpleCashRegister
{
private:
	vector<Sale*> saleslist;
public:
	SimpleCashRegister();
	void cashRegister();
	void regularCash();
	void contractorCash();
	void regularCheck();
	void contractorCheck();
	void regularCreditCard();
	void contractorCreditCard();
	void printSales();

	// helper functions

};

#endif // SimpleCashRegister.hpp