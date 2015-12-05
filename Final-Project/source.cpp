#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
#include<iomanip> // Decimal precision
using namespace std;

//--------- FUNCTIONS START -------------------
double _Power(double I, double R) // Power Function
{
	double P;
	P = I * I * R;
	return P;
}

double _Resistance(double V, double I) // Resistance Function
{
	double R;
	R = V / I;
	return R;
}

double _Voltage(double I, double R) // Voltage Function
{
	double V;
	V = I * R;
	return V;
}

double _Current(double V, double R) // Current Function
{
	double I;
	I = V / R;
	return I;
}
//--------- FUNCTIONS END --------------------

int main() {

	std::cout << std::fixed; // std Decimal Precision
	std::cout << std::setprecision(2); // std Decimal Precision
	char toolmenu; // Menu Charactar

	do
	{
		system("cls");
	//------------------------------------------------------------------------------------MENU
		cout << "|==============================================|" << endl;
		cout << "|===========| TOOLBOX PROGRAM |================|" << endl;
		cout << "|==============================================|" << endl;
		cout << "|                 Programs                     |" << endl;
		cout << "| A) Basic Circuit Simulator                   |" << endl;
		cout << "| B) Magic Square Generator                    |" << endl;
		cout << "| C) Transistor Bias Calculators               |" << endl;
		cout << "| D) Exit Toolbox                              |" << endl;
		cout << "| Selection: ";
		cin >> toolmenu;
	//------------------------------------------------------------------------------------MENU END

		while (toolmenu == 'A') // Basic Circuit Simulator
		{
			char circuitmenu; // Menu Charactar
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
				cout << "=============== Select Option ==================" << endl;
				cout << "________________________________________________" << endl;
				cout << "Options" << endl;
				cout << "A) Load Values" << endl;
				cout << "B) Calculate Voltages" << endl;
				cout << "C) Calculate Currents" << endl;
				cout << "D) Calculate Power" << endl;
				cout << "E) Exit Program" << endl;
				cout << "Option: ";
				cin >> circuitmenu;

				if (circuitmenu == 'A') 
				{ 
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
				RT = R1 + ((R2*R3) / (R2 + R3));
				IT = _Current(VS, RT);
				VR1 = _Voltage(IT, R1);
				VR2 = VS - VR1;
				VR3 = VR2;
				IR1 = IT;
				IR2 = _Current(VR2, R2);
				IR3 = _Current(VR3, R3);
				A = VS;
				B = VR2;
				C = VR3;
				_PR1 = _Power(IR1, VR1);
				_PR2 = _Power(IR2, VR2);
				_PR3 = _Power(IR3, VR3);
				_PT = _Power(IT, VS);
				// --------- CIRCUIT MATH END----------------------

				while (circuitmenu == 'B') // Voltage
				{
					cout << "VR1 = " << VR1 << " V" << endl;
					cout << "VR2 = " << VR2 << " V" << endl;
					cout << "VR3 = " << VR3 << " V" << endl;
					cout << "VA = " << A << " V" << endl;
					cout << "VB = " << B << " V" << endl;
					cout << "VC = " << C << " V" << endl;
					cout << endl;
					system("pause");
					circuitmenu = '0';
				}

				while (circuitmenu == 'C') // Current
				{
					cout << "" << IR1 << "mA" << endl;
					cout << "" << IR2 << "mA" << endl;
					cout << "" << IR3 << "mA" << endl;
					cout << "" << IT << "mA" << endl;
					cout << endl;
					system("pause");
					circuitmenu = '0';
				}

				while (circuitmenu == 'D') // Power
				{
					cout << "PR1 = " << _PR1 << " mW" << endl;
					cout << "PR2 = " << _PR2 << " mW" << endl;
					cout << "PR3 = " << _PR3 << " mW" << endl;
					cout << "PT = " << _PT << " mW" << endl;
					cout << endl;
					system("pause");
					circuitmenu = '0';
				}

			} while (circuitmenu != 'E'); // Exits Program
		}

		while (toolmenu == 'B') // Magic Square Generator
		{

		}

		while (toolmenu == 'C') // Transistor Bias Calculators
		{

		}


	} while (toolmenu != 'D'); // Exits Program

	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
