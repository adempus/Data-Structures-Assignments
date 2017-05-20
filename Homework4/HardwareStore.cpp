/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#include "HardwareStore.h"

HardwareStore::HardwareStore() { }

/** @param   an integer of registers available at the hardware store. */
HardwareStore::HardwareStore(int numRegisters) :
        registerVector((unsigned) numRegisters) {
}

/** Adds a shopper to the shortest queue of shoppers in line at available registers.
 *  @param shopper  a shopper to be added to the shortest line. */
void HardwareStore::addShopperToLine(const Shopper& shopper) {
    registerVector[getShortestQueueIndex()].push(shopper);
}

/** Processes the longest queue of shoppers. */
void HardwareStore::processShopper() {
    while (!registerVector[getLongestQueueIndex()].empty()) {
        pointOfSaleProcess(getLongestQueueIndex());
    }
}

/** Processes all shoppers still on queue in the vector. */
void HardwareStore::checkoutAllShoppers() {
    for (int i = 0 ; i < registerVector.size() ; i++) {
        // check if i is the index of the largest queue in the vector.
        if(i == getLongestQueueIndex()) {
            // if so, call processShopper() to process that queue.
            processShopper();
        } else {
            while (!registerVector[i].empty()) {
                pointOfSaleProcess(i);
            }
        }
    }
}

/** Checks out a shopper at the front of a line.
 *  @param index    the index of the shopper.*/
void HardwareStore::pointOfSaleProcess(int index) {
    // Create a pointer to the items of the first shopper in line to assign their prices.
    vector<Item> *purchases = registerVector[index].front().getItems();
    // loop through each item to specify a price for it.
    for(unsigned int i = 0 ; i < purchases->size() ; i++) {
        // get a reference to the shopper's items to dynamically assign their prices.
        Item &item = purchases->at(i);
        // here we query the inventory for the item to give it a price.
        item.setPrice(inventory.queryItemPrice(item.getName()));
    }
    // update the store's profits.
    adjustRevenue(registerVector[index].front().getAmountOwed());
    cout << "\n" << registerVector[index].front().getReceipt() << endl;
    registerVector[index].pop(); // thank you, come again!
}

/** @returns the index of an empty queue in the register vector.*/
int HardwareStore::getAvailEmpty() {
    return emptyLineIndex();
}

/** A visual of the shopping lines. */
void HardwareStore::printShoppingLines() {
    queue<Shopper> tempQueue;
    for (int i = 0 ; i < registerVector.size() ; i++) {
        tempQueue = registerVector[i];
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " | ";
            tempQueue.pop();
        }
        cout << endl;
    }
}

/** Inserts an item in the store's inventory.
 * @param item - the item to be added to the inventory.*/
void HardwareStore::stockInventory(Item& item) {
    inventory.stockItem(item);
}

/** @returns The index to an empty queue in registerVector of shoppers.
 *           The size is returned if there are no empty queues. */
int HardwareStore::emptyLineIndex() {
    for (int i = 0 ; i < registerVector.size() ; i++) {
        if (registerVector[i].empty()) return i;
    }
    return (unsigned) registerVector.size();
}

/** Updates the total amount of money made by the hardware store.
 *  @param amount   the amount of money being added to the store's revenue. */
void HardwareStore::adjustRevenue(int amount) {
    revenue += (amount / 100);
}

/** @returns total amount of money made by the hardware store. */
double HardwareStore::getTotalRevenue() {
    return revenue;
}

/** @returns The index of the largest shopper queue in 'registerVector'. */
int HardwareStore::getLongestQueueIndex() {
    int longestIndex = 0;
    // store the size of the 0th queue in the register to start comparisons.
    int lineSize = (unsigned) registerVector[0].size();
    // Loop through registerVector to find index of the longest queue.
    for (int i = 0 ; i < registerVector.size() ; i++) {
        if (lineSize < registerVector[i].size()) {
            lineSize = (unsigned) registerVector[i].size();
            longestIndex = i;
        }
    }
    return longestIndex;
}

/** @returns an index to the shortest queue in the register vector. */
int HardwareStore::getShortestQueueIndex() {
    // get the least amount of shoppers from the first line.
    int shortestValue = (unsigned) registerVector[0].size();
    int shortestIndex = 0;
    // Check through each line to find the one with the least amount of shoppers (the smallest sized queue).
    for(int i = 0 ; i < registerVector.size() ; i++) {
        // if the current shortest line's size is greater than the next line's size,
        if(shortestValue > registerVector[i].size()) {
            // reassign the current shortest line with the newest shortest line value.
            shortestValue = (unsigned) registerVector[i].size();
            // store the index of the registerVector containing the shortest line.
            shortestIndex = i;
        }
    }
    return shortestIndex;
}

void HardwareStore::printInventory() {
    cout << inventory.numItems() << " items:" <<endl;
    map<string, double>::const_iterator it = inventory.getItems().begin();
    for ( ; it != inventory.getItems().end() ; it++) {
        cout << it->first << " " << it->second << endl;
    }
}