#include <iostream>
#include <iomanip>
using namespace std;


void engineering(double); // b/c it doesnt return anything you can call this a sub routine
int exponentialVal(double);

int main(){

	double testingVar = 0.0;


	while (true){
		cout << "--loop--" << endl;
		cout << "enter number to format in engineering notation" << endl;
		cin >> testingVar;


		if (testingVar == -1) // fail safe to exit loop
			break; // stops the previous loop (in this code its the while loop)


		
		engineering(testingVar); // doesnt return anything, doesnt need to be related
								// it only needs the variables it is meant to receive



	}// while closes here




	system("pause");
	return 0; 
}
void engineering(double inputVar){
	double temporal = inputVar;
	int expVar = exponentialVal(inputVar);
	int powerVal = 1;




	if (inputVar >= 1){ //larger values open here
		if (inputVar >= 1000){
			for (int i = 1; i <= expVar; i++)
				powerVal *= 10;
			temporal = inputVar / (powerVal);
			cout << setprecision(3) << temporal << " x10^" << expVar << endl;
		}
		else {
			cout << temporal << endl;
			}

	/*if (inputVar >= 1){ // larger numbers open here
		if (inputVar >= 1000000){
			temporal = inputVar / 1000000;	// elimitates the million from the number
			cout << setprecision(3) << temporal << "x10^" << expVar << endl;
		}
		else if (inputVar >= 1000){ // 1 x 10^3
			temporal = inputVar / 1000;	// elimitates the thousand from the number
			cout << setprecision(3) << temporal << "x10^" << expVar << endl;
		} // if closes here
		*/

	}//larger values closes here
	else if(inputVar >0 && inputVar < 1){ // small values open here


		for (int i = -1; i >= expVar; i--)
			powerVal *= 10;
			temporal = inputVar * (powerVal);
			cout << setprecision(3) << temporal << " x10^" << expVar << endl;
		
	
	}//small values close here





}
int exponentialVal(double inputVar){ 
	double temporal = 0.0;
	if (inputVar < 0)
		inputVar *= -1;
	if (inputVar == 0)
		return 1;

	temporal = log10(inputVar);    //returns the exponent of the value 
	int returnVar = floor(temporal / 3) * 3; 
	return returnVar; 

}
