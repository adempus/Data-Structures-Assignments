/**
 * Jeff Morin
 * CISC 3130
 * Fall 2016
 * Homework #5
 */


#ifndef HOMEWORK5_BOOKDATABASE_H
#define HOMEWORK5_BOOKDATABASE_H

#include "Book.h"
#include <map>
#include <set>

class BookDatabase {
public:
    BookDatabase();

    Book searchByTitle(const string&);
    set<Book> searchByAuthor(const string&);
    set<Book> publishedBefore(int);
    set<Book> searchByPublisher(const string&);
    void addBook(Book&);
    bool removeBook(const string&);
    friend ostream& operator<<(ostream&, const BookDatabase&);

private:
    map<string, Book> bookData;

};


#endif //HOMEWORK5_BOOKDATABASE_H