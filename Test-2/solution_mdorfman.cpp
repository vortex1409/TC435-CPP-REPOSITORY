// Michael Dorfman
// I have applied the concepts of C++ to this test but I may have made a few mistakes.
// Most values have to be entered using kOhms
// Capacitor Values MUST be entered in uF (MicroFarads)
// Frequency MUST be entered using kHz (kiloHertz)

#include <iostream> // Template
#include <cmath> // Added to remove 'ambiguous'
using namespace std; // Template

// Global Variables
double freq = 1;//kHz
double XcTotal = 0; //kOhms
double RTotal = 0; //kOhms
double ZT = 0; //kOhms
// Other Variables
double CapTotal = 0; //uF

//--------- FUNCTIONS START -------------------
double _CapReact(double f, double c) // Capacitive Reactance
{
	double Xc;
	Xc = 1 / 2 * 3.14159 * f * c;
	return Xc;
}

double _SeriesResistance(double R1, double R2) // Series Resistance
{
	double RO = 0;
	RO = R1 + R2;
	return RO;
}

double _ParallelResistance(double _R1, double _R2) // Parallel Resistance
{
	double _RO;
	_RO = (1 / (1 / _R1) + (1 / _R2));
	return _RO;
}
//--------- FUNCTIONS END --------------------

int main() {
	char _optionsMainMenu; // Menu 1
	int _optionsMainMenu2 = 0; // Menu 2
	int _optionsMainMenu3 = 0; //Menu 3
	double RIN = 0;// kOhms
	double XIN = 0; //uF
	double CapIN = 0; //uF
	
	do{
		system("cls");
		cout << "Series - Parallel Impedance Calculator by Michael Dorfman" << endl;
		cout << "________________________________________________" << endl;
		cout << "Circuit Values" << endl;
		cout << "Frequency: " << freq << " kHz" << endl;
		cout << "Total Resistance: " << RTotal << " ohms" << endl;
		cout << "Total Reactance: " << XcTotal << " ohms" << endl;
		cout << "________________________________________________" << endl;
		cout << "Options" << endl;
		cout << "A) Change Frequency? (Default 1kHz)" << endl;
		cout << "B) Calculate Resistance" << endl;
		cout << "C) Calculate Reactance" << endl;
		cout << "D) Total Circuit Impedance" << endl;
		cout << "E) Clear All Variables" << endl;
		cout << "F) Exit Program" << endl;
		cout << "Option: ";
		cin >> _optionsMainMenu;

		if (_optionsMainMenu == 'a') { // Changes Frequency
			cout << "Enter the Frequency: ";
			cin >> freq;
			_optionsMainMenu = '0';
		}

		while (_optionsMainMenu == 'b') { // Calculates Resistance
			do{
				system("cls");
				cout << "Series or Parallel Menu (Resistors)" << endl;
				cout << "1) Series" << endl;
				cout << "2) Parallel" << endl;
				cout << "3) Leave Menu" << endl;
				cout << "Option: ";
				cin >> _optionsMainMenu2;

				while (_optionsMainMenu2 == 1){ // SERIES
					cout << "Resistor Value: ";
					cin >> RIN;
					RTotal = RTotal + RIN;
					cout << endl;
					cout << "Add More? (1 = Yes & 2 = No)" << endl;
					cout << "Option:";
					double addr = 0;
					cin >> addr;
					if (addr == 1)
					{
						cout << "Resistor Value: ";
						cin >> RIN;
						RTotal = RTotal + RIN;
					}
					else if (addr == 2)
					{
						_optionsMainMenu2 = 0;
					}
				}

				while (_optionsMainMenu2 == 2){ // PARALLEL
					cout << "Resistor Value: ";
					cin >> RIN;
					RTotal = _ParallelResistance(RTotal, RIN);
					cout << endl;
					cout << "Add More? (1 = Yes & 2 = No)" << endl;
					cout << "Option:";
					double addr = 0;
					cin >> addr;
					if (addr == 1)
					{
						cout << "Resistor Value: ";
						cin >> RIN;
						RTotal = _ParallelResistance(RTotal, RIN);
					}
					else if (addr == 2)
					{
						_optionsMainMenu2 = 0;
					}
				}

			} while (_optionsMainMenu2 != 3);
			_optionsMainMenu = '0';
		}

		while (_optionsMainMenu == 'c') // Calculate Capacitive Reactance
		{
			do{
				system("cls");
				cout << "Series or Parallel Menu (Capacitors)" << endl;
				cout << "1) Series" << endl;
				cout << "2) Parallel" << endl;
				cout << "3) Leave Menu" << endl;
				cout << "Option: ";
				cin >> _optionsMainMenu3;

				while (_optionsMainMenu3 == 1){ // SERIES
					cout << "Cap Value: ";
					cin >> XIN;
					CapTotal = CapTotal + XIN;
					cout << endl;
					cout << "Add More? (1 = Yes & 2 = No)" << endl;
					cout << "Option:";
					double addr = 0;
					cin >> addr;
					if (addr == 1)
					{
						cout << "Cap Value: ";
						cin >> RIN;
						CapTotal = CapTotal + XIN;
					}
					else if (addr == 2)
					{
						_optionsMainMenu3 = 0;
					}
				}

				while (_optionsMainMenu3 == 2){ // PARALLEL
					cout << "Cap Value: ";
					cin >> XIN;
					CapTotal = _ParallelResistance(CapTotal, XIN);
					cout << endl;
					cout << "Add More? (1 = Yes & 2 = No)" << endl;
					cout << "Option:";
					double addr = 0;
					cin >> addr;
					if (addr == 1)
					{
						cout << "Cap Value: ";
						cin >> XIN;
						CapTotal = _ParallelResistance(CapTotal, XIN);
					}
					else if (addr == 2)
					{
						_optionsMainMenu3 = 0;
					}
				}

			} while (_optionsMainMenu3 != 3);
			_optionsMainMenu = '0';
		}

		while (_optionsMainMenu == 'd') // Calculates Final Results
		{
			XcTotal = _CapReact(freq, CapTotal);
			ZT = _SeriesResistance(RTotal, XcTotal);
			cout << "Final Results" << endl;
			cout << "Frequency: " << freq << " kHz" << endl;
			cout << "Total Resistance: " << RTotal << " kohms" << endl;
			cout << "Total Capacitive Reactance: " << XcTotal << " kohms" << endl;
			cout << "Total Circuit Impedance: " << ZT << " kohms" << endl;
			system("pause");
			_optionsMainMenu = '0';
		}

		// --------- CIRCUIT OP END-----------------------------------
		while (_optionsMainMenu == 'e') { // Resets Variables
			RTotal = 0;
			XcTotal = 0;
			freq = 1;
			_optionsMainMenu = '0';
		}

	} while (_optionsMainMenu != 'f'); // Exits Program

	// SPACER ---------------------------------------------------------
	cout << "________________________________________________" << endl; // Template
	system("pause"); // Template
	return 0; // Template
} // END OF PROGRAM
