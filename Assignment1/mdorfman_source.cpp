#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
using namespace std;

//Compute Function
double _compute(double input)
{
	double output;
	output = input + (input * (2 * input));
	return output;
}

int main() {

	//double output = 0;
	double input = 0;

	cout << "Enter Number to Compute: ";
	cin >> input;

	cout << _compute(input);

	//OP1
	//output = input + (input * (2 * input));
	//cout << output << endl;

	/*
	All the options work correctly as they should but option 1 seems the most logical
	because it only uses one line which makes your code less messy and takes up less space.
	With this option you could include it into a small function what would compute it for you
	could uses it multiple times.
	*/

	//OP2
	//output = input;

	//for (int i = 0; i < 2 * input; i++)
	//{
	//	output += input;
	//}
	//cout << output << endl;

	//OP3
	//while (output < input + (input * (2 * input))) 
	//{
	//	output += input;
	//}
	//cout << output << endl;


	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
//TC435
