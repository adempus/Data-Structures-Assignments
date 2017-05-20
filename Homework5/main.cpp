/**
 * Jeff Morin
 * CISC 3130
 * Fall 2016
 * Homework #5
 */


#include <iostream>
#include <fstream>
#include <vector>
#include "Book.h"
#include "BookDatabase.h"

using namespace std;

BookDatabase database;

void readBooksFile(string& path);
void testAddBook();
void testRemoveBook();
void testSearchTitle();
void testSearchAuthor();
void testPublishedBefore();
void testSearchPublisher();
void viewCatalogedBooks();

int main() {
    cout << "Enter a file path: ";
    string path;
    cin >> path;
    readBooksFile(path);
    testAddBook();
    testRemoveBook();
    viewCatalogedBooks();
    testSearchAuthor();
    testSearchTitle();
    testPublishedBefore();
    testSearchPublisher();
    return 0;
}

/** To add a book to the database. */
void testAddBook() {
    cout << "-- Add Book --" << endl;
    string b1Title = "Database Systems: A Pragmatic Approach";
    string b1Publisher = "Apress";
    int b1Year = 2016;
    string b1Authors[2] = {"Foster", "Godbole"};
    // book 2
    string b2Title = "Natural Language Processing with Java";
    string b2Publisher = "Packt Publishing";
    int b2Year = 2015;
    string b2Authors[1] = {"Reese"};

    Book book1(b1Title, b1Publisher, b1Year, b1Authors, 2);
    Book book2(b2Title, b2Publisher, b2Year, b2Authors, 1);
    database.addBook(book1);
    database.addBook(book2);
    cout << database << endl;
}

/** To remove a book from the database. */
void testRemoveBook() {
    cout << "-- Testing remove Book --"
            "\nEnter a book title to remove: " << endl;
    string title;
    cin >> title;
    cout << (database.removeBook(title) ?
             "Book removed.\n" : "Book not found!\n");
    cout << database << endl;
}

/** Searches a book by title. */
void testSearchTitle() {
    cout << "--Testing Search Books by Title --" << endl;
    string searchKey = "Chemistry";
    cout << "Searching: " << searchKey << endl;
    Book foundBook = database.searchByTitle(searchKey);
    cout << "Found: " << foundBook.getTitle() << endl;
}

/** Searches for the author.*/
void testSearchAuthor() {
    cout << "-- Testing Search Books --" << endl;
    set<Book> foundBooks;
    string authorKeys[4] = { "Derrickson", "Woodward", "McConnell", "Cormen"};
    for (int i = 0 ; i < 4 ; i++) {
        cout << "Searching: " << authorKeys[i] << endl;
        foundBooks = database.searchByAuthor(authorKeys[i]);

        cout << "Found: " << endl;
        for (set<Book>::const_iterator it = foundBooks.begin()
                ; it != foundBooks.end() ; it++)  cout << *it << endl;
    }
}

/** Searches books published before a certain date. */
void testPublishedBefore() {
    cout << "-- Testing Published Before -- " << endl;
    set<Book> foundBooks;
    int yearKeys[4] = {2009, 2007, 2001, 2010};
    for (int i = 0 ; i < 4 ; i++) {
        cout << "Searching books before " << yearKeys[i] << ": " << endl;
        foundBooks = database.publishedBefore(yearKeys[i]);

        cout << "Found: " << endl;
        for (set<Book>::const_iterator it = foundBooks.begin() ;
                it != foundBooks.end() ; it++) cout << *it << endl;
    }
}

/** Searches a book based on a specific publisher. */
void testSearchPublisher() {
    cout << "-- Testing Search Publisher -- " << endl;
    set<Book> foundBooks;
    string publisherKeys[4] = { "Wiley_and_sons",  "MIT_Press", "Prentice_Hall", "Jones_and_Bartlett"};
    for (int i = 0 ; i < 4 ; i++) {
        cout << "Searching publisher: " << publisherKeys[i] << endl;
        foundBooks = database.searchByPublisher(publisherKeys[i]);

        cout << "Found: " << endl;
        for (set<Book>::const_iterator it = foundBooks.begin() ;
                it != foundBooks.end() ; it++) cout << *it << endl;
    }
}

/** Prints all the books currently available in the database */
void viewCatalogedBooks() {
    cout << "-- Book Catalog --" << endl;
    cout << database << endl;
}

/** Reads all the books line by line in the text file. */
void readBooksFile(string& path) {
    ifstream bookStream(path);
    if (bookStream.fail()) {
        cerr << "file not found. " << endl;
    }
    string title, numAuthors, publisher, year;
    vector<string> authors;
    int nAuthors = 0;
    while (!bookStream.eof()) {
        bookStream >> title;
        bookStream >> numAuthors;
        // parse authors into vector
        if (isdigit(numAuthors[0])) {
            string author;
            nAuthors = stoi(numAuthors);
            for(int i = 0 ; i < nAuthors ; i++) {
                bookStream >> author;
                authors.push_back(author);
            }
        }
        // continue parsing publisher and year.
        bookStream >> publisher;
        bookStream >> year;
        // create book object
        Book newBook(title, publisher, stoi(year), &authors[0], nAuthors);
        database.addBook(newBook);      // add the book to the database.
        authors.clear();                // clear the author's names for new line.
    }
}