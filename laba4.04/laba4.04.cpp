// Лабораторная 4, задача 4. Выполнена: Леоненко А. О.

/* Подсчитать количество локальных минимумов заданной матрицы. */

#include <iostream>
#include <ctime>

using namespace std;

int input()	// Checking input
{
	int x;
	while (true)
	{
		cin >> x;
		if (cin.fail() || x < 0)
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

int main() {

	int n, m;	// The size of matrix
	cout << "This program outputs number of local minimums. \n"
		"Input the size of matrix (n): ";
	n = input();
	cout << "Input the size of matrix(m) : ";
	m = input();

	int** matrix = new int* [n];

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

	cout << "The array is: \n\n";

	for (int i = 0; i < n; i++)	// Output the array
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "   ";
		}
		cout << "\n\n";
	}

	int numb = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (n == 1 && m == 1) numb++;	// 1 element

			else if (n == 1)	// 1 line
			{
				if (j == 0)
				{
					if (matrix[i][j] < matrix[i][j + 1]) numb++;
				}
				else if (j == (m - 1))
				{
					if (matrix[i][j] < matrix[i][j - 1]) numb++;
				}
				else if (matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i][j + 1]) numb++;
			}

			else if (m == 1)	// 1 column
			{
				if (i == 0)
				{
					if (matrix[i][j] < matrix[i + 1][j]) numb++;
				}
				else if (i == (n - 1))
				{
					if (matrix[i][j] < matrix[i - 1][j]) numb++;
				}
				else if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i + 1][j]) numb++;
			}

			else if (i == 0 && j == 0)
			{
				if (matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i + 1][j + 1] &&
					matrix[i][j] < matrix[i][j + 1]) numb++;	// Left top corner
			}
			else if (i == 0 && j == (m - 1))
			{
				if (matrix[i][j] < matrix[i + 1][j] && matrix[i][j] < matrix[i + 1][j - 1] &&
					matrix[i][j] < matrix[i][j - 1]) numb++;	// Right top corner
			}
			else if (i == (n - 1) && j == 0)
			{
				if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i - 1][j + 1] &&
					matrix[i][j] < matrix[i][j + 1]) numb++;	// Left bottom corner
			}
			else if (i == (n - 1) && j == (m - 1))
			{
				if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i - 1][j - 1] &&
					matrix[i][j] < matrix[i][j - 1]) numb++;	// Right bottom corner
			}
			else if (i == 0)
			{
				if (matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i + 1][j - 1] && matrix[i][j] < matrix[i + 1][j] &&
					matrix[i][j] < matrix[i + 1][j + 1] && matrix[i][j] < matrix[i][j + 1]) numb++;	// Top
			}
			else if (i == (n - 1))
			{
				if (matrix[i][j] < matrix[i][j - 1] && matrix[i][j] < matrix[i - 1][j - 1] && matrix[i][j] < matrix[i - 1][j] &&
					matrix[i][j] < matrix[i - 1][j + 1] && matrix[i][j] < matrix[i][j + 1]) numb++; // Bottom
			}
			else if (j == 0)
			{
				if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i - 1][j + 1] && matrix[i][j] < matrix[i][j + 1] &&
					matrix[i][j] < matrix[i + 1][j + 1] && matrix[i][j] < matrix[i + 1][j]) numb++;	// Left
			}
			else if (j == (m - 1))
			{
				if (matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i - 1][j - 1] && matrix[i][j] < matrix[i][j - 1] &&
					matrix[i][j] < matrix[i + 1][j - 1] && matrix[i][j] < matrix[i + 1][j]) numb++;	// Right
			}
			else if (matrix[i][j] < matrix[i - 1][j - 1] && matrix[i][j] < matrix[i - 1][j] && matrix[i][j] < matrix[i - 1][j + 1] && 
				matrix[i][j] < matrix[i][j + 1] && matrix[i][j] < matrix[i + 1][j + 1] && matrix[i][j] < matrix[i + 1][j] && 
				matrix[i][j] < matrix[i + 1][j - 1] && matrix[i][j] < matrix[i][j - 1]) numb++;	// Inside
		}
	}

	cout << "Number of local minimums is: " << numb << "\n";

	return 0;
}