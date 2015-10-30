#include <iostream>

using namespace std;

bool isEven(int _checkInteger)
{
	return (_checkInteger % 2 == 0 && _checkInteger > 2) || _checkInteger == 0;
}

int main()
{
	for (int i = 0; i < 100; i++)
	{
		cout << i;

		if (isEven(i))
		{
			cout << " is even!" << endl;
			continue;
		}

		cout << " is odd!" << endl;
	}
	cin.get();
	return 0;
}

