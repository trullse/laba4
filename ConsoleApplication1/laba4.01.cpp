// Лабораторная 4, задача 1. Выполнена: Леоненко А. О.

/* Ввести одномерный массив. 14) Удалить элементы, значение которых меньше среднего значения всех элементов. */

#include <iostream>
#include <ctime>

using namespace std;

int delete_el(int arr[], int noel, int el)
{
	for (int i = 0; i < noel; i++)
	{
		if (arr[i] == el)
		{
			for (int j = i; j < (noel - 1); j++)
			{
				arr[j] = arr[j + 1];
			}
			noel--; i--; 
		}
	}
	return noel;
}

int main() {
	const int n = 10;	// Size of array
	int arr[n], s = 0, noel = n;
	double sr;

	srand(time(0));

	for (int i = 0; i < noel; i++)	// Adding elements
	{
		arr[i] = rand() % 50;
	}

	cout << "This program deletes the elements lower than average of the elements of the array.\n"
		"The array is: \n";

	for (int i = 0; i < noel; i++)	// output array
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	for (int i = 0; i < noel; i++)	// s / n
	{
		s = s + arr[i];
	}
	sr = static_cast<double>(s) / n;

	for (int i = 0; i < noel; i++)
	{
		if (arr[i] < sr)
		{
			noel = delete_el(arr, noel, arr[i]);
			i--;
		}
	}

	cout << "\nThe fixed array is: \n";

	for (int i = 0; i < noel; i++)	// output array
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	return 0;
}