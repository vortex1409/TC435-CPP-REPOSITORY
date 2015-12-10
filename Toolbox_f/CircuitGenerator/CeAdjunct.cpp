#include "CeAdjunct.h"
namespace RCG
{
	// Ground
	CeGround::CeGround():CeElement(){}

	string CeGround::getName()
	{
		return " GD ";
	}

	// Reserved Cell
	CeReservedCell::CeReservedCell():CeElement(){}

	string CeReservedCell::getName()
	{
		return "    ";
	}


	// Wire
	CeWire::CeWire(bool _vertical)
		:CeElement()
	{
		vertical = _vertical;
	}

	string CeWire::getName()
	{
		if (vertical){
			return "  . ";
		}
		return "....";
	}
}