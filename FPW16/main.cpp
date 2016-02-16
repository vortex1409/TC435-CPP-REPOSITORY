#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
#include "dorfmanm_w16.h" // Stored in Same DIR Relative to main.cpp
using namespace std;

//--------- FUNCTIONS START -------------------



//--------- FUNCTIONS END --------------------

int main() {

	firstTest(1);

	cout << "AmoD Function" << endl;
	cout << AmodB(3, 2) << endl;

	cout << "Custom Equation 1" << endl;
	cout << customEquation_1(1, 1, 1) << endl;

	int miscArray[] = { 1,2,3,4,5,-1,-3 };

	PLC controller_1;
	controller_1.PV = 30;

	customEquation_2(miscArray, 4);

	//------CLASSES START--------------

	firstClass testClass;
	testClass.firstfunction();

	cout << endl;
	cout << testClass.addTwo(3, 4) << endl;

	cout << testClass.misc << endl;

	//--------Assignment 3--------------------

	cout << "------ Assignment 3 -------" << endl;

	intToHex(127);

	cout << endl;

	intToBin(127);

	//--------- MAIN END --------------------
	cout << endl;
	system("pause");
	return 0;
}


//TC435
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
