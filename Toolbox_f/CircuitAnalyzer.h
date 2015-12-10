#pragma once
#include <vector>

using namespace std;

class CircuitAnalyzer
{
public:
	// singleton instance fn
	static CircuitAnalyzer* getInstance();
	// dumps current values
	void listContents();
	// change the source voltage
	void setVoltage(double);
	// move into a different branch
	int selectBranch(int);
	// delete a branch
	void deleteBranch();
	// add a new branch
	void addBranch();
	// add a resistance to the current branch
	void placeResistance(int);
	// transh all values
	void clearAll();
private:
	// constructor
	CircuitAnalyzer();
	// singleton instance buffer pointer
	static CircuitAnalyzer* instance;
	// all the branches
	vector<int> branchResistances;
	// the source voltage
	double sourceVoltage;
	// index of the current branch in branchResistances
	int currentBranch;
};

