/* Jeff Morin
 * CISC 3130
 * Homework 1
 * Fall 2016
 *
 * */


#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H

using namespace std;

class Contact
{
public:
    Contact(string fname = "unknown", string lname = "unknown", string number = "unknown",
            string street = "unknown", string city = "unknown", string state = "unknown");

    string get_first_name();
    string get_last_name();
    string get_full_name();
    string get_number();
    string get_st_address();
    string get_city();
    string get_state();
    void update(string, string, string, string, string, string);
    void set_address(string, string, string);

    // overloaded operators
    friend bool operator==(const Contact& c1, const Contact& c2);
    friend bool operator!=(const Contact& c1, const Contact& c2);
    friend bool operator<(const Contact& c1, const Contact& c2);
    friend bool operator>(const Contact&, const Contact&);
    friend ostream& operator<<(ostream&, Contact&);

private:
    friend bool equals_ignore_case(string str1, string str2);
    string first_name;
    string last_name;
    string full_name;
    string number;
    string street;
    string city;
    string state;
};

#endif //CONTACT_CONTACT_H