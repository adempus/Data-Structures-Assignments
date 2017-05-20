/**
 * Jeff Morin
 * CISC 3130
 * Homework #4
 * Fall 2016
 */

#include <sstream>
#include <iomanip>
#include "Shopper.h"

Shopper::Shopper() { }

Shopper::Shopper(const string& firstName, const string& lastName) :
        firstName(firstName), lastName(lastName),
        receipt("Shopper: "+firstName+" "+lastName) { }

/**
 * Recursively adds an item to the Shopper's cart while quantity > 1, otherwise a single item is added.
 *  @param item     a reference of item being added to cart.
 *  @param quantity    The number of times that particular item is added to cart. Default value is 1
 */
void Shopper::addItemToCart(const Item& item, int quantity) {
    cart.addItem(item);
    if (quantity > 1) addItemToCart(item, quantity-1);
}

/** Calculates the total amount of money owed by the shopper.
 *  @returns the int amount of money owed in cents by the shopper.
 * */
int Shopper::getAmountOwed() {
    double taxRate = 8.875 / 100;
    double dollarAmt = round((cart.grandTotal() + (cart.grandTotal() * taxRate)));
    int centAmount = (int) (dollarAmt * 100);
    return centAmount;
}

/** @returns the number of items in the shopper's cart. */
int Shopper::getNumItems() {
    return cart.numItems();
}

/** @returns a pointer to a vector of Items in the Shopper's cart.
 *           A pointer is needed to access the Item object stored in the
 *           ShoppingCart object, of the shopper; and initialize its price at checkout.
 */
vector<Item>* Shopper::getItems() {
    return &cart.getItems();
}

/** @returns a string log of the shopper's transaction. */
string Shopper::getReceipt() {
    // a stringstream is needed to set the precision of the double value price,
    // to x.xx in a string for proper display.
    stringstream taxStr, totalStr;

    receipt.append("\n---------------------");
    for (int i = 0 ; i < cart.getItems().size() ; i++) {
        stringstream itemPriceStr;
        itemPriceStr << fixed << setprecision(2) << cart.getItems()[i].getPrice();
        receipt.append("\n"+cart.getItems()[i].getName()+"  - \t$"+itemPriceStr.str());
    }
    taxStr << fixed << setprecision(2) << (getAmountOwed()/100)-cart.grandTotal();
    totalStr << fixed << setprecision(2) << ((double) getAmountOwed()/100);
    receipt.append("\n\nTax: \t$"+taxStr.str());
    receipt.append("\nTotal:\t$"+totalStr.str()+
                           "\n\t------------");
    return receipt;
}

ostream& operator<<(ostream& os, const Shopper& shopper) {
    Shopper s = shopper;
    os << shopper.firstName << " " << shopper.lastName
       << " Num items: " << s.getNumItems();
    return os;
}