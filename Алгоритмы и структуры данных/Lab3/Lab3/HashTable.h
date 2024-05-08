#pragma once
#include <vector>
#include <string.h>
#include <iostream>
#include "SList.h"

using namespace std;

class HashTable {
private:
    int q;
    vector<SList> table;

public:
    HashTable(int q) : q(q), table(q) {}

    size_t hashFunction(const char* str) {
        size_t hash = 0;
        for (const char* p = str; *p != '\0'; ++p) {
            hash = hash * 31 + *p;
        }
        return hash % q;
    }

    void addUniqueString(const char* str) {
        size_t index = hashFunction(str);
        table[index].Add(str);
    }

    void concatenateAllLists() {
        SList mergedList;
        for (SList& list : table) {
            mergedList.Concatenate(list);
        }
    }
};