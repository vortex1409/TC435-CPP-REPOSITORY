#pragma once
#include "CeResistor.h"

using namespace std;
namespace RCG
{
	class CeVoltageSource : public CeResistor
	{
	public:
		// Constructor, takes voltage and an ID
		CeVoltageSource(double _sourceVoltage, int _id);
		// gets the source voltage
		double getValue() override;
		// Daniel, if you read this, tell me about it, please :)
		// Override getName from CeResistor explicitly
		string getName() override;
	private:
		// The source voltage, duh.
		double sourceVoltage;
	};
}