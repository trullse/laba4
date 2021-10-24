// Лабораторная 4, задача 8. Выполнена: Леоненко А. О.

/* Заменить нулями все элементы, которые находятся в ячейках 
между минимальным и максимальным элементами (не включая их). 
Изначально все элементы в массиве различные. Если после данного действия 
большая часть массива будет содержать нули, то удалить все нулевые 
элементы из массива (c сохранением порядка следования остальных 
элементов). */

#include <iostream>
#include <ctime>

using namespace std;

int input()	// Checking input
{
	int x;
	while (true)
	{
		cin >> x;
		if (cin.fail() || x < 1)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "The value is incorrect, try again: \n";
		}
		else
		{
			cin.ignore(10000, '\n');
			return x;
		}
	}
}

int* DelEl(int* arr, int n, int st, int fin)	// Deleting elements, if their number >  half of number of elements
{
	int count = fin - st - 1;
	int* arr2 = new int[n - count];
	for (int i = 0; i <= st; i++)
	{
		arr2[i] = arr[i];
	}
	int j = st + 1;
	for (int i = fin; i < n; i++)
	{
		arr2[j] = arr[i];
		j++;
	}
	delete[] arr;
	return arr2;
}

int main() {

	int n, count, nmax = 0, nmin = 0, max, min;
	cout << "This program replaces by 0 the elements of array between maximum and minimum elements.\n"
		"Enter the size of array: ";
	n = input();
	int* arr = new int[n];

	srand(time(0));	// Filling the array
	for (int i = 0; i < n; i++)
	{
		arr[i] = 1 + rand() % (n + 50);
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] == arr[j]) count++;
		}
		if (count != 0) i--;
	}

	cout << "The array is: \n\n";	// Output the array
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "   ";
		if (i % 20 == 0 && i != 0) cout << "\n\n";
	}
	cout << "\n\n";

	max = arr[0]; min = arr[0];	// Finding max and min
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
		{
			nmax = i; max = arr[i];
		}
		if (arr[i] < min)
		{
			nmin = i; min = arr[i];
		}
	}

	if (nmax < nmin)	// Replacing by 0
	{
		int a;
		a = nmax; nmax = nmin; nmin = a;
	}
	for (int i = nmin + 1; i < nmax; i++)
	{
		arr[i] = 0;
	}

	count = nmax - nmin - 1;
	if (count > (n / 2))	// Deleting 0's
	{
		arr = DelEl(arr, n, nmin, nmax);
		n -= count;
	}

	cout << "The fixed array is: \n\n";	// Output the array
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "   ";
		if (i % 20 == 0 && i != 0) cout << "\n\n";
	}
	cout << "\n\n";

	return 0;
}