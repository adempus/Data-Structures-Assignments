//
// Created by adempus on 12/13/16.
//

#ifndef HOMEWORK6_ENTRY_H
#define HOMEWORK6_ENTRY_H

#include <list>

template<class K, class V>
class Entry {
public:
    Entry(const K& key, const V& val = 0) :
            key(key), value(val) {
    }
    K getKey() {
        return key;
    }
    V& getVal() {
        return value;
    }
    void setValue(V& value) {
        this->value = value;
    }
private:
    K key;
    V value;
};

#endif //HOMEWORK6_ENTRY_H
