#include <iostream>
using namespace std;

int main(){

	char firstArray[2];
	int secondArray[2];
	double thirdArray[2];

	/*
	//total bytes of the whole array
	cout << "size of char: " << sizeof(firstArray) << endl;
	cout << "size of int: " << sizeof(secondArray) << endl;
	cout << "size of double: " << sizeof(thirdArray) << endl;

	//number of elements per array = number of elements / size of a single element
	cout << "number of elements in char: " << sizeof(firstArray) / sizeof(firstArray[0]) << endl;
	cout << "number of elements in int: " << sizeof(secondArray) / sizeof(secondArray[0]) << endl;
	cout << "number of elements in double: " << sizeof(thirdArray) / sizeof(thirdArray[0]) << endl;
	*/

	int sumOfElements[10];

	/*
	//loop will run, starting at x=0, up to 1 less than the number of elements of the array
	for (int x = 0; x < (sizeof(sumOfElements) / sizeof(sumOfElements[0])); x++){
		cout << "give me element " << x + 1 << ": ";
		cin >> sumOfElements[x];
	}

	//display values within array
	for (int x = 0; x < (sizeof(sumOfElements) / sizeof(sumOfElements[0])); x++){
		cout << "element #" << x + 1 << ": " << sumOfElements[x] << endl;
	}

	int sumOfAllTheElements = 0;

	for (int x = 0; x < (sizeof(sumOfElements) / sizeof(sumOfElements[0])); x++)
		sumOfAllTheElements += sumOfElements[x];

	cout << "the sum is: " << sumOfAllTheElements << endl;

	cout << endl << endl;
	*/

	/*
	//multidimensional arrays
	
	char anotherArray[3][3];

	//total number of bytes
	cout << sizeof(anotherArray) << endl;

	//number of elements of main array
	cout << sizeof(anotherArray) / sizeof(anotherArray[0]) << endl;

	//number of elements of all arrays (within multidimensional array)
	cout << sizeof(anotherArray) / sizeof(anotherArray[0][0]) << endl;

	int temporalNumber = sizeof(anotherArray) / sizeof(anotherArray[0]);

	for (int x = 0; x < temporalNumber; x++){
		for (int y = 0; y < temporalNumber; y++){
			cout << "give me element x= " << x + 1 << ", y= " << y + 1 << ", ";
			cin >> anotherArray[x][y];
		}
	}

	for (int x = 0; x < temporalNumber; x++){
		for (int y = 0; y < temporalNumber; y++){
			cout << x + 1 << ", " << y + 1 << ", " << anotherArray[x][y] << "  ";
		}
		cout << endl;
	}
	*/

	cout << endl;

	cout << "how do we find the lowest value" << endl;
	int arrayToFindAValue[] = { 4, 2, 7, 8, 5, 1 };		//# of elements is 6

	//# of elements in array
	int tamanio = sizeof(arrayToFindAValue) / sizeof(arrayToFindAValue[0]);
	int temporal = 0;

	//step 1: assign first value of the array on my temporal variable
	temporal = arrayToFindAValue[0];

	//step 2: check each element, after the first one, and compare each value
	//if the next value is lower, then assign such value to my temporal variable
	for (int x = 0; x < tamanio; x++){
		if (arrayToFindAValue[x] < temporal)
			temporal = arrayToFindAValue[x];
	}

	cout << "lowest value: " << temporal << endl;

	for (int x = 0; x < tamanio; x++){
		if (arrayToFindAValue[x] > temporal)
			temporal = arrayToFindAValue[x];
	}

	cout << "greatest value: " << temporal << endl;


	//original array: { 4, 2, 7, 8, 5, 1 }
	// should be: { 1, 2, 4, 5, 7, 8 }

	for (int x = 0; x < tamanio; x++)
		cout << arrayToFindAValue[x] << ", ";
	cout << endl;

	for (int w = 0; w < tamanio; w++){
		for (int t = 0; t < (tamanio - 1); t++){
			if (arrayToFindAValue[t] > arrayToFindAValue[t + 1]){
				temporal = arrayToFindAValue[t];
				arrayToFindAValue[t] = arrayToFindAValue[t + 1];
				arrayToFindAValue[t + 1] = temporal;
			}
		}
	}

	for (int x = 0; x < tamanio; x++)
		cout << arrayToFindAValue[x] << ", ";
	cout << endl;


	system("pause");
	return 0;
}
