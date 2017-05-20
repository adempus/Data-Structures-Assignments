/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#ifndef HOMEWORK4_HARDWARESTORE_H
#define HOMEWORK4_HARDWARESTORE_H

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "Item.h"
#include "Shopper.h"
#include "Inventory.h"

class HardwareStore {
public :
    HardwareStore();
    HardwareStore(int);
    void addShopperToLine(const Shopper&);
    void processShopper();
    void checkoutAllShoppers();
    int getAvailEmpty();
    void printShoppingLines();
    void printInventory();
    double getTotalRevenue();
    void stockInventory(Item&);

private :
    double                  revenue;
    Inventory               inventory;
    vector<queue<Shopper>>  registerVector;

    int emptyLineIndex();
    void adjustRevenue(int);
    int getLongestQueueIndex();
    int getShortestQueueIndex();
    void pointOfSaleProcess(int);
};

#endif //HOMEWORK4_HARDWARESTORE_H