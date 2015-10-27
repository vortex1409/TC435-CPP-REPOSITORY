#include<stdio.h>
#include <iostream>
using namespace std;


int main(){

    int number;
    int min,max;
 
    cout << "Enter the minimum range: ";
    cin >> min;

   cout << "Enter the maximum range: ";
    cin >> max;

    cout << "Odd numbers in given range are: ";
    for(number = min;number <= max; number++)

         if(number % 2 !=0)
             cout << number<< " ";

    printf("\nEven numbers in given range are: ");
    for(number = min;number <= max; number++)

         if(number % 2 ==0)
             cout << number << " ";
 
    return 0;
}
