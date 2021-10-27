// Лабораторная 4, задача 9. Выполнена: Леоненко А. О.

/* В качестве входных данных поступают две целочисленные 
матрицы A и B, которые имеют размер N и соответственно. Требуется найти 
произведение матриц A*B. Выделение памяти через функции языка С.
 */

#include <iostream>
#include <stdlib.h>
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

int** MakeMatrix(int n, int m)
{
	int** mat = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		mat[i] = (int*)malloc(m * sizeof(int));
	}
	return mat;
}

void DelMatrix(int** mat, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		free(mat[i]);
	}
	free(mat);
}

int main() {

	int n, m, k;
	cout << "This program multiplies two matrices (N * M and M * K). \n"
		"Enter the size of matrix (N): ";
	n = input();
	cout << "Enter the size of matrix (M): ";
	m = input();
	cout << "Enter the size of matrix (K): ";
	k = input();

	int** mat = MakeMatrix(n, m);

	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = 1 + rand() % 5;
		}
	}

	cout << "The first matrix is: \n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << "   ";
		}
		cout << "\n\n";
	}

	int** mat2 = MakeMatrix(m, k);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			mat2[i][j] = 1 + rand() % 5;
		}
	}

	cout << "The second matrix is: \n\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << mat2[i][j] << "   ";
		}
		cout << "\n\n";
	}

	int** res = MakeMatrix(n, k);
	int sum = 0, M, K;
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < k; b++)
		{
			for (int c = 0; c < m; c++)
			{
				sum = sum + mat[a][c] * mat2[c][b];
			}
			res[a][b] = sum; sum = 0;
		}
	}

	cout << "The result is: \n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cout << res[i][j] << "   ";
		}
		cout << "\n\n";
	}

	DelMatrix(mat, n, m);
	DelMatrix(mat2, m, k);
	DelMatrix(res, n, k);

	return 0;
}