#include <iostream>
using namespace std;

int main();

//Functions
bool AND(bool, bool);
bool OR(bool, bool);
bool NOT(bool, bool);

int main() {

	bool output;

	cout << "AND Gate" << endl;
	cout << "A  B  C" << endl;
	output = AND(0, 0);
	cout << "0  0  " << output << endl;
	output = AND(0, 1);
	cout << "0  1  " << output << endl;
	output = AND(1, 0);
	cout << "1  0  " << output << endl;
	output = AND(1, 1);
	cout << "1  1  " << output << endl;

	cout << "OR Gate" << endl;
	cout << "A  B  C" << endl;
	output = AND(0, 0);
	cout << "0  0  " << output << endl;
	output = AND(0, 1);
	cout << "0  1  " << output << endl;
	output = AND(1, 0);
	cout << "1  0  " << output << endl;
	output = AND(1, 1);
	cout << "1  1  " << output << endl;



	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}

// Define Function
int add(int a, int b)
{
	// Version 1
	//int sum = a + b;
	//return sum;

	// Version 2
	return a + b;
}

bool AND(bool A, bool B) 
{
	if (A == true && B == true)
	{ 
		return true;
	}
	else
	{
		return false;
	}
}

bool OR(bool A, bool B)
{
	if (A == true || B == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool NOT(bool N)
{
	if (N == true)
	{
		return false;
	}
	else
	{
		return true;
	}
}
