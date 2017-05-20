/* Jeff Morin
 * CISC 3130
 * Homework #2
 * Fall 2016
 *
 * */

#include <iostream>
#include <fstream>
#include <sstream>
#include "ContactList.h"

using namespace std;

void read_data();
void test_search_lname(ContactList&);
void test_search_lname_char(ContactList&);
void test_search_by_city(ContactList&);
void test_search_number(ContactList&);
void test_add_contact(ContactList&);
void test_size(ContactList&);
void print_contact_list(ContactList&);

Contact contacts_array[1000]; // Array to be passed in ContactList ctor.

int main() {
    read_data();
    ContactList contact_list(contacts_array);
    //unit tests
    test_search_lname(contact_list);
    test_search_number(contact_list);
    test_search_lname_char(contact_list);
    test_search_by_city(contact_list);
    test_add_contact(contact_list);
    test_size(contact_list);
    print_contact_list(contact_list);

    return 0;
}

void test_search_lname(ContactList& cl) {
    cout << "----\nTesting search by last name..." << endl;
    string lname_array[] = {
            "West", "Howard", "Clark",
            "Johnson", "Martinez", "Grant"
    };
    for(int i = 0 ; i < 6 ; i++) {
        cout << "Result for last name: " << lname_array[i] << endl;
        cout << cl.search_last_name(lname_array[i]) << endl;
    }
}

void test_search_number(ContactList& cl) {
    cout << "----\nTesting search by phone number..." << endl;
    string phone_num_arr[] = {
            "518-862-8806", "(413)724-7892",
            "9154647058", "(717) 728-5491",
            "(402) 136 1205", "615 122 8447"
    };
    for(int i = 0 ; i < 6 ; i++) {
        cout << "Result for number: " << phone_num_arr[i] << endl;
        cout << cl.search_number(phone_num_arr[i]) << endl;
    }
}

void test_search_lname_char(ContactList& cl) {
    cout << "----\nTesting search by first char of last name..." << endl;
    for(char key = 'a' ; key <= 'z' ; key++) {
        cout << "\nResults for '" << (char) toupper(key) << "':" << endl;
        vector<Contact> matches = cl.search_lname_letter(key);
        for(int i = 0 ; i < matches.size() ; i++)
            cout << matches[i].get_full_name() << endl;
    }
}

void test_search_by_city(ContactList& cl) {
    vector<Contact> matches;
    cout << "----\nTesting search by city..." << endl;
    string nyc = "New York City";
    string chi = "chicago";
    string la = "los angeles";

    cout << "Results for contacts in New York City: " << endl;
    matches = cl.search_by_city(nyc);
    for(int i = 0 ; i < matches.size() ; i++)
        cout << matches[i] << endl;

    cout << "\nResults for contacts in Chicago: " << endl;
    matches = cl.search_by_city(chi);
    for(int i = 0 ; i < matches.size() ; i++)
        cout << matches[i] << endl;

    cout << "\nResults for contacts in Los Angeles:" << endl;
    matches = cl.search_by_city(la);
    for(int i = 0 ; i < matches.size() ; i++)
        cout << matches[i] << endl;
}

void test_add_contact(ContactList& cl) {
    cout << "----\nTesting add contact..." << endl;
    Contact contact1("Jane", "Doe", "(718)910-1112",
                     "222 Broadway ave", "Manhattan", "NY");
    Contact contact2("Gayle", "West", "(123)456-7891",
                     "123 Sesame st", "Los Angeles", "CA");

    cout << "adding contact1:\n" << contact1 << endl;
    cout << "adding contact2: \n" << contact2 << endl;

    cl.add_contact(contact1);
    cl.add_contact(contact2);

    cout << "New contact list size: " << cl.size() << endl;
}

void test_size(ContactList& cl) {
    cout << "----\nTesting contact list size..." << endl;
    cout << "There are " << cl.size() << " contacts stored." << endl;
}


void print_contact_list(ContactList& cl) {
    cout << "----\nTesting contact list print..." << endl;
    cout << cl << endl;
}

/** Reads a text file of contact dummy data. */
void read_data()
{
    ifstream input_file("/home/adempus/Documents/School/2016-2017/Fall/CISC3130/Homework2/data.txt");
    if(input_file.fail()) {
        cerr << "File not found." << endl;
        return;
    }
    string data;
    string parsed_datum;
    string data_array[6];
    const char delimiter = ',';
    int contacts_arr_index = 0;
    while(getline(input_file, data, '\n')) {
        stringstream ss;
        ss.str(data);
        for(int i = 0 ; getline(ss, parsed_datum, delimiter) ; i++) {
            data_array[i] = parsed_datum;
        }
        contacts_array[contacts_arr_index] = Contact(
                data_array[0], data_array[1], data_array[2],
                data_array[3], data_array[4], data_array[5]);
        contacts_arr_index++;
    }
    input_file.close();
}