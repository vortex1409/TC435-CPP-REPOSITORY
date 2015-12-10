#include "Console.h"
#include "Menus.h"
																																							void partyTime(){	Console::head("PRESS ENTER TO PARTAY"); Console::head("ENTER r TO QUIT PARTAYING");	char cols[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };while (true){		int r = rand() % 16; int s = rand() % 16;		char buf[16] = { 'C', 'O', 'L', 'O', 'R', ' ', cols[r], cols[s]};		system(buf);		if (cin.get() == 'R'){			system("COLOR f8");			break;		}	}}
int main()
{
	// increase size of console
	system("MODE CON COLS=100 LINES=50");
	system("COLOR f8");

	while (Menus::currentState != 0)
	{
		Console::clear();
		Console::log("Final Project for TC335 - by Falko Retter");
		Console::log();
		switch (Menus::currentState)
		{
		case Menus::MenuState::MAIN :
			Menus::currentState = Menus::menuMain();
			break;
		case Menus::MenuState::CIRCUIT_ANALYZER:
			Menus::currentState = Menus::menuCircAn();
			break;
		case Menus::MenuState::SHIFT_REGISTER_ANALYZER:
			Menus::currentState = Menus::menuShiftRgAn();
			break;
		case Menus::MenuState::RANDOM_CIRCUIT_GENERATOR:
			Menus::currentState = Menus::menuRandCircGen();
			break;																																			case Menus::MenuState::PARTY_TIME: partyTime(); Menus::currentState = Menus::MenuState::MAIN; break;
		}
	}
	return 0;
}