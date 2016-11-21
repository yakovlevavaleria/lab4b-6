// ConsoleApplication25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

double sum(double a, double b)
{
	return a + b;
}
double subtraction(double a, double b)
{
	return a - b;
}
double multiplication(double a, double b)
{
	return a*b;
}
double division(double a, double b)
{
	return a / b;
}



int main()
{

	const double a = 2.45, b = 4.23;
	cout << "Sum of numbers a+b= " << double(sum(a, b)) << endl;
	cout << "Subtracion of numbers a-b= " << double(subtraction(a, b)) << endl;
	cout << "Multiplication of numbers a*b= " << double(multiplication(a, b)) << endl;
	cout << "Division of numbers a/b= " << double(division(a, b)) << endl;
	
	system("pause");

}


