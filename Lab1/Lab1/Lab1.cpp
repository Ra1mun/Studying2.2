
#include "Sort.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n = 10;

	int* arrRand = new int[n];
	int* arrUp = new int[n];
	int* arrDown = new int[n];
	int* id = new int[n];

	Sort<int> s;

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
		arrUp[i] = i;
		//cout << arrUp[id[i]] << " ";
	}
	cout << "Пирамидальная сортировка" << endl;

	int iter = s.PiramidSort(arrUp, id, n);
	if (s.IsSorted(arrUp, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrUp[id[i]] << " ";
		}
		//cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
	}

	cout << "Сортировка Шелла" << endl;

	iter = s.ShellSort(arrUp, id, n);
	if (s.IsSorted(arrUp, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrUp[id[i]] << " ";
		}
		//cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl << endl;


	for (int i = 0; i < n; i++)
	{
		id[i] = i;
		arrDown[i] = n - i;
		//cout << arrDown[id[i]] << " ";
	}
	cout << "Пирамидальная сортировка" << endl;


	iter = s.PiramidSort(arrDown, id, n);
	if (s.IsSorted(arrDown, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrDown[id[i]] << " ";
		}
		//cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
	}

	cout << "Сортировка Шелла" << endl;

	iter = s.ShellSort(arrDown, id, n);
	if (s.IsSorted(arrDown, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrDown[id[i]] << " ";
		}
		//cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl << endl;


	for (int i = 0; i < n; i++)
	{
		id[i] = i;
		arrRand[i] = rand() % 10;
		//cout << arrRand[i] << " ";
	}
	cout << "Пирамидальная сортировка" << endl;


	iter = s.PiramidSort(arrRand, id, n);
	if (s.IsSorted(arrRand, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrRand[i] << " ";
		}
		//cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
	}

	cout << "Сортировка Шелла" << endl;

	iter = s.ShellSort(arrRand, id, n);
	if (s.IsSorted(arrRand, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrRand[id[i]] << " ";
		}
		//cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;
}
