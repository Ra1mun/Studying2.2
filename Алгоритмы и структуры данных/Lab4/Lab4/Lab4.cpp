#include <iostream>
#include <ctime>
#include "Sort.h"

using namespace std;

int greedy_alghorithm(int* values, int* weight, size_t size, int capacity) {
    int* cost = new int[size];
    int* id = new int[size];

    for (int i = 0; i < size; i++) {
        cost[i] = values[i] / weight[i];
        id[i] = i;
    }

    Sort<int> sort;
    sort.ShellSort(cost, id, size);

    int result = 0;
    for (int i = 0; i < size; i++) {
        if (weight[id[i]] <= capacity) {
            result += values[id[i]];
            capacity -= weight[id[i]];
        }
    }

    return result;
}

int dynamic_alghorithm(int* values, int* weights, size_t size, int capacity) {
    int** dp = new int* [size + 1];

    for (int i = 0; i <= size; i++) {
        dp[i] = new int[capacity + 1];
    }

    for (int i = 0; i <= size; i++) {
        for (int j = 0; j <= capacity; j++) {
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= size; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] > w) {
                dp[i][w] = dp[i - 1][w];
            }
            else {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return dp[size][capacity];
}

void backtracking_alghorithm(int* values, int* weights, size_t size, int capacity,
    int currentWeight, int currentValue, int& maxValue, int index) {

    if (index >= size || currentWeight > capacity) {
        maxValue = max(currentValue, maxValue);
        return;
    }
    
    backtracking_alghorithm(values, weights, size, capacity,
        currentWeight + weights[index], currentValue + values[index], maxValue, index + 1);

    backtracking_alghorithm(values, weights, size, capacity,
        currentWeight, currentValue, maxValue, index + 1);
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(nullptr));

     int n = 10;

     int* values = new int[n];
     int* weights = new int[n];

     int totalWeight = 0;

     for (int i = 0; i < n; i++) {
         values[i] = 1 + rand() % 20;
         weights[i] = 1 + rand() % 20;
         /*values[i] = 1;
         weights[i] = 1;*/
         totalWeight += weights[i];
     }

     int W = totalWeight / 2;

     //Жадный алгоритм
     int max_value_greedy = greedy_alghorithm(values, weights, n, W);
     cout << "Жадный алгоритм: " << max_value_greedy << '\n';

     //Динамический алгоритм
     int max_value_dynamic = dynamic_alghorithm(values, weights, n, W);
     cout << "Динамический алгоритм: " << max_value_dynamic << '\n';

     //Бектрекинг
     //int* currentSubset = new int[n];
     //for (int i = 0; i < n; i++)
     //    currentSubset[i] = 0;

     int max_value_backtrack = 0;
     backtracking_alghorithm(values, weights, n, W, 0, 0, max_value_backtrack, 0);
     cout << "Перебор: " << max_value_backtrack;

     delete[] values;
     delete[] weights;
}