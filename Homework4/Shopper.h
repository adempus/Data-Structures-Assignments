/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#ifndef HOMEWORK4_SHOPPER_H
#define HOMEWORK4_SHOPPER_H

#include <string>
#include <iostream>
#include <math.h>
#include "ShoppingCart.h"

using namespace std;

class Shopper {
public :
    Shopper();
    Shopper(const string&, const string&);
    void addItemToCart(const Item&, int quantity = 1);
    int getAmountOwed();
    int getNumItems();
    vector<Item>* getItems();
    string getReceipt();
    friend ostream& operator<<(ostream&, const Shopper&);

private :
    string        firstName;
    string        lastName;
    ShoppingCart      cart;
    string         receipt;
};

#endif //HOMEWORK4_SHOPPER_H