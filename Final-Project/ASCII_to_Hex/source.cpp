#include <iostream>
#include <string>
using namespace std;

int main()
{

	cout.setf(ios::showbase);

	string text;
	cout << "Write text, please: ";
	cin >> text;

	for (int i = 0; i < text.length(); i++)
	{
		cout << "Letter [" << dec << i << "]: "
			<< hex << (text.at(i) - '0') << "\n";
	}
	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
