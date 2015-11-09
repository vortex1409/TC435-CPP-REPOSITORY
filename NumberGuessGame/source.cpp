#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int input = 0;


	cout << "Enter a number between 1-10: ";
	cin >> input;

	int guess = 0;
	srand(time(NULL));
	int random = rand() % 111;

	for (guess = 2; guess >= 0; guess--) {

		if (input == random) {
			cout << "You have guessed correctly \n";
			break;
		}
		else{
			cout << "Guess Again \n" << "Enter another number: ";
			cin >> input;
		}

	}

	cout << "The random number is: " << random;



	// SPACER ---------------------------------------------------------
	cout << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}
