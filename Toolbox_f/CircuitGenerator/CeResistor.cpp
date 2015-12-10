#include "CeResistor.h"
namespace RCG
{
	CeResistor::CeResistor(int _resistance, int _id)
	{
		isResistor = true;
		resistance = _resistance;
		id = _id;
		childPointer = -1;
		children = vector<CeResistor*>();
	}

	double CeResistor::getValue()
	{
		return resistance;
	}

	double CeResistor::getPowerDissipation(double _current)
	{
		return _current * _current * resistance;
	}

	double CeResistor::getVoltageDrop(double _current)
	{
		return _current * resistance;
	}
	
	string CeResistor::getName()
	{
		return " R" + to_string(id) + " ";
	}
	
#pragma region HierarchyManagement

	CeResistor* CeResistor::getNextChild()
	{
		int s = children.size();
		if (s > 0 && childPointer < s-1)
		{
			childPointer++;
			return children[childPointer];
		}
		return false;
	}

	CeResistor* CeResistor::getChildAt(int _i)
	{
		
		if (children.size() == 0 || _i >= children.size())
		{
			return false;
		}

		return children[_i];
	}

	int CeResistor::getChildCount()
	{
		return children.size();
	}
	
	void CeResistor::addChild(CeResistor* _r)
	{
		children.push_back(_r);
	}

#pragma endregion
}