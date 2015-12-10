#include "CircuitAnalyzer.h"
#include "Console.h"


CircuitAnalyzer* CircuitAnalyzer::instance = false;

CircuitAnalyzer::CircuitAnalyzer()
{
	branchResistances = vector<int>();
	clearAll();
}

CircuitAnalyzer* CircuitAnalyzer::getInstance()
{
	if (!instance)
	{
		instance = new CircuitAnalyzer();
	}

	return instance;
}

void CircuitAnalyzer::listContents()
{
	string resistorMessage = "";

	if (branchResistances.size() <= 0)
	{
		Console::log("No resistances in the circuit yet.");
		return;
	}
	int branchID = 0;
	double totalResistance = 0;

	for each (int resistance in branchResistances)
	{
		if (totalResistance == 0)
		{
			totalResistance = resistance;
		}
		else
		{
			if (resistance > 0)
			{
				totalResistance = (1 / totalResistance);
				totalResistance += (1 / (double)resistance);
				totalResistance = 1 / totalResistance;
			}
		}
		string line = "Branch #" + to_string(branchID + 1) + "\t" + Console::engNot(resistance, "Ohms");

		if (branchID == currentBranch)
		{
			line = ">> " + line;
		}

		resistorMessage = resistorMessage + line + "\n";
		branchID++;
	}

	double totalPower = (totalResistance > 0)? (sourceVoltage * sourceVoltage) / totalResistance : 0;
	double totalCurrent = (totalResistance > 0) ? sourceVoltage / totalResistance : 0;

	Console::log();
	Console::log("- Current Values -");
	Console::log("Source Voltage:   " + Console::engNot(sourceVoltage, "V"));
	Console::log("Total Resistance: " + Console::engNot(totalResistance, "Ohms"));
	Console::log("Total Power:      " + Console::engNot(totalPower, "W"));
	Console::log("Total Current:    " + Console::engNot(totalCurrent, "A"));
	Console::log();
	Console::log(resistorMessage);
	Console::log("------------------");
	Console::log();
}

void CircuitAnalyzer::setVoltage(double _vs)
{
	sourceVoltage = _vs;
}

void CircuitAnalyzer::addBranch()
{
	branchResistances.push_back(0);
	selectBranch(branchResistances.size());
}

int CircuitAnalyzer::selectBranch(int _branchId)
{
	--_branchId;
	if (_branchId >= branchResistances.size() || _branchId < 0)
	{
		return 10;
	}
	currentBranch = _branchId;
	return currentBranch;
}

void CircuitAnalyzer::deleteBranch()
{
	// Delete the first branch only if there are other branches available
	if (currentBranch == 0 && branchResistances.size() <= 1)
	{
		branchResistances[0] = 0;
		return;
	}
	branchResistances.erase(branchResistances.begin() + currentBranch);
	currentBranch = 0;
}

void CircuitAnalyzer::placeResistance(int _r)
{
	branchResistances[currentBranch] += _r;
	if (branchResistances[currentBranch] < 0)
	{
		branchResistances[currentBranch] = 0;
	}
}

void CircuitAnalyzer::clearAll()
{
	sourceVoltage = 12;
	currentBranch = 0;
	branchResistances.clear();
	branchResistances.push_back(0);
}