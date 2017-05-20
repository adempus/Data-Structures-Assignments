/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() { }

/** Adds an item to the shopping cart.
 * @param item     The item being added to the cart.
 */
void ShoppingCart::addItem(const Item& item) {
    itemsVector.push_back(item);
}

/** Removes an item from the cart.
 * @param item: the item to remove from cart. If cart
 *      contains no such item, then it remains unchanged.
 */
void ShoppingCart::removeItem(const Item& item) {
    // an iterator is needed to delete an element in a vector.
    vector<Item>::iterator it;
    for (it = itemsVector.begin() ; it != itemsVector.end() ; it++) {
        if (*it == item) itemsVector.erase(it);
    }
}

/** @returns: the vector of items in the cart. */
vector<Item>& ShoppingCart::getItems() {
    return itemsVector;
}

/** Calculates a sum of the items prices.
 *  @returns total  A sum of all the items.
 */
double ShoppingCart::grandTotal() {
    double total = 0.00;
    for (int i = 0 ; i < itemsVector.size() ; i++) {
        total += itemsVector[i].getPrice();
    }
    return total;
}

/** @returns the number of items in the cart. */
int ShoppingCart::numItems() {
    return (unsigned) itemsVector.size();
}

ostream& operator<<(ostream& os, ShoppingCart& sc) {
    ShoppingCart cart = sc;
    for (int i = 0 ; i < cart.numItems() ; i++) {
        os << cart.itemsVector[i] << endl;
    }
    return os;
}