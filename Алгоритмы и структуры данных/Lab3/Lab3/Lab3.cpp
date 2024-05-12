#include <iostream>
#include "HashTable.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    int n = 10000;
    int minLen = 5, maxLen = 15;
    int q = 100;

    HashTable hashTable(q);

    for (int i = 0; i < n; ++i) {
        int len = rand() % (maxLen - minLen + 1) + minLen;
        char* str = new char[len + 1];
        for (int j = 0; j < len; ++j) {
            str[j] = 96 + rand() % 26;
        }
        str[len] = '\0';

        hashTable.addUniqueString(str);

        delete[] str;
    }

    hashTable.concatenateAllLists();

    cout << "Число уникальных строк: " << hashTable.GetNumberOfUniqueElements() << endl;
    cout << hashTable << "-----------" << endl;
    hashTable.concatenateAllLists();
    cout << hashTable << endl;

    return 0;
}