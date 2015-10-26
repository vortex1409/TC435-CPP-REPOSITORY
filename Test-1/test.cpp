#include <iostream>
using namespace std;
// I DO NOT HAVE THE CONVERSION EXAMPLE WE DID IN CLASS
int main() {

	cout << "Test #1 created by Michael Dorfman\n\nDate Completed: 12:07pm 10/5/2015\nSuprervised by Daniel Garcia Gonzalez & Falko Retter\n";
	cout << "----------------------------------------------------------------\n";
	cout << "Select your operation\n" << endl;
	cout << "1. Convert to Binary\n";
	cout << "2. Convert to Hex" << endl;
	cout << "3. Convert to Octal" << endl;
	cout << "4. Exit Appication" << endl;

	cout << "Select an option: ";
	int _input = 0;
	cin >> _input;


	if (_input >= 1 && _input <= 5) {
		if (_input == 1) {

			cout << "Type a value to convert (0 - 15): ";
			cin >> _input;
			
			char bit0, bit1, bit2, bit3; // new type of variable
			int temporalVariable = _input;

			if (temporalVariable >= 8)
			{
				temporalVariable = temporalVariable - 8;
				bit3 = '1';
			}
			else
			{
				bit3 = '0';
			}


			if (temporalVariable >= 4)
			{
				temporalVariable = temporalVariable - 4;
				bit2 = '1';
			}
			else
			{
				bit2 = '0';
			}

			if (temporalVariable >= 2)
			{
				temporalVariable = temporalVariable - 2;
				bit1 = '1';
			}
			else
			{
				bit1 = '0';
			}

			if (temporalVariable >= 1)
			{
				temporalVariable = temporalVariable - 1;
				bit0 = '1';
			}
			else
			{
				bit0 = '0';
			}

			cout << "The value in binary is: " << bit3 << bit2 << bit1 << bit0 << endl;
		}
		else if (_input == 2) {
			int hex = 0;
			cout << "Give me a number: ";
			cin >> hex;
			if (hex <= 9) {
				cout << "0" << hex << "h" << endl;
			}
			else if (hex == 10) {
				cout << "0A" << "h" << endl;
			}
			else if (hex == 11) {
				cout << "0B" << "h" << endl;
			}
			else if (hex == 12) {
				cout << "0C" << "h" << endl;
			}
			else if (hex == 13) {
				cout << "0D" << "h" << endl;
			}
			else if (hex == 14) {
				cout << "0E" << "h" << endl;
			}
			else if (hex == 15) {
				cout << "0F" << "h" << endl;
			}
		}
		else if (_input == 3) {
			int octal = 0;
			int _outoctal = 0;
			cout << "Give me a number";
			cin >> octal;
			if (octal <= 7) {
				cout << "0" << octal << "o" << endl;
			}
			else if (octal >= 7){
				_outoctal = octal + 2;
				cout << _outoctal << "o" << endl;
			}
		}
		else {
		}
	}
	else {
		cout << endl << "Input Refused" << endl;
	}
	// SPACER ---------------------------------------------------------
	printf("\n");
	printf("________________________________________________");
	printf("\n");
	system("pause");
	return 0;
}
