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
    HashTable(int q) {
        this->q = q;
        table.resize(q);
    }

    size_t hashFunction(const char* str) {
        size_t hash = str[0];
        for (const char* p = str; *p != '\0'; ++p) {
            hash = hash % table.size() * 31 + *p;
        }
        return hash % q;
    }

    void addUniqueString(const char* str) {
        size_t index = hashFunction(str);
        table[index].Add(str);
    }

    void concatenateAllLists() {
        SList mergedList;
        for (int i = 1; i < table.size(); i++) {
            table[0].Concatenate(table[i]);
        }
    }

    int GetNumberOfUniqueElements() {
        return table.size();
    }

    friend std::ostream& operator<<(std::ostream& stream, const HashTable& obj)
    {
        for (int i = 0; i < obj.q; i++) {
            stream << obj.table[i] << "\n";
        }

        return stream;
    }
};