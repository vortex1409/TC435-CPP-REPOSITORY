#include <iostream>
// the following libraries are used for the random
#include <stdio.h>            //null
#include <stdlib.h>           // srand, rand
#include <time.h>             // time
#include <iomanip>

using namespace std;

//declared functions
void clearglobals();
void printTable();
void inputuser();
void manual();
int _s11, _s12, _s13, _s21, _s22, _s23, _s31, _s32, _s33;
int repeatedVal();
void automode();

int main(){

	srand(time(NULL)); // random seed. is an algorythm that creates random numbers
						// timeNULL will use the system clock to feed the algoryth to create random #

	// intial condition
	clearglobals();
	int _opt; // var for inital options
	// call for the table
	do{
		system("cls");   // clears screen easier to follow2
		printTable();
		cout << "1. manual mode, input values" << endl;
		cout << "2. auto mode, iterations" << endl;
		cout << "3. exit" << endl << "what should i do: ";
		cin >> _opt;

			if (_opt == 3) // if the user inputs 3 this condition is true
				break; // break will stop the pervious loop.. infinte 
			if (_opt == 1) // calls for manual 
				manual();
			if (_opt == 2) // calls for auto
				automode();

	} while (true); // the code will always run unit a break triggered


	/*srand(time(NULL));
	rand_int = rand() % (max - min + 1) + min;*/


	system("pause");
	return 0;
}

//define functions
void printTable(){
	cout << setw(3) << _s11 << setw(3) << _s12 << setw(3) << _s13 << setw(3) << " -- " << _s11 + _s12 + _s13 << endl;
	cout << setw(3) << _s21 << setw(3) << _s22 << setw(3) << _s23 << setw(3) << " -- " << _s21 + _s22 + _s23 << endl;
	cout << setw(3) << _s31 << setw(3) << _s32 << setw(3) << _s33 << setw(3) << " -- " << _s31 + _s32 + _s33 << endl;
	cout << setw(3) << "|" << setw(3) << "|" << setw(3) << "|" << endl;
	cout << setw(3) << _s11 + _s21 + _s31 << setw(3) << _s12 + _s22 + _s32 << setw(3) << _s13 + _s23 + _s33 << endl;
}
void clearglobals(){
	_s11 = 0;
	_s12 = 0;
	_s13 = 0;
	_s21 = 0;
	_s22 = 0;
	_s23 = 0;
	_s31 = 0;
	_s32 = 0;
	_s33 = 0;
}
void manual(){
	cout << " give me the value for coordinate 1,1: ";
	cin >> _s11;
	cout << " give me the value for coordinate 1,2: ";
	cin >> _s12;
	cout << " give me the value for coordinate 1,3: ";
	cin >> _s13;
	cout << " give me the value for coordinate 2,1: ";
	cin >> _s21;
	cout << " give me the value for coordinate 2,2: ";
	cin >> _s22;
	cout << " give me the value for coordinate 2,3: ";
	cin >> _s23;
	cout << " give me the value for coordinate 3,1: ";
	cin >> _s31;
	cout << " give me the value for coordinate 3,2: ";
	cin >> _s32;	
	cout << " give me the value for coordinate 3,3: ";
	cin >> _s33;
	
	int evaluation = repeatedVal();
	if (evaluation == 1){
		cout << "sorry you gave me a repeated number, try again" << endl;
		system("pasue");
		system("cls");
			manual();
	} 
}// manual input function closes here
int repeatedVal(){
	// my rule: if there's no repeated numbers, this function
	//		will return a 0; if there's a repeated number
	//		it will return a 1.

	if (_s11 == _s12 || _s12 == _s13 || _s13 == _s11)
		return 1;
	if (_s21 == _s22 || _s22 == _s23 || _s23 == _s21)
		return 1;
	if (_s31 == _s32 || _s32 == _s33 || _s33 == _s31)
		return 1;
	if (_s11 == _s21 || _s21 == _s31 || _s31 == _s11)
		return 1;
	if (_s21 == _s22 || _s22 == _s32 || _s32 == _s21)
		return 1;
	if (_s31 == _s32 || _s32 == _s33 || _s33 == _s31)


	return 0;

}
void automode(){
	int rand_int, max = 9, min = 1;
	_s11 = rand() % (max - min + 1) + min;
	_s12 = rand() % (max - min + 1) + min;






	system("pause")

}
