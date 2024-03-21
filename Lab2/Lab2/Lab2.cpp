#include "Sort.h"
#include "User.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

    const int n = 50;

    int* id = new int[n];
    User** users = new User*[n];

    for (int i = 0; i < n; i++) {
        users[i] = new User();
        id[i] = i;
    }

    Sort<User*> s;
    cout << "Сортировка Шелла" << endl;
    s.ShellSort(users, id, n);
    if (s.IsSorted(users, id, n)) {
        for (int i = 0; i < n; i++) {
            cout << i + 1 << "место: " << *users[id[n - i - 1]];
            cout << endl;
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        id[i] = i;
    }

    cout << "Пирамидальная сортировка" << endl;
    s.PiramidSort(users, id, n);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "место: " << *users[id[n - i - 1]];
        cout << endl;
    }


    for (int i = 0; i < n; i++) {
        delete[] users[i];
    }

    delete[] users;

    delete[] id;

    return 0;
}