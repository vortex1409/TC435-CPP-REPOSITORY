#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
#include <iomanip> // Decimal precision
using namespace std;

//--------- FUNCTIONS START -------------------

// XOR FUNCTION
int _xor(int A, int B)
{
	int X = 0;
	if (A == 0 && B == 0)
	{
		X = 0;
	}
	else if(A == 0 && B == 1)
	{
		X = 1;
	}
	else if (A == 1 && B == 0)
	{
		X = 1;
	}
	else if (A == 1 && B == 1)
	{
		X = 0;
	}
	return X;
} 

// NOT FUNCTION
int _not(int A)
{
	int X = 0;
	if (A == 0)
	{
		X = 1;
	}
	else
	{
		X = 0;
	}
	return X;
} 

// PARITY CHECK
int _parity(int X, int P)
{
	int bit = 0;
	if (P == 1 && X == 1)
	{
		bit = 0;
	}
	else if (P == 1 && X == 0)
	{
		bit = 1;
	}
	else if (P == 0 && X == 1)
	{
		bit = 1;
	}
	else if (P == 0 && X == 0)
	{
		bit = 0;
	}
	return bit;
}
//--------- FUNCTIONS END --------------------

int main() {

	char mainmenu;
	int parity = 0; //Even by Default
	int bit = 0;
	int A = 0;
	int B = 0;
	int AB = 0;
	int C = 0;
	int ABC = 0;
	int D = 0;
	int X = 0;
	int ABCD = bit;	
	
	do // Menu Loop
	{
		//------------------------------------------------------------------------------------MENU
		system("cls");
		cout << "|==============================================|" << endl;
		cout << "|==============| PARITY PROGRAM |==============|" << endl;
		cout << "|==============================================|" << endl;
		cout << "|========| CREATED BY MICHAEL DORFMAN |========|" << endl;
		cout << "|==============================================|" << endl;
		cout << "A: " << A << endl;
		cout << "B: " << B << endl;
		cout << "C: " << C << endl;
		cout << "D: " << D << endl;
		cout << "Parity Bit: " << bit << endl;
		cout << "Parity Setting: " << parity << "    ( 1 = Odd | 0 = Even )" << endl;
		cout << "|==============================================|" << endl;
		cout << "|                 Options                      |" << endl;
		cout << "| A) Change Inputs & Parity                    |" << endl;
		cout << "| C) Transistor Bias Calculators (Optional)    |" << endl;
		cout << "| E) Exit Toolbox                              |" << endl;
		cout << "| Selection: ";
		cin >> mainmenu;
		//------------------------------------------------------------------------------------MENU END
		
		if (mainmenu == 'A' || mainmenu == 'a')
		{
			system("cls");
			cout << "Change Inputs" << endl;
			cout << "=====================" << endl;
			cout << "A: ";
			cin >> A;
			cout << "B; ";
			cin >> B;
			cout << "C: ";
			cin >> C;
			cout << "D: ";
			cin >> D;
			cout << "Change Parity? 1 = Odd | 0 = Even" << endl;
			cin >> parity;
		}
		// LOGIC --------------------------------------------------------------
		AB = _xor(A, B); // XOR First Gate
		ABC = _xor(AB, C); // XOR Second Gate
		X = _xor(ABC, D); // XOR Third Gate + output
		bit = _parity(X, parity); //Parity Bit Checker
		// LOGIC END ----------------------------------------------------------
	} while (!(mainmenu == 'E' || mainmenu == 'e'));

	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
