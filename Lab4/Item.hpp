// Lab 4:       Simple Cash Register Application with 
//              Inheritance and Vitual Functions
// File:        Item.hpp
// Description: Item class abstraction.
#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>

class Item
{
private:
    std::string name;   
    double price;       
public:
    Item();
    Item(std::string name, double price);
    std::string getName();
    double getPrice();
};

#endif /* Item_hpp */