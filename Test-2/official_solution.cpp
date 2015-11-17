#include <iostream>
	 using namespace std;

//Declared functions - required for the test
double series(double, double);	//function to do series calculation
double parallel(double, double);	//function to do parallel calculation
double reactance(double);		// function to calculate reactance

//This functions are only cosmetic - they bring no benefit to the end result, but to the programmer (me)
// ::notice that all of the are declared as "void" and recieve nothing. The will just print information
// and probably modify global variables. They can use local variables, but these will dissapear when the function
// ends.
void header();					
void initialParameters();
void ResistanceCalculationMenu();
void ReactanceCalculationMenu();
void FinalResult();
void clearVariables();

//global variables
double TotalResistance =0.0, TotalReactance = 0.0, frequency = 1.0;
const double _pi = 3.14159;


int main(){

	int _options;	//I create this variable local to avoid conflict with other functions

	do{
		header();

		cout << endl;

		cout << "Options:" << endl;
		cout << "1. Initial parameters" << endl;
		cout << "2. Resistance calculation" << endl;
		cout << "3. Reactance calculation" << endl;
		cout << "4. Final result" << endl;
		cout << "5. Clear variables" << endl;
		cout << "9. Exit" << endl;
		cout << "::";
		cin >> _options;

		if (_options == 9)
			break;							// Exits the previous loop (while). In this case, the loop controllin the menu. Hence, exists the program

		if (_options == 1)					//Selection depending on the option selected.
			initialParameters();			//Functions were not requested for this part
		else if (_options == 2)				//Is just a cosmetic enhancement I do on my programs
			ResistanceCalculationMenu();
		else if (_options == 3)
			ReactanceCalculationMenu();
		else if (_options == 4)
			FinalResult();
		else if (_options == 5)
			clearVariables();
	} while (true);							// Infinite loop; works the same as } while(_options != 9);


	cout << "good bye!" << endl;
	system("pause");
	return 0;
}											//Main loop finishes here.

//Functions defined - required for this test
double series(double x, double y){
	return x + y;
}

double parallel(double x, double y){
	if (x == 0)
		return y;							//Notice that only X is compared to 0. Why? This is my fail safe for the first time this function runs.
	else									//answer: because the local variable that is sent to this function is is inizialized as 0.
		return 1 / (1 / x + 1 / y);			//Yes, if the user tries to calculate a 0 ohm resistor, this function fails.
}											//How do you fix that?

double reactance(double capacitance){
	if (capacitance <= 0)
		return 0.0;
	else
		return 1 / (2 * _pi * frequency * capacitance);
}

//This functions are cosmetic - Do not give any benefit to the code; they make it look cleaner.
void header(){
	system("cls");
	cout << "--Series and parallel, impedance calculator--" << endl << "--Prepared by Daniel G Gonzalez--" << endl << endl;
}		// Because I am using this title all the time, why not make it a function on its own.

void initialParameters(){
	char edit;			//Notice this variable exists only when this function is called. Do I care about it after? no
	header();
	cout << "-initial parameters-" << endl;
	cout << "pi (constant): " << _pi << endl;
	cout << "frequency: " << frequency << endl;
	cout << "change frequency?(y/n): ";
	cin >> edit;
	if (edit == 'y'){
		cout << "new frequency (in Hz): ";
		cin >> frequency;			//Have a look at the global variables; this is one of them.
		cout << "thank you!" << endl;
	}
}

void ResistanceCalculationMenu(){
	char menu;
	double localResistance, localTotalResistance = 0.0;		//This variables will only exist when this functions is called. They will dissapear from memory once the function finishes.
	
	do{
		header();		//Function with the title of the program and my name. Esthetic purposes.

		cout << "-Resistance calculation-" << endl;
		cout << "Total resistance (so far): " << TotalResistance << " Ohms" << endl;
		cout << "Local resistance (so far): " << localTotalResistance << " Ohms" << endl;
		cout << "---To return to previous menu and add your calculation to the total, type e" << endl;
		cout << "---To clear local calculation, type c" << endl;
		cout << endl << "(S)eries or (P)arallel?: ";
		cin >> menu;

		if (menu == 'S' || menu == 's'){			//Not a requirement, but helps to avoid problems with upper and lower cases.
			cout << "Add new resistance (in Ohms): ";
			cin >> localResistance;

			localTotalResistance = series(localTotalResistance, localResistance);
		}
		else if (menu == 'P' || menu == 'p'){		//Notice this is an -else if-; in this program, using only 'if' gives the same result.
			cout << "Add new resistance (in Ohms): ";
			cin >> localResistance;

			localTotalResistance = parallel(localTotalResistance, localResistance);
		}
		else if (menu == 'c')			// Only lower case c will work for this condition
			localTotalResistance = 0.0;

	} while (menu != 'e');
	//When the user finishes the previous loop, whatever his/hers calculated value is, it will be added to the variable I am using to keep the results.
	TotalResistance += localTotalResistance; //This is the same as TotalResistance = TotalResistance + localTotalResistance;
}

void ReactanceCalculationMenu(){		//Compare this function to the one for resistors. Is exactly the same.
										//I could have used the same variables. They only exist on that function.
	char menu;		//This menu, with the same name as the variable in the other function, is not the same and has different information on it.
	double localReactance, localTemporalReactance = 0.0;
	
	do{
		header();
		cout << "-Reactance calculation-" << endl;
		cout << "Total reactance (so far): " << TotalReactance << " Ohms" << endl;
		cout << "Local reactance (so far): " << localTemporalReactance << " Ohms" << endl;
		cout << "Frequency: " << frequency << " Hz" << endl;		//This would be the only difference.
		cout << "---To return to previous menu and add your calculation to the total, type e" << endl;
		cout << "---To clear local calculation, type c" << endl;
		cout << endl << "(S)eries or (P)arallel?: ";
		cin >> menu;

		if (menu == 'S' || menu == 's'){
			cout << "Add new capacitance (in microFarads): ";
			cin >> localReactance;

			localTemporalReactance = series(localTemporalReactance, reactance(localReactance / 1000000)); //Format adjustment (I asked for values in microFarads)
		}

		else if (menu == 'P' || menu == 'p'){
			cout << "Add new capacitance (in microFarads): ";
			cin >> localReactance;

			localTemporalReactance = parallel(localTemporalReactance, reactance(localReactance / 1000000));
		}
		else if (menu == 'c')
			localTemporalReactance = 0.0;

	} while (menu != 'e');
	TotalReactance += localTemporalReactance;
}

void FinalResult(){
	header();
	cout << "The total impedance is: " << TotalResistance << " - j" << TotalReactance << " ohms" << endl;
	system("pause");
}

void clearVariables(){
	header();		//I only clear the variables that are holding variables all over the program.
					
	TotalResistance = 0.0, TotalReactance = 0.0, frequency = 1.0;
	//_pi = 3.14158;	//Would this line work for this program? Answer: no; this variables was declared as constant.
	cout << "All clear. Pi remains constant. " << endl;
	system("pause");
}
