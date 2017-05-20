/**
 * Jeff Morin
 * CISC 3130
 * Fall 2016
 * Homework #5
 */

#include "Book.h"

Book::Book(const string& title, const string& publisher,
           int year, string* authors, int numAuthors) :
        title(title), publisher(publisher), yearOfPublication(year),
        authors(authors, authors+numAuthors), numAuthors(numAuthors) { }


string Book::getTitle() {
    return title;
}

string Book::getPublisher() {
    return publisher;
}

const set<string> Book::getAuthors() {
    return authors;
}

int Book::getYearOfPublication() {
    return yearOfPublication;
}

int Book::getNumAuthors() {
    return numAuthors;
}

bool operator<(const Book& book1, const Book& book2) {
    return (book1.title < book2.title);
}

bool operator==(const Book& book1, const Book& book2) {
    return (book1.title == book2.title && book1.authors == book2.authors &&
            book1.publisher == book2.publisher && book1.numAuthors == book2.numAuthors &&
            book1.yearOfPublication == book2.yearOfPublication);
}

ostream& operator<<(ostream& os, const Book& book) {
    os << "Title: " << book.title;
    os << "\nAuthor(s): ";
    set<string>::const_iterator it = book.authors.begin();
    for (int i = 1 ; it != book.authors.end() ; it++, i++)
        os << (i < book.numAuthors ? *it+", " : *it);
        os << "\nAuthors: " << book.numAuthors
            << "\nPublisher: " << book.publisher
            << "\nYear: " << book.yearOfPublication << "\n\n";

    return os;
}