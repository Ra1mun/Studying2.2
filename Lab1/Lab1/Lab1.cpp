
#include "Sort.h"

int main()
{
	srand(time(NULL));
	int n = 10;

	int* arrRand = new int[n];
	int* arrUp = new int[n];
	int* arrDown = new int[n];
	int* id = new int[n];


	for (int i = 0; i < n; i++)
	{
		id[i] = i;
		arrUp[i] = i;
		//cout << arrUp[id[i]] << " ";
	}
	cout << endl;

	Sort<int> s;
	int iter = s.PiramidSort(arrUp, id, n);
	if (s.IsSorted(arrUp, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrUp[id[i]] << " ";
		}
		cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
	}

	iter = s.ShellSort(arrUp, id, n);
	if (s.IsSorted(arrUp, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrUp[id[i]] << " ";
		}
		cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl << endl;


	for (int i = 0; i < n; i++)
	{
		id[i] = i;
		arrDown[i] = n - i;
		//cout << arrDown[id[i]] << " ";
	}
	cout << endl;


	iter = s.PiramidSort(arrDown, id, n);
	if (s.IsSorted(arrDown, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrDown[id[i]] << " ";
		}
		cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
	}

	iter = s.ShellSort(arrDown, id, n);
	if (s.IsSorted(arrDown, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrDown[id[i]] << " ";
		}
		cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl << endl;


	for (int i = 0; i < n; i++)
	{
		id[i] = i;
		arrRand[i] = rand() % 10;
		//cout << arrRand[i] << " ";
	}
	cout << endl;


	iter = s.PiramidSort(arrRand, id, n);
	if (s.IsSorted(arrRand, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrRand[i] << " ";
		}
		cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;

	for (int i = 0; i < n; i++)
	{
		id[i] = i;
	}

	iter = s.ShellSort(arrRand, id, n);
	if (s.IsSorted(arrRand, id, n))
	{
		for (int i = 0; i < n; i++)
		{
			//cout << arrRand[i] << " ";
		}
		cout << endl;
	}
	else iter = -1;
	cout << "iter = " << iter << endl;
}
