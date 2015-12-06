#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
#include<iomanip> // Decimal precision
#include <string>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

//=====|Encryption Functions Start|=====
void Encrypt(string&);
string Decrypt(string strTarget);

void Encrypt(string &strTarget)
{
	int len = strTarget.length();
	char a;
	string strFinal(strTarget);

	for (int i = 0; i <= (len - 1); i++)
	{
		a = strTarget.at(i);
		int b = (int)a; //get the ASCII value of 'a'
		b += 2; //Mulitply the ASCII value by 2
		if (b > 254) { b = 254; }
		a = (char)b; //Set the new ASCII value back into the char
		strFinal.insert(i, 1, a); //Insert the new Character back into the string
	}
	string strEncrypted(strFinal, 0, len);
	strTarget = strEncrypted;
}

string Decrypt(string strTarget)
{
	int len = strTarget.length();
	char a;
	string strFinal(strTarget);

	for (int i = 0; i <= (len - 1); i++)
	{
		a = strTarget.at(i);
		int b = (int)a;
		b -= 2;

		a = (char)b;
		strFinal.insert(i, 1, a);
	}
	string strDecrypted(strFinal, 0, len);
	return strDecrypted;
}
//=====|Encryption Functions End|======


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

// --TRANSISTOR FUNCTIONS EMITTER FEEDBACK----
double _fIE(double V, double R, double R2, double BETA)
{
	double IE;
	IE = (V - 0.7) / ((R / BETA) + R2);
	return IE;
}

double _fVCE(double V, double I, double R, double R2)
{
	double VCE;
	VCE = V - I * (R + R2);
	return VCE;
}

//--------- FUNCTIONS END --------------------

int main() {
	system("COLOR 02");
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
		cout << "| B) Magic Square Generator (Core)             |" << endl;
		cout << "| C) Transistor Bias Calculators (Optional)    |" << endl;
		cout << "| D) Text Encryption (Extra)                   |" << endl;
		cout << "| E) Text to Hex (Extra)                       |" << endl;
		cout << "| F) Exit Toolbox                              |" << endl;
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
						cout << "|========| TRANSITOR BIAS CALCULATORS |========|" << endl;
						cout << "|==============================================|" << endl;
						cout << "|                 Programs                     |" << endl;
						cout << "| A) Load Values                               |" << endl;
						cout << "| B) View Results                              |" << endl;
						cout << "| C) Exit                                      |" << endl;
						cout << "| Selection: ";
						cin >> emittermenu;

						if (emittermenu == 'A' || emittermenu == 'a')
						{
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

						while (emittermenu == 'B' || emittermenu == 'c')
						{
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
						}

					} while (emittermenu != 'C' || emittermenu != 'c');
					transistormenu = '0';
				}

				// VOLTAGE DIVIDER BIAS
				while (transistormenu == 'B' || transistormenu == 'b')
				{

				}

				// EXIT
			} while (!(transistormenu == 'C' || transistormenu == 'c'));
			toolmenu = '0';
		}

		// Text Encryption (Makes Text Unreadable by Humans (Security))
		while (toolmenu == 'D' || toolmenu == 'd')
		{
			//initialize and get the string from the user
			string strTarget;
			cout << "Text to Encrypt: ";
			cin >> strTarget;
			string temp(strTarget);
			Encrypt(strTarget);
			cout << "=============================" << endl;
			cout << "Encrypted: " << strTarget << endl;
			cout << "Decrypted: " << Decrypt(strTarget) << endl;
			cout << "=============================" << endl;
			system("pause");
			toolmenu = '0';
		}

		// Text to Hex Converter (Converts Text String to Hexadecimal)
		while (toolmenu == 'E' || toolmenu == 'e')
		{
			cout.setf(ios::showbase);

			string text;
			cout << "Text to Hex Encode: ";
			cin >> text;

			for (int i = 0; i < text.length(); i++)
			{
				cout << "Letter [" << dec << i << "]: "
					<< hex << (text.at(i) - '0') << "\n";
			}
			system("pause");
			toolmenu = '0';

		}

	} while (!(toolmenu == 'F' || toolmenu == 'f')); // Exits Program
	
	// SPACER ---------------------------------------------------------
	system("cls");
	cout << "|===============================================|" << endl;
	cout << "|    The Toolbox Program has been Terminated    |" << endl;
	cout << "|  This program was created by Michael Dorfman  |" << endl;
	cout << "|===============================================|" << endl;
	system("pause");
	return 0;
}
