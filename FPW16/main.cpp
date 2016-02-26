#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
#include "dorfmanm_w16.h" // Stored in Same DIR Relative to main.cpp
using namespace std;

//--------- FUNCTIONS START -------------------



//--------- FUNCTIONS END --------------------

int main() {
	//--------- MAIN START ------------------
	/*while (true) {
		timer0 overflow;

		overflow = timer0overflow();
		timer0config(overflow.intHex);
	}*/

		/*
	double degrees = 180;

	cout << degrees << endl;
	degToRad(degrees);
	cout << degrees << endl;
	radToDeg(degrees);
	cout << degrees << endl;


	char aString[10] = "HELLO!";
	cout << aString << endl;
	cout << aString[0] << endl;
	cout << aString[1] << endl;
	cout << aString[2] << endl;

	cout << sizeof(aString) << endl;
	cout << strlen(aString) << endl;

	char anotherCString[50];
	cout << anotherCString[50];
	cout << "GIMME A WOOORDD: ";
	cin >> anotherCString;

	//print contents of new c-string
	cout << "::" << anotherCString << endl;

	//1st is target array
	//2nd is source array
	//3rd is how many characters of the source (exclude null \0)
	strncat_s(anotherCString, aString, 9);
	cout << "::" << anotherCString << endl;

	strncat_s(anotherCString, "-random", 7);
	cout << "::" << anotherCString << endl;

	char thirdCString[100];
	//testing copy function for strings
	strncpy_s(thirdCString, anotherCString, 50);
	cout << "::" << thirdCString << endl;

	//test the function to compare two cstrings
	//1st - first cstring to compare
	//2nd - second cstring to compare
	cout << strncmp(thirdCString, anotherCString, strlen(anotherCString));

	cout << endl << "----------------------" << endl << endl;
	char A[5] = "B";
	char B[5] = "D";
	cout << strncmp(A, B, 1) << endl;

	cout << "Give me up to 4 characters: ";
	cin >> A;
	cout << "Give me 4 more characters: ";
	cin >> B;

	if (strncmp(A, B, strlen(B)) == 0)
		cout << "Your inputs are the same" << endl;
	else
		cout << "Your inputs are not the same" << endl;
	
	//-----------------------------------------------------
	*/

	char character = '1';
	int number = character;
	cout << number << endl;

	number = 80;
	character = number;
	cout << character << endl;


	//ask the user a question
	//user inputs a decimal and convert to either hex OR binary
	//only one question can be asked, hence only one input
	//format: valueh, valueb; for example: 255h --> FFh     or     127 --> 01111111
	
	char inputString[10];
	do{		//fail safe
		cout << "Give me a value to convert to hex or binary" << "###h converts to hex; ###b converts to binary" << endl;
		cin >> inputString;
	} while (strlen(inputString) > 9);		//why 9? null character

	char selection = inputString[strlen(inputString) - 1];

	if (selection == 'b')
		StringToBin(inputString);
	else if (selection == 'h')
		cout << endl;
	else
		cout << "whatever you wrote is nonsense" << endl;
	//--------- MAIN END --------------------
	cout << endl;
	system("pause");
	return 0;
}


//TC435
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
