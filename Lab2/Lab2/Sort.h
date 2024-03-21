#pragma once
#include <iostream>

using namespace std;

template<class T>
class Sort
{
private:
	static void Shift(const T* arr, int* id, int root, int bottom);
public:
	static void ShellSort(const T* arr, int* id, int n);
	static void PiramidSort(const T* arr, int* id, int n);
	static bool IsSorted(const T* arr, int* id, int n);

};

template<class T>
void Sort<T>::ShellSort(const T* arr, int* id, int n)
{
	for (int i = n / 2; i > 0; i /= 2)
	{
		for (int j = i; j < n; j++)
		{
			int temp = id[j];
			int k;

			for (k = j; k >= i; k -= i)
			{
				if (*arr[id[k - i]] < *arr[temp])
				{
					break;
				}
				if (*arr[id[k - i]] == *arr[temp] && id[k - i] < temp) {
					break;
				}

				id[k] = id[k - i];
			}

			id[k] = temp;
		}
	}
}

template<class T>
void Sort<T>::PiramidSort(const T* arr, int* id, int n)
{
	for (int i = n / 2; i >= 0; i--)
	{
		Shift(arr, id, i, n - 1);
	}
	for (int i = n - 1; i > 0; i--)
	{
		int temp = id[0];
		id[0] = id[i];
		id[i] = temp;
		Shift(arr, id, 0, i - 1);
	}
}

template<class T>
void Sort<T>::Shift(const T* arr, int* id, int root, int bottom)
{
	int maxChild;
	bool done = false;

	while ((root * 2 <= bottom) && !done)
	{
		if ((root * 2 == bottom) || (*arr[id[root * 2]] > *arr[id[root * 2 + 1]]))
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;

		if (*arr[id[root]] < *arr[id[maxChild]] || (*arr[id[root]] == *arr[id[maxChild]] && root < maxChild))
		{
			int temp = id[root];
			id[root] = id[maxChild];
			id[maxChild] = temp;
			root = maxChild;
		}
		else done = true;
	}
}

template<class T>
bool Sort<T>::IsSorted(const T* arr, int* id, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (*arr[id[i]] > *arr[id[i + 1]])
			return false;
	}
	return true;
}