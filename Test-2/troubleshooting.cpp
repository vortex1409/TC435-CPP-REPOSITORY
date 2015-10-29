//Prepared by Daniel Garcia Gonzalez
//Troubleshooting logic
//This program is designed to input three numbers, compare them logically, and identify which number is the largest one, compared to the other two.
//For some reason, a restriction for this program is that it cannot compute repeated numbers.

// -Conditions:
// * The problem with this program is that your instructor claims there's a logic error somewhere within the code.
// * Your team mate, known for 50% of the times be a hard worker and 50% just copies someone else's work, says the code is right.
// * This is a test question worth 80% of the final grade. Programming is the last course to graduate.
// * A full time, permanent job offer is waiting for your team mate to graduate. No pressure.
// * IF your peer is right, and your professor wrong, everyone earns a cookie and your mate, a job. The professor goes fishing.
// * If you claim your mate's program to be right, but it is actually wrong, the job offer will be withrawn.
// * if the professor is right, and you prove your team mate wrong, the job offer will stay over the table and your professor will pass your peer.

// Instruction: Test the code and prove either your team mate or your professor right. Your peer, nor the instructor, knows you are testing the program.

#include <iostream>
using namespace std;

int main(){
	int a, b, c;

	cout << "give me a number: ";
	cin >> a;
	cout << "give me another different number: ";
	cin >> b;
	cout << "give me a third different number: ";
	cin >> c;

	if (a == b || a == c || b == c)		//Should I include b == a, c == a, and c == b? why? why not?
	{
		cout << "I don't  know what to do with repeated numbers, sorry!" << endl;
	}
	else if (a > b){
		if (a > c)
			cout << a << " is greater than " << b << " and " << c << endl;
		else
			cout << a << " is greater than " << b << " but smaller than " << c << endl;
	}
	else if (b > c){
		if (b > a)
			cout << b << " is greater than " << c << " and " << a << endl;
		else
			cout << b << " is greater than " << c << " but smaller than " << a << endl;
	}
	else if (c > a){
		if (c > b)
			cout << c << " is greater than " << a << " and " << b << endl;
		else
			cout << c << " is greater than " << a << " but smaller than " << b << endl;
	}
	else
		cout << "I am confused :(" << endl;			// will this line ever run? yes? no? in which conditions?

	system("pause");
	return 0;
}
