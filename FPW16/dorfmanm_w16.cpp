#include <iostream>
#include "dorfmanm_w16.h"
using namespace std;

void firstTest(int input)
{
	cout << "Test #: " << input << endl;
}

void quiz_1(double input)
{
	double output;

	if (input == 0)
	{
		output = -1;
	}
	else
	{
		output = input + (input * (2 * input));
	}
}

void quiz_2(int input_1, char input_2) // DGG - Solution
{
	//In this version of quiz 2, the integer input was used for this loop
	if (input_2 == 'd') {
		for (int i = input_1; i <= input_1 + (3 * input_1); i++)
			cout << i << " ";
	}

	//in this particular case, it wasn't requested to run only one condition at a time (the character input_2 will control that).
	//Howevever, for good practice, it's always better to reduce the time a function takes to work, because it can be called multiple times.
	else if (input_2 == 'o') {
		for (int i = 0; i < 10; i++) {
			if (i < 7)
				cout << i + 1 << " ";
			else
				cout << i + 3 << " ";	//The output effect is like an octal cout up, but because it only uses numbers, there's no need for alphabetical conditions.
		}
	}

	else if (input_2 == 'm') {

		//method 1 - initializing the matriz
		int matrix[4][4] = { { 1, 1, 1, 1 },{ 1, 1, 1, 1 },{ 1, 1, 1, 1 },{ 1, 1, 1, 1 } };

		//method 2 - creating a loop to fill the matrix
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				matrix[i][j] = 1;
		}

		//prints the array as a 4 x 4 matrix
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}

	//Because all the previous statements are attached to the main if (i.e. they are else if's), a single else is enough
	//to catch any other combination not anticipated.
	else {
		cout << "I can't do that, John" << endl;
	}
}

int AmodB(int A, int B)
{
	int output;
	output = A%B;
	return output;
}

double customEquation_1(double A, double B, double C)
{
	double output;
	output = ((C * C)*sqrt(A + B)) + (C / (B + A) / C);
	return output;
}

void customEquation_2(int inputArray[], int sizeOfArray)
{
	int working_r = 0;

	// Part A
	for (int i = 0; i < sizeOfArray; i++)
	{
		working_r += inputArray[i];

	}

	cout << "Total: " << working_r << endl;

	working_r = inputArray[0];

	// Park B bubble sorting
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (inputArray[i] < working_r)
		{
			working_r = inputArray[i];
		}
		
	}
	cout << "Smallest Val: " << working_r << endl;
}

void intToHex(int, int inputNumber)
{
	if (inputNumber > 255)
	{
		cout << endl << "err" << endl;
	}
	else
	{
		char output_bit1, output_bit0;
		if()
	}
}


void firstClass::firstfunction()
{
	cout << "hello" << endl;
	firstClass working_r;
	cout << working_r.num1 << endl;
}

int firstClass::addTwo(int a, int b)
{
	return a + b;
}

