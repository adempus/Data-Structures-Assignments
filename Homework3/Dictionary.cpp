/**
 * @author: Jeff Morin
 * CISC 3130
 * Homework #3
 * Fall 2016
 *
 */

#include "Dictionary.h"

/** ctor
    @param fileName   -The path of the file to be read into the dictionary.
*/

Dictionary::Dictionary(const string& fileName) {
    readFile(fileName);
}

/** Searches for a specified word in the dictionary.
    @param word    -The string to be searched for.
    @return true if the word is found, false otherwise.
*/
bool Dictionary::containsWord(const string& word) {
    wordList.sort();
    // the binary search algorithm searches through the list of words for the specified word,
    // and returns true if the word is found in the list.
    return binary_search(wordList.begin(), wordList.end(), word);
}

/** Searches for every word that begins with a specified character.
    @param ch  -The character to be searched
    @return A list of strings that begins with the specified character.
*/
list<string> Dictionary::startWith(char ch) {
    list<string> results;
    list<string>::const_iterator it;
    for(it = wordList.begin() ; it != wordList.end(); it++) {
        // tolower for clean comparisons between characters.
        if(tolower(ch) == tolower(it->at(0)))
            results.push_back(*it);
    }
    return results;
}

/** Searches for every word that begins with a specified prefix.
    @param prefix   -The prefix string to be searched.
    @return A list of strings beginning with the specified prefix.
*/
list<string> Dictionary::startWith(const string& prefix) {
    list<string> results;
    list<string>::const_iterator it;
    for(it = wordList.begin() ; it != wordList.end() ; it++) {
        // here we compare a portion of the string (spanning from the first index
        // of the string to the length of the prefix) with the specified prefix,
        // to push back all matches of strings starting with the prefix.
        if(it->compare(0, prefix.length(), prefix) == 0)
            results.push_back(*it);
    }
    return results;
}

/** Searches for every word that ends with a specified character.
    @param ch   -The character to be searched.
    @return A list of strings that ends with the specified character.
*/
list<string> Dictionary::endWith(char ch) {
    list<string> results;
    list<string>::const_iterator it;
    for(it = wordList.begin() ; it != wordList.end() ; it++) {
        if(tolower(ch) == tolower(it->at(it->length()-1)))
            results.push_back(*it);
    }
    return results;
}

/** Searches for every word that ends with a specified suffix.
    @param suffix   -The suffix string to be searched.
    @return A list of strings ending with the specified suffix.
*/
list<string> Dictionary::endWith(const string& suffix) {
    list<string> results;
    list<string>::const_iterator it;
    for(it = wordList.begin() ; it != wordList.end() ; it++) {
        // here we check to see if the lenght of the suffix exceeds the length of the string.
        // if so, we continue the loop to avoid an out_of_range error in the comparison.
        if(suffix.length() > it->length()) continue;

        // here we compare a portion of the string (spanning the difference between the lengths
        // of the string and suffix, and the length of the suffix) with the specified suffix,
        // to push back all matches of strings ending with the suffix.
        if(it->compare(it->length() - suffix.length(), suffix.length(), suffix) == 0)
            results.push_back(*it);
    }
    return results;
}

/** Reads a file and pushes the contents into the word list.
    @param fileName   -Path of the file to be read.
    @throw runtime_error   -An invalid file path.
*/
void Dictionary::readFile(const string& fileName) {
    ifstream input(fileName.c_str());
    if(input.fail()) {
        throw runtime_error("File not found");
    } else {
        string word;
        while (getline(input, word)) {
            wordList.push_back(word);
        }
    }
}

/** Adds a specified string to the list of words.
    @param word   -The word to be added to the dictionary.
    @post If the addition is successful, the dictionary contains the newly added word,
        otherwise, the dictionary is unchanged.
*/
void Dictionary::addWord(const string& word) {
    list<string>::const_iterator it;
    //a search through the word list to check if the specified word already exists.
    for(it = wordList.begin() ; it != wordList.end() ; it++)
        if (equalsIgnoreCase(*it, word)) return;

    wordList.push_back(word);
    // sorting wordList after an addition mantains order for valid comparisons.
    wordList.sort();
}

/** Updates a specified word with a replacement in the dictionary.
    @param target   -The word to be replaced.
    @param replacement   -The word to replace the target.
    @post if the dictionary contains the target word, it is changed to the replacement,
        otherwise, the dictionary is unchanged.
*/
void Dictionary::updateWord(const string& target, const string& replacement) {
    list<string>::iterator it;
    for(it = wordList.begin() ; it != wordList.end() ; it++)
        if (*it == target) *it = replacement;
}

/** Compares two strings ignoring case considerations.
    @param str1     -The first string to be compared.
    @param str2     -The second string to be compared.
    @return -true if the two strings have an equal sequence of characters,
             false otherwise.
*/
bool Dictionary::equalsIgnoreCase(string str1, string str2) {
    // the lines below converts all the characters of the string into lowercase
    // characters. They are unchanged if already lowercase.
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    return str1 == str2;
}

/** Sorts dictionary in lexicographical order */
void Dictionary::sortDictionary() {
    wordList.sort();
}

bool operator==(const Dictionary& d1, const Dictionary& d2) {
    if (d1.wordList.size() != d2.wordList.size()) {
        return false;
    }
    list<string>::const_iterator it1 = d1.wordList.begin(), it2 = d2.wordList.begin();
    for ( ; it1 != d1.wordList.end() ; ++it1, ++it2) {
        // compares each iteration of the two dictionaries and returns false on a contrast
        // between the two iterators.
        if (!Dictionary::equalsIgnoreCase(*it1, *it2)) {
            return false;
        }
    }
    return true;
}

ostream& operator<<(ostream& os, const Dictionary& d) {
    list<string>::const_iterator it;
    for(it = d.wordList.begin() ; it != d.wordList.end() ; it++) {
        os << *it << endl;
    }
}