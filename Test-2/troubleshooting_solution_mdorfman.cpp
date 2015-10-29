#include <iostream>
using namespace std;

int main() {

	int a, b, c;

	cout << "Give me a number for variable a: ";
	cin >> a;
	cout << "Give me a number for variable b: ";
	cin >> b;
	cout << "Give me a number for variable c: ";
	cin >> c;

	if (isdigit(a) && isdigit(b) && isdigit(c))
	{
		if (a == b && a != c)
		{
			cout << a << " is equal to " << b << " but not equal to " << c << endl;
			if (a > c)
			{
				cout << a << " is greater than " << c << endl;
			}
			else
			{
				cout << c << " is greater tha " << a << endl;
			}
		}
		else if (b == c && b != c)
		{
			cout << b << " is equal to " << c << " but not equal to " << a << endl;
			if (b > c)
			{
				cout << b << " is greater than " << c << endl;
			}
			else
			{
				cout << c << " is greater than " << b << endl;
			}
		}
		else if (a == b && c)
		{
			cout << a << "," << b << " and " << c << " are equal." << endl;
		}
		else if (a > b) {
			if (a > c)
				cout << a << " is greater than " << b << " and " << c << endl;
			else
				cout << a << " is greater than " << b << " but smaller than " << c << endl;
		}
		else if (b > c) {
			if (b > a)
				cout << b << " is greater than " << c << " and " << a << endl;
			else
				cout << b << " is greater than " << c << " but smaller than " << a << endl;
		}
		else if (c > a) {
			if (c > b)
				cout << c << " is greater than " << a << " and " << b << endl;
			else
				cout << c << " is greater than " << a << " but smaller than " << b << endl;
		}
	}
	else
	{
		cout << "One of your values was not a number" << endl;
	}
	
	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
