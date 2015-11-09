#include <iostream> 
using namespace std; 
int main() 
{ 
int num1,num2; 
char yesorno='y'; /*we will use this variable to signal that enough numbers have been entered*/ 

cout << "Addition. Please enter numbers."<<endl; 
cin >> num1; 
cin >> num2; 
num1 = num1 + num2; /*there is no need to use another variable, we can simply add to one of the existing ones*/ 

/*this loop will work until the user enters n when prompted*/ 
while(yesorno!='n') /*this is the condition of the loop: if it is false, the program will continue at the first command below the loop; if it is true, the program will pass through commands in the loop as normal, and afterwards repeat this check the condition. This continues for as long as the condition is true */ 
{ 
cout << "Do you wish to enter more numbers? y/n" << endl; 
cin >> yesorno; 

if(yesorno=='y') 
{ 
cout << "Enter a number to add to the previous sum:"<<endl; 
cin >> num2; /*we can store a new number in this variable, and add it to num1*/ 
num1 = num1 + num2; 
}//end if 
}//end loop 
cout << num1;/*when the user is done with entering numbers, display the current value of num1*/ 
return 0; 
}//end main
