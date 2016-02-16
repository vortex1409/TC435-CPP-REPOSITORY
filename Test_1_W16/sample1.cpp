#include <iostream>
using namespace std;
//solutions, for practice problems, for test 1, for TC-435, for fun!
//prepared by: Daniel Garcia-Gonzalez

//2
struct anyRandomName
{
	int aVariable, anotherOne;
	double something;
	//12 - ignore if you are in step 2
	int stepTwelve[8];
};

//18 - ignore if you are in previous steps
void question18(anyRandomName);

//20 - a
void createTriangle();

int main() {
	//1
	int anArrayOfTwentyElements[20];

	//3
	int noDimension[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//4
	anyRandomName question4;

	//5
	int sizeOfArray = sizeof(anArrayOfTwentyElements) / sizeof(anArrayOfTwentyElements[0]);

	//6
	question4.aVariable = sizeOfArray;

	//7
	for (int i = 0; i < sizeOfArray; i++)//<-- hint
		cout << noDimension[i] << ", ";			//What's wrong here that is affecting the printing of values?
	cout << endl << '\n';
	
	//8
	int working_r = 0;
	while (working_r < sizeOfArray) {//<-- hint
		cout << noDimension[working_r] << ", ";	//What's wrong here that is affecting the printing of values?
		working_r++;
	}
	cout << endl << '\n';

	//9
	working_r = 0;
	for (int abc = 0; abc < 2 * sizeOfArray; abc += 2) {	//mutilplied by two because sizeOfArray is 20, and abc will increase by 2 every step (so, it will cycle 10 times only without the multiplication).
		anArrayOfTwentyElements[working_r] = abc;
		working_r++;
	}
	cout << endl << '\n';

	//10
	for (int i = 0; i < sizeOfArray; i++)//<-- hint
		cout << anArrayOfTwentyElements[i] << " -> ";			//The arrow at the end is expected
	cout << endl << '\n';

	//11
	double average = 0.0;
	for (int i = 0; i < sizeOfArray; i++)
		average += anArrayOfTwentyElements[i];			
	
	average = average / sizeOfArray;

	//13
	cout << average;
	cout << endl << '\n';

	//14
	working_r = 5;			//initial condition for this step.
	for (int lewtz = 0; lewtz < 8; lewtz++) {					//using a fized value of as the size of the array because we know that's its size. Yet, not good programming practice.
		question4.stepTwelve[lewtz] = working_r;
		working_r += 5;		// the same as typing working_r = working_r + 5.
	}

	//15
	for (int i = 0; i < 8; i++)
		cout << question4.stepTwelve[i] << endl;

	//16
	average = 0.0;
	for (int i = 0; i < 8; i++)
		average += question4.stepTwelve[i];

	average = average / 8;

	//17
	cout << average;
	cout << endl << '\n';

	//19 - b
	question18(question4);

	//20 - c
	createTriangle();

	system("pause");
	return 0;
}

//19 - a
void question18(anyRandomName input_1) {
	for (int i = 0; i < 8; i++)
		cout << input_1.stepTwelve[i] << '\t';
	cout << endl << '\n';
}	//end of function

//20 - b
void createTriangle() {
	int height = 0, widththththth = 0;		//everything initialized to 0; check why.

	for (height = 0; height < 4; height++) {

		for (int i = 0; i <= widththththth; i++) {	//the key for this code is the variable widthththththththth
			cout << '*';
		}	//end of inner loop
		widththththth++;		//notice it increase by 1, here.
		cout << endl;

	}	//end of outer loop

}	//end of function
