// Лабораторная 4, задача 6. Выполнена: Леоненко А. О.

/* Для заданной матрицы построить матрицу такого же размера, элементы которой
	обладают следующим свойством: элемент В равен максимальному из элементов матрицы
	А, расположенных левее и выше позиции элемента, включая эту позицию. */

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

int main() {

	int n, m;
	cout << "This program builds matrix and does task with elements with maximum value. \n"
		"Enter the size of matrix (n): ";
	n = input();
	cout << "Enter the size of matrix (m): ";
	m = input();

	int** mat = new int* [n];	// Building a matrix and filling it
	for (int i = 0; i < n; i++)
	{
		mat[i] = new int[m];
	}

	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			mat[i][j] = 1 + rand() % 50;
		}
	}

	cout << "The first matrix is: \n\n";
	for (int i = 0; i < n; i++)	// Output matrix
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat[i][j] << "  ";
		}
		cout << "\n\n";
	}

	int** mat2 = new int* [n];	// Building another matrix
	for (int i = 0; i < n; i++)
	{
		mat2[i] = new int[m];
	}

	int max;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			max = 0;
			for (int I = 0; I <= i; I++)
			{
				for (int J = 0; J <= j; J++)
				{
					if (mat[I][J] > max) max = mat[I][J];
				}
			}
			mat2[i][j] = max;
		}
	}

	cout << "The second matrix is: \n\n";
	for (int i = 0; i < n; i++)	// Output the second matrix
	{
		for (int j = 0; j < m; j++)
		{
			cout << mat2[i][j] << "  ";
		}
		cout << "\n\n";
	}

	return 0;
}