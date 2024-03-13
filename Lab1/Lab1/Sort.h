#pragma once
#include <iostream>

using namespace std;

template<class T>
class Sort
{
private:
	static int Sift(const T* arr, int* id, int root, int bottom);
public:
	static int ShellSort(const T* arr, int* id, int n);
	static int PiramidSort(const T* arr, int* id, int n);
	static bool IsSorted(const T* arr, int* id, int n);

};

template<class T>
int Sort<T>::ShellSort(const T* arr, int* id, int n)
{
	int iter = 0;
	for (int inter = n / 2; inter > 0; inter /= 2)
	{
		for (int i = inter; i < n; i++)
		{
			int temp = id[i];
			int j;
			for (j = i; j >= inter; j -= inter)
			{
				iter++;
				if (arr[id[j - inter]] <= arr[temp])
				{
					break;
				}
				id[j] = id[j - inter];
			}
			id[j] = temp;
		}
	}
	return iter;
}

template<class T>
int Sort<T>::PiramidSort(const T* arr, int* id, int n)
{
	int iter = 0;
	for (int i = n / 2; i >= 0; i--)
	{
		iter += Sift(arr, id, i, n - 1);
	}
	for (int i = n - 1; i >= 1; i--)
	{
		int temp = id[0];
		id[0] = id[i];
		id[i] = temp;
		iter += Sift(arr, id, 0, i - 1);
	}
	return iter;
}

template<class T>
bool Sort<T>::IsSorted(const T* arr, int* id, int n)
{
	for (int i = 0; i < n - 1; i++)
	{

		if (arr[id[i]] > arr[id[i + 1]]) return false;
	}
	return true;
}

template<class T>
int Sort<T>::Sift(const T* arr, int* id, int root, int bottom)
{
	int maxChild, done = 0;
	int iter = 0;
	while ((root * 2 <= bottom) && !done)
	{
		if (root * 2 == bottom) maxChild = root * 2;
		else if (arr[id[root * 2]] > arr[id[root * 2 + 1]]) maxChild = root * 2;
		else maxChild = root * 2 + 1;

		if (arr[id[root]] < arr[id[maxChild]])
		{
			int temp = id[root];
			id[root] = id[maxChild];
			id[maxChild] = temp;
			root = maxChild;
			iter++;
		}
		else done = 1;
	}
	return iter;
}