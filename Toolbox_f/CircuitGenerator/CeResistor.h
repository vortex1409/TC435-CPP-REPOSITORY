#pragma once
#include <vector>
#include <string>
#include "CeElement.h"

using namespace std;
namespace RCG
{
	// Class for resistive elements. Voltage sources inherit from here.
	class CeResistor : public CeElement
	{
	public:
		// Constructor, takes resistance and an ID
		CeResistor(int _resistance, int _id);
		// gets the resistance
		double getValue() override;
		// gets the power using the current
		double getPowerDissipation(double _current);
		// gets the voltage drop using the current
		double getVoltageDrop(double _current);
		// Returns something of the fashion of R2, Vs5 etc
		string getName() override;

		// add a child to this element
		void addChild(CeResistor* _r);
		// proceed to the next child during iteration
		CeResistor* getNextChild();
		// access the child at index _i
		CeResistor * getChildAt(int _i);
		// Get the amount of children in this element
		int getChildCount();
		// Is this a resistor or voltage source?
		bool isResistor;
	protected:
		// the resistors value
		int resistance;
		// The id of the resistor
		int id;

		// the current place in the iteration
		int childPointer;
		// this elements children
		vector<CeResistor*> children;
	};
}