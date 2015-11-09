#include <iostream>
using namespace std;

// declaring functions
char decToHex(int);
void printTable(int); // this function will return nothing to the user
void decToBinary(int);
void printBinaryUpCountUsingGlobalVariables(int);


char _bit3, _bit2, _bit1, _bit0;

int main(){

	// example 1
	/*
	int _input; //local to main function
	char _output;
	cout << "Give me a number: ";
	cin >> _input;

	_output = decToHex(_input);
	cout << _output << endl;

	/*for (int i = 0; i < 256; i++) //this code prints a list of hex values
	{
	_output = decToHex(i);
	cout << i << " :: " << _output << endl;
	}*/

	// example 2
	//int _matrixGrid;
	//cout << "Gimme the size of the matrix: ";
	//cin >> _matrixGrid;
	//printBinaryUpCountUsingGlobalVariables(_matrixGrid);
	

	// example 3
	double _output = 0, _temporal;

	do{
		cout << "Gimme a number: ";
		cin >> _temporal;
		if (_temporal == -1) //when comparing, use 2 equal signs
			break;
		_output += _temporal;   // same as _output = _output + _temporal
	} while (true); //infinite loop

	cout << "The result is: " << _output << endl;

system("pause");
	return 0;
}


//defining functions
char decToHex(int _input){
	if (_input >= 0 && _input <= 9)
		return _input + 48;
	else if (_input >= 10 && _input <= 15)
		return _input + 55;
	else{
		return 'e'; // fail safe
	}
}

void printTable(int _printSize)
{
	for (int i = 0; i < _printSize; i++) // how to adjust this function
	{
		for (int j = 0; j < _printSize; j++)
		{
			decToBinary(i);
			cout << _bit1 << _bit0;
		}
		cout << endl;
	}
}

void decToBinary(int _binaryConversion){
	// 2 bit conversion, hence 0 to 3
	int temporalVariable = _binaryConversion;

	
	if (temporalVariable >= 8){
		_bit3 = '1';
		temporalVariable = temporalVariable - 8;
	}
	else{
		_bit3 = '0';
	}
	
	if (temporalVariable >= 4){
		_bit2 = '1';
		temporalVariable = temporalVariable - 4;
	}
	else{
		_bit2 = '0';
	}
	
	if (temporalVariable >= 2){
		_bit1 = '1';
		temporalVariable = temporalVariable - 2;
	}
	else{
		_bit1 = '0';
	}

	if (temporalVariable >= 1){
		_bit0 = '1';
		temporalVariable = temporalVariable - 1;
	}
	else{
		_bit0 = '0';
	}
}

void printBinaryUpCountUsingGlobalVariables(int x){
	for (int i = 0; i < x; i++){
		decToBinary(i);
		cout << _bit3 << _bit2 << _bit1 << _bit0 << endl;
	}
}
