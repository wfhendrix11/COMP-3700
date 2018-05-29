// Lab 4:		Simple Cash Register Application with 
//				Inheritance and Vitual Functions
// File:	    SimpleCashRegister.cpp
// Description:	SimpleCashRegister class implementation.

#include <iostream>
#include <vector>

#include "SimpleCashRegister.hpp"

// default constructor
SimpleCashRegister::SimpleCashRegister()
{

}

// operates the program
void SimpleCashRegister::cashRegister()
{
    char choiceChar;

    // cout number formatting...
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // display header and menu until quit is selected...
    do
    {   
        // print start welcome banner
        cout << endl;
        cout << "             ====================================================================" << endl;
        cout << "             |                      Welcome to Tiger Store!                     |" << endl;
        cout << "             ====================================================================" << endl;
        cout << endl;

    	// print menu options 
    	cout << "Select an option: (1) Regular Cash, (2) Regular Check, (3) Regular Credit Card, (4)" << endl;
      	cout << "Contract Cash, (5) Contract Check, (6) Contract Credit Card, (7) Print all Sales, or (8)" << endl;
      	cout << "Quit: ";
 		
 		// read in user choice
 		int userChoice;
      	cin >> userChoice;

      	// convert int to char
      	choiceChar = '0' + userChoice;
        
      	switch (choiceChar)
      	{
         	case '1':
         		// Regular Cash
                cout << endl;
                regularCash();
            	break;
         	case '2':
            	// Regular Check 
                cout << endl;
                regularCheck();
            	break;
         	case '3':
            	// Regular Credit Card 
                cout << endl;
                regularCreditCard();
            	break;
         	case '4':
            	// Contract Cash
                cout << endl;
                contractorCash();
            	break;
         	case '5':
            	// Contract checkl
                cout << endl;
                contractorCheck();
            	break;
         	case '6':
            	// Contract Credit Card 
                cout << endl;
                contractorCreditCard();
            	break;
         	case '7':
            	// Print all sales
                cout << endl;
                printSales();
            	break;
         	case '8':
            	// Quit
            	break;
         	default:
         		cout << endl;
            	cout << "Invalid input! Please try again!" << endl;
            	cout << endl;
           	 	break;
      	}
      
   	} while (choiceChar != '8');
}

// regular cash 
void SimpleCashRegister::regularCash()
{
    // crate new RegularCash object 
    RegularCash* rc = new RegularCash;

    // read in all the items...
    double subtotal = 0.0;
    string line;
    while (getline(cin, line)) 
    {   
        // get Item name
        string itemName;
        cout << "Enter item: ";
        getline(cin, itemName);
        cout << endl;

        if (itemName == "*")
        {
            break;
        } 

        // get Item price 
        double price;
        cout << "Enter amount: $ ";
        cin >> price;
        cout << endl;

        subtotal += price;

        // create new item
        rc->addItem(Item(itemName, price));   
    }

    rc->setSubTotal(subtotal);
    cout << "Sub-Total: $ " << subtotal << endl;

    // calculate total amount after tax
    rc->process_sale();

    // process the payment
    rc->process_payment();

    // add to the list of sales
    saleslist.push_back(rc);
}

void SimpleCashRegister::contractorCash()
{
    // create new contractor cash object
    ContractorCash* cc = new ContractorCash();

    // read in all the items...
    double subtotal = 0.0;
    string line;
    while (getline(cin, line)) 
    {   
        // get Item name
        string itemName;
        cout << "Enter item: ";
        getline(cin, itemName);
        cout << endl;

        if (itemName == "*")
        {
            break;
        } 

        // get Item price 
        double price;
        cout << "Enter amount: $ ";
        cin >> price;
        cout << endl;

        subtotal += price;

        // create new item
        cc->addItem(Item(itemName, price));   
    }

    cc->setTotalAmount(subtotal);
    cout << "Sub-Total: $ " << subtotal << endl;

    // calculate total amount after tax
    cc->process_sale();

    // process pament
    cc->process_payment();

    // add to the list of sales
    saleslist.push_back(cc);
}

void SimpleCashRegister::regularCheck()
{   
    // create a new regular check object 
    RegularCheck* rchk = new RegularCheck();

    // read in all the items...
    double subtotal = 0.0;
    string line;
    while (getline(cin, line)) 
    {   
        // get Item name
        string itemName;
        cout << "Enter item: ";
        getline(cin, itemName);
        cout << endl;

        if (itemName == "*")
        {
            break;
        } 

        // get Item price 
        double price;
        cout << "Enter amount: $ ";
        cin >> price;
        cout << endl;

        subtotal += price;

        // create new item
        rchk->addItem(Item(itemName, price));   
    }

    rchk->setSubTotal(subtotal);
    cout << "Sub-Total: $ " << subtotal << endl;

    // process the sale
    rchk->process_sale();

    // process the payment
    rchk->process_payment(); 

    // add to the list of sales
    saleslist.push_back(rchk);
}

void SimpleCashRegister::contractorCheck()
{   
    // create a new regular check object 
    ContractorCheck* cchk = new ContractorCheck();

    // read in all the items...
    double subtotal = 0.0;
    string line;
    while (getline(cin, line)) 
    {   
        // get Item name
        string itemName;
        cout << "Enter item: ";
        getline(cin, itemName);
        cout << endl;

        if (itemName == "*")
        {
            break;
        } 

        // get Item price 
        double price;
        cout << "Enter amount: $ ";
        cin >> price;
        cout << endl;

        subtotal += price;

        // create new item
        cchk->addItem(Item(itemName, price));   
    }

    cchk->setTotalAmount(subtotal);
    cout << "Sub-Total: $ " << subtotal << endl;

    // process the sale
    cchk->process_sale();

    // process the payment
    cchk->process_payment(); 

    // add to the list of sales
    saleslist.push_back(cchk);
}

void SimpleCashRegister::regularCreditCard()
{
    // create a new regular credit card object
    RegularCreditCard* rcc = new RegularCreditCard();

    // read in all the items...
    double subtotal = 0.0;
    string line;
    while (getline(cin, line)) 
    {   
        // get Item name
        string itemName;
        cout << "Enter item: ";
        getline(cin, itemName);
        cout << endl;

        if (itemName == "*")
        {
            break;
        } 

        // get Item price 
        double price;
        cout << "Enter amount: $ ";
        cin >> price;
        cout << endl;

        subtotal += price;

        // create new item
        rcc->addItem(Item(itemName, price));   
    }

    rcc->setSubTotal(subtotal);
    cout << "Sub-Total: $ " << subtotal << endl;

    // process the sale
    rcc->process_sale();

    // process the payment
    rcc->process_payment(); 

    // add to the list of sales
    saleslist.push_back(rcc);


}

void SimpleCashRegister::contractorCreditCard()
{
    // create a new regular credit card object
    ContractorCreditCard* ccc = new ContractorCreditCard();

    // read in all the items...
    double subtotal = 0.0;
    string line;
    while (getline(cin, line)) 
    {   
        // get Item name
        string itemName;
        cout << "Enter item: "; 
        getline(cin, itemName);
        cout << endl;

        if (itemName == "*")
        {
            break;
        } 

        // get Item price 
        double price;
        cout << "Enter amount: $ ";
        cin >> price;
        cout << endl;

        subtotal += price;

        // create new item
        ccc->addItem(Item(itemName, price));   
    }

    ccc->setTotalAmount(subtotal);
    cout << "Sub-Total: $ " << subtotal << endl;

    // process the sale
    ccc->process_sale();

    // process the payment
    ccc->process_payment(); 

    // add to the list of sales
    saleslist.push_back(ccc);
}

void SimpleCashRegister::printSales()
{
    // for each Sale in saleslist
    for (int i = 0; i < saleslist.size() ; i++)
    {
        cout << "Sale #" << i + 1 << endl;
        saleslist[i]->print_sale();
        cout << endl;
    }

}