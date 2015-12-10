#pragma once
#include <string>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "../Console.h"
#include "CeResistor.h"
#include "CeVoltageSource.h"
#include "CeAdjunct.h"

namespace RCG
{
	class RandCircGen
	{
	public:
		// singleton Instance getter
		static RandCircGen* getInstance();
		// Print the current circuit
		void outputCircuit();
		// change options - amt of resistors and voltage sources wanted in-circuit
		void changeOptions(int, int);
		// generatres a new circuit. _seed can be passed to load specific circuit
		void generate(unsigned int _seed = 0);
	private:
		RandCircGen();
		int resistorCount;
		int voltageSourceCount;
		// The root voltage source that also contains ground.
		CeVoltageSource* rootVs;
		// singleton instance
		static RandCircGen* instance;
		// Randomize the seed based on time or use
		// the seed passed through to reload a circuit
		void roll(unsigned int _seed = 0);
		// The seed itself
		unsigned int seed;
		// Get a random integer between _min and _max
		int random(int, int);
		// Generate a new circuit
		void createCircuit();
		// Unravel an element and print it and its children recursively
		void unravel(CeResistor*, int*, int*, int*);
		// Contains a cartesian representation of the circuit for
		// in-console printing
		vector<vector<CeElement*>> circuitMap;
		// Will add the element at x, y coordinates and make sure
		// that the vectors are padded to fit the new element
		void addToMap(int, int, CeElement*);
		// Returns true if there is a space free at x,y
		bool cellAvailable(int, int);

		// Vector containing all circuit elements
		// in the circuit for ordered listing
		vector<CeResistor*> legendListing;

		// Total resistance
		double totalResistance;
		// Total current
		double totalCurrent;
	};
}
