//
// Created by adempus on 12/13/16.
//

#ifndef HOMEWORK6_MYMAP_H
#define HOMEWORK6_MYMAP_H

#include "Entry.h"
#include <vector>
#include <list>

using namespace std;

template<class K, class V>
class MyMap {
public:
    MyMap();
    MyMap(int);
    MyMap(K, V, int);
    void insert(const K& key, V value);
    bool containsKey(const K& key);
    bool containsValue(V& value);
    void erase(const K& key);
    int getValueOf(const K& key);

    V& operator[] (const K& key);
    int size();
    bool isEmpty();

private:
    vector<std::list<Entry<K, V>>> table;
    int hashIndex(K&);
};

#include "MyMap.cpp"
#endif //HOMEWORK6_MYMAP_H
