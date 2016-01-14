#include <iostream>
using namespace std;

int main(){

	//int firstArray[5];			//declared the array
	//int secondArray[] = { 0, 1, 2 };	//C will define size 3 for this array
	//firstArray[0] = 1;			//intitalizing each index of the array
	//firstArray[1] = 2;
	//firstArray[2] = 1;
	//firstArray[3] = 2;
	//firstArray[4] = 1;
	//cout << "index 0: " << firstArray[0] << endl;
	//cout << "index 1: " << firstArray[1] << endl;
	//cout << "index 2: " << firstArray[2] << endl;
	//cout << "index 3: " << firstArray[3] << endl;
	//cout << "index 4: " << firstArray[4] << endl;
	//cout << "index 0: " << secondArray[0] << endl;
	//cout << "index 1: " << secondArray[1] << endl;
	//cout << "index 2: " << secondArray[2] << endl;
	//cout << endl;
	//secondArray[2] = firstArray[1] + firstArray[4];
	//cout << secondArray[2] << endl;
	//cout << "index 0: " << secondArray[0] << endl;
	//cout << "index 1: " << secondArray[1] << endl;
	//cout << "index 2: " << secondArray[2] << endl;
	//cout << endl;
	//for (int i = 0; i <= 2; i++){
	//	secondArray[i] = 0;
	//}
	//cout << "index 0: " << secondArray[0] << endl;
	//cout << "index 1: " << secondArray[1] << endl;
	//cout << "index 2: " << secondArray[2] << endl;
	//cout << endl;
	//int thirdArray[4];
	//int sizeOfArray = sizeof(thirdArray);
	//cout << sizeOfArray << endl;
	//sizeOfArray = sizeof(thirdArray) / sizeof(thirdArray[0]);
	//cout << sizeOfArray << endl;
	//cout << endl;
	//double fourthArray[4];
	//sizeOfArray = sizeof(fourthArray);
	//cout << sizeOfArray << endl;
	//sizeOfArray = sizeof(fourthArray) / sizeof(fourthArray[0]);
	//cout << sizeOfArray << endl;
	//char fifthArray[4];
	//sizeOfArray = sizeof(fifthArray);
	//cout << sizeOfArray << endl;
	//sizeOfArray = sizeof(fifthArray) / sizeof(fifthArray[0]);
	//cout << sizeOfArray << endl;

	int aByte[8];

	for (int i = 0; i < 8; i++)
		aByte[i] = 0;

	aByte[5] = 5;

	for (int j = 0; j < 8; j++){
		for (int i = 0; i < 8; i++)
			cout << aByte[i] << " ";
		cout << endl;
	}


	cout << endl << endl;


	int matrixOne[64];

	for (int i = 0; i < 64; i++)
		matrixOne[i] = 0;			//loop to define a starting value

	matrixOne[24] = 45;

	for (int i = 0; i < 64; i++){
		cout << matrixOne[i] << " ";
		if (i == 7 || i == 15 || i == 23 || i == 31 || i == 39 || i == 47 || i == 55)
			cout << endl;
	}


	cout << "\n\n";


	int matrixTwo[8][8];			//an array of two dimensions

	for (int j = 0; j < 8; j++){
		for (int i = 0; i < 8; i++)
			matrixTwo[j][i] = 0;
	}

	for (int j = 0; j < 8; j++){
		for (int i = 0; i < 8; i++)
		cout << matrixTwo[j][i] << " ";
		cout << endl;
	}


	system("pause");
	return 0;
}
