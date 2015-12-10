#pragma once
#include <string>

using namespace std;

namespace RCG
{
	// The base class for all circuit elements
	class CeElement
	{
	public:
		CeElement();
		// Returns something of the fashion of R2, Vs5 etc
		virtual string getName();
		// Returns the numerical value of the element 
		// or -1 if there's no value (ONLY positive Vs are allowed at the moment)
		virtual double getValue();
	};
}

