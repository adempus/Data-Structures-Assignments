/**
 * @author: Jeff Morin
 * CISC 3130
 * Homework #3
 * Fall 2016
 *
 */

#include <iostream>
#include <thread>
#include "Dictionary.h"

using namespace std;

void test_prefix_search(Dictionary&);
void test_suffix_search(Dictionary&);
void test_startWith_char(Dictionary&);
void test_endWith_char(Dictionary&);
void test_add_word(Dictionary&);
void test_contains_word(Dictionary&);
void test_update_word(Dictionary&);
void test_output_stream(Dictionary&);
void test_eq_operator(Dictionary&, Dictionary&);

int main() {
    cout << "Enter a file path: "<< endl;
    string filePath;
    cin >> filePath;
    Dictionary d1(filePath), d2(filePath);

    // Due to the large number of elements to process, using a thread object to sort the elements
    // concurrently speeds up the process, and makes them readily available for comparisons.
    std::thread d1Sort(&Dictionary::sortDictionary, &d1),
                d2Sort(&Dictionary::sortDictionary, &d2);
    d1Sort.join(); d2Sort.join();

    test_prefix_search(d1);
    test_suffix_search(d1);
    test_startWith_char(d1);
    test_endWith_char(d1);
    test_add_word(d1);
    test_contains_word(d1);
    test_eq_operator(d1, d2);
    test_update_word(d1);
    test_output_stream(d1);

    return 0;
}

void test_prefix_search(Dictionary& d) {
    cout << "---Testing prefix search...\n"
        "Searching prefix: temp"<< endl;
    list<string> matches = d.startWith("temp");
    cout << matches.size() << " matches found: " << endl;
    list<string>::const_iterator it = matches.begin();
    for( ; it != matches.end() ; it++)
        cout << *it << endl;
}

void test_suffix_search(Dictionary& d) {
    cout << "\n---Testing suffix search...\n"
        "Searching suffix: eau" << endl;
    list<string> matches = d.endWith("eau");
    list<string>::const_iterator it = matches.begin();
    cout << matches.size() << " matches found: " << endl;
    for( ; it != matches.end() ; it++)
        cout << *it << endl;
}

void test_startWith_char(Dictionary& d) {
    cout << "\n---Testing start with char...\n"
         "Searching words that start with 'Z'" << endl;
    list<string> matches = d.startWith('Z');
    cout << matches.size() << " matches found." << endl;
    list<string>::const_iterator it = matches.begin();
    for( ; it != matches.end() ; it++) {
        cout << *it << endl;
    }
}

void test_endWith_char(Dictionary& d) {
    cout << "\n---Testing end with char...\n"
         "Searching word that end with 'X'" << endl;
    list<string> matches = d.endWith('X');
    cout << matches.size() << " matches found. " << endl;
    list<string>::const_iterator it = matches.begin();
    for( ; it != matches.end() ; it++) {
        cout << *it << endl;
    }
}

void test_update_word(Dictionary& d) {
    cout << "\n---Testing update word...\n"
         "Updating 'vaporwave' to 'vaporwaves'" << endl;
    d.updateWord("vaporwave", "vaporwaves");
}

void test_add_word(Dictionary& d) {
    cout << "\n---Testing add word...\n"
         "Adding word: Pokemon" << endl;
    d.addWord("Pokemon");
}

void test_contains_word(Dictionary& d) {
    cout << "\n---Testing contains word...\n"
         "Checking for word: ace" << endl;
    cout << "returns: " << (boolalpha) << d.containsWord("ace") << endl;
    cout << "Checking for word: ubuntu\n" << "returns: "<< (boolalpha)
         << d.containsWord("ubuntu");
}

void test_eq_operator(Dictionary& d1, Dictionary& d2) {
    cout << endl << "\n---Testing dictionary comparisons..." << endl;
    cout << "d1 == d2: " << (d1 == d2 ? "true" : "false") << endl;
}

void test_output_stream(Dictionary& d) {
    cout << "printing dictionary..." << endl;
    cout << d << endl;
}
