#include <iostream>
using namespace std;

void quiz(int, char);

int main(){

	//sample execution
	quiz(2, 'd');
	cout << endl << endl;

	quiz(3, 'h');
	cout << endl << endl;

	quiz(3, 'm');
	cout << endl << endl;

	quiz(3, 'e');
	cout << endl << endl;

	system("pause");
	return 0;
}

void quiz(int input_1, char input_2){

	//In this version of quiz 2, the integer input was used for absolutely nothing
	if (input_2 == 'd'){
		for (int i = 0; i < 15; i++)
			cout << i + 1 << " ";
	}

	//in this particular case, it wasn't requested to run only one condition at a time (the character input_2 will control that).
	//Howevever, for good practice, it's always better to reduce the time a function takes to work, because it can be called multiple times.
	else if (input_2 == 'h'){
		for (int i = 0; i < 15; i++){					//for loop starts
		
			if (i < 10)
				cout << i << " ";
			else{
				//Option 1 - using a switch statement
				switch (i)
				{
				case 10:
					cout << "A ";
					break;
				case 11:
					cout << "B ";
					break;
				case 12:
					cout << "C ";
					break;
				case 13:
					cout << "D ";
					break;
				case 14:
					cout << "E ";
					break;
				default:
					break;
				}	//end of switch

				//option 2	- single line if-statements
				if (i == 10)
					cout << "A ";
				if (i == 11)
					cout << "B ";
				if (i == 12)
					cout << "C ";
				if (i == 13)
					cout << "D ";
				if (i == 14)
					cout << "E ";
									//note: choose only one of the previous methods. Right now, the output will display 2 sets of each letter.
			}	//end of else

		}														//end of for loop
	}

	else if (input_2 == 'm'){

		//method 1 - initializing the matriz
		int matrix[4][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

		//method 2 - creating a loop to fill the matrix
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++)
				matrix[i][j] = 0;
		}

		//prints the array as a 4 x 4 matrix
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}

	//Because all the previous statements are attached to the main if (i.e. they are else if's), a single else is enough
	//to catch any other combination not anticipated.
	else{
		cout << "I can't do that, John" << endl;
	}


}
