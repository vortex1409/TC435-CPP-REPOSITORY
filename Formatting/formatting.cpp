#include <iostream>
#include <iomanip>
using namespace std;

int main(){

	//cout << hex; // changes base of the output (only the output)
	//cout << setiosflags(ios::showbase); // manipulator, add characteristics to the output for the user
	//cout << 10 << endl;
	//cout << setiosflags(ios::uppercase);
	//cout << 10 << endl;
	//cout << dec;
	//cout << 10 << endl;

	//double output = 234.32145;
	//cout << output << endl;
	//cout << setprecision(3) << output << endl;
	//cout << setprecision(2) << output << endl;
	//cout << setprecision(4) << output << endl;

	//cout << ".........." << endl;
	//cout << setw(10);
	//cout << "Hello" << endl;
	//cout << setw(10);
	//cout << left;
	//cout << "Hello" << endl;
	//cout << "bye" << endl;

	/*cout << setfill('x');
	cout << setfill('-') << setw(5) << 77 << endl;
	cout.fill('x');
	cout.width(10);
	cout.fill('#');
	cout.width(10);
	cout << 10 << endl;
*/

	/*double a = 3.1415926534; // how to change displayed amount of decimal places
	cout << a << endl;
	cout.precision(4);
	cout << a << endl;

	cout << fixed;

	cout << a << endl;
	cout.precision(3);
	cout << a << endl;*/

	//double a = 314.15926534;
	//cout << a << endl;
	//cout.precision(4);
	//cout << a << endl;
	//cout << scientific;
	//cout << a << endl;
	//cout.precision(2);
	//cout << a << endl;
	//cout << fixed;
	//cout << a << endl;
	//cout.precision(4);
	//cout << a << endl;
	//cout.precision(10);  //adds zeros because there is not enough info to place there
	//cout << a << endl;

	int width = 6;
	for (int row = 1; row <= 10; row++){
		for (int column = 1; column <= 4; column++){
			cout << setw(width) << row * column;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
