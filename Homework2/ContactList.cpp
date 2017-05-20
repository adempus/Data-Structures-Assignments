/* Jeff Morin
 * CISC 3130
 * Homework #2
 * Fall 2016
 * */

#include <algorithm>
#include <iostream>
#include "Contact.h"
#include "ContactList.h"

ContactList::ContactList() : contact_vector(0) { }

// search for last names
Contact& ContactList::search_last_name(string& key) {
    for(int i = 0 ; i < contact_vector.size() ; i++) {
        string lname = contact_vector[i].get_last_name();
        if(equals_ignore_case(key, lname)) {
            found_contact = contact_vector[i];
            break;
        }
    }
    return found_contact;
}

// search for a number
Contact& ContactList::search_number(string& key) {
    for(int i = 0 ; i < contact_vector.size() ; i++) {
        string number = contact_vector[i].get_number();
        if(is_same_number(key, number)) {
            found_contact = contact_vector[i];
            break;
        }
    }
    return found_contact;
}

// search last names by first character
vector<Contact> ContactList::search_lname_letter(char letter) {
    vector<Contact> lname_vector;
    for(int i = 0 ; i < contact_vector.size() ; i++) {
        if(tolower(contact_vector[i].get_last_name().at(0)) == tolower(letter))
            lname_vector.push_back(contact_vector[i]);
    }
    return lname_vector;
}

// search for cities
vector<Contact> ContactList::search_by_city(string& key) {
    vector<Contact> city_vector;
    for(int i = 0 ; i < contact_vector.size() ; i++) {
        string city = contact_vector[i].get_city();
        if(equals_ignore_case(key, city))
            city_vector.push_back(contact_vector[i]);
    }
    return city_vector;
}

//add a contact
void ContactList::add_contact(Contact& contact) {
    string num1 = contact.get_number();
    for(int i = 0 ; i < contact_vector.size() ; i++) {
        string num2 = contact_vector[i].get_number();
        if(contact == contact_vector[i] || is_same_number(num1, num2)) {
            cerr << "Contact already exists. " << endl;
            return;
        }
    }
    contact_vector.push_back(contact);
}

int ContactList::size() {
    return (signed) contact_vector.size();
}

/** Helper function to remove symbols from phone numbers for clean comparisons */
bool ContactList::is_same_number(string& num1, string& num2) {
    char tokens[] = {'(', ')', '-', ' '};
    for(int i = 0 ; i < 4 ; i++) {
        num1.erase(remove(num1.begin(), num1.end(), tokens[i]), num1.end());
        num2.erase(remove(num2.begin(), num2.end(), tokens[i]), num2.end());
    }
    return num1 == num2;
}

/** Helper function that returns true for two strings
 *  having the same length and sequence of characters regardless of case. */
bool ContactList::equals_ignore_case(string& str1, string& str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 == str2;
}

Contact& ContactList::operator[](int index) {
    if (index < 0 || index > contact_vector.size())
        throw std::runtime_error("contact list index out of bounds.");
    return contact_vector[index];
}

ostream& operator <<(ostream& output, ContactList& cl) {
    for(int i = 0 ; i < cl.size() ; i++)
        output << cl[i] << endl;
    return output;
}