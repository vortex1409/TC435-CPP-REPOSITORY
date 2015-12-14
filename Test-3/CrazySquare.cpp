#include <iostream>
#include <iomanip>

//The following libraries are used for the random
#include <stdio.h>      /* NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

//Declared functions
void clearGlobals();
void printTable();
void inputFromUser();
void manualInput();
void autoModeForThisProgram();
void randomFill();
bool repeatedValues();


// Declared global variables - Will work for the whole program
int s11, s12, s13, s21, s22, s23, s31, s32, s33; //do not use arrays
int iteraciones;

//Main program
int main(){
	
	srand(time(NULL)); //random seed. Is an algorythm that creates the source for random numbers
					   // we will use the system clock to feed the random
	
	//Initial condition - for good programming practice
	clearGlobals();
	int _options; //Variable for initial options
	
	//Call for the program
	do{					// This is the infite loop. For us, is a menu.
		system("cls"); // CLears Screen so its easier to follow on screen.
		printTable();
		cout << "1. Auto mode (iterations)" << endl;
		cout << "4. Exit" << endl << "What should I do?: ";
		cin >> _options;

		if (_options == 4) // if the user inputs a 3, this condition is true
			break;		// break will "stop" the previous loop. In this case, the infinite loop.

		if (_options == 1){
			cout << "delay expected. Be patient (this message is not needed as part of your code) " << endl;
			autoModeForThisProgram();
		}

	} while (true); //the code will always run until a break is triggered.
	
	system("pause");
	return 0;
}

//Define functions
void printTable(){
	cout << "crazy square (3x3) - prepared by Daniel Garcia-Gonzalez" << endl;
	cout << setw(3) << s11 << setw(3) << s12 << setw(3) << s13 << " - " << s11 + s12 - s13 << endl;
	cout << setw(3) << s21 << setw(3) << s22 << setw(3) << s23 << " - " << s21 - s22 + s23 << endl;
	cout << setw(3) << s31 << setw(3) << s32 << setw(3) << s33 << " - " << s31 * s32 - s33 << endl;
	cout << setw(3) << "|" << setw(3) << "|" << setw(3) << "|" <<endl;
	cout << setw(3) << s11 + s21 - s31 << setw(3) << s12 * s22 - s32 << setw(3) << s13 + s23 - s33 << endl;
	cout << "iterations: " << iteraciones << endl << endl;
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
	iteraciones = 0;
}

void manualInput(){
	cout << "give me the value for coordinate 1, 1: ";
	cin >> s11;
	cout << "give me the value for coordinate 1, 2: ";
	cin >> s12;
	cout << "give me the value for coordinate 1, 3: ";
	cin >> s13;
	cout << "give me the value for coordinate 2, 1: ";
	cin >> s21;
	cout << "give me the value for coordinate 2, 2: ";
	cin >> s22;
	cout << "give me the value for coordinate 2, 3: ";
	cin >> s23;
	cout << "give me the value for coordinate 3, 1: ";
	cin >> s31;
	cout << "give me the value for coordinate 3, 2: ";
	cin >> s32;
	cout << "give me the value for coordinate 3, 3: ";
	cin >> s33;
	
	int evaluation = repeatedValues();

	if (evaluation == false){
		cout << "sorry, you gave me a repeated number, try again..." << endl;
		system("pause");
		system("cls");
		printTable();
		manualInput();
	}
		iteraciones++;
}   //manual input function closes here

bool repeatedValues(){
	//my rule: if there's no repeated numbers, this function
	//         will return a true; if there's a repeated number
	//		   it will return a false.

	if (s11 * s12 * s13 * s31 * s32 * s33 * s21 * s22 * s23 != 362880)
		return false;
	//if (s11 == s12 || s12 == s13 || s13 == s11)
	//	return false;
	//if (s21 == s22 || s22 == s23 || s23 == s21)
	//	return false;
	//if (s31 == s32 || s32 == s33 || s33 == s31)
	//	return false;
	//if (s11 == s21 || s21 == s31 || s31 == s11)
	//	return false;
	//if (s21 == s22 || s22 == s32 || s32 == s21)
	//	return false;
	//if (s31 == s32 || s32 == s33 || s33 == s31)
	//	return false;
	return true;
}

void randomFill(){
	int max = 9, min = 1;
	
	s11 = rand() % (max - min + 1) + min;
	s21 = rand() % (max - min + 1) + min;
	s31 = rand() % (max - min + 1) + min;
	s12 = rand() % (max - min + 1) + min;
	s13 = rand() % (max - min + 1) + min;
	s22 = rand() % (max - min + 1) + min;
	s33 = rand() % (max - min + 1) + min;
	s32 = rand() % (max - min + 1) + min;
	s23 = rand() % (max - min + 1) + min;
	s21 = rand() % (max - min + 1) + min;

	bool evaluation = repeatedValues();

	if (evaluation == false ){
		randomFill();
	}
}

void autoModeForThisProgram(){
	clearGlobals();
	do{
		randomFill();
		iteraciones++;
		if (iteraciones > 1000000){
			cout << "overload" << endl;
			system("pause");
			break;
		}

	}while(((s11 + s12 - s13) == 4 && (s21 - s22 + s23) == 8 && (s31 * s32 - s33) == 8 && (s11 + s21 - s31) == 6 && (s12 * s22 - s32) == 2 && (s13 + s23 - s33) == 6) == false);
}
