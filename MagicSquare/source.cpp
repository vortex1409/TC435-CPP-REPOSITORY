#include <iostream>
//the following libraries are used for the random number generation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//declared functions
void clearGlobals();
void printTable(); 
void inputFromUser();
void manualInput(); 

int s11, s12, s13, s21, s22, s23, s31, s32, s33;

int main(){

	//initial condition
	clearGlobals();
	int _options; //variab;e for initial options
	//call for table
	do{
		printTable();
		cout << "1. Manual Mode (input values)" << endl;
		cout << "2. Auto Mode (iterations)" << endl;
		cout << "3. Exit" << endl << "What should i do?";
		cin >> _options

			if (_options == 3)
				break;


	} while (true);  //will always run until break is triggered

	system("pause");
	return 0;
}


//defined functions
void printTable(){
	cout << s11 << s12 << s13 << endl << s21 << s22 << s23 << endl << s31 << s32 << s33 << endl;
}

void clearGlobals(){
	s11 = 0;
	s12 = 0;
	s13 = 0;
	s21 = 0;
	s22 = 0;
	s23 = 0;
	s31 = 0;
	s32 = 0;
	s33 = 0;
}

void manualInput(){
	cout << "Give me the value for coordinate 1, 1: ";
	cin >> s11;
	cout << "Give me the value for coordinate 1, 2: ";
	cin >> s12;
	cout << "Give me the value for coordinate 1, 3: ";
	cin >> s13;
	cout << "Give me the value for coordinate 2, 1: ";
	cin >> s21;
	cout << "Give me the value for coordinate 2, 2: ";
	cin >> s22;
	cout << "Give me the value for coordinate 2, 3: ";
	cin >> s23;
	cout << "Give me the value for coordinate 3, 1: ";
	cin >> s31;
	cout << "Give me the value for coordinate 3, 2: ";
	cin >> s32;
	cout << "Give me the value for coordinate 3, 3: ";
	cin >> s33;
}
