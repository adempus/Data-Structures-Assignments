/**
 * Jeff Morin
 * CISC 3130
 * Fall 2016
 * Homework #5
 */


#ifndef HOMEWORK5_BOOK_H
#define HOMEWORK5_BOOK_H

#include <iostream>
#include <string>
#include <set>

using namespace std;

class Book {
public:
    Book(){ }
    Book(const string&, const string&, int, string*, int);

    string getTitle();
    string getPublisher();
    const set<string> getAuthors();
    int getYearOfPublication();
    int getNumAuthors();

    friend bool operator<(const Book&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend ostream& operator<<(ostream&, const Book&);

private:
    string      title;
    string      publisher;
    set<string> authors;
    int         yearOfPublication;
    int         numAuthors;
};


#endif //HOMEWORK5_BOOK_H
