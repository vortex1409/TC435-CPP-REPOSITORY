#include <iostream>
using namespace std;

int XORgate(int, int);
int parityCheck(int, int, int, int, int);
int NOTgate(int);

int main(){
	char options;
	int inputA = 0, inputB = 0, inputC = 0, inputD = 0, currentParity = 0, parityBit;

	while (true){

		parityBit = parityCheck(inputA, inputB, inputC, inputD, currentParity);
		system("cls");
		cout << "parity bit :: prepared by Daniel Garcia-Gonzalez" << endl << endl;
		cout << "input A: " << inputA << endl;
		cout << "input B: " << inputB << endl;
		cout << "input C: " << inputC << endl;
		cout << "input D: " << inputD << endl;
		cout << "parity bit: " << parityBit << endl;
		if (currentParity == 1)
			cout << "parity: odd" << endl;
		else
			cout << "parity: even" << endl;
		cout << endl << "menu: " << endl;
		cout << "a. change inputs (A, B, C, and D)" << endl;
		cout << "b. change parity (odd or even)" << endl;
		cout << "c. exit" << endl;
		cout << "::";
		cin >> options;

		if (options == 'c')
			break;

		switch (options)
		{
		case 'a':
			cout << "give me input A(0 or 1): ";
			cin >> inputA;
			cout << "give me input B(0 or 1): ";
			cin >> inputB;
			cout << "give me input C(0 or 1): ";
			cin >> inputC;
			cout << "give me input D(0 or 1): ";
			cin >> inputD;
			break;
		case 'b':
			cout << "set parity to odd (1) or even(0): ";
			cin >> currentParity;
		default:
			break;
		}

	}
	return 0;
}

int XORgate(int x, int y){
	if ((x == 0 && y == 1) || (x == 1 && y == 0))
		return 1;
	else
		return 0;
}

int NOTgate(int input){
	if (input == 0)
		return 1;
	else
		return 0;
}

int parityCheck(int A, int B, int C, int D, int P){
	if (P == 0)
		return XORgate(A, XORgate(B, XORgate(C, D)));
	else
		return NOTgate(XORgate(A, XORgate(B, XORgate(C, D))));
}
