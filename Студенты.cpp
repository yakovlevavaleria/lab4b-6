// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct STUDENT

{
	string name;
		int group;
	float ses[5];
};
int main()
{
	const int size = 5;
	STUDENT studl[size];
	int i, j;
	int n = 0;
	int count = 0;

	for (i = 0; i < size; i++)
	{
		cout << "Enter the surname of student" << endl;
		cin >> studl[n].name;
		cout << "Enter number of group" << endl;
		cin >> studl[n].group;
		cout << "Enter 5 assessment" << endl;
		for (int i = 0; i < 5; i++)
			cin >> studl[n].ses[i];
		n++;

	}
	float sum = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
			sum += studl[i].ses[j];

		if (sum / 5 > 4.0)
		{
			cout << studl[i].name << endl;
			cout << studl[i].group << endl;

		}
		else
			count++;
		sum = 0;
	}
	if (count == size)
		cout << "This student are missing" << endl; 
	system ("pause");

}

