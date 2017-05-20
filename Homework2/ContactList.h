/* Jeff Morin
 * CISC 3130
 * Homework #2
 * Fall 2016
 *
 * */


#ifndef HOMEWORK2_CONTACTLIST_H
#define HOMEWORK2_CONTACTLIST_H

#include <vector>
#include "Contact.h"
#include <algorithm>
#include <iostream>
#include "Contact.h"
#include "ContactList.h"

using namespace std;

class ContactList
{
public:
    ContactList();

    /* used a function template here utilizing a 'size_t' data type
       to guarantee array size every time. This makes it so that the
       user may simply pass the array as an argument.
    */
    template <size_t length>
    ContactList(Contact (&contact_arr)[length]) :
            contact_vector(contact_arr, &contact_arr[length]) { }

    //operations
    Contact& search_last_name(string& last_name);
    Contact& search_number(string& number);
    vector<Contact> search_lname_letter(char letter);
    vector<Contact> search_by_city(string& city);
    void add_contact(Contact& new_contact);
    int size();

    // operator overloads
    Contact& operator[](int index);
    friend ostream& operator<<(ostream&, ContactList&);

private:
    Contact         found_contact;
    vector<Contact> contact_vector;

    // helpers
    bool is_same_number(string& num1, string& num2);
    bool equals_ignore_case(string& str1, string& str2);

};

#endif //HOMEWORK2_CONTACTLIST_H