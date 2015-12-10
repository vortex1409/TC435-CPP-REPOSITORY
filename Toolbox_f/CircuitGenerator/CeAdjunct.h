#pragma once
#include "CeElement.h"

using namespace std;
namespace RCG
{
	// Class for the ground element. Basically a dummy.
	class CeGround : public CeElement
	{
	public:
		// Constructor, needs no parameters
		CeGround();
		// Override getName from CeResistor explicitly
		string getName() override;
	};

	// Class for the reserved cell element. Basically air.
	class CeReservedCell : public CeElement
	{
	public:
		// Constructor, needs no parameters
		CeReservedCell();
		// Override getName from CeResistor explicitly
		string getName() override;
	};

	// Class for the wire element.
	class CeWire : public CeElement
	{
	public:
		// Constructor, needs no parameters
		CeWire(bool);
		// Override getName from CeResistor explicitly
		string getName() override;
	private:
		// is this a vertical wire?
		bool vertical;
	};
}