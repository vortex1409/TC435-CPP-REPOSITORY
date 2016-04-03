//#pragma once
#ifndef DORFMAN_W16_H
#define DORFMAN_W16_H
#include <iostream>
#include <cmath> // Added to remove 'ambiguous'
#include <cstring>
#include <fstream>
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

//struct PLC
//{
//	double SP, PV;
//	double ProportionalG, DifferentialG, IntegralG;
//	double Alarm_1, Alarm_2;
//};

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
	// Old Struct Data (Redundancy)
	//double capacitance;
	//double cap_LP, cap_HP;
	//double resistance_LP;
	//double resistance_HP;
	//double frequency;
	//double Fl, Fr, Fh;
	//double Frequency;
	//double Impedance;
	//double Amplitude;

	// Test 2
	double Capacitance;
	double Resistance_LP;
	double Resistance_HP;
	double Frequency;
	double Impedance;
	double Amplitude;
	double cap_LP, cap_HP;
	double Fl, Fr, Fh;
};

struct PLC
{
	double SP, PV;
	double ProportionalG, DifferentialG, IntegralG;
	double System_T, System_G;
	double CharacteristicEffects[2];
};

struct plotter
{
	char Y_axisLabel[15], X_axisLabel[15];
	int axis_MIN, axis_MAX;
	double _X, _Y, _step;
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

int sizeofCString(char[]);

void StringToBin(char[]);

// Quiz - 7 A
void WhoAreYou();

// Quiz - 7 A
void vowelCounter();

void plot(int, int, int);

double pie();

double exponent(double);

void Equation_1(PLC&);

double capacitance(double, double);

double inductance(double, double);

void Equation_2(PLC&);

void Equation_3(filter_RC&);

void Equation_4(filter_RC&);

void Equation_5(filter_RC&);

double impedance(double, double, double);

// TEST 2 FUNCTIONS

void functionToPlot(plotter&, filter_RC&);

void plotFilter(plotter&, filter_RC&);

void initializeFilter(filter_RC&);

void resonantFrequency(filter_RC&);

void bandPassFilter(filter_RC&);

void effectiveImpedance(filter_RC&);

void highPassFilter(filter_RC&);

void lowPassFilter(filter_RC&);

void hi_cutOff_Frequency(filter_RC&);

void lo_cutOff_Frequency(filter_RC&);

void power_correction(filter_RC&);

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
