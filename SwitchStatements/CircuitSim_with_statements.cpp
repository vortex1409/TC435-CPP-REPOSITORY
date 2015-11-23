#include <iostream>
using namespace std;

//declare functions
double seriesCalc(double , double);
double parallelCalc(double, double);
double capacitance(double);

//these functions wont receive values or return anything back
void initialConditions();
void resistanceCalc();
void capacitiveCalc();

//global variables
const double _pi = 3.14159;
double _frequency = 1;
double totalResistance = 0.0, totalReactance = 0.0;

int main(){
	int x = 0;

	/*cout << "Give me a number: ";
	cin >> x;

	switch (x)
	{
	case 1:
		cout << "x is 1" << endl;
		break;
	case 2:
		cout << "x is 2" << endl;
		break;
	case 3:
		cout << "x is 3" << endl;
		break;
	}*/

	int _input = 0;

	while (true)
	{
		system("cls");
		cout << "Main Menu" << endl;
		cout << "1. Initital Constants" << endl;
		cout << "2. Resistance Calculation" << endl;
		cout << "3. Capacitive Reactance Calculation" << endl;
		cout << "4. Display Total Impedance" << endl;
		cout << "5. Exit" << endl;
		cin >> _input;

		switch (_input)
		{
		case 1:
			initialConditions();
			break;
		case 2:
			resistanceCalc();
			break;
		case 3:
			capacitiveCalc();
			break;
		default:
			cout << "I don't know what you want" << endl;
			system("pause");
			break;
		}
		if (_input == 5)
			break;
	}








	system("pause");
	return 0;
}

//define functions
double seriesCalc(double x, double y){
	return x + y;
}

double parallelCalc(double x, double y){
	return (x * y) / (x + y);
}

double capacitance(double cap){
	return 1 / (2 * _pi * _frequency * cap);
}

void initialConditions(){
	char _change; //var only exists in function
	cout << "Pi has a value of: " << _pi << endl;
	cout << "The frequency is: " << _frequency << endl;
	cout << "Do you want to change the frequency? (y/n)" << endl;
	cin >> _change;

	switch (_change)
	{
	case 'y':
	case 'Y':
		cout << "Give me the frequency: ";
		cin >> _frequency;
		break;
	default:
		break;
	}
}

void resistanceCalc(){
	double localTotal = 0.0, temporalValue = 0.0;
	char _input;

	do{
		cout << "Total resistance: " << totalResistance << " ohms" << endl;
		cout << "local resistance: " << localTotal << " ohms" << endl;
		cout << "series or parallel or exit (s/p/e)?: ";
		cin >> _input;

		switch (_input)
		{
		case 's':
		case 'S':
			cout << "Give me the resistance (ohms): ";
			cin >> temporalValue;
			localTotal = seriesCalc(localTotal, temporalValue);
			break;
		case 'p':
		case 'P':
			cout << "Give me resistance (ohms): ";
			cin >> temporalValue;
			localTotal = parallelCalc(localTotal, temporalValue);
			break;
		case 'e':
			totalResistance += localTotal; //same as totalresisatnce = totalresistance + localtotal
			break;
		default:
			cout << "I don't know what you want" << endl;
			break;
		}

		if (_input == 'e') //this will end infinite loop, because of break
			break;
		system("cls");
	} while (true);
}

void capacitiveCalc(){
	double localTotal = 0.0, temporalValue = 0.0;
	char _input;

	do{
		cout << "Total reactance: " << totalReactance << " ohms" << endl;
		cout << "local reactance: " << localTotal << " ohms" << endl;
		cout << "Frequency: " << _frequency << " Hz" << endl;
		cout << "series or parallel or exit (s/p/e)?: ";
		cin >> _input;

		switch (_input)
		{
		case 's':
		case 'S':
			cout << "Give me the capacitance (uF): ";
			cin >> temporalValue;
			localTotal = seriesCalc(localTotal, capacitance(temporalValue / 1000000));
			break;
		case 'p':
		case 'P':
			cout << "Give me resistance (uF): ";
			cin >> temporalValue;
			localTotal = parallelCalc(localTotal, capacitance(temporalValue / 1000000));
			break;
		case 'e':
			totalReactance += localTotal; //same as totalreactance = totalreactance + localtotal
			break;
		case 'c':
			localTotal = 0.0;
			break;
		default:
			cout << "I don't know what you want" << endl;
			break;
		}

		if (_input == 'e') //this will end infinite loop, because of break
			break;
		system("cls");
	} while (true);
}
