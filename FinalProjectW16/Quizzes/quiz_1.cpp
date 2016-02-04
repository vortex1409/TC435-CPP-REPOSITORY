#include <iostream>
using namespace std;

void quiz_2(int, char);

int main(){

	//sample execution
	quiz_2(2, 'd');
	cout << endl << endl;

	quiz_2(3, 'o');
	cout << endl << endl;

	quiz_2(3, 'm');
	cout << endl << endl;

	quiz_2(3, 'e');
	cout << endl << endl;
	
	system("pause");
	return 0;
}

void quiz_2(int input_1, char input_2){


	//In this version of quiz 2, the integer input was used for this loop
	if (input_2 == 'd'){
		for (int i = input_1; i <= input_1 + (3 * input_1); i++)
			cout << i << " ";
	}

	//in this particular case, it wasn't requested to run only one condition at a time (the character input_2 will control that).
	//Howevever, for good practice, it's always better to reduce the time a function takes to work, because it can be called multiple times.
	else if (input_2 == 'o'){
		for (int i = 0; i < 10; i++){
			if (i < 7)
				cout << i + 1 << " ";
			else
				cout << i + 3 << " ";	//The output effect is like an octal cout up, but because it only uses numbers, there's no need for alphabetical conditions.
		}
	}
	
	else if (input_2 == 'm'){
		
		//method 1 - initializing the matriz
		int matrix[4][4] = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 1 } };

		//method 2 - creating a loop to fill the matrix
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++)
				matrix[i][j] = 1;
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
