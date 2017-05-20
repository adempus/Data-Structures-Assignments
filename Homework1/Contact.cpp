/* Jeff Morin
 * CISC 3130
 * Homework 1
 * Fall 2016
 *
 * */

#include <ostream>
#include "Contact.h"

/* constructor */
Contact::Contact(string fname, string lname, long number,
                 string street, string city, string state) :
        first_name(fname), last_name(lname), number(number),
        street(street), city(city), state(state)
{ }

/* getters */
string Contact::get_first_name() {
    return first_name;
}

string Contact::get_last_name() {
    return last_name;
}

string Contact::get_full_name() {
    return first_name+" "+last_name;
}

long Contact::get_number() {
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

void Contact::update(string fname, string lname, long num,
                     string street, string city, string state)
{
    first_name = fname;
    last_name = lname;
    number = num;
    set_address(street, city, state);
}

string Contact::number_format() {
    string number_str = to_string(number);
    if((unsigned) number_str.length() >= 10) {
        number_str.insert(0, "(");
        number_str.insert(4, " ");
        number_str.insert(4, ")");
        number_str.insert(9, "-");
    }
    return number_str;
}

/* overloaded operators */
bool operator!=(const Contact& c1, const Contact& c2) {
    return (c1.last_name != c2.last_name);
}

bool operator==(const Contact& c1, const Contact& c2) {
    return (c1.first_name == c2.first_name && c1.last_name == c2.last_name);
}

bool operator<(const Contact& c1, const Contact& c2) {
    return (c1.last_name != c2.last_name ?
            c1.last_name < c2.last_name : c1.first_name < c2.first_name);
}

bool operator>(const Contact& c1, const Contact& c2) {
    return (c1.last_name != c2.last_name ?
            c1.last_name > c2.last_name : c1.first_name > c2.first_name);
}

ostream& operator<<(ostream& output, Contact& contact) {
    return output << contact.first_name << " " << contact.last_name << "\tPhone Number: " <<
           contact.number_format() << "\n" << contact.street << "\n" <<
           contact.city << ", " << contact.state << endl;
}