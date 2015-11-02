#include <iostream>
using namespace std;

int addTwoNumbers(int, int); //declares function
bool ANDgate(bool, bool);
bool ORgate(bool, bool);
bool NOTgate(bool);
bool NANDgate(bool, bool);
bool NORgate(bool, bool);
bool XORgate(bool, bool);
bool XNORgate(bool, bool);

int main() {

	/*//int _variable1, _variable2, _variable3; //create input variable
	//int sum = 0;\

	//cout << "Give me an integer number" << endl;
	//cin >> _variable1;
	//cout << "Give me another integer number" << endl;
	//cin >> _variable2;
	//cout << "Give me a third number" << endl;
	//cin >> _variable3;

	//sum = addTwoNumbers(_variable3, addTwoNumbers(_variable1, _variable2));

	//cout << "The result is: " << sum << endl;
	*/

	bool output;

	cout << "AND gate" << endl;
	cout << "A   B   C" << endl;
	output = ANDgate(0, 0);
	cout << "0   0   " << output << endl;
	output = ANDgate(0, 1);
	cout << "0   1   " << output << endl;
	output = ANDgate(1, 0);
	cout << "1   0   " << output << endl;
	output = ANDgate(1, 1);
	cout << "1   1   " << output << endl;

	cout << endl;

	cout << "OR gate" << endl;
	cout << "A   B   C" << endl;
	output = ORgate(0, 0);
	cout << "0   0   " << output << endl;
	output = ORgate(0, 1);
	cout << "0   1   " << output << endl;
	output = ORgate(1, 0);
	cout << "1   0   " << output << endl;
	output = ORgate(1, 1);
	cout << "1   1   " << output << endl;

	cout << endl;

	cout << "NAND gate" << endl;
	cout << "A   B   C" << endl;
	output = NANDgate(0, 0);
	cout << "0   0   " << output << endl;
	output = NANDgate(0, 1);
	cout << "0   1   " << output << endl;
	output = NANDgate(1, 0);
	cout << "1   0   " << output << endl;
	output = NANDgate(1, 1);
	cout << "1   1   " << output << endl;

	cout << endl;

	cout << "NOR gate" << endl;
	cout << "A   B   C" << endl;
	output = NORgate(0, 0);
	cout << "0   0   " << output << endl;
	output = NORgate(0, 1);
	cout << "0   1   " << output << endl;
	output = NORgate(1, 0);
	cout << "1   0   " << output << endl;
	output = NORgate(1, 1);
	cout << "1   1   " << output << endl;

	cout << endl;

	cout << "XOR gate" << endl;
	cout << "A   B   C" << endl;
	output = XORgate(0, 0);
	cout << "0   0   " << output << endl;
	output = XORgate(0, 1);
	cout << "0   1   " << output << endl;
	output = XORgate(1, 0);
	cout << "1   0   " << output << endl;
	output = XORgate(1, 1);
	cout << "1   1   " << output << endl;

	cout << endl;

	cout << "XNOR gate" << endl;
	cout << "A   B   C" << endl;
	output = XNORgate(0, 0);
	cout << "0   0   " << output << endl;
	output = XNORgate(0, 1);
	cout << "0   1   " << output << endl;
	output = XNORgate(1, 0);
	cout << "1   0   " << output << endl;
	output = XNORgate(1, 1);
	cout << "1   1   " << output << endl;

	system("pause");
	return 0;
} // the main function finishes here

int addTwoNumbers(int a, int b) {      //define function AFTER main function
	int sum = a + b;
	return sum;
}

bool ANDgate(bool A, bool B) {     //define function AFTER main function closes
	if (A == true && B == true)
		return true;
	else
		return false;
}

bool ORgate(bool A, bool B) {
	if (A == true || B == true)
		return true;
	else
		return false;
}

bool NOTgate(bool N) {
	if (N == true)
		return false;
	else
		return true;
}

bool NANDgate(bool A, bool B) {
	return NOTgate(ANDgate(A, B));
}

bool NORgate(bool A, bool B) {
	return NOTgate(ORgate(A, B));
}

bool XORgate(bool A, bool B) {
	return ORgate(ANDgate(NOTgate(A), B), ANDgate(NOTgate(B), A));
}

bool XNORgate(bool A, bool B) {
	return NOTgate(XORgate(A, B));
}
