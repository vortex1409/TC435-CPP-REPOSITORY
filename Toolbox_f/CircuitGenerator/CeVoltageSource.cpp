#include "CeVoltageSource.h"
namespace RCG
{
	CeVoltageSource::CeVoltageSource(double _sourceVoltage, int _id)
		:CeResistor(0, _id)
	{
		isResistor = false;
		sourceVoltage = _sourceVoltage;
	}

	double CeVoltageSource::getValue()
	{
		return sourceVoltage;
	}

	string CeVoltageSource::getName()
	{
		return " Vs" + to_string(id);
	}
}