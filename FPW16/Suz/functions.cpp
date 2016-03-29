#include <iostream>
#include "veillieuxs_w16.h"   //fundamental concept
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;

//Name : Susan Veillieux
//Course: TC-435
//Project: Custom Header File

//define the functions from the .h file

//Created by: Susan Veillieux
//Description: prints a label on the screen
void firstFunction(){
	cout << "Hello, World!" << endl;
}

//Created by: Susan Veillieux
//Description: Quiz_1 Review
double quiz_1(double input)
{
	if (input == 0)
		return -1; //fail safe

	//2; 2+4*2:10
	//option 1
	double output = input + 2 * input *input;

	//option 2
	output = input;
	for (int i = 0; i < 2; i++)
	{
		output += input;
	}

	//option 3
	while (output < 2 * input)
	{
		output += input;
	}

	//output = output / ((output / 2) + 1);
	return output / ((output / 2) + 1);
}

//Created by: Susan Veillieux
//Description: Quiz_2 Matrixes
void quiz_2(int input_num, char input_chara)
{
	if (input_chara == 'd')
	{
		for (int i = input_num; i <= input_num + (3 * input_num); i++){
			cout << i << " ";
		}//for loop closes here
		cout << endl;
	}//if stmt closes here
	else if (input_chara == 'o'){
		for (int i = 0; i < 11; i++){
			if (i < 8)
				cout << i << " ";
			else
				cout << i + 2 << " ";
		}//for loop ends here
		cout << endl;
	}//else if ends here
	else if (input_chara == 'm'){
		int matrixOnes[4][4];

		for (int i = 0; i < 4; i++) //Fill matrix with ones
			for (int j = 0; j < 4; j++)
				matrixOnes[i][j] = 1;

		for (int i = 0; i < 4; i++) //print matrix as a table
			for (int j = 0; j < 4; j++)
				cout << matrixOnes[i][j] << " ";
		cout << endl;

	}//else if ends here
}//fucntion closes here

//Created by: Susan Veillieux
//Description: Quiz 3 - AmodB & CustEquation
int AmodB(int a, int b){

return a%b;
}
double customEquation_1(double A, double B, double C){

return (((C*C) * sqrt(A + B)) + ((C / ((B + A) / C))));
}

//Created by: Susan Veillieux
//Description: Matrix Exercise
void eyeMatrix(int sizeOfIdentMatrix)
{
int eye[1] = { 1 };		//Identity Matrix - I
int eye2x2[2][2] = { { 1, 0 }, { 0, 1 } };
int eye3x3[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

//Chooses which matrix to print.
if (sizeOfIdentMatrix == 2){
for (int z = 0; z < 2; z++){
for (int g = 0; g < 2; g++)
cout << eye2x2[z][g] << " ";
cout << endl;
}//Main FOR loop closes here.
}//If stmt closes here.
else if (sizeOfIdentMatrix == 3)
for (int z = 0; z < 3; z++){
for (int g = 0; g < 3; g++)
cout << eye3x3[z][g] << " ";
cout << endl;
}// Main FOR loop closes here
else{
cout << eye[0] << endl;
}
}

//Created by: Susan Veillieux
//Description: Binary Function
/*
void inttobin(int inputvariable)
{//			bit wise		7  6  5  4  3  2  1  0
int binaryoutput[8] = { 0, 0, 0, 0, 0, 0, 0, 0, };
//          index       0  1  2  3  4  5  6  7


if (inputvariable < 0 || inputvariable > 255)
cout << "Error" << endl;
else
{
int working_r = inputvariable;
if (working_r >= 128)	//2^7
{
binaryoutput[0] = 1;
working_r -= 128;
}
if (working_r >= 64)	//2^6
{
binaryoutput[1] = 1;
working_r -= 64;
}
if (working_r >= 32)	//2^5
{
binaryoutput[2] = 1;
working_r -= 32;
}
if (working_r >= 16)	//2^4
{
binaryoutput[3] = 1;
working_r -= 16;
}
if (working_r >= 8)		//2^3
{
binaryoutput[4] = 1;
working_r -= 8;
}
if (working_r >= 4)		//2^2
{
binaryoutput[5] = 1;
working_r -= 4;
}
if (working_r >= 2)		//2^1
{
binaryoutput[6] = 1;
working_r -= 2;
}
if (working_r >= 1)		//2^0
{
binaryoutput[7] = 1;
working_r -= 1;
}

for (int i = 0; i < 8; i++)
{
cout << binaryoutput[i] << " ";
}




}// else closes here

}//function closes here
*/

//Created by: Susan Veillieux
//Description: Custom Equation #2
/*
void customequation_2(int inputarray[], int sizeofarray)
{
int working_r = 0;

//step a
for (int x = 0; x < sizeofarray; x++)
working_r += inputarray[x];

cout << "The total is : " << working_r << endl;

//step b
working_r = inputarray[0];
for (int x = 0; x < sizeofarray; x++)
{
if (inputarray[x]>working_r)
working_r = inputarray[x];

}//for loop finishes here

cout << "the largest number is : " << working_r << endl;

}//function finishes here
*/


/*-------------------- TEST  1 / FEB.16.16 -------------------*/
/*
void timer0overflow(timer0){
int input_bit, input_freq, input_presc;
int c, Fosc, prescaler;
double T_Period;
cout << "Select the desired control bit (8 or 16):" << endl;
cout << "\t 1) 8 bit\n" << "\t 2) 16 bit\n" << endl;
cin >> input_bit;

if (input_bit == 1)
c = 8;
if (input_bit == 2)
c = 16;

cout << "Select from the following frequencies:" << endl;
cout << "\t1) 1 MHz\n" << "\t2) 2 MHz\n" << "\t3) 4 MHz\n" << "\t4) 8 MHz\n" << "\t5) 16 MHz\n" << endl;
cin >> input_freq;

if (input_freq == 1)
Fosc = 1000000;
if (input_freq == 2)
Fosc = 2000000;
if (input_freq == 3)
Fosc = 4000000;
if (input_freq == 4)
Fosc = 8000000;
if (input_freq == 5)
Fosc = 16000000;

cout << "Select from the following prescaler factors:" << endl;
cout << "\t1) 1\n" << "\t2) 2\n" << "\t3) 4\n" << "\t4) 8\n" << "\t5) 16\n"
<< "\t6) 32\n" << "\t7) 64\n" << "\t8) 128\n" << endl;
cin >> input_presc;

if (input_presc == 1)
prescaler = 1;
if (input_presc == 2)
prescaler = 2;
if (input_presc == 3)
prescaler = 4;
if (input_presc == 4)
prescaler = 8;
if (input_presc == 5)
prescaler = 16;
if (input_presc == 6)
prescaler = 32;
if (input_presc == 7)
prescaler = 64;
if (input_presc == 8)
prescaler = 128;

T_Period = pow(2, c)*(1 / ((Fosc / 4) / prescaler));
}
void timer0config(int){

}
*/

/*-------FEB.26.16-------*/
//Created by: Susan Veillieux
//Description: Quiz 6 & C-Strings
/*QUIZ 6*/
void degToRad(double &input){
	const double pi = 3.1415928;
	input = (input*pi) / 180;
}
void radToDeg(double &input){
	const double pi = 3.1415928;
	input = (input * 180) / pi;
}

/*Translate chars --> numbers, and identify --> hex or bin*/

int sizeOfString(char input[]){
	//func. returns the number of charas inside the string
	int working_r = 0;
	while (input[working_r] != '\0')
		working_r++;
	return working_r;
}
void StringToBin(char input[]){
	//step 1: know the size of the string
	int sizeOftheString = sizeOfString(input);
	//step 2: conversion chara in a string to a number
	int working_r = 0, counter = 0;
	//loop that does the conversion
	for (int i = 0; i < (sizeOftheString - 1); i++){
		counter = input[i] - 48;		//0 is chara 48, 9 is chara 57
		working_r += (pow(10, ((sizeOftheString - 2) - i))*counter);
	}
	cout << working_r << endl; //number translated here

	//final step - convert to binary
	//inttobin(working_r);		//the binary conversion code is commented above
}


/*-------MAR.4.16-------*/
/* QUIZ 7 */
/*
void WhoAreYou(){
cout << "Name: Susan Veillieux\n" << "Course: TC-435, Winter 2016\n" << "Program: Electrical Engineering Tech.\n"
<< "Header File Function: The header file allows me to store structures/functions, and variables"
<< "associated with those particular components." << endl;
}
//void vowelCounter(){
//cout << "Print a sentence. 30 characters maximum:\n";
//char sentence[30];
//cin >> sentence;
//
//for (int i = 0; i <= 30; i++)
//
//}
*/
/* QUIZ 7 SOLUTION - vowelCounter */
/*
void vowelCounter(){
char inputString[30];
do{
system("cls");
cout << "Print a sentence. 30 characters maximum (nospaces):\n";
cout << ":: ";
cin >> inputString;
} while (strlen(inputString) > 29);		//why? Need room for the null character.

int working_r = 0;
for (int i = 0; i < strlen(inputString); i++){
if (inputString[i] == 'A' || inputString[i] == 'a')
working_r++;
if (inputString[i] == 'E' || inputString[i] == 'e')
working_r++;
if (inputString[i] == 'I' || inputString[i] == 'i')
working_r++;
if (inputString[i] == 'O' || inputString[i] == 'o')
working_r++;
if (inputString[i] == 'U' || inputString[i] == 'u')
working_r++;
}//closes for loop
cout << "Vowels counted: " << working_r << endl;
}
*/

void plotFunc(int min, int max, int step){

	ofstream fileToPlot("DataBase.txt");
	double _Y = 0.0, _Y2 = 0.0, _Y3 = 0.0, angle = 0.0;
	int working_r = 1;		//count up

	if (fileToPlot.is_open()){
		for (int x = min; x <= max; x += step){
			angle = x;
			degToRad(angle);
			_Y = sin(angle);
			
			angle = x + 60;
			degToRad(angle);
			_Y2 = sin(angle);

			angle = x + 120;
			degToRad(angle);
			_Y3 = sin(angle);

			//this section stores the info
			fileToPlot << working_r << " " << _Y << " " << _Y2 << " " << _Y3 << endl;
			working_r++;
		}//for loop closes here

		fileToPlot.close();

	}//if stmt ends
	else
		cout << "It is impossible to open or create the file.";
}

/*-------------------- Assignment 5 & 6 -- DUE. MAR 26/16-------------------*/
double pi(){
	return 3.14159265;
}
double Exponent(double input){
	return pow(2.718281828, input);
}
void Equation_1(PLC& temporal){
	if (temporal.System_T == 0)
	{
		temporal.CharaEffects[0] = 0;
	}
	else
		temporal.CharaEffects[0] = (Exponent(1 / (temporal.System_T))*-1);
}
double capacitance(double cap, double freq){
	return 1 / (2 * pi()*cap*freq);
}
double inductance(double cap, double freq){
	return 2 * pi()*freq*cap;
}
void Equation_2(PLC& temporal){
	temporal.CharaEffects[1] = temporal.System_G *(1 + temporal.CharaEffects[0]);
}
void Equation_3(Filter_RC& temporal){
	temporal.Fh = 1 / (2 * pi() * temporal.Resistance_HP * temporal.cap_HP);
}
void Equation_4(Filter_RC& temporal){
	temporal.Fl = 1 / (2 * pi() *  temporal.Resistance_LP * temporal.cap_LP);
}
void Equation_5(Filter_RC& temporal){
	Equation_3(temporal);
	Equation_4(temporal);
	temporal.Fr = (sqrt(temporal.Fh * temporal.Fl));
}
double impedance(double IN_1, double IN_2, double IN_3){
	return (sqrt(pow(IN_1, 2) + pow((IN_2 - IN_3), 2)));
}
