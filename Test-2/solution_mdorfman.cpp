#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
using namespace std;

// Global Variables
double freq = 1;//kHz
double XcTotal = 0;
double RTotal = 0;


//--------- FUNCTIONS START -------------------
double _CapReact(double f, double c) // Power Function
{
	double Xc;
	Xc = 1 / 2 * 3.14159 * f * c;
	return Xc;
}

double _SeriesResistance(double R1, double R2)
{
	double RO = 0;
	RO = R1 + R2;
	return RO;
}

double _ParallelResistance(double _R1, double _R2)
{
	double _RO;
	_RO = (1 / (1 / _R1) + (1 / _R2));
	return _RO;
}

//--------- FUNCTIONS END --------------------

int main() {
	char _optionsMainMenu;
	int _optionsMainMenu2 = 0;
	double RIN = 0;
	
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
				cout << "Series or Parallel Menu" << endl;
				cout << "1) Series" << endl;
				cout << "2) Parallel" << endl;
				cout << "3) Leave Menu" << endl;
				cout << "Option: ";
				cin >> _optionsMainMenu2;

				while (_optionsMainMenu2 == 1){
					cout << "Resistor Value: ";
					cin >> RIN;
					RTotal = RTotal + RIN;
					cout << endl;
					cout << "Add More? (1 = Yes & 2 = No)" << endl;
					double addr = 0;
					if (addr = 1)
					{
						cout << "Resistor Value: ";
						cin >> RIN;
						RTotal = RTotal + RIN;
					}
					else
					{
						_optionsMainMenu2 = 0;
					}
				}

				while (_optionsMainMenu2 == 2){

				}

			} while (_optionsMainMenu2 != 3);
			cout << endl;
			system("pause");
			_optionsMainMenu = '0';
		}


		// --------- CIRCUIT OP END-----------------------------------
		while (_optionsMainMenu == 'e') { // Resets Variables


			_optionsMainMenu = '0';
		}

	} while (_optionsMainMenu != 'f'); // Exits Program


	// SPACER ---------------------------------------------------------
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
