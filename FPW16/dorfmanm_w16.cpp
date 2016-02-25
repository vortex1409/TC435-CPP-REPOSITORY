#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
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

timer0 timer0overflow()
{
	/*
	C = Iinterval Timer Size
	Fosc = Internal Frequency Clock Hz
	Prescaler = ratio to add additional variabiity
	*/
	
	timer0 overflow;

	overflow.TMR0ON = 1;
	overflow.T08BIT = 1;
	overflow.T0SC = 1;
	overflow.T0SE = 1;
	overflow.PSA = 1;
	overflow.T0PS[0] = 1;
	overflow.T0PS[1] = 1;
	overflow.T0PS[2] = 1;
	overflow.T_Period = 0;
	overflow.DecVal = 0;

	//for (int x; x < 3; x++)
	//{
	//	overflow.T0PS[x] = 1;
	//}

	double T = 0;
	double C = 0;
	double Fosc = 0;
	double prescaler = 0;
	int bitmenu = 0;
	int freqmenu = 0;
	int scalemenu = 0;

	cout << "Select Bits (1) 8 | (2) 16" << endl;
	cin >> bitmenu;

	if (bitmenu == 1)
	{
		C = 8;
		overflow.T08BIT = 1;

	}
	else if (bitmenu == 2)
	{
		C = 16;
		overflow.T08BIT = 0;
	}

	cout << "Select Frequency (1) 31 KHz | (2) 250 kHz" << endl;
	cout << "Select Frequency (3) 500 kHz | (4) 1 MHz" << endl;
	cout << "Select Frequency (5) 2 MHz | (6) 4 MHz" << endl;
	cout << "Select Frequency (7) 8 MHz | (8) 16 MHz" << endl;
	cin >> freqmenu;

	if (freqmenu == 1)
	{
		Fosc = 31000;
	}
	else if (freqmenu == 2)
	{
		Fosc = 250000;
	}
	else if (freqmenu == 3)
	{
		Fosc = 500000;
	}
	else if (freqmenu == 4)
	{
		Fosc = 1000000;
	}
	else if (freqmenu == 5)
	{
		Fosc = 2000000;
	}
	else if (freqmenu == 6)
	{
		Fosc = 4000000;
	}
	else if (freqmenu == 7)
	{
		Fosc = 8000000;
	}
	else if (freqmenu == 8)
	{
		Fosc = 16000000;
	}

	cout << "Select Prescaler (1) 1 | (2) 2" << endl;
	cout << "Select Prescaler (3) 4 | (4) 8" << endl;
	cout << "Select Prescaler (5) 16 | (6) 32" << endl;
	cout << "Select Prescaler (7) 64 | (8) 128" << endl;
	cout << "Select Prescaler (9) 256 |" << endl;
	cin >> scalemenu;

	if (scalemenu == 1)
	{
		prescaler = 1;
		overflow.PSA = 1;
		overflow.T0PS[0] = 0;
		overflow.T0PS[1] = 0;
		overflow.T0PS[2] = 0;

	}
	else if (scalemenu == 2)
	{
		prescaler = 2;
		overflow.PSA = 0;
		overflow.T0PS[0] = 0;
		overflow.T0PS[1] = 0;
		overflow.T0PS[2] = 0;
	}
	else if (scalemenu == 3)
	{
		prescaler = 4;
		overflow.PSA = 0;
		overflow.T0PS[0] = 1;
		overflow.T0PS[1] = 0;
		overflow.T0PS[2] = 0;
	}
	else if (scalemenu == 4)
	{
		prescaler = 8;
		overflow.PSA = 0;
		overflow.T0PS[0] = 0;
		overflow.T0PS[1] = 1;
		overflow.T0PS[2] = 0;
	}
	else if (scalemenu == 5)
	{
		prescaler = 16;
		overflow.PSA = 0;
		overflow.T0PS[0] = 1;
		overflow.T0PS[1] = 1;
		overflow.T0PS[2] = 0;
	}
	else if (scalemenu == 6)
	{
		prescaler = 32;
		overflow.PSA = 0;
		overflow.T0PS[0] = 0;
		overflow.T0PS[1] = 0;
		overflow.T0PS[2] = 1;
	}
	else if (scalemenu == 7)
	{
		prescaler = 64;
		overflow.PSA = 0;
		overflow.T0PS[0] = 1;
		overflow.T0PS[1] = 0;
		overflow.T0PS[2] = 1;
	}
	else if (scalemenu == 8)
	{
		prescaler = 128;
		overflow.PSA = 0;
		overflow.T0PS[0] = 0;
		overflow.T0PS[1] = 1;
		overflow.T0PS[2] = 1;
	}
	else if (scalemenu == 9)
	{
		prescaler = 256;
		overflow.PSA = 0;
		overflow.T0PS[0] = 1;
		overflow.T0PS[1] = 1;
		overflow.T0PS[2] = 1;
	}

	T = pow(2,C) * (1 / ((Fosc / 4) / prescaler));

	overflow.T_Period = T;

	overflow.intHex = overflow.TMR0ON * pow(2, 7) +
		overflow.T08BIT * pow(2, 6) +
		overflow.T0SC * pow(2, 5) +
		overflow.T0SE * pow(2, 4) +
		overflow.PSA * pow(2, 3) +
		overflow.T0PS[2] * pow(2, 2) +
		overflow.T0PS[1] * pow(2, 1) +
		overflow.T0PS[0] * pow(2, 0);

	return overflow;
}

void timer0config(int value)
{
	cout << "-------------------------------" << endl;
	intToBin(value);
	cout << endl;
	intToHex(value);
	cout << "-------------------------------";
}

// Quiz 6 -  A
void degtorad(double& input)
{
	double pi = 3.14159265;

	input = (input*pi) / 180;
}

// Quiz 6 - A
void radtodeg(double& input)
{
	double pi = 3.14159265;

	input = (input * 180) / pi;
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
