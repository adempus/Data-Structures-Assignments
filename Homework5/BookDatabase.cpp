/**
 * Jeff Morin
 * CISC 3130
 * Fall 2016
 * Homework #5
 */

#include "BookDatabase.h"

BookDatabase::BookDatabase() {}

/** Searches for books given a particular title.
 *  @param title The title of the book to search for.
 *  @returns A resuting book object of the title, if found.
 * */
Book BookDatabase::searchByTitle(const string& title) {
    map<string, Book>::const_iterator it = bookData.begin();
    for ( ; it != bookData.end() ; it++) {
        if (it->first == title) return it->second;
    }
}

/** Searches for books published before a certain year.
 *  @param year   Max cutoff year for published books.
 *  @returns A set of books published before the year.
 * */
set<Book> BookDatabase::publishedBefore(int year) {
    set<Book> bookResults;
    map<string, Book>::iterator it = bookData.begin();
    for ( ; it != bookData.end() ; it++) {
        if (it->second.getYearOfPublication() < year)
            bookResults.insert(it->second);
    }
    return bookResults;
}

/** Searches for books with common authors in the database.
 *  @param   author  The name of the author of the books.
 *  @returns booksByAuthor A set of books with the same author.
 * */
set<Book> BookDatabase::searchByAuthor(const string& author) {
    set<Book> booksByAuthor;
    map<string, Book>::const_iterator it = bookData.begin();
    for ( ; it != bookData.end() ; it++) {
        Book book = it->second;
        set<string> authors = book.getAuthors();
        // check the set of authors to find an author in the set matching the search key
        set<string>::const_iterator foundIt = authors.find(author);
        if (foundIt != authors.end())
            booksByAuthor.insert(book);
    }
    return booksByAuthor;
}

/** Searches for books with the same publisher in the database.
 *  @param   publisher    The name of the publisher of the books.
 *  @returns bookResults  A set of books with the same publisher.
 * */
set<Book> BookDatabase::searchByPublisher(const string& publisher) {
    set<Book> bookResults;
    map<string, Book>::const_iterator it = bookData.begin();
    for ( ; it != bookData.end() ; it++) {
        Book book = it->second;
        if (book.getPublisher() == publisher)
            bookResults.insert(it->second);
    }
    return bookResults;
}

/** Inserts a book to the database.
 *  @param book    the book object to insert into the database.
 * */
void BookDatabase::addBook(Book& book) {
    bookData.insert(pair<string, Book>(book.getTitle(), book));
}

/** Deletes a book from the database.
 *  @param title   the title of the book to be deleted from the database.
 *  @returns true  if the book is found and sucessessfully deleted, false otherwise.
 **/
bool BookDatabase::removeBook(const string& title) {
    map<string, Book>::const_iterator it = bookData.begin();
    for ( ; it != bookData.end() ; it++) {
        if (it->first == title) {
            bookData.erase(it->first);
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const BookDatabase& db) {
    map<string, Book>::const_iterator it = db.bookData.begin();
    for ( ; it != db.bookData.end() ; it++) {
        Book book = it->second;
        os << book << endl;
    }
    return os;
}