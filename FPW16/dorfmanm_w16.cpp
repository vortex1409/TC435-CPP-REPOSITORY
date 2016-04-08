#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
#include <cstring>
#include <fstream>
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

	T = pow(2, C) * (1 / ((Fosc / 4) / prescaler));

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

int sizeofCString(char inputString[]) {
	//this function returns the size of the Cstring
	int indexx = 0;

	while (inputString[indexx] != '\0') {
		indexx++;
	}

	return indexx;
}

void StringToBin(char inputString[]) {
	int sizeOfString = sizeofCString(inputString);
	int byte[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	//NOTE that 1 is character 49 in ASCII, 0 is character 48 in ASCII

	int WREG = 0, counter = 0;

	for (int i = 0; i < (sizeOfString - 1); i++) {
		counter = inputString[i] - 48;
		WREG += (pow(10, ((sizeOfString - 2) - i)) * counter);
	}
	cout << WREG << endl;

	//add intToBin(WREG);
	intToBin(WREG);
	cout << endl;
	intToHex(WREG);

}

// Quiz - 7 A
void WhoAreYou()
{
	cout << "Michael Dorfman" << endl;
	cout << "TC435" << endl;
	cout << "Computer Software C++" << endl;
	cout << "Header file directs the main to functions stored in the header .cpp file" << endl;
}

// Quiz - 7 A
void vowelCounter()
{
	char inputString[100];
	double working_r = 0;
	do
	{
		system("cls");
		cout << "Input: ";
		cin >> inputString;
	} while (strlen(inputString) > 99);

	for (int i = 0; i < strlen(inputString); i++)
	{
		if (inputString[i] == 'a' || inputString[i] == 'A')
		{
			working_r++;
		}
		if (inputString[i] == 'e' || inputString[i] == 'E')
		{
			working_r++;
		}
		if (inputString[i] == 'i' || inputString[i] == 'I')
		{
			working_r++;
		}
		if (inputString[i] == 'o' || inputString[i] == 'O')
		{
			working_r++;
		}
		if (inputString[i] == 'u' || inputString[i] == 'U')
		{
			working_r++;
		}
	}

	cout << "Vowels counted: " << working_r << endl;
}

//Moved to Bottom (Redundancy)

//void plot(int min, int max, int step)
//{
//	ofstream plotFile("database.txt");
//	int working_r = 1;
//
//	if (plotFile.is_open())
//	{
//		for (int i = min; i < max; i += step)
//		{
//			plotFile << working_r << " " << i << endl;
//			working_r++;
//		}
//
//		plotFile.close();
//
//	}
//}

double pie()
{
	double pi = 3.14159265;
	return pi;
}

double exponent(double input)
{
	return pow(2.718281828, input);
}

void Equation_1(PLC& equ)
{
	double e = 2.718281828;

	if (equ.System_T == 1)
	{
		equ.CharacteristicEffects[0] = 0;
	}
	else
	{
		equ.CharacteristicEffects[0] = pow(e, (1 / equ.System_T));
	}

}

double capacitance(double f, double c)
{
	double Xc;

	Xc = 1 / (2 * pie() * f * c);
	return Xc;
}

double inductance(double f, double L)
{
	double XL;

	XL = 2 * pie() * f * L;
	return XL;
}

void Equation_2(PLC& equ2)
{
	equ2.CharacteristicEffects[1] = equ2.System_G*(1 + equ2.CharacteristicEffects[0]);
}

void Equation_3(filter_RC& equ3)
{
	equ3.Fr = 1 / (2 * pie()*equ3.Resistance_HP*equ3.cap_HP);
}

void Equation_4(filter_RC &equ4)
{
	equ4.Fl = 1 / (2 * pie()*equ4.Resistance_LP*equ4.cap_LP);
}

void Equation_5(filter_RC& equ5)
{
	equ5.Fr = sqrt(equ5.Fh * equ5.Fl);
}

double Impedance(double x1, double x2, double x3)
{
	double Z;

	Z = sqrt(pow(x1, 2) + pow((x2 - x3), 2));
	return Z;
}

// TEST 2

void initializeFilter(filter_RC& filter_var)
{
	/*system("cls");
	cout << "Cap HP Val: (nF): ";
	cin >> filter_var.cap_HP;
	cout << "Cap LP Val: (nF): ";
	cin >> filter_var.cap_LP;
	cout << "Resistor HP Val: (kOhms): ";
	cin >> filter_var.Resistance_HP;
	cout << "Resistor LP Val: (kOhms): ";
	cin >> filter_var.Resistance_HP;*/
	
	filter_var.cap_HP = 15;
	filter_var.cap_LP = 0.56;
	filter_var.Resistance_HP = filter_var.Resistance_LP = 10;

	power_correction(filter_var);

	resonantFrequency(filter_var);

}

void power_correction(filter_RC& input)
{
	input.cap_HP = input.cap_HP*pow(10, -9);
	input.cap_LP = input.cap_LP*pow(10, -9);
	input.Resistance_HP = input.Resistance_HP * pow(10, 3);
	input.Resistance_LP = input.Resistance_LP * pow(10, 3);

}

void resonantFrequency(filter_RC& RF)
{
	hi_cutOff_Frequency(RF);
	lo_cutOff_Frequency(RF);
	RF.Fr = sqrt(RF.Fh * RF.Fl);
}

void hi_cutOff_Frequency(filter_RC& hcutoff)
{
	hcutoff.Fh = 1 / (2 * pie()* hcutoff.Resistance_HP * hcutoff.cap_HP);
}

void lo_cutOff_Frequency(filter_RC& lcutoff)
{
	lcutoff.Fl = 1 / (2 * pie()*lcutoff.Resistance_LP * lcutoff.cap_LP);
}

void bandPassFilter(filter_RC& var)
{
	if (var.Frequency <= var.Fr)
	{
		/*highPassFilter(var);*/
		lowPassFilter(var);
	}
	else
	{
		/*lowPassFilter(var);*/
		highPassFilter(var);
	}

}	

void effectiveImpedance(filter_RC& var)
{
	if (var.Frequency <= var.Fr)
	{
		var.Capacitance = capacitance(var.Frequency,var.cap_HP);
		var.Impedance = Impedance(var.Resistance_HP, 0, var.Capacitance);
	}
	else
	{
		var.Capacitance = capacitance(var.Frequency, var.cap_LP);
        var.Impedance = Impedance(var.Resistance_LP, 0, var.Capacitance);
	}
	
}

void highPassFilter(filter_RC& var) 
{
	effectiveImpedance(var);
	
	var.Amplitude = var.Resistance_HP / var.Impedance;
}

void lowPassFilter(filter_RC& var)
{
	effectiveImpedance(var);

	var.Amplitude = var.Capacitance / var.Impedance;
}

void functionToPlot(plotter& plot, filter_RC& filter)
{
	filter.Frequency = plot._X;
	bandPassFilter(filter);
	plot._Y = filter.Amplitude;
}

void plotFilter(plotter& plot, filter_RC& filter)
{
	ofstream myfile("test2.txt");
	double vfile = 1;

	strncpy_s(plot.X_axisLabel, "Frequency(Hz)",15);
	strcpy_s(plot.Y_axisLabel, "Voltage(Vpp)");

	


	if (myfile.is_open())
	{
		myfile << plot.X_axisLabel << " " << plot.Y_axisLabel << endl;
		for (int i = plot.axis_MIN; i < plot.axis_MAX; i += plot._step)
		{
			plot._X = i;
			functionToPlot(plot, filter);
			myfile << i << " " << plot._Y << endl;
		} 

		myfile.close();

	}

}

void plot(int min, int max, int step)
{
	ofstream plotFile("database.txt");
	int working_r = 1;

	if (plotFile.is_open())
	{
		for (int i = min; i < max; i += step)
		{
			plotFile << working_r << " " << i << endl;
			working_r++;
		}

		plotFile.close();

	}
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

//Almost an object - uController
void uController::initializeController() {
	initialized = true;	//Condition to avoid memory errors and problems addressing pointers.
	for (int i = 0; i < sizeof(controllerMemory) / sizeof(controllerMemory[0]); i++)
		controllerMemory[i] = 0;
	working_r = &controllerMemory[0];	//the pointer working_r of the object is "pointing at (looking at)" the memory address of the first element of this array
	for (int i = 0; i < sizeof(equivalentByte) / sizeof(equivalentByte[0]); i++)
		equivalentByte[i] = 0;
}



void uController::print(char input[]) {//dont forget to include a space after
	if (initialized == true) {//first if
		if (input[0] == 'w') {//second if		with lower case, I call the integer value of the working R. IT value it is pointing at.
			cout << *working_r;	//printing the content of the memory address, the pointer is looking at.
		}//second if
		else if (input[0] == 'W') {//first else-if  with upper case, I call the same value, decoded in bits. In reality, I print an array with specific conditions.
			for (int i = 0; i < 16; i++)
				cout << equivalentByte[i] << " ";
			cout << endl;
		}//first else-if
		else
			cout << "  ** no variable under that category **" << endl;
	}//first if
	else
		cout << endl << "  **controller not initialized**" << endl;
}//function closes




void uController::MOVLW(char input[]) {
	if (initialized == true) {		//fail safe
									//me (the programmer) know that the pointer working_R is "looking at"
									//the index memeber 0 of the array controllerMemory. So, I save the
									// literal (the value,the integer) to such index of the array.
		controllerMemory[0] = charToInt(input);

		//now that I have the literal, I convert the operation to a binary
		//sequence.
		convertToByte("movlw");
	}
	else
		cout << endl << "  **controller not initialized**" << endl;
}





void uController::stopController() {
	//this function is for good practice. Clears all data.
	initialized = false;
	for (int i = 0; i < sizeof(controllerMemory) / sizeof(controllerMemory[0]); i++)
		controllerMemory[i] = 0;
	working_r = &controllerMemory[0];
	for (int i = 0; i < sizeof(equivalentByte) / sizeof(equivalentByte[0]); i++)
		equivalentByte[i] = 0;
}

int uController::sizeOfChar(char input[]) {
	//this function calculates the size of the input cstring
	int WREG = 0;
	while (input[WREG] != '\0')
		WREG++;
	return WREG;
}

int uController::charToInt(char input[]) {
	//Converting a input cstring into an integer
	int WREG = 0;
	int sizeOfInputString = sizeOfChar(input);
	int holder = 0;

	for (int i = 0; i < sizeOfInputString; i++) {
		holder = static_cast<int>(input[i]) - 48;   //using the ASCII table to convert to integer. Risky.
		if (holder < 0 || holder > 9)
			WREG += 0;
		else
			WREG += static_cast<int>(holder * pow(10, (sizeOfInputString - 1) - i));
	}
	return WREG;
}

void uController::convertToByte(char input[]) {
	//stores the simulated bit sequence into the proper array.
	if (input == "movlw") {
		//Will print the byte represented by the movlw function and the input byte from the user.
		intToBinC(*working_r, equivalentByte);	//stores the byte in the working r, first

		for (int i = 0; i < 4; i++) //fills everything according to the documentation
			equivalentByte[i] = 0;

		for (int i = 4; i < 8; i++)
			equivalentByte[i] = 1;
	}
	else
		cout << " **byte conversion not possible**" << endl;
}

void uController::intToBinC(int inputConversion, int arrayToStore[]) {
	//limited to 0 to 255
	//building the simulated binary sequence relative to the inputConversion integer.
	int powerOfinput = 7/*definePower(2, inputConversion)*/;
	int holder = inputConversion;
	int sizeOfArray = 16;	//limited to be used with the equivalentByte array

	if (holder < 0 || holder > 255)	//fail safe to limit the input between 0 to 255
		cout << endl << "  **  ERROR: out of range  **  " << endl;
	else
	{	//Will print the number of bits required for the specific number (no more than the size of my input), instead of a whole string of 8
		for (int i = ((sizeOfArray - 1) - powerOfinput); i < sizeOfArray; i++) {
			if (holder >= pow(2, (sizeOfArray - 1) - i)) {
				arrayToStore[i] = 1;	//starts recording at the maximum bit needed
				holder -= static_cast<int>(pow(2, (sizeOfArray - 1) - i));	//not the best approach, but works
			}
			else
				arrayToStore[i] = 0;
		}
	}
}
