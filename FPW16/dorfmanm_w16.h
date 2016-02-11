//#pragma once
#ifndef DORFMAN_W16_H
#define DORFMAN_W16_H
#include <iostream>
//Name : Michael Dorfman
// COurce: TC435
// Project: Custom Header
// Header for keeping functions and other code together to be used
//in any program
//--------------- DECLARING FUNCTIONS ----------------------

void firstTest(int);

void quiz_1(double);

void quiz_2(int, char);

int AmodB(int, int);

double customEquation_1(double, double, double);

void customEquation_2(int [], int);

void intToHex(int);

//------------- DECLARING STRUCTURES --------------------------

struct transistor
{
	double hfe;
	double vce, ic, ie, ib;
	char npnorpnp;
};

struct PLC
{
	double SP, PV, ProportionalG, DifferentialG, IntegralG, Alarm_1, Alarm_2, Output;
};

// ------------- DECLARING CLASSES-----------------------
class firstClass
{
public: // Info Gathered

	void firstfunction();
	int addTwo(int, int);
	int misc = 1;


private: // Info

	int num1 = 1;
	int num2 = 2;
};

#endif
