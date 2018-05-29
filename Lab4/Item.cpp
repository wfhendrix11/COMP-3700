// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        Item.cpp
// Description: Item class implementation.
#include "Item.hpp"

// Default constructor.
Item::Item()
{
    name = "NULL";
    price = 0;
}

// Alternate constructor.
Item::Item(std::string name, double price)
{
    this->name = name;
    this->price = price;
}

// Function:     getName
// Description:  Accessor for the item's name.
std::string Item::getName()
{
    return name;
}

// Function:     getPrice
// Description:  Accessor for the item's price.
double Item::getPrice()
{
    return price;
}