#include <iostream> // Core
#include <cmath> // Added to remove 'ambiguous'
using namespace std;

//--------- FUNCTIONS START -------------------

struct adding
{
	double x;
	double y;
	double o;
};

//--------- FUNCTIONS END --------------------

int main() {

	adding main;

	main.x = 2;
	main.y = 4;
	main.o = main.x + main.y;

	cout << main.o << endl;

	//--------- MAIN END --------------------
	cout << endl;
	system("pause");
	return 0;
}
//TC435
// 2015 (C) MICHAEL DORFMAN | VORTEX1409 | base64(TUlDSEFFTCBET1JGTUFOIHwgVk9SVEVYMTQwOQ==)
//MTQwOQ==
