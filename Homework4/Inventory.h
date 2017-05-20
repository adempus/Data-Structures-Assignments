/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#ifndef HOMEWORK4_INVENTORY_H
#define HOMEWORK4_INVENTORY_H

#include <string>
#include <map>
#include <vector>
#include "Item.h"

using namespace std;

class Inventory {
public :
    Inventory() { }
    Inventory(vector<Item>&);
    double queryItemPrice(const string&);
    void stockItem(Item);
    const map<string, double>& getItems();
    int numItems();

private :
    // A map to query the Item's price.
    // The string is the Item's name to key for it's price double value.
    map<string, double> stockedItems;
};

#endif //HOMEWORK4_INVENTORY_H