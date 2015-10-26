#include <iostream>
using namespace std;

int main() {
	char _optionsMainMenu;
	int vs = 0;
	double r1 = 0;
	double r2 = 0;
	double r3 = 0;
	double rt = 0;
	double it = 0;
do{
	system("cls");
	cout << "Simple Circuit by Michael Dorfman" << endl;
	cout << "________________________________________________" << endl;
	cout << "     A      R1        B         C" << endl;
	cout << "     .____/\\/\\/\\______._________." << endl;
	cout << "     |                |         |" << endl;
	cout << "    ___               >         <" << endl;
	cout << " Vs  -                > R2      < R3" << endl;
	cout << "     |                >         <" << endl;
	cout << "     |                |         |" << endl;
	cout << "     |________________|_________|" << endl;
	cout << "________________________________________________" << endl;
	cout << "Circuit Values" << endl;
	cout << "Vs: " << vs << "V" << endl;
	cout << "R1: " << r1 << "kOhms" << endl;
	cout << "R2: " << r2 << "kOhms" << endl;
	cout << "R3: " << r3 << "kOhms" << endl;
	cout << "________________________________________________" << endl;
	cout << "Options" << endl;
	cout << "A) Load Values" << endl;
	cout << "B) Calculate Currents" << endl;
	cout << "C) Calculate Power" << endl;
	cout << "D) Exit Program" << endl;
	cout << "Option: ";
	cin >> _optionsMainMenu;

	if (_optionsMainMenu == 'a') {
		cout << "Enter All Resistor Values in kOhms" << endl;
		cout << "Enter Vs: ";
		cin >> vs;
		cout << "Enter R1: ";
		cin >> r1;
		cout << "Enter R2: ";
		cin >> r2;
		cout << "Enter R3: ";
		cin >> r3;

	}

	while (_optionsMainMenu == 'b') {
		rt = (r1 + 1 / (1 / r2 + 1 / r3)) * 1000;
		it = vs / rt;

		cout << "Results" << endl;
		cout << "Total Resistance: " << rt / 1000 << "kOhms" << endl;
		cout << "Total Current: " << it / 1000 << "mA" << endl;
		cout << "VR1: " << vs * r1 / (rt / 1000);
		cout << "V(BC)" << vs * (1 - r1 / (rt / 1000));

		cout << endl;
		system("pause");
		_optionsMainMenu = '0';
	}



} while (_optionsMainMenu != 'd');


	// SPACER ---------------------------------------------------------
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
