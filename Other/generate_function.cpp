#include <iostream>
using namespace std;
void printDigit(int);
void printTensDigit(int);
 
int main()
{
        // 1 mark for decleration, prompt and input statements
        int number, currDigit, digitsCount = 1;
        int x = 3;
       
        while (true)
        {
                do
                {
                        cout << "Please input a positive integer: ";
                        cin >> number;
                        if (number == -1)
                        {
                                return 0;
                        }
 
                } while (number < 0);
 
                //count the number of digits the integer has
                int temp = number;
                while ((temp /= 10) > 0)
                {
                        digitsCount++;
                }
                cout << "The number has " << digitsCount << " digits." << endl;
 
                while (digitsCount > 0)
                {
                        digitsCount--;
 
                        //1st method
                        //currDigit = number / pow(10, digitsCount);
                        //number = number - currDigit * pow(10, digitsCount);
 
                        //2nd method
                        currDigit = (number % (int)pow(10, digitsCount + 1)) / pow(10, digitsCount);
 
                        int currentMultiplier = pow(10, digitsCount);
 
                        // cout << "The current digit is " << currDigit << " * " << pow(10, digitsCount) << " ." << endl;
 
                        if ((currentMultiplier >= 10 && currentMultiplier < 99) ||
                                (currentMultiplier >= 10000 && currentMultiplier < 99999))
                        {
                                printTensDigit(currDigit);
                        }
                        else if ((currentMultiplier >= 100 && currentMultiplier < 999) ||
                                (currentMultiplier >= 100000 && currentMultiplier < 999999))
                        {
                                if (currDigit != 0){
                                        printDigit(currDigit);
                                        cout << "Hundred ";
                                }
                        }
                        else
                        {
                                printDigit(currDigit);
                        }
 
                        if (pow(10, digitsCount) == 1000)
                        {
                                cout << "Thousand ";
                        }
 
                }
                cout << endl << endl;
                system("pause");
        }
        return 0;
}
 
void printDigit(int x)
{
        switch (x)
        {
        case 0:
                cout << "  ";
                break;
        case 1:
                cout << "One ";
                break;
        case 2:
                cout << "Two ";
                break;
        case 3:
                cout << "Three ";
                break;
        case 4:
                cout << "Four ";
                break;
        case 5:
                cout << "Five ";
                break;
        case 6:
                cout << "Six ";
                break;
        case 7:
                cout << "Seven ";
                break;
        case 8:
                cout << "Eight ";
                break;
        case 9:
                cout << "Nine ";
                break;
        default:
                cout << "Invalid input" << endl;
        }
}
 
void printTensDigit(int x)
{
        switch (x)
        {
        case 0:
                cout << "  ";
                break;
        case 1:
                cout << "Ten ";
                break;
        case 2:
                cout << "Twenty ";
                break;
        case 3:
                cout << "Thirty ";
                break;
        case 4:
                cout << "Fourty ";
                break;
        case 5:
                cout << "Fifty ";
                break;
        case 6:
                cout << "Sixty ";
                break;
        case 7:
                cout << "Seventy ";
                break;
        case 8:
                cout << "Eighty ";
                break;
        case 9:
                cout << "Ninety ";
                break;
        default:
                cout << "Invalid input" << endl;
        }
}
