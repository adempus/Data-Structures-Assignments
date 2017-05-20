/**
 * Jeff Morin
 * CISC 3130
 * Fall 2016
 * Homework #4
 */

#ifndef HOMEWORK4_SHOPPINGCART_H
#define HOMEWORK4_SHOPPINGCART_H

#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class ShoppingCart {
public :
    ShoppingCart();
    void addItem(const Item&);
    void removeItem(const Item&);
    double grandTotal();
    int numItems();
    vector<Item>& getItems();
    friend ostream& operator<<(ostream&, ShoppingCart&);

private :
    vector<Item> itemsVector;
};

#endif //HOMEWORK4_SHOPPINGCART_H