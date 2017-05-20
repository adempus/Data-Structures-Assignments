/**
 * @author: Jeff Morin
 * CISC 3130
 * Homework #3
 * Fall 2016
 *
 */

#ifndef HOMEWORK3_DICTIONARY_H
#define HOMEWORK3_DICTIONARY_H

#include <list>
#include <algorithm>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Dictionary {
public:
    Dictionary() { }
    Dictionary(const string& fileName);
    bool containsWord(const string& word);
    list<string> startWith(char ch);
    list<string> startWith(const string& prefix);
    list<string> endWith(char ch);
    list<string> endWith(const string& suffix);
    void addWord(const string& word);
    void updateWord(const string& target, const string& replacement);
    void sortDictionary();

private:
    list<string> wordList;
    static bool equalsIgnoreCase(string s1, string s2);
    void readFile(const string& filePath);
    friend bool operator==(const Dictionary& d1, const Dictionary& d2);
    friend ostream& operator<<(ostream& os, const Dictionary& d);
};

#endif //HOMEWORK3_DICTIONARY_H
