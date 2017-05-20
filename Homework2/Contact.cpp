/* Jeff Morin
 * CISC 3130
 * Homework 1
 * Fall 2016
 *
 * */

#include <ostream>
#include <algorithm>
#include "Contact.h"

/* constructor */
Contact::Contact(string fname, string lname, string number,
                 string street, string city, string state) :
        first_name(fname), last_name(lname), number(number),
        street(street), city(city), state(state),
        full_name(first_name+" "+last_name)
{ }

/* getters */
string Contact::get_first_name() {
    return first_name;
}

string Contact::get_last_name() {
    return last_name;
}

string Contact::get_full_name() {
    return full_name;
}

string Contact::get_number() {
    return number;
}

string Contact::get_st_address() {
    return street;
}

string Contact::get_city() {
    return city;
}

string Contact::get_state() {
    return state;
}

void Contact::set_address(string street, string city, string state) {
    this->street = street;
    this->city = city;
    this->state = state;
}

void Contact::update(string fname, string lname, string num,
                     string street, string city, string state)
{
    first_name = fname;
    last_name = lname;
    number = num;
    full_name = first_name+" "+last_name;
    set_address(street, city, state);
}

bool equals_ignore_case(string str1, string str2) {
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    return str1 == str2;
}

/* overloaded operators */
bool operator!=(const Contact& c1, const Contact& c2) {
    return !equals_ignore_case(c1.last_name, c2.last_name);
}

bool operator==(const Contact& c1, const Contact& c2) {
    return equals_ignore_case(c1.full_name, c2.full_name);
}

bool operator<(const Contact& c1, const Contact& c2) {
    return !equals_ignore_case(c1.last_name, c2.last_name) ?
            c1.last_name < c2.last_name : c1.first_name < c2.first_name;
}

bool operator>(const Contact& c1, const Contact& c2) {
    return !equals_ignore_case(c1.last_name, c2.last_name) ?
            c1.last_name > c2.last_name : c1.first_name > c2.first_name;
}

ostream& operator<<(ostream& output, Contact& contact) {
    return output << contact.first_name << " " << contact.last_name << "\tPhone Number: " <<
           contact.number << "\n" << contact.street << "\n" <<
           contact.city << ", " << contact.state << endl;
}