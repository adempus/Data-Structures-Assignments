/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#include "Inventory.h"

Inventory::Inventory(vector<Item> &stockVector) {
    vector<Item>::iterator item = stockVector.begin();
    while (item != stockVector.end()) {
        stockedItems.insert(
                pair<string, double>(item->getName(), item->getPrice()));
    }
}

/** Searches an item by name to return its price when rung up at the register.
 * @param key   a string containing the name of an item to find the price for.
 * @returns     the price (a double) of the item if it is found. Otherwise 0.00
 *              is returned.
 */
double Inventory::queryItemPrice(const string& key) {
    map<string, double>::const_iterator val = stockedItems.find(key);
    return (val != stockedItems.end() ? val->second : 0.00);
}

/** Adds an item to the inventory.
 * @param item  The item to add into the inventory. */
void Inventory::stockItem(Item item) {
    stockedItems.insert(
            pair<string, double>(item.getName(), item.getPrice()));
}

/** @returns a map of the inventory's items. */
const map<string, double>& Inventory::getItems() {
    return stockedItems;
}

/** @returns the number of varieties of Items stocked at the store.*/
int Inventory::numItems() {
    return (unsigned) stockedItems.size();
}