#include "Menus.h"
#include "Console.h"
#include "CircuitAnalyzer.h"
#include "ShiftRegister.h"
#include "CircuitGenerator\RandCircGen.h"

int Menus::currentState = MenuState::MAIN;

int Menus::menuMain()
{
	Console::head("Main Menu");
	Console::log("Make a selection:");
	Console::log("1) Simple circuit toolset");
	Console::log("2) Shift register toolset");
	Console::log("3) Random circuit generator");
	Console::log("0) Quit");

	int ret = Console::getInput<int>(0, 4);
	// Jump over the zero-state that ends the program in this menu only
	if (ret == 0)
	{
		return 0;
	}
	else
	{
		return ret + 1;
	}
}

int Menus::menuCircAn()
{
	CircuitAnalyzer* can = CircuitAnalyzer::getInstance();
	while (true)
	{
		Console::head("Simple Circuit Toolset");
		can->listContents();
		Console::log("Make a selection:");
		Console::log("1) Set source voltage");
		Console::log("2) Add or remove a resistance in the current branch");
		Console::log("3) Add a branch");
		Console::log("4) Remove the current branch");
		Console::log("5) Go to branch");
		Console::log("6) Clear all values");
		Console::log("0) Back");

		switch (Console::getInput<int>(0, 6, true))
		{
		case 1:
			Console::clear();
			Console::head("Set the source voltage");
			Console::log("Enter the new voltage in Volts:");
			can->setVoltage(Console::getInput<double>());
			Console::clear();
			break;
		case 2:
			Console::clear();
			Console::head("Add or remove a branch resistor");
			Console::log("Enter the resistance in whole Ohms.");
			Console::log("If the resistance should be removed, use a negative sign:");
			can->placeResistance(Console::getInput<int>());
			Console::clear();
			break;
		case 3:
			Console::clear();
			can->addBranch();
			Console::head("Success");
			Console::log("Branch Added.");
			Console::wait();
			Console::clear();
			break;
		case 4:
			Console::clear();
			can->deleteBranch();
			Console::head("Success");
			Console::log("Branch deleted.");
			Console::wait();
			Console::clear();
			break;
		case 5:
			Console::clear();
			Console::head("Go to Branch");
			can->listContents();
			Console::log("Enter ID:");
			if (can->selectBranch(Console::getInput<int>()) == 10)
			{
				Console::log("This branch does not exist.");
				Console::wait();
			}
			Console::clear();
			break;
		case 6:
			Console::clear();
			can->clearAll();
			Console::head("Success");
			Console::log("Values cleared.");
			Console::wait();
			Console::clear();
			break;
		default:
			return Menus::MenuState::MAIN;
			break;
		}
	}
}

int Menus::menuShiftRgAn()
{
	ShiftRegister* shrg = ShiftRegister::getInstance();
	while (true)
	{
		Console::head("Shift register toolset");
		shrg->showContents();
		Console::log("Make a selection:");
		Console::log("1) Reset Register");
		Console::log("2) Load Values");
		Console::log("3) Shift 1 left");
		Console::log("4) Shift 1 right");
		Console::log("5) Shift 0 left");
		Console::log("6) Shift 0 right");
		Console::log("0) Back");
		switch (Console::getInput<int>(0, 6, true))
		{
		case 1:
			Console::clear();
			shrg->reset();
			Console::head("Success");
			Console::log("Register reset");
			Console::clear();
			break;
		case 2:
			Console::clear();
			Console::head("Load Values");
			Console::log("Enter the value you wish to load as an");
			Console::log("integer between 0 and 15");
			shrg->loadDecimal(Console::getInput<int>(0, 15, true));
			Console::clear();
			break;
		case 3:
			shrg->shiftTo(ShiftRegister::SHIFT::LEFT, true);
			Console::clear();
			break;
		case 4:
			shrg->shiftTo(ShiftRegister::SHIFT::RIGHT, true);
			Console::clear();
			break;
		case 5:
			shrg->shiftTo(ShiftRegister::SHIFT::LEFT, false);
			Console::clear();
			break;
		case 6:
			shrg->shiftTo(ShiftRegister::SHIFT::RIGHT, false);
			Console::clear();
			break;
		default:
			return Menus::MenuState::MAIN;
			break;
		}
	}
}

int Menus::menuRandCircGen()
{
	RCG::RandCircGen* rcg = RCG::RandCircGen::getInstance();
	while (true)
	{
		Console::head("Random Circuit Generator");
		rcg->outputCircuit();
		Console::log();
		Console::log("Make a selection:");
		Console::log("1) Set resistor count");
		Console::log("2) Load from seed");
		Console::log("3) Generate random");
		Console::log("0) Back");

		switch (Console::getInput<int>(0, 3, true))
		{
		case 1:
			Console::clear();
			Console::head("Set resistor count");
			Console::log("Enter the amount of resistors in the circuit (1-20):");
			rcg->changeOptions(Console::getInput<int>(1, 20, true), 0);
			rcg->generate();
			Console::clear();
			break;
		case 2:
			Console::clear();
			Console::head("Load From Seed");
			Console::log("Enter the seed you wish to load:");
			rcg->generate(Console::getInput<int>(0, INT_MAX, true));
			Console::clear();
			break;
		case 3:
			rcg->generate();
			Console::clear();
			break;
		default:
			return Menus::MenuState::MAIN;
			break;
		}
	}
}