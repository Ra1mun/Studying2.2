#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Sort {
public:
	static void ShellSort(T* arr, int n);
	static void PyramidSort(T* arr, int n);
	static void CheckSort(T* arr);
};

template<typename T>
inline void Sort<T>::ShellSort(T* arr, int n)
{
    int n = arr.size();

    for (int step = n / 2; step > 0; step /= 2) {
        int tmp;
        for (int i = step; i < n; i++)
        {
            tmp = arr[i];
            for (int j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
    }  
}

template<typename T>
inline void Sort<T>::PyramidSort(T* arr, int n)
{
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

template<typename T>
inline void Sort<T>::CheckSort(T* arr)
{
}


void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}