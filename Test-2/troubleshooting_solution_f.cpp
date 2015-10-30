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

	if (a == b || a == c || b == c)
	{
		/*
		
		  a b c
		a x = =
		b = x =
		c = = x

		All cases are covered since they also apply to the reverse, i.e. a == b is the same as  b == a
		*/

		cout << "I don't know what to do with repeated numbers, sorry!" << endl;
	}
	else if (a > b){
				if (a > c)
		{
			cout << a << " (a) is greater than " << b << " (b) and (c) " << c << endl;
		}
		else
		{
			cout << a << " (a) is greater than " << b << " (b) but smaller than (c) " << c << endl;
		}
	}
	else if (b > c){
			if (b > a){
			cout << b << " (b) is greater than " << c << " and (a) " << a << endl;
		}
		else{
			cout << b << " (b) is greater than " << c << " but smaller than (a) " << a << endl;
		}
	}
	else if (c > a){
		if (c > b){
			cout << c << "(c) is greater than (a) " << a << " and (b)" << b << endl;
		}
		else{
			cout << c << "(c) is greater than (a) " << a << " but smaller than (b)" << b << endl;
		}
	}
	else
	{
		// Conflicting conditions for this to be executed are:
		// a < c && a > c
		// Seeing that a can never equal c from the get-go, and the first and last condition cannot 
		// be true at the same time, this is unreachable code.
		// This could be considered a logic error.
		cout << "Still give my mate that job. People deserve an income :U" << endl;
	}

	system("pause");
}
return 0;
}
