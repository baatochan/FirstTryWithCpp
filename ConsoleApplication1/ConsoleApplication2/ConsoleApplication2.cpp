// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

int main()
{
	int x;
	int y;
	cout << "Podaj dlugosc tablicy: ";
	cin >> x;
	int array[x];
beggining:
	for (int i = 0; i < x; i++) {
		y = rand() % 19 - 9;
		array[i] = y;
		cout << y << endl;
	}
	cout << "Tablica: " << endl;
	for (int i = 0; i < x; i++) {
		cout << "Element " << i + 1 << ": " << array[i] << endl;
	}
	getch();
	goto beggining;
	return 0;
}