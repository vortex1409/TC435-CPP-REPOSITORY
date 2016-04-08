#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
#include <cstring>
#include <fstream>
#include "dorfmanm_w16.h" // Stored in Same DIR Relative to main.cpp
using namespace std;

int main() {
	//--------- MAIN START ------------------

	//plotter bandPass;
	//filter_RC filterToTest;

	//initializeFilter(filterToTest);

	//bandPass.axis_MIN = 1;
	//bandPass.axis_MAX = 500000;
	//bandPass._step = 10;

	//plotFilter(bandPass, filterToTest);

	//cout << filterToTest.Fr << endl;
	//cout << filterToTest.Fh << endl;
	//cout << filterToTest.Fl << endl;

	uController tester;

	tester.print("w");
	cout << endl;

	tester.initializeController();

	tester.print("W");
	cout << endl;

	tester.print("w");
	cout << endl;

	tester.MOVLW("31");
	cout << endl;

	tester.print("w");
	cout << endl;

	tester.print("W");
	cout << endl;

	tester.stopController();

	tester.print("w");
	cout << endl;

	// -------- MAIN END --------------------
	cout << endl;
	system("pause");
	return 0;
}


//TC435
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
