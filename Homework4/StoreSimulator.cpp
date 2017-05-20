/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include "Item.h"
#include "HardwareStore.h"

using namespace std;

// objects
HardwareStore _hardwareStore(5);
vector<Shopper> _shoppers;
stack<pair<string, string>> _shopperNames;

// functions
bool initInventory(string&);
bool initShopperNames(string&);
void initEvents(string&);
void shopperEvent(string&);
void processEvent();
void printShopperNames();
void printStoreInventory();

int main()
{
    string namesPath = "/home/adempus/Documents/School/2016-2017/Fall/CISC3130/Homework4/shopper_names.txt";
    string inventoryPath = "/home/adempus/Documents/School/2016-2017/Fall/CISC3130/Homework4/inventory.txt";
    string eventsPath = "/home/adempus/Documents/School/2016-2017/Fall/CISC3130/Homework4/events.txt";

    // To prevent errors, make sure name and inventory file dependencies are satisfied before processing events.
    if (initShopperNames(namesPath) & initInventory(inventoryPath)) {
        initEvents(eventsPath);
    }
    return 0;
}

/**
 * Parses "S" events to initialize Shoppers with Item purchases.
 * @param data  a line prefixed 'S' in the file, representing a Shopper event.
 *
 * j flags the loop for every n mod 2 == 0, comma-separated value, starting at
 * n = 2. j denotes an Item's name to be paired with its following purchase quantity.
                n =  0  1    2    3     4    5    6     7
                     S, 3, grill, 1, hammer, 3, wrench, 5
                j:          |2|       |4|        |6|

 * i accesses a vector element for every n mod 2 != 0, denoting an item's purchase quantity to pair.
 *                   S, 3, grill, 1, hammer, 3,  wrench, 5
                i:               |3|        |5|         |7
 */
void shopperEvent(string& data) {
    stringstream ss;
    ss.str(data);
    string parsedDatum;
    // a vector of the purchase item and its quantity pair.
    vector<pair<Item, int>> items;
    // parse comma delimited strings from data to initialize Item objects with.
    for (int i = 0, j = 0 ; getline(ss, parsedDatum, ',') ; j++) {
        // skipping the 'S', and on every 2nd (0 based) value effectively...
        if (parsedDatum != "S" && j % 2 == 0) {
            // initialize an Item in the pair with its name.
            items.push_back(pair<Item, int>(Item(parsedDatum), 0));
        } else if (j > 1) {  // skip the value following the 'S'
            // use i (when j % 2 != 0), to access the vector and pair an Item with its int quantity
            items[i].second = stoi(parsedDatum);
            i++;
        }
    }
    // initialize a shopper on the stack with first and last name
    _shoppers.push_back(Shopper(_shopperNames.top().first, _shopperNames.top().second));
    // add all of the parsed items of x quantity to the shopper's cart
    for (int i = 0 ; i < items.size() ; i++) {
        _shoppers.back().addItemToCart(items[i].first, items[i].second);
    }
    _hardwareStore.addShopperToLine(_shoppers.back());
    _shopperNames.pop(); // to the next shopper's name.
}

/** Starts the checkout process for shoppers in line at the hardware store. */
void processEvent() {
    _hardwareStore.checkoutAllShoppers();
    cout << "--HardwareStore: Total revenue: $"
         << _hardwareStore.getTotalRevenue() << "--" << endl;
}

/** Initializes the vector of string,string pairs with names of shoppers.
    @param path  directory to the 'shopper_names' txt file.
    @returns false if the file is not found; true otherwise.
*/
bool initShopperNames(string& path) {
    ifstream nameStream(path.c_str());
    if(nameStream.fail()) {
        cerr << "Names file not found." << endl;
        return false;
    }
    string data;
    while (getline(nameStream, data, '\n')) {
        stringstream ss;
        ss.str(data);
        pair<string, string> firstLast;
        while (ss.good()) {
            ss >> firstLast.first >> firstLast.second;
            _shopperNames.push(firstLast);
        }
    }
    return true;
}

/** Initializes the Hardware store's inventory with Items.
 * @param path  directory to the 'inventory' txt file.
 * @returns false   if the file is not found; true otherwise.
 * */
bool initInventory(string& path) {
    ifstream inventoryStream(path.c_str());
    if (inventoryStream.fail()) {
        cerr << "Inventory file not found." << endl;
        return false;
    }
    string data;
    string parsedDatum;
    string dataArr[2];
    while (getline(inventoryStream, data, '\n')) {
        stringstream ss;
        ss.str(data);
        for(int i = 0 ; getline(ss, parsedDatum, ',') ; i++) {
            dataArr[i] = parsedDatum;
        }
        Item newItem(dataArr[0], stod(dataArr[1]));
        _hardwareStore.stockInventory(newItem);
    }
    return true;
}

/** Reads a file of events to either initialize a shopper, or process a shopper in line.
 * @param path  directory to the events.txt file
 */
void initEvents(string& path) {
    ifstream eventStream(path.c_str());
    if (eventStream.fail()) {
        cerr << "File not found." << endl;
        return;
    }
    string data;
    // read each line of text from the event file.
    while (getline(eventStream, data, '\n')) {
        // if the line is prefixed 'S', initialize shopper with items
        if (data.at(0) == 'S')
            shopperEvent(data);
        else if (data.at(0) == 'P') // else process shoppers in line.
            processEvent();
    }
}

void printStoreInventory() {
    cout << endl;
    _hardwareStore.printInventory();
}