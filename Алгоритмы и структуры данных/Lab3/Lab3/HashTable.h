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
    HashTable(int q) : q(q), table(q) { }

    int hashFunction(const char* str) {
        int hash = str[0];
        for (const char* p = str; *p != '\0'; ++p) {
            hash = hash % q * 31 + *p;
        }
        return hash % q;
    }

    void addUniqueString(const char* str) {
        int index = hashFunction(str);
        table[index].Add(str);
        
    }

    void concatenateAllLists() {
        for (int i = 1; i < q; i++) {
            table[0].Concatenate(table[i]);
        }
    }

    int GetNumberOfUniqueElements() {
        return table[0].GetUniqueElements();
    }

    friend std::ostream& operator<<(std::ostream& stream, const HashTable& obj)
    {
        for (int i = 0; i < obj.q; i++) {
            stream << obj.table[i] << "\n";
        }

        return stream;
    }
};