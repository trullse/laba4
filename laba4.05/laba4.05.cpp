// Лабораторная 4, задача 5. Выполнена: Леоненко А. О.

/* Построить результат сглаживания заданной вещественной матрицы. */

#include <iostream>

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
	cout << "This program outputs smoothed matrix. \n"
		"Input the size of matrix (n): ";
	n = input();
	cout << "Input the size of matrix(m) : ";
	m = input();

	double** matrix = new double* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[m];
	}

	srand(time(0));	// Filling the array
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i][j] = 1 + 4.0 * rand() / (float)RAND_MAX;
		}
	}

	double** cmatrix = new double* [n];	// coping the matrix
	for (int i = 0; i < n; i++)
	{
		cmatrix[i] = new double[m];
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cmatrix[i][j] = matrix[i][j];
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

	double el, sr;
	int num;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (n == 1 && m == 1);	// 1 element

			else if (n == 1)	// 1 line
			{
				if (j == 0)
				{
					matrix[i][j] = (cmatrix[i][j + 1]);
				}
				else if (j == (m - 1))
				{
					(matrix[i][j] = cmatrix[i][j - 1]);
				}
				else matrix[i][j] = (cmatrix[i][j - 1] + cmatrix[i][j + 1]) / 2;
			}

			else if (m == 1)	// 1 column
			{
				if (i == 0)
				{
					matrix[i][j] = cmatrix[i + 1][j];
				}
				else if (i == (n - 1))
				{
					matrix[i][j] = cmatrix[i - 1][j];
				}
				else matrix[i][j] = (cmatrix[i - 1][j] + cmatrix[i + 1][j]) / 2;
			}

			else if (i == 0 && j == 0)
			{
				matrix[i][j] = (cmatrix[i + 1][j] + cmatrix[i + 1][j + 1] +
					cmatrix[i][j + 1]) / 3;	// Left top corner
			}
			else if (i == 0 && j == (m - 1))
			{
				matrix[i][j] = (cmatrix[i + 1][j] + cmatrix[i + 1][j - 1] +
					cmatrix[i][j - 1]) / 3;	// Right top corner
			}
			else if (i == (n - 1) && j == 0)
			{
				matrix[i][j] = (cmatrix[i - 1][j] + cmatrix[i - 1][j + 1] +
					cmatrix[i][j + 1]) / 3;	// Left bottom corner
			}
			else if (i == (n - 1) && j == (m - 1))
			{
				matrix[i][j] = (cmatrix[i - 1][j] + cmatrix[i - 1][j - 1] +
					cmatrix[i][j - 1]) / 3;	// Right bottom corner
			}
			else if (i == 0)
			{
				matrix[i][j] = (cmatrix[i][j - 1] + cmatrix[i + 1][j - 1] + cmatrix[i + 1][j] +
					cmatrix[i + 1][j + 1] + cmatrix[i][j + 1]) / 5;	// Top
			}
			else if (i == (n - 1))
			{
				matrix[i][j] = (cmatrix[i][j - 1] + cmatrix[i - 1][j - 1] + cmatrix[i - 1][j] +
					cmatrix[i - 1][j + 1] + cmatrix[i][j + 1]) / 5; // Bottom
			}
			else if (j == 0)
			{
				matrix[i][j] = (cmatrix[i - 1][j] + cmatrix[i - 1][j + 1] + cmatrix[i][j + 1] +
					cmatrix[i + 1][j + 1] + cmatrix[i + 1][j]) / 5;	// Left
			}
			else if (j == (m - 1))
			{
				matrix[i][j] = (cmatrix[i - 1][j] + cmatrix[i - 1][j - 1] + cmatrix[i][j - 1] +
					cmatrix[i + 1][j - 1] + cmatrix[i + 1][j]) / 5;	// Right
			}
			else
			{
				matrix[i][j] = (cmatrix[i - 1][j - 1] + cmatrix[i - 1][j] + cmatrix[i - 1][j + 1] +
					cmatrix[i][j + 1] + cmatrix[i + 1][j + 1] + cmatrix[i + 1][j] +
					cmatrix[i + 1][j - 1] + cmatrix[i][j - 1]) / 8;	// Inside
			}
		}
	}

	cout << "The smoothed matrix is: \n\n";

	for (int i = 0; i < n; i++)	// Output the array
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i][j] << "   ";
		}
		cout << "\n\n";
	}

	return 0;
}