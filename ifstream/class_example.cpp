#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
#include <cstring>
#include <fstream>
#include "dorfmanm_w16.h" // Stored in Same DIR Relative to main.cpp
using namespace std;

int main() {
	//--------- MAIN START ------------------

	//Files 1
	ofstream file1("text.txt");
	if (file1.is_open())
	{
		for (double i = 1; i <= 10; i++)
		{
			file1 << i << endl;
		}
		file1.close();
	}
	else
	{
		cout << "Unable to Open File" << endl;
	}

	system("pause");

	//Files 2
	ifstream inputFile("text.txt");
	char var1;

	if (inputFile.is_open())
	{
		while (!inputFile.eof())
		{
			inputFile >> var1;
			cout << var1 << ".";
		}
	}
	else
	{
		cout << "ERROR" << endl;
	}

	// -------- MAIN END --------------------
	cout << endl;
	system("pause");
	return 0;
}


//TC435
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
