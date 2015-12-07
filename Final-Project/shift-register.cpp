#include <iostream>

using namespace std;

void clear()
{
    cout << "\033[2J\033[1;1H";
}

void pause()
{
    // system("pause");
    cin.ignore();
    cin.clear();
    cout << "Press any key to continue...";
    cin.get();
}


int main(){
    // SHIFT REGISTER
	while (true) // SHIFT REGISTER
	{
		char shiftmenu;
		
		int D0, D1, D2, D3;
		D0 = D1 = D2 = D3 = 0;

		int _input = 0;
		int _output = 0;

		do
		{
			cout << "|==============================================|" << endl;
			cout << "|================| SHIFTER |===================|" << endl;
			cout << "|==============================================|" << endl;
			cout << "|=======|" << "D3" << "|===|" << "D2" << "|===|" << "D1" << "|===|" << "D0" << "|==========|" << endl;
			cout << "|===========|" << D3 << "|===|" << D2 << "|===|" << D1 << "|===|" << D0 << "|==============|" << endl;
			cout << "|==============================================|" << endl;
			cout << "| A) SHIFT ONE RIGHT                           |" << endl;
			cout << "| B) SHIFT ONE LEFT                            |" << endl;
			cout << "| C) SHIFT ZERO RIGHT                          |" << endl;
			cout << "| D) SHIFT ZERO LEFT                           |" << endl;
			cout << "| E) EXIT                                      |" << endl;
			cout << "| Selection: ";
			cin >> shiftmenu;

            switch(shiftmenu)
            {
                case 'A':
                case 'a':
                clear();
                // Shift 1 right
                D0 = D1;
                D1 = D2;
                D2 = D3;
                D3 = 1;
                break;
                
                case 'B':
                case 'b':
                clear();
                // Shift 1 left
                D3 = D2;
                D2 = D1;
                D1 = D0;
                D0 = 1;
                break;
                
                case 'C':
                case 'c':
                clear();
                // Shift 0 right
                D0 = D1;
                D1 = D2;
                D2 = D3;
                D3 = 0;
                break;
                
                
                case 'D':
                case 'd':
                clear();
                // Shift 0 left
                D3 = D2;
                D2 = D1;
                D1 = D0;
                D0 = 0;
                break;
                
                default:
                clear();
                cout << "Enter something valid you idiot." << endl;
                pause();
                break;
            }
		} while (!(shiftmenu == 'E' || shiftmenu == 'e')); // EXIT
	}
}
