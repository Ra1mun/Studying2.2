#include "Sort.h"
#include "User.h"
#include <fstream>

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    const int n = 10;

    int* id = new int[n];
    User** users = new User*[n];

    ofstream outputFile("result.txt");

    for (int i = 0; i < n; i++) {
        users[i] = new User();
        id[i] = i;
    }

    Sort<User*> s;

    outputFile << "Сортировка Шелла" << endl;
    s.ShellSort(users, id, n);
    if (s.IsSorted(users, id, n) && outputFile.is_open()) {
        for (int i = 0; i < n; i++) {
            outputFile << i + 1 << "место: " << *users[id[n - i - 1]] << "  " << id[n - i - 1];
            outputFile << endl;
        }
    }

    outputFile << endl;

    for (int i = 0; i < n; i++) {
        id[i] = i;
    }

    outputFile << "Пирамидальная сортировка" << endl;
    s.PiramidSort(users, id, n);
    if (s.IsSorted(users, id, n) && outputFile.is_open()) {
        for (int i = 0; i < n; i++) {
            outputFile << i + 1 << "место: " << *users[id[n - i - 1]] << "  " << id[n - i - 1];
            outputFile << endl;
        }
    }

    outputFile.close();

    for (int i = 0; i < n; i++) {
        delete[] users[i];
    }

    delete[] users;

    delete[] id;

    return 0;
}