/*INDEX FOR ALL STRUCTURES/FUNCTIONS*/
#ifndef veillieux_w16
#define veillieux_w16
#include <iostream>
#include <cstring>
using namespace std;

/*Here the functions/structures are declared
Only declared - not defined*/

/*DECLARING STRUCTURES*/

struct transistor
{
	int Hfe;					//Members of the structure "transistor"
	double Vce, Ic, Ie, Ib;
	char NPNorPNP;
}; //<--- NEVER forget the semicolon!

struct miscelaneous
{
	int output[5];
};

//Global variables?? - NOPE
int eye[1] = { 1 };		//Identity Matrix - I
int eye2x2[2][2] = { { 1, 0 }, { 0, 1 } };
int eye3x3[3][3] = { { 1, 0, 0 }, { 0, 1, 0 }, { 0, 0, 1 } };

/*-------FEB.26.16-------*/
/*QUIZ 6*/
struct Filter_RC
{
	double cap_LP, cap_HP, Capacitance, Resistance_LP, Resistance_HP, Frequency, Period;
	double Fl, Fr, Fh;
};
void degToRad(double&);
void radToDeg(double&);

/*DECLARING FUNCTIONS*/
void firstFunction();

/*Quiz1*/
double quiz_1(double);

/*Quiz2*/
void quiz_2(int, char);

/*Quiz_3*/
int AmodB(int, int);
double customEquation_1(double, double, double);

/*Matrices - IdentMatrix*/
void eyeMatrix(int);
void transverse(int[]);
void determinant(int[]);

/*Decimal to Binary*/
void inttobin(int);

/*Custom Equation_2*/
void customequation_2(int, int);

/*-------------------- TEST  1 / FEB.16.16 -------------------*/
struct timer0{	
	int TMR0ON_7, T08BIT_6, T0SC_5, T0SE_4, PSA_3, DecVal;
	int TOPS_array[3];
	double T_Period;
};
void timer0overflow(timer0);
void timer0config(int);

/*-------FEB.26.16-------*/

int sizeOfString(char[]); //this array is being passed by
void StringToBin(char[]);

/*-------MAR.4.16-------*/
/* QUIZ 7 */
void WhoAreYou();
void vowelCounter();
/* Mar.4 Walkthrough */
void plotFunc(int, int, int);

/*-------------------- Assignment 5 & 6 -------------------*/
struct PLC{
	double System_T, System_D, System_G;
	double CharaEffects[2];
};

double pi();
double Exponent(double);
void Equation_1(PLC&);
double capacitance(double, double);
double inductance(double, double);
void Equation_2(PLC&);
void Equation_3(Filter_RC&);
void Equation_4(Filter_RC&);
void Equation_5(Filter_RC&);
double impedance(double, double, double);

#endif //end of pre-processor safeguard
