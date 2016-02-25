//#pragma once
#ifndef DORFMAN_W16_H
#define DORFMAN_W16_H
#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
/*
Name: Michael Dorfman
Course: TC435
Project: dorfmanm_w16.h

Header file is used to keep functions and other code together, to be used in any program
*/

//------------- DECLARING STRUCTURES --------------------------

struct transistor
{
	double hfe;
	double vce, ic, ie, ib;
	char npnorpnp;
};

struct PLC
{
	double SP, PV;
	double ProportionalG, DifferentialG, IntegralG;
	double Alarm_1, Alarm_2;
};

struct timer0
{
	bool TMR0ON;
	bool T08BIT;
	bool T0SC;
	bool T0SE;
	bool PSA;
	int T0PS[3];
	double T_Period;
	int DecVal;
	int intHex;
};

// Quiz 6 - A
struct filter_RC
{
	double capacitance_LP;
	double capacitance_LC;
	double resistance_LP;
	double resistance_HP;
	double frequency;
	double period;
};
//--------------- DECLARING FUNCTIONS ----------------------

void firstTest(int);

void quiz_1(double);

void quiz_2(int, char);

int AmodB(int, int);

double customEquation_1(double, double, double);

void identityMatrix(int);

void determinantOfMatrix(int[][3], int);

void customEquation_2(int[], int);

void intToHex(int);

void intToBin(int);

timer0 timer0overflow();

void timer0config(int);

void degtorad(double&);

void radtodeg(double&);

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
