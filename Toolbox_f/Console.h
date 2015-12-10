#pragma once
#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;


class Console
{
public:
	// Write to stream and insert newline
	static void log(string);
	// Write newline
	static void log();
	// Write head line
	static void head(string);
	// Clear the console
	static void clear();
	// Wait for enter
	static void wait();
	// Clear the cin buffer so error states don't get stuck
	static void clearCin();
	// convert to engineering notation
	static string engNot(double, char*);

	// Gets input from the user. Templated to express expectations.
	// Templates may only exist in the header otherwise they are inaccessible
	template <typename T>
	static T getInput(int _min = -1, int _max = -1, bool _constrain = false)
	{
		cout << "> ";
		T inbetween = -1;
		cin >> inbetween;

		if (cin.fail() || (inbetween > _max && _constrain) || (inbetween < _min && _constrain))
		{
			string message = "Please enter a valid ";
			message += typeid(T).name();

			if (inbetween > _max && _constrain)
			{
				message = message + " which is less than " + to_string(_max);
			}
			else if (inbetween < _min && _constrain)
			{
				message = message + " which is larger than " + to_string(_min);
			}

			log(message);

			Console::clearCin();
			return getInput<T>(_min, _max, _constrain);
		}

		return inbetween;
	}
};


