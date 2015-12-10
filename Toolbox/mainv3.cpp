#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
#include<iomanip> // Decimal precision
#include <string> // Ignore
#include <cctype> // Ignore
#include <cstdlib> // Ignore
#include <ctime> // Ignore
#include <cstring> // Ignore
using namespace std; // Core

//MTQwOQ==

//--------- FUNCTIONS START -------------------

// Power Function
double _Power(double I, double R) // Power Function
{
	double P;
	P = I * I * R;
	return P;
}

// Resistance Function
double _Resistance(double V, double I) // Resistance Function
{
	double R;
	R = V / I;
	return R;
}

// Voltage Function
double _Voltage(double I, double R) // Voltage Function
{
	double V;
	V = I * R;
	return V;
}

// Current Function
double _Current(double V, double R) // Current Function
{
	double I;
	I = V / R;
	return I;
}

// IE Function
double _fIE(double V, double R, double R2, double BETA)
{
	double IE;
	IE = (V - 0.7) / ((R / BETA) + R2);
	return IE;
}

// VCE Function
double _fVCE(double V, double I, double R, double R2)
{
	double VCE;
	VCE = V - I * (R + R2);
	return VCE;
}

// Clear Function
void clear()
{
	system("cls");
}

// Pause Function
void pause()
{
	// system("pause");
	cin.ignore();
	cin.clear();
	cout << "Press any key to continue...";
	cin.get();
}

//--------- FUNCTIONS END --------------------

int main() {
	system("COLOR 70"); // Stylish Change :D
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
		cout << "| A) Basic Circuit Simulator (Core)            |" << endl;
		cout << "| B) Shift Register (Core)                     |" << endl;
		cout << "| C) Transistor Bias Calculators (Optional)    |" << endl;
		cout << "| D) Credits                                   |" << endl;
		cout << "| E) Exit Toolbox                              |" << endl;
		cout << "| Selection: ";
		cin >> toolmenu;
		//------------------------------------------------------------------------------------MENU END

		// CIRCUIT SIMULATOR SIMPLE
		while (toolmenu == 'A' || toolmenu == 'a') // Basic Circuit Simulator
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

				if (circuitmenu == 'A' || circuitmenu == 'a')
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

				while (circuitmenu == 'B' || circuitmenu == 'b') // Voltage
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

				while (circuitmenu == 'C' || circuitmenu == 'c') // Current
				{
					cout << "IR1 = " << IR1 << "mA" << endl;
					cout << "IR2 = " << IR2 << "mA" << endl;
					cout << "IR3 = " << IR3 << "mA" << endl;
					cout << "IT = " << IT << "mA" << endl;
					cout << endl;
					system("pause");
					circuitmenu = '0';
				}

				while (circuitmenu == 'D' || circuitmenu == 'd') // Power
				{
					cout << "PR1 = " << _PR1 << " mW" << endl;
					cout << "PR2 = " << _PR2 << " mW" << endl;
					cout << "PR3 = " << _PR3 << " mW" << endl;
					cout << "PT = " << _PT << " mW" << endl;
					cout << endl;
					system("pause");
					circuitmenu = '0';
				}

			} while (!(circuitmenu == 'E' || circuitmenu == 'e')); // Exits Program
			toolmenu = '0';
		}

		// SHIFT REGISTER
		while (toolmenu == 'B' || toolmenu == 'b') // SHIFT REGISTER
		{
			char shiftmenu;

			int D0, D1, D2, D3;
			D0 = D1 = D2 = D3 = 0;

			int _input = 0;
			int _output = 0;

			do
			{
				system("cls");
				cout << "|==============================================|" << endl;
				cout << "|================| SHIFTER |===================|" << endl;
				cout << "|==============================================|" << endl;
				cout << "|=======|" << "D3" << "|===|" << "D2" << "|===|" << "D1" << "|===|" << "D0" << "|==========|" << endl;
				cout << "|===========|" << D3 << "|===|" << D2 << "|===|" << D1 << "|===|" << D0 << "|==============|" << endl;
				cout << "|==============================================|" << endl;
				cout << "| A) SHIFT ONE RIGHT                           |" << endl;
				cout << "| B) SHIFT ONE LEFT                            |" << endl;
				cout << "| C) SHIFT ZERO RIGHT                          |" << endl;
				cout << "| D) SHIFT ZERO LEFT                           |" << endl;
				cout << "| E) EXIT                                      |" << endl;
				cout << "| Selection: ";
				cin >> shiftmenu;

				switch (shiftmenu)
				{
				case 'A':
				case 'a':
					clear();
					// Shift 1 right
					D0 = D1;
					D1 = D2;
					D2 = D3;
					D3 = 1;
					break;

				case 'B':
				case 'b':
					clear();
					// Shift 1 left
					D3 = D2;
					D2 = D1;
					D1 = D0;
					D0 = 1;
					break;

				case 'C':
				case 'c':
					clear();
					// Shift 0 right
					D0 = D1;
					D1 = D2;
					D2 = D3;
					D3 = 0;
					break;


				case 'D':
				case 'd':
					clear();
					// Shift 0 left
					D3 = D2;
					D2 = D1;
					D1 = D0;
					D0 = 0;
					break;

				default:
					clear();
					break;
				}
			} while (!(shiftmenu == 'E' || shiftmenu == 'e')); // EXIT
			toolmenu = '0';
		}

		// TRANSITOR BIAS CALCULATORS (2 Bias Calculators)
		while (toolmenu == 'C' || toolmenu == 'c') // Transistor Bias Calculators
		{
			char transistormenu;
			do
			{
				system("cls");
				cout << "|==============================================|" << endl;
				cout << "|========| TRANSITOR BIAS CALCULATORS |========|" << endl;
				cout << "|==============================================|" << endl;
				cout << "|                 Programs                     |" << endl;
				cout << "| A) Emitter Feedback Bias                     |" << endl;
				cout << "| B) Voltage Divider Bias                      |" << endl;
				cout << "| C) Exit Calculator                           |" << endl;
				cout << "| Selection: ";
				cin >> transistormenu;

				// EMITTER FEDBACK BIAS
				while (transistormenu == 'A' || transistormenu == 'a')
				{
					char emittermenu;
					double VCC = 0;
					double RB = 0;
					double RC = 0;
					double RE = 0;
					double VBE = 0.7;
					double IE = 0;
					double IB = 0;
					double IC = 0;
					double VB = 0;
					double VC = 0;
					double VE = 0;
					double VRB = 0;
					double VRC = 0;
					double VRE = 0;
					double _ICSAT = 0;
					double _VCECUT = VCC;
					double _VCE = 0;
					double _BETA = 0;

					do
					{
						system("cls");
						cout << "|==============================================|" << endl;
						cout << "|=====| Emitter Feedback BIAS CALCULATOR |=====|" << endl;
						cout << "|==============================================|" << endl;
						cout << "|                 Programs                     |" << endl;
						cout << "| A) Load Values                               |" << endl;
						cout << "| B) View Results                              |" << endl;
						cout << "| C) Exit                                      |" << endl;
						cout << "| Selection: ";
						cin >> emittermenu;

						if (emittermenu == 'A' || emittermenu == 'a')
						{
							system("cls");
							cout << "Load Values" << endl;
							cout << "=====================" << endl;
							cout << "VCC: ";
							cin >> VCC;
							cout << "RB: ";
							cin >> RB;
							cout << "RC: ";
							cin >> RC;
							cout << "RE: ";
							cin >> RE;
							cout << "BETA: ";
							cin >> _BETA;
						}
						//_fVCE(double V, double I, double R, double R2)    _PT = _Power(IT, VS);
						// ----------- CIRCUIT MATH -----------------------
						IE = _fIE(VCC, RB, RE, _BETA);
						IC = IE;
						IB = IC / _BETA;
						_VCE = _fVCE(VCC, IE, RC, RE);
						VRB = _Voltage(IB, RB);
						VRC = _Voltage(IC, RC);
						VRE = _Voltage(IE, RE);
						VB = VBE - VRE;
						VE = VRE;
						VC = VCC - VRC;
						_ICSAT = VCC / (RC + RE);
						// --------- CIRCUIT MATH END----------------------

						while (emittermenu == 'B' || emittermenu == 'b')
						{
							system("cls");
							cout << "Calculated Values" << endl;
							cout << "=====================" << endl;
							cout << "VCC = " << VCC << " V" << endl;
							cout << "RB = " << RB << " kOhms" << endl;
							cout << "RC = " << RC << " kOhms" << endl;
							cout << "RE = " << RE << " kOhms" << endl;
							cout << "IE = " << IE << " mA" << endl;
							cout << "IC = " << IC << " mA" << endl;
							cout << "IB = " << IB << " uA" << endl;
							cout << "VB = " << VB << " V" << endl;
							cout << "VC = " << VC << " V" << endl;
							cout << "VE = " << VE << " V" << endl;
							cout << "VRB = " << VRB << " V" << endl;
							cout << "VRC = " << VRC << " V" << endl;
							cout << "VRE = " << VRE << " V" << endl;
							cout << "BETA = " << _BETA << "hfe" << endl;
							cout << "IC(SAT) = " << _ICSAT << " mA" << endl;
							cout << "VCE(CUT)" << VCC << " V" << endl;
							system("pause");
							emittermenu = '0';
						}

					} while (!(emittermenu == 'C' || emittermenu == 'c'));
					transistormenu = '0';
				}

				// VOLTAGE DIVIDER BIAS
				while (transistormenu == 'B' || transistormenu == 'b')
				{
					char voltagemenu;
					double VCC = 0;
					double VR2 = 0;
					double RB = 0;
					double RC = 0;
					double RE = 0;
					double R1 = 0;
					double R2 = 0;
					double VBE = 0.7;
					double IE = 0;
					double IB = 0;
					double IC = 0;
					double VB = 0;
					double VC = 0;
					double VE = 0;
					double VRB = 0;
					double VRC = 0;
					double VRE = 0;
					double _ICSAT = 0;
					double _VCECUT = VCC;
					double _VCE = 0;
					double _BETA = 0;

					do
					{
						system("cls");
						cout << "|==============================================|" << endl;
						cout << "|======| Voltage Divider BIAS CALCULATOR |=====|" << endl;
						cout << "|==============================================|" << endl;
						cout << "|                 Programs                     |" << endl;
						cout << "| A) Load Values                               |" << endl;
						cout << "| B) View Results                              |" << endl;
						cout << "| C) Exit                                      |" << endl;
						cout << "| Selection: ";
						cin >> voltagemenu;

						if (voltagemenu == 'A' || voltagemenu == 'a')
						{
							cout << "Load Values" << endl;
							cout << "=====================" << endl;
							cout << "VCC: ";
							cin >> VCC;
							cout << "R1: ";
							cin >> R1;
							cout << "R2: ";
							cin >> R2;
							cout << "RC: ";
							cin >> RC;
							cout << "RE: ";
							cin >> RE;
							cout << "BETA: ";
							cin >> _BETA;
						}

						//_fVCE(double V, double I, double R, double R2)    _PT = _Power(IT, VS);
						// ----------- CIRCUIT MATH -----------------------
						VR2 = (VCC * VR2) / (R1 + R2);
						IE = (VR2 - VBE) / RE;
						IC = IE;
						IB = IC / _BETA;
						_VCE = VCC - IE * (RC + RE);
						VB = VR2;
						VE = _Voltage(IE, RE);
						VC = VCC - _Voltage(IC, RC);
						VRC = _Voltage(IC, RC);
						VRE = _Voltage(IE, RE);
						_ICSAT = VCC / (RC + RE);
						_VCECUT = VCC;
						// --------- CIRCUIT MATH END----------------------

						while (voltagemenu == 'B' || voltagemenu == 'b')
						{
							system("cls");
							cout << "Calculated Values" << endl;
							cout << "=====================" << endl;
							cout << "VCC = " << VCC << " V" << endl;
							cout << "R1 = " << R1 << " kOhms" << endl;
							cout << "R2 = " << R1 << " kOhms" << endl;
							cout << "RC = " << RC << " kOhms" << endl;
							cout << "RE = " << RE << " kOhms" << endl;
							cout << "IE = " << IE << " mA" << endl;
							cout << "IC = " << IC << " mA" << endl;
							cout << "IB = " << IB << " uA" << endl;
							cout << "VB = " << VB << " V" << endl;
							cout << "VC = " << VC << " V" << endl;
							cout << "VE = " << VE << " V" << endl;
							cout << "VR2 = " << VR2 << " V" << endl;
							cout << "VRC = " << VRC << " V" << endl;
							cout << "VRE = " << VRE << " V" << endl;
							cout << "BETA = " << _BETA << "hfe" << endl;
							cout << "IC(SAT) = " << _ICSAT << " mA" << endl;
							cout << "VCE(CUT)" << VCC << " V" << endl;
							system("pause");
							voltagemenu = '0';
						}

					} while (!(voltagemenu == 'C' || voltagemenu == 'c'));
					transistormenu = '0';
				}

				// EXIT
			} while (!(transistormenu == 'C' || transistormenu == 'c'));
			toolmenu = '0';
		}

		//Credits
		while (toolmenu == 'D' || toolmenu == 'd')
		{
			system("cls");
			cout << "|===============================================|" << endl;
			cout << "|                   Credits                     |" << endl;
			cout << "|  This program was created by Michael Dorfman  |" << endl;
			cout << "|===============================================|" << endl;
			cout << "|                Compiled Using                 |" << endl;
			cout << "|     Visual Studio 2015 Enterprise 64 Bit      |" << endl;
			cout << "|        Cloud9 IDE (Online Workspace)          |" << endl;
			cout << "|===============================================|" << endl;
			cout << "|        Thanks For the Great Semester          |" << endl;
			cout << "|===============================================|" << endl;
			system("pause");
			toolmenu = '0';
		}

		//Exit Statement
	} while (!(toolmenu == 'E' || toolmenu == 'e')); // Exits Program

													 // SPACER ---------------------------------------------------------
	system("cls");
	cout << "|===============================================|" << endl;
	cout << "|    The Toolbox Program has been Terminated    |" << endl;
	cout << "|  This program was created by Michael Dorfman  |" << endl;
	cout << "|===============================================|" << endl;
	system("pause");
	return 0;
}
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
