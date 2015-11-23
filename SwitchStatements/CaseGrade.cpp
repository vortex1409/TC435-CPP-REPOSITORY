#include <iostream>
using namespace std;

int main() {

	// local variable declaration:
	char grade;
	cout << "Enter a Letter Grade: ";
	cin >> grade;

	switch (grade)
	{
	case 'A':
		cout << "Excellent!" << endl;
		break;
	case 'B':
	case 'C':
		cout << "Well done" << endl;
		break;
	case 'D':
		cout << "You passed" << endl;
		break;
	case 'F':
		cout << "Better try again" << endl;
		break;
	default:
		cout << "Invalid grade" << endl;
	}
	cout << "Your grade is " << grade << endl;

	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
