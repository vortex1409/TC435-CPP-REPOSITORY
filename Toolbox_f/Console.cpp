#include "Console.h"
#include <typeinfo>
#include <sstream>
#include <iomanip>

void Console::log(string _msg)
{
	cout << _msg << endl;
}

void Console::log()
{
	cout << endl << endl;
}

void Console::head(string _msg)
{
	transform(_msg.begin(), _msg.end(), _msg.begin(), toupper);
	cout << "---------- " << _msg << " ----------" << endl;
}

void Console::clear()
{
	system("cls");
}

void Console::wait()
{
	system("pause");
}

void Console::clearCin()
{
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

string Console::engNot(double _value, char* _unit)
{
	int magnitude = 8;
	// Populate an array with prefix characters
	static char *prefixes[] = { "y", "z", "a", "f", "p", "n", "u", "m", "", "k", "M", "G", "T", "P", "E", "Z", "Y" };

	if (_value == 0)
	{
		string temp = "0.000 ";
		temp = temp + _unit;
		return temp;
	} 
	else if (_value > 1)
	{
		// Cut the value down to size if its larger than 1000, over and over until it is not
		// while incrementing the prefix.
		while (_value >= 1000)
		{
			_value /= 1000;
			magnitude++;
		}
	}
	else {
		// multiply the value if its smaller than one, decrementing the prefix.
		while (_value <= 1)
		{
			_value *= 1000;
			magnitude--;
		}
	}

	// If the value is out of range (smaller than yocto, larger than Yotta)
	// quit in frustration - however, double is not large enough to hold more than
	// single digit exa values anyways.
	if (magnitude < 0 || magnitude >= 17)
	{
		return "Could not enginneer the notation: Number too large.";
	}
	// Rounding
	stringstream roundingStream;
	roundingStream << fixed << setprecision(3) << _value;

	string message = roundingStream.str() + " " + prefixes[magnitude] + _unit;

	return message;
}