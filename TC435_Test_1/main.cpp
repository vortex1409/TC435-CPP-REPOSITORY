#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
#include "dorfmanm_w16.h" // Stored in Same DIR Relative to main.cpp
using namespace std;

//--------- FUNCTIONS START -------------------



//--------- FUNCTIONS END --------------------

int main() {
	//--------- MAIN START ------------------

	timer0 overflow;

	overflow = timer0overflow();
	timer0config(overflow.intHex);

	//--------- MAIN END --------------------
	cout << endl;
	system("pause");
	return 0;
}


//TC435
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
