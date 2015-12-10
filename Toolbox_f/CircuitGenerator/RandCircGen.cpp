#include "RandCircGen.h"

namespace RCG
{
	RandCircGen* RandCircGen::instance = false;

	RandCircGen::RandCircGen()
	{
		circuitMap = vector<vector<CeElement*>>();
		legendListing = vector<CeResistor*>();

		changeOptions(4, 0);
		roll();
		createCircuit();
	}

	void RandCircGen::generate(unsigned int _seed)
	{
		roll(_seed);
		createCircuit();
	}

	RandCircGen* RandCircGen::getInstance()
	{
		if (!instance)
		{
			instance = new RandCircGen();
		}

		return instance;
	}

	void RandCircGen::addToMap(int _x, int _y, CeElement* _element)
	{
		int squareSide = (_x > _y) ? _x : _y;

		int xSize = circuitMap.size() - 1;
		if (xSize < squareSide)
		{
			circuitMap.resize(squareSide + 1);
		}

		for (unsigned int i = 0; i < circuitMap.size(); i++)
		{
			int ysize = circuitMap[i].size() - 1;
			if (ysize < squareSide)
			{
				circuitMap[i].resize(squareSide + 1);
			}
		}

		circuitMap[_x][_y] = _element;

		// If the element is in a higher row than the second, reserve
		// the positions above it
		if (_y > 1)
		{
			for (int i = 0; i < _y; i++)
			{
				if (cellAvailable(_x, i))
				{
					circuitMap[_x][i] = new CeReservedCell();
				}
			}
		}
	}

	bool RandCircGen::cellAvailable(int _x, int _y)
	{
		int xSize = circuitMap.size() - 1;
		int ysize = (circuitMap.size() > 0) ? circuitMap[0].size() - 1 : 0;
		if (_x > xSize || _y > ysize)
		{
			return true;
		}

		return circuitMap[_x][_y] == NULL;
	}

	void RandCircGen::changeOptions(int _resistorCount, int _voltageSourceCount)
	{
		resistorCount = _resistorCount - 1;
		voltageSourceCount = _voltageSourceCount;
	}

	void RandCircGen::roll(unsigned int _seed)
	{
		seed = (_seed == 0) ? (unsigned int)time(NULL) : _seed;
		srand(seed + random(0, 200000));
	}

	int RandCircGen::random(int _min, int _max)
	{
		_max++;
		return rand() % _max + _min;
	}

	void RandCircGen::createCircuit()
	{
		// Keep count for the components
		int vsIds = 1;
		int rIds = 0;

		rootVs = new CeVoltageSource(random(3,30), 1);

		CeResistor* currentElement = rootVs;

		// Are max amnts of components reached
		while (vsIds - 1 < voltageSourceCount
			|| rIds - 1 < resistorCount)
		{
			// Roll for parent component a random number of times
			// 1 - 15 = go one deeper, 11 - 20 = stay, 21 - 22 = return to root
			int path = random(1, 22);

			if (path <= 15)
			{
				currentElement = currentElement->getChildAt(random(0, currentElement->getChildCount()));

				if (!currentElement)
				{
					// If the assignment fails because the index is out of range 
					// (should ideally never occur), return to root
					currentElement = rootVs;
				}
			}
			else if (path > 20)
			{
				currentElement = rootVs;
			}

			// Roll for new component to attach (>1 = resistor, 0 = vs)
			// If the component isnt available, attach the other.
			while (true)
			{
				if (random(0, 5) > 1 && rIds - 1 < resistorCount)
				{
					rIds++;
					currentElement->addChild(new CeResistor(random(1, 100) * 100, rIds));
					break;
				}
				else if (vsIds - 1 < voltageSourceCount)
				{
					vsIds++;
					currentElement->addChild(new CeVoltageSource(random(3, 30), vsIds));
					break;
				}
			}

		}
	}

	// Functional Iterator for sorting legendListing
	bool sortByName(CeResistor* lhs, CeResistor* rhs)
	{
		return lhs->getName() < rhs->getName();
	}

	void RandCircGen::outputCircuit()
	{
		legendListing.clear();
		circuitMap.clear();
		int* x = new int(0);
		int* y = new int(-1);
		int* branchResistance = new int(0);
		totalResistance = 0;

		// Pass the ADRESS of x and y and construct the circuit map
		unravel(rootVs, x, y, branchResistance);

		// Sort and output the legend
		Console::log("CIRCUIT CONTENTS");
		Console::log("Seed: " + to_string(seed));
		Console::log("Total Resistance: " + Console::engNot(totalResistance, "Ohms"));
		Console::log("Total Current: " + Console::engNot(rootVs->getValue() / totalResistance, "A"));
		sort(legendListing.begin(), legendListing.end(), sortByName);
		for (CeResistor* _currEl : legendListing)
		{
			if (_currEl->isResistor)
			{
				Console::log(_currEl->getName() + " - " + Console::engNot(_currEl->getValue(), "Ohms"));
				continue;
			}
			Console::log(_currEl->getName() + " - " + Console::engNot(_currEl->getValue(), "V"));
		}

		Console::log();
		Console::log("CIRCUIT MAP");
		// print the circuit map to console line by line
		for (unsigned int y = 0; y < circuitMap[0].size(); y++)
		{
			for (unsigned int x = 0; x < circuitMap.size(); x++)
			{
				if (circuitMap[x][y] == NULL)
				{
					cout << "    ";
					continue;
				}
				cout << circuitMap[x][y]->getName();
			}
			cout << endl;
		}
	}

	void RandCircGen::unravel(CeResistor* _currentElement, int* _x, int* _y, int* _branchResistance)
	{
		legendListing.push_back(_currentElement);
		// Increment the VALUE at _y and let localY be that value
		*_y += 1;
		int localY = *_y;

		// go east until we find an available cell
		while (!cellAvailable(*_x, *_y))
		{
			*_x += 1;
		}

		// Place the element in the map
		addToMap(*_x, *_y, _currentElement);

		if (_currentElement->isResistor)
		{
			*_branchResistance += _currentElement->getValue();
		}

		// If this element has no children, add a ground connection below and then capitulate
		if (_currentElement->getChildCount() <= 0)
		{
			//gnd
			int ny = *_y + 1;
			addToMap(*_x, ny, new CeGround());

			// Add branch resistance to total resistance
			if (totalResistance > 0)
			{
				totalResistance = 1 / ((1 / (double)(*_branchResistance)) + (1 / totalResistance));
			}
			else 
			{
				totalResistance = *_branchResistance;
			}
			*_branchResistance = 0;
			return;
		}

		CeResistor* _childElement;
		while (_childElement = _currentElement->getNextChild())
		{
			unravel(_childElement, _x, _y, _branchResistance);
			*_y = localY;
		}
	}
}


