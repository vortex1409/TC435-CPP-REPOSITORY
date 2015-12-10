#include "ShiftRegister.h"

ShiftRegister* ShiftRegister::instance = false;

ShiftRegister::ShiftRegister()
{
	reset();
}

ShiftRegister* ShiftRegister::getInstance()
{
	if (!instance)
	{
		instance = new ShiftRegister();
	}

	return instance;
}

void ShiftRegister::shiftTo(bool _direction, bool _value)
{
	if (_direction == SHIFT::LEFT)
	{
		qd = qc;
		qc = qb;
		qb = qa;
		qa = _value;
	}
	else {
		qa = qb;
		qb = qc;
		qc = qd;
		qd = _value;
	}
}

void ShiftRegister::showContents()
{
	Console::log();
	Console::log("- Current Value -");
	Console::log("Decimal: " + to_string(toDecimal()));
	Console::log("Binary:  " + to_string(qd) + to_string(qc) + to_string(qb) + to_string(qa));
	Console::log("------------------");
	Console::log();
}

int ShiftRegister::toDecimal()
{
	int output = 0;

	output += (qa) ? 1 : 0;
	output += (qb) ? 2 : 0;
	output += (qc) ? 4 : 0;
	output += (qd) ? 8 : 0;

	return output;
}

void ShiftRegister::loadDecimal(int _dec)
{
	qa = _dec % 2;
	_dec /= 2;
	qb = _dec % 2;
	_dec /= 2;
	qc = _dec % 2;
	_dec /= 2;
	qd = _dec % 2;
}

void ShiftRegister::reset()
{
	qa = qb = qc = qd = false;
}