// Лабораторная 4, задача 3. Выполнена: Леоненко А. О.

/* Дана действительная квадратная матрица порядка N. 
Найти сумму и произведение элеметов, располоденных в заштрихованной части матрицы (рис б). */

#include <iostream>
#include <ctime>

using namespace std;

int main() {

	int n = 5, m = n;	// The size of matrix
	int** matrix = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m];
	}

	srand(time(0));	// Filling the array
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = rand() % 10 + 1;
		}
	}

	cout << "This program finds sum and multiplication of the elements under hatching. \n"
		"The array is: \n\n";

	for (int i = 0; i < n; i++)	// Output the array
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "   ";
		}
		cout << "\n\n";
	}

	int mid, b = 0, e = n, j = 0, i = 0;
	unsigned long long int s = 0, mult = 1;

	mid = n / 2 + n % 2 - 1;

	while (j <= mid)	// First half of matrix
	{
		for (i = b; i < e; i++)
		{
			s += matrix[i][j];
			mult *= matrix[i][j];
		}
		b++; e--; j++;
	}

	b = 0; e = n; j = n - 1; i = 0;
	while (j > mid)	// Second half of matrix
	{
		for (i = b; i < e; i++)
		{
			s += matrix[i][j];
			mult *= matrix[i][j];
		}
		j--; b++; e--;
	}

	cout << "The result of multiplication is: " << mult << "\n";
	cout << "The result of addition is: " << s << "\n";

	return 0;
}