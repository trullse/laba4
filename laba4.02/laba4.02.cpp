// Лабораторная 4, задача 2. Выполнена: Леоненко А. О.

/* Инициализировать статический двумерный массив целых чисел размером N * M. 
14) Найти произведение элементов, расположеннных в нечетных (по номеру) столбцах матрицы.*/

#include <iostream>
#include <ctime>

using namespace std;

int main() {

	const int n = 3, m = 5;	// The size of the array
	unsigned int arr[n][m];
	long long unsigned int mult = 1;

	cout << "This program multiplies the elements with odd column numbers. \n";

	srand(time(0));	// Filling the array
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = rand() % 20 + 1;
		}
	}

	cout << "The array is: \n\n";	// Output the array
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << arr[i][j] << "   ";
		}
		cout << "\n\n";
	}

	for (int i = 0; i < n; i++)	// Multiply the odd elements
	{
		for (int j = 0; j < m; j++)
		{
			if (j % 2 == 1)
			{
				mult *= arr[i][j];
			}
		}
	}

	cout << "The result is: " << mult << "\n";

	return 0;
}