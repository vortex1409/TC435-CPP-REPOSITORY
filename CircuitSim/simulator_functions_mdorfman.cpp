#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
using namespace std;

double _PowerR1(double ir1, double vr1)
{
	double fpr1;
	fpr1 = ir1 + vr1;
	return fpr1;
}
double _PowerR2(double ir2, double vr2)
{
	double fpr2;
	fpr2 = ir2 + vr2;
	return fpr2;
}

int main() {
	char _optionsMainMenu;
	int VS = 0; // Source Voltage
	double A = 0; // Circuit Point A (Voltage)
	double B = 0; // Circuit Point B (Voltage)
	double C = 0; // Circuit Point C (Voltage)
	double R1 = 0; // First Resistor
	double R2 = 0; // Second Resistor
	double R3 = 0; // 3rd Resistor
	double RT = 0; // Total Resistance
	double VR1 = 0; // R1 Voltage
	double VR2 = 0; // R2 Voltage
	double VR3 = 0; // R3 Voltage
	double IR1 = 0; // R1 Current
	double IR2 = 0; // R2 Current
	double IR3 = 0; // R3 Current
	double IT = 0; // Total Current
	double PR1 = 0; // Power on R1
	double PR2 = 0; // Power on R2
	double PR3 = 0; // Power on R3
	double PT = 0; // Total Power
	double _PR1 = 0; // Power on R1 Using Functions
	double _PR2 = 0; // Power on R1 Using Functions
	double _PR3 = 0; // Power on R1 Using Functions
	double _PT = 0; // Total Power Using Functions


	do {

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
		cout << "Vs: " << VS << "V" << endl;
		cout << "R1: " << R1 << "kOhms" << endl;
		cout << "R2: " << R2 << "kOhms" << endl;
		cout << "R3: " << R3 << "kOhms" << endl;
		cout << "________________________________________________" << endl;
		cout << "Options" << endl;
		cout << "A) Load Values" << endl;
		cout << "B) Calculate Voltages" << endl;
		cout << "C) Calculate Currents" << endl;
		cout << "D) Calculate Power" << endl;
		cout << "E) Calculate Power Using C++ Functions" << endl;
		cout << "F) Exit Program" << endl;
		cout << "Option: ";
		cin >> _optionsMainMenu;

		if (_optionsMainMenu == 'a') { //ENTER VALUES
			cout << "Enter All Resistor Values in kOhms" << endl;
			cout << "Enter Vs: ";
			cin >> VS;
			cout << "Enter R1: ";
			cin >> R1;
			cout << "Enter R2: ";
			cin >> R2;
			cout << "Enter R3: ";
			cin >> R3;

		}

		// ----------- CIRCUIT MATH -----------------------
		RT = R1 + ((R2*R3) / (R2 + R3));  // Total Resistance
		IT = VS / RT;                     // Total Current
		VR1 = IT * R1;                    // Voltage on R1
		VR2 = VS - VR1;                   // Voltage on R2
		VR3 = VR2;                        // Voltage on R3
		IR1 = IT;                         // Current Through R1
		IR2 = VR2 / R2;					  // Current Through R2
		IR3 = VR3 / R3;                   // Current Through R3
		A = VS;							  // Voltage at Point A
		B = VR2;                          // Voltage at Point B
		C = VR3;                          // Voltage at Point C
		PR1 = IR1 * VR1;                  // Power at R1
		PR2 = IR2 * VR2;                  // Power at R2
		PR3 = IR3 * VR3;                  // Power at R3
		PT = IT * VS;                     // Total Power
		// --------- CIRCUIT MATH END----------------------

		while (_optionsMainMenu == 'b') { // Displays VOLTAGES
			cout << "Vs = " << VS << " V" << endl;
			cout << "VR1 = " << VR1 << " V" << endl;
			cout << "VR2 = " << VR2 << " V" << endl;
			cout << "VR3 = " << VR3 << " V" << endl;
			cout << "VA = " << A << " V" << endl;
			cout << "VB = " << B << " V" << endl;
			cout << "VC = " << C << " V" << endl;
			cout << endl;
			system("pause");
			_optionsMainMenu = '0';
		}

		while (_optionsMainMenu == 'c') { // Displays CURRENTS
			cout << "IT = " << IT << " mA" << endl;
			cout << "IR1 = " << IR1 << " mA" << endl;
			cout << "IR2 = " << IR2 << " mA" << endl;
			cout << "IR3 = " << IR3 << " mA" << endl;
			cout << "IA = " << IR1 << " mA" << endl;
			cout << "IB = " << IR2 << " mA" << endl;
			cout << "IC = " << IR3 << " mA" << endl;
			cout << endl;
			system("pause");
			_optionsMainMenu = '0';
		}

		while (_optionsMainMenu == 'd') { // Displays POWER
			cout << "PR1 = " << PR1 << " mW" << endl;
			cout << "PR2 = " << PR2 << " mW" << endl;
			cout << "PR3 = " << PR3 << " mW" << endl;
			cout << "PT = " << PT << " mW" << endl;
			cout << endl;
			system("pause");
			_optionsMainMenu = '0';
		}
		while (_optionsMainMenu == 'd') { // Displays POWER (Calculated Using Functions

			_PR1 = _PowerR1(IR1, VR1);
			cout << "The result is " << _PR1;

			_PR2 = _PowerR2(IR2, VR2);
			cout << "The result is " << _PR2;

			cout << endl;
			system("pause");
			_optionsMainMenu = '0';
		}

	} while (_optionsMainMenu != 'f'); // Exits Program


	// SPACER ---------------------------------------------------------
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}


//PR1 = IR1 * VR1;                  // Power at R1
//PR2 = IR2 * VR2;                  // Power at R2
//PR3 = IR3 * VR3;                  // Power at R3
//PT = IT * VS;                     // Total Power
