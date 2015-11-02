#include <iostream>
using namespace std;

int main();

//Functions
int add(int, int); //Add Two Numbers

int main() {

	int sum, var1, var2, var3; // Input Variables
	cout << "Enter Number: ";
	cin >> var1;
	cout << "Enter another number: ";
	cin >> var2;
	cout << "Enter another number: ";
	cin >> var3;

	sum = add(var3, add(var1, var2));

	cout << "Sum = " << sum << endl;

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
