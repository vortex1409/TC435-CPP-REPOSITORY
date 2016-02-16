#include <iostream>
#include "dorfmanm_w16.h"
using namespace std;

/*
Name: Michael Dorfman
Course: TC435
Project: dorfmanm_w16.h

Library/Archive file that contains all functions, structures and classes.
*/

//--------------- DECLARING FUNCTIONS ----------------------

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

void identityMatrix(int sizeOfMatrix) {

	int eye[1] = { 1 };
	int eye2x2[2][2] = { { 1, 0 },{ 0, 1 } };
	int eye3x3[3][3] = { { 1, 0, 0 },{ 0, 1, 0 },{ 0, 0, 1 } };

	//limit identity to size 2 or 3
	if (sizeOfMatrix == 2) 
	{
		for (int x = 0; x < 2; x++) 
		{
			for (int y = 0; y < 2; y++) 
			{
				cout << eye2x2[x][y] << " ";
			}
			cout << endl;
		}
	}
	else if (sizeOfMatrix == 3) 
	{
		for (int x = 0; x < 3; x++) 
		{
			for (int y = 0; y < 3; y++) 
			{
				cout << eye3x3[x][y] << " ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << eye[0];
	}
}

void determinantOfMatrix(int[][3], int) 
{

}

//void intToHex(int inputNumber) 
//{
//	if (inputNumber > 255) 
//	{
//		cout << endl << "error" << endl;
//	}
//	else 
//	{
//		char output_bit_1, output_bit_0;
//		if (inputNumber >= 240)
//			cout << endl;
//	}
//}

void intToHex(int input)
{
	cout << "Hex: " << hex << input << "h" << endl;
}

void intToBin(int input)
{
	int binary_array[100], i = 0, j;

	while (input > 0)
	{
		binary_array[i] = input % 2;
		i++;
		input = input / 2;
	}
	
	cout << "Binary: ";

	for (j = i - 1; j >= 0; j--)
	{
		cout << binary_array[j];
	}

	cout << "b";
}
// ------------- DECLARING CLASSES-----------------------

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

