#pragma once
#include "Console.h"

class ShiftRegister
{
public:
	// Shift directions
	enum SHIFT
	{
		RIGHT,  // f
		LEFT  // t
	};
	// Singleton instance
	static ShiftRegister* getInstance();
	// Shift contents
	void shiftTo(bool, bool);
	// Print contents
	void showContents();
	// Zero out contents
	void reset();
	// Insert binary from decimal
	void loadDecimal(int);
private:
	ShiftRegister();
	// Singleton instance
	static ShiftRegister* instance;
	// The bits
	bool qa; // LSB
	bool qb;
	bool qc;
	bool qd; // MSB
	// Convert contents to decimal
	int toDecimal();
};

