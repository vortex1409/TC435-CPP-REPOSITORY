#pragma once


class Menus
{
public:
	// State machine
	static int currentState;
	enum MenuState 
	{
		MAIN = 1,
		CIRCUIT_ANALYZER,
		SHIFT_REGISTER_ANALYZER,
		RANDOM_CIRCUIT_GENERATOR																																																						,PARTY_TIME
	};
	// GUI switch functions
	static int menuMain();
	static int menuCircAn();
	static int menuShiftRgAn();
	static int menuRandCircGen();
};