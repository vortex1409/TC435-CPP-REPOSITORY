#include <iostream>
#include <iomanip>
using namespace std;

void title();
void engineering(double);
int exponentialValue(double);
double factorial(int);
void fibonacci(int);


int main(){
	int _option;
	double testingVariable;
	int integerVariable;

	do{
		system("cls");
		title();
		cout << "1. Enginerring notation" << endl;
		cout << "2. Factorial" << endl;
		cout << "3. Fibonacci sequence" << endl;
		cout << "4. exit" << endl;
		cin >> _option;

		if (_option == 4)
			break;

		switch (_option)
		{
		case 1:
			cout << "Give me a number:" << endl;
			cin >> testingVariable;
			engineering(testingVariable);
			system("pause");
			break;
		case 2:
			cout << "Give me a number: " << endl;
			cin >> integerVariable;
			cout << "the factorial is: " << factorial(integerVariable);
			system("pause");
			break;
		case 3:
			cout << "number of digits for the sequence: " << endl;
			cin >> integerVariable;
			fibonacci(integerVariable);
			system("pause");
			break;
		default:
			break;
		}

	} while (true);
	return 0;
}

void title(){
	cout << "The Show Off - prepared by Daniel Garcia-Gonzalez" << endl;
}

void engineering(double inputVariable){
	// initial conditions
	double temporal = inputVariable;
	int exponentVariable = exponentialValue(inputVariable);
	int powerValue = 1; //variable to control the division. Or to eliminate as many decimals as I need from the number

	if (inputVariable >= 1){ //larger numbers open here

		if (inputVariable >= 1000){

			for (int i = 1; i <= exponentVariable; i++)	//power function
				powerValue *= 10;

			temporal = inputVariable / (powerValue);
			cout << setprecision(3) << temporal << " x10^" << exponentVariable << endl;
		}
		else{
			cout << temporal << endl;
		}

		//if (inputVariable >= 1000000){ // 1 x 10^6
		//	temporal = inputVariable / 1000000; // elimitates the thousand from the number
		//	cout << setprecision(3) << temporal << " x10^" << exponentVariable << endl;
		//}
		//else if (inputVariable >= 1000){ // 1 x 10^3
		//	temporal = inputVariable / 1000; // elimitates the thousand from the number
		//	cout << setprecision(3) << temporal << " x10^" << exponentVariable << endl;
		//} // if closes here

	}		//larger numbers close here
	else if (inputVariable > 0 && inputVariable < 1){ //small values open here

		for (int i = -1; i >= exponentVariable; i--)	//power function
			powerValue *= 10;

		temporal = inputVariable * (powerValue);
		cout << setprecision(3) << temporal << " x10^" << exponentVariable << endl;
	}// small values close here


} //function closes here

int exponentialValue(double inputVariable){
	double temporal = 0.0;				//initial condition

	if (inputVariable < 0)
		inputVariable *= -1;			// avoids calculating the log of a negative number.

	if (inputVariable == 0)				// avoids calculating the log of 0 (zero).
		return 1;

	temporal = log10(inputVariable);	// Returns the exponent of the value
	int returnVariable = floor(temporal / 3) * 3; //formats the exponent to the range we want
	return returnVariable;				// returns the proper INTeger value
}

double factorial(int input){
	double temporal = 1;
	if (input == 0)
		return temporal;
	else{
		for (int i = 1; i <= input; i++)
			temporal *= i;
	}
	return temporal;
}

void fibonacci(int input){
	int first = 1, second = 1, output = 0;
	
	for (int i = 0; i < input; i++){
		if (i == 0 || i == 1)
			output = 1;
		else{
			output = first + second;
			first = second;
			second = output;
		}
		cout << output << " ";
	}
	cout << endl;
}
