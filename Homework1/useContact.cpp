/* Jeff Morin
 * CISC 3130
 * Homework 1
 * Fall 2016
 *
 * */


#include <iostream>
#include "Contact.h"

using namespace std;

/* prototypes */
void test_get_first_name();
void test_get_last_name();
void test_get_full_name();
void test_lex_order(Contact, Contact);
void test_compare(Contact, Contact);
void test_get_number();
void test_get_street();
void test_get_city();
void test_get_state();
void test_update();
void test_stream();

/* contacts as globals */
Contact contact1("John", "Doe");
Contact contact2("Jeff", "Morin", 7187654321);
Contact contact3("Jane", "Doe", 7189101112, "222 Broadway ave", "Manhattan", "NY");
Contact contact4("Gayle", "West", 1234567891, "123 Sesame st", "Los Angeles", "CA");

/* array for referencing each contact */
Contact *contact_array[] = { &contact1, &contact2, &contact3, &contact4 };

int main() {
    test_get_first_name();
    test_get_last_name();
    test_get_full_name();
    test_lex_order(contact1, contact2);
    test_lex_order(contact1, contact3);
    test_compare(contact1, contact2);
    test_compare(contact1, Contact("John", "Doe"));
    test_get_number();
    test_get_street();
    test_get_city();
    test_get_state();
    test_update();
    test_stream();
}

void test_get_first_name() {
    cout << "Testing first names...\n";
    for(int i = 0 ; i < 4 ; i++) {
        cout << "Contact" << i+1 << ": " <<
                contact_array[i]->get_first_name() << endl;
    }
}

void test_get_last_name() {
    cout << "\nTesting last names..." << endl;
    for(int i= 0 ; i < 4 ; i++) {
        cout << "Contact" << i+1 << ": " <<
                contact_array[i]->get_last_name() << endl;
    }
}

void test_get_full_name() {
    cout << "\nTesting full names..." << endl;
    for(int i= 0 ; i < 4 ; i++) {
        cout << "Contact" << i+1 << ": " <<
        contact_array[i]->get_full_name() << endl;
    }
}

void test_get_number() {
    cout << "\nTesting numbers..." << endl;
    for(int i= 0 ; i < 4 ; i++) {
        cout << "Contact" << i+1 << ": " <<
        contact_array[i]->get_number() << endl;
    }
}

void test_get_street() {
    cout << "\nTesting streets..." << endl;
    for(int i= 0 ; i < 4 ; i++) {
        cout << "Contact" << i+1 << ": " <<
        contact_array[i]->get_st_address() << endl;
    }
}

void test_get_city() {
    cout << "\nTesting cities..." << endl;
    for(int i= 0 ; i < 4 ; i++) {
        cout << "Contact" << i+1 << ": " <<
        contact_array[i]->get_city() << endl;
    }
}

void test_get_state() {
    cout << "\nTesting states..." << endl;
    for(int i= 0 ; i < 4 ; i++) {
        cout << "Contact" << i+1 << ": " <<
        contact_array[i]->get_state() << endl;
    }
}

void test_update() {
    cout << "\nTesting update..." << endl;
    // update contact 1
    cout << "Contact 1 pre-update: \n" << contact1 << endl;
    contact1.update(contact1.get_first_name(),
                    contact1.get_last_name(),
                    9546274780, "616 SE 2nd Street",
                    "Deerfield Beach", "FL");
    cout << "Contact 1 post-update: \n" << contact1 << endl;

    // update contact 2
    cout << "Contact 2 pre-update: \n" << contact2 << endl;
    contact2.update(contact2.get_first_name(),
                    contact2.get_last_name(),
                    contact2.get_number(),
                    "2551 Aragon Blvd", "Sunrise", "FL");
    cout << "Contact 2 post-update: \n" << contact2 << endl;
}

void test_compare(Contact c1, Contact c2) {
    cout << "\nTesting equality... " << endl;

    cout << c1.get_full_name() << " == " << c2.get_full_name()
        << " = " << (c1 == c2 ? "true" : "false") << endl;

    cout << c1.get_full_name() << " != " << c2.get_full_name()
        << " = " << (c1 != c2 ? "true" : "false") << endl;
}

void test_lex_order(Contact c1, Contact c2) {
    cout << "\nTesting lexicographic order (last names)... " << endl;
    cout << c1.get_full_name() << " > " << c2.get_full_name();
    cout << " = " << (c1 > c2 ? "true" : "false") << endl;

    cout << c1.get_full_name() << " < " << c2.get_full_name();
    cout << " = " << (c1 < c2 ? "true" : "false") << endl;
}

void test_stream() {
    cout << "\nTesting inline output functions..." << endl;
    for(int i = 0 ; i < 4 ; i++) {
        cout << "Contact " << i+1 << endl;
        cout << *contact_array[i] << endl;
    }
}