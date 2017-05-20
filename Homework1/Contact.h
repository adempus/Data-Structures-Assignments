/* Jeff Morin
 * CISC 3130
 * Homework 1
 * Fall 2016
 *
 * */


#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H
#include <string>

using namespace std;

class Contact
{
public:
    Contact(string fname = "unknown", string lname = "unknown", long number = 0,
            string street = "unknown", string city = "unknown", string state = "unknown");

    string get_first_name();
    string get_last_name();
    string get_full_name();
    long get_number();
    string get_st_address();
    string get_city();
    string get_state();
    void update(string, string, long, string, string, string);
    void set_address(string, string, string);

    // overloaded operators
    friend bool operator==(const Contact& c1, const Contact& c2);
    friend bool operator!=(const Contact& c1, const Contact& c2);
    friend bool operator<(const Contact& c1, const Contact& c2);
    friend bool operator>(const Contact&, const Contact&);
    friend ostream& operator<<(ostream&, Contact&);

private:
    string  first_name;
    string  last_name;
    long    number;
    string  street;
    string  city;
    string  state;
    string number_format();
};

#endif //CONTACT_CONTACT_H