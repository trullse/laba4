// Лабораторная 4, задача 7. Выполнена: Леоненко А. О.

/* Дано натуральное число n. Требуется подсчитать количество цифр 
числа и определить, какая цифра стоит в разряде с номером i (разряды 
нумеруются с конца, т.е. разряд единиц имеет номер 0).
 */

#include <iostream>

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
	
	int n, len = 0, dig;

	cout << "This program counts number of digits and finds out what digit is placed under some number. \n"
		"Enter a number: ";
	n = input();
	int num = n;

	while (num != 0)
	{
		num /= 10; len++;
	}

	int* arrn = new int[len];
	for (int i = 0; i < len; i++)
	{
		arrn[i] = n % 10;
		n /= 10;
	}
	 
	cout << "Enter a number of digit: ";
	dig = input();

	if (dig > len - 1)
	{
		cout << "The digit under " << dig << " number is 0 \n";
	}
	else
	{
		cout << "The digit under " << dig << " number is " << arrn[dig] << "\n";
	}

	return 0;
}