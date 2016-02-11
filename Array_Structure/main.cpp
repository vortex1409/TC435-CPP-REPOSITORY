#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
#include "dorfmanm_w16.h"
using namespace std;

void printArray(int[], int);

void printHfe(transistor);

int main() {
	//--------- MAIN Start --------------------

	/*
	int arrayOnes[4][4];
	transistor amplifier;

	transistor arrayTwo[4];

	for (int x = 0; x < 4; x++)
	{
		arrayTwo[x].hfe = 150 + (2 * x);
	}

	for (int y = 0; y < 4; y++)
	{
		cout << arrayTwo[y].hfe << endl;
	}
	*/

	int randomAray[] = { 1,1,1,1 };

	printArray(randomAray, 4);

	transistor mdorfman;

	mdorfman.hfe = 300;
	mdorfman.ic = 50;
	mdorfman.ib = mdorfman.ic / mdorfman.hfe;
	printHfe(mdorfman);

	identitymatrix(1);
	cout << endl;
	identitymatrix(2);
	cout << endl;
	identitymatrix(3);
	cout << endl;
	identitymatrix(4);
	cout << endl;
	identitymatrix(5);
	cout << endl;
	identitymatrix(6);
	cout << endl;

	//--------- MAIN END ----------------------
	cout << endl;
	system("pause");
	return 0;
}

void printArray(int input_array[], int sizeofthearray)
{
	/*int working_r = sizeof(input_array) / sizeof(input_array[0]);*/

	for (int x = 0; x < sizeofthearray; x++)
	{
		cout << input_array[x] << endl;
	}
}

void printHfe(transistor inputAmp)
{
	cout << inputAmp.hfe << endl;
}

//TC435
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
