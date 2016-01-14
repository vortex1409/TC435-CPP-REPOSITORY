#include <iostream>

using namespace std;

double quiz_1(double _number)
{
    if(_number == 0)
    {
        return -1;
    }

    double numberOfIterations = (int)(2 * _number);
    double divisor = _number / 2 + 1;
    double returnNumber = _number;

    for(int i = 0; i < numberOfIterations; i++)
    {
        returnNumber += _number;
    }

    return returnNumber / divisor;
}


double quiz_1b(double _number)
{
    if(_number == 0)
    {
        return -1;
    }

    return (_number * (2 * _number + 1))/(_number / 2 + 1);
}


int main()
{
    cout << quiz_1(7.00) << endl;
    cout << quiz_1b(7.00) << endl;

    cin.get();
    return 0;
}



