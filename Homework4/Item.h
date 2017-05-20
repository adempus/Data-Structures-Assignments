/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#ifndef HOMEWORK4_ITEM_H
#define HOMEWORK4_ITEM_H

#include <string>
#include <iostream>
using namespace std;

class Item {
public :
    Item() { }

    Item(const string& name, double price) :
        itemName(name), itemPrice(price) { }

    Item(const string& name) :
            itemName(name) { }

    Item(double price) :
            itemPrice(price) { }

    const string getName() { return itemName; }
    double getPrice() { return itemPrice; }
    void setPrice(double price) { itemPrice = price; }

private :
    string  itemName;
    double  itemPrice;

    /** operator overloads for scalability sake. */

    /** Compares the prices of two items
     * @returns true if item1 costs more money than item2, false otherwise. */
    friend bool operator>(const Item& item1, const Item& item2) {
        return item1.itemPrice > item2.itemPrice;
    }

    /** Compares the prices of two items
     * @returns true   if item1 costs less money than item2, false otherwise. */
    friend bool operator<(const Item& item1, const Item& item2) {
        return item1.itemPrice < item2.itemPrice;
    }

    /** Compares two items to see if they're the same.
     * @returns true   if item1 and item2 are of the same name and price. */
    friend bool operator==(const Item& item1, const Item& item2) {
        return item1.itemName == item2.itemName && item1.itemPrice == item2.itemPrice;
    }

    friend ostream& operator<<(ostream& os, const Item& item) {
        Item item1 = item;
        os << item1.getName() << " -- " << item1.getPrice();
        return os;
    }
};

#endif //HOMEWORK4_ITEM_H