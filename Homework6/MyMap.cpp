//
// Created by adempus on 12/13/16.
//


#include <cctype>
#include <array>
#include <cstring>
#include <iostream>
#include "MyMap.h"

template<class K, class V>
MyMap<K, V>::MyMap() {
    table = std::vector<std::list<Entry<K, V>>>();
}

template<class K, class V>
MyMap<K, V>::MyMap(int size) {
    table = std::vector<std::list<Entry<K, V>>>((unsigned) size);
}

template<class K, class V>
MyMap<K, V>::MyMap(K key, V val, int size) {
    table = std::vector<std::list<Entry<K, V>>>((unsigned) size);
    insert(key, val);
}

template <class K, class V>
void MyMap<K, V>::insert(const K& key, V value) {
    Entry<K, V> newEntry(key, value);
    int index = hashIndex(key);

    if(table[index] != nullptr) {
        cout << "Nulld";
    }
}

/** The hash function turns whatever key is being passed into a
 * */
 // assume the key is always a string, and the value anything user wants.

template <class K, class V>
int MyMap<K, V>::hashIndex(K& key) {
    if(isalpha(key)) {
        string keyStr = key.c_str();
        char bytes[keyStr.length()];
        strcpy(bytes, keyStr, keyStr.length());
        for (int i = 0 ; i < keyStr.length() ; i++) {
            cout << bytes[i] << ", ";
        }
    }
}

template <class K, class V>
int MyMap<K, V>::size() {
    return (unsigned) table.size();
}

template <class K, class V>
bool MyMap<K, V>::isEmpty() {
    return table.empty();
}