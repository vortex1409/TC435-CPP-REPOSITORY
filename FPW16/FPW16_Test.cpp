#include <iostream>
/*include your header .h file here*/
#include <>
using namespace std;

void whatsThePointOFthis();
void test_quiz_1();
void test_quiz_2();
void test_quiz_3();
void test_quiz_4();
void test_assignment3();
void test_test1();
void test_quiz_6();
void test_quiz_7();
void test_test_2();

int main() {
	whatsThePointOFthis();

	//you can comment any of these functions and test them individually if you want to
	test_quiz_1();
	test_quiz_2();
	test_quiz_3();
	test_quiz_4();
	test_assignment3();
	test_test1();
	test_quiz_6();
	test_quiz_7();
	test_test_2();

	cout << endl << "------end of testing-------. " << endl;
	system("pause");
	return 0;
}

void whatsThePointOFthis() {
	system("cls");
	cout << endl << "--------------------------------------------------------------" << endl
		<< endl << "                       header File tester " << endl
		<< endl << "                   Update: 1.4 April 14, 2016" << endl
		<< endl << "                 Prepared by: Daniel Garcia-Gonzalez" << endl
		<< endl << "--------------------------------------------------------------" << endl;


	cout << endl << endl << "   The point of this file is to test your header files up to what" << endl
		<< " we have worked on so far." << endl
		<< endl << "   Check the capital letters, use of numbers, and all the indications " << endl
		<< "we have defined for the functions, structures, and everything." << endl << endl;
	system("pause");
}

void test_quiz_1() {
	system("cls");
	cout << "quiz 1" << endl << endl
		<< "a) -3, must return -30: " << quiz_1(-3) << endl
		<< "b) 10.15, must return a 35.58: " << quiz_1(10.15) << endl
		<< "c) -2, must return -1: " << quiz_1(-2) << endl;
	system("pause");
}

void test_quiz_2() {
	system("cls");
	cout << "quiz 2" << endl << endl
		<< "a) num: 6, char: d. I must see sequence 0 to 15 or 6 to 24" << endl;
	quiz_2(6, 'd');                                                                                                 //v 1.1 correction
	cout << endl << "b) num: 2, char: h. I must see a sequence from 0 to 9, then A to E" << endl;
	quiz_2(3, 'h');
	cout << endl << "c) num: 3, char: m. I must see a 4 x 4 matrix (zeros or ones)" << endl;
	quiz_2(3, 'm');
	cout << endl << "e) num: 5, char: o. I must see sequence 0 to 7, then 10 to 12; or error message" << endl;
	quiz_2(3, 'o');
	cout << endl << "d) num: 4, char: e. I must see an error message" << endl;
	quiz_2(3, 'e');
	cout << endl;
	system("pause");
}

void test_quiz_3() {
	system("cls");
	cout << "quiz 3" << endl
		<< "--modulus--" << endl << endl
		<< "a) Modulo 3 by 2, must return a 1: " << AmodB(3, 2) << endl
		<< "b) Modulo 15 by 4, must return a 2: " << AmodB(14, 4) << endl
		<< "c) Modulo 1 by 15, must return a 1: " << AmodB(1, 15) << endl
		<< "d) Modulo 20 by 20, must return a 0: " << AmodB(20, 20) << endl
		<< "d) Modulo 0 by 0, must return a -1: " << AmodB(0, 0) << endl;

	cout << endl << " Custom equation 1 " << endl
		<< "... missing evaluation for results on this version... " << endl;

	double working_r = customEquation_1(1, 2, 3);
	cout << "Result from your function with 1, 2, and 3 as inputs: " << working_r << endl << endl;

	system("pause");
}

void test_quiz_4() {
	system("cls");
	int testing_array[] = { 0, -1, 2, -3, 4, -5, 6, -7, 8, -9 };

	cout << "quiz 4" << endl
		<< "--PLC (structure)--" << endl
		<< endl << "  Note: dont worry about the order of the values, as long as all are decimal" << endl;
	PLC controller;
	controller.DiferentialG = 0.4;
	controller.IntegralG = 0.5;
	controller.ProportionalG = 0.3;
	cout << "PLC, SP not tested (due to changes in test 2)" << endl
		<< "PLC, PV not tested (due to changes in test 2)" << endl
		<< "PLC, ProportionalG, expected 0.3: " << controller.ProportionalG << endl
		<< "PLC, DiferentialG, expected 0.4: " << controller.DiferentialG << endl
		<< "PLC, IntegralG, expected 0.5: " << controller.IntegralG << endl
		<< "PLC, Alarm_1 eliminated (due to changes in test 2)" << endl
		<< "PLC, Alarm_2 eliminated (due to changes in test 2)" << endl
		<< "PLC, output not tested (due to changes in test 2)" << endl
		<< endl << "  If you don't see decimal values, change your variable to double" << endl << endl;

	cout << "Custom equation 2" << endl;
	cout << "testing array: 0, -1, 2, -3, 4, -5, 6, -7, 8, -9" << endl
		<< "-results expected: sum = -5, largest: 8; small: -9" << endl << endl;
	customEquation_2(testing_array, 10);
	system("pause");
}

void test_assignment3() {
	system("cls");
	cout << "Assignment 3 - Decimal to hex and decimal to bin conversions" << endl
		<< endl;
	cout << "--HEX-----" << endl
		<< " a) Convert 0 to hex (expected 0 or 00): " << endl;
	intToHex(0);
	cout << endl << " b) Convert 15 to hex (expected F or 0F): ";
	intToHex(15);
	cout << endl << " c) Convert 174 to hex (expected AE): ";
	intToHex(174);
	cout << endl << " d) Convert 255 to hex (expected FF): ";
	intToHex(255);
	cout << endl << " e) Convert 256 to hex (expected error message): ";
	intToHex(256);  //we defined this function to be limited to a max input of 255

	cout << endl << "--BIN-----" << endl
		<< " a) Convert 0 to bin (expected 0 or 00000000): " << endl;
	intToBin(0);
	cout << endl << " b) Convert 15 to bin (expected 1111 or 00001111): ";
	intToBin(15);
	cout << endl << " c) Convert 174 to bin (expected 10101110): ";
	intToBin(174);
	cout << endl << " d) Convert 255 to bin (expected 11111111): ";
	intToBin(255);
	cout << endl << " e) Convert 256 to bin (expected error message): ";
	intToBin(256);  //we defined this function to be limited to a max input of 255
	system("pause");
}

void test_test1() {
	system("cls");
	cout << "test 1 /assignment 4 - microController Timer0 calculator" << endl
		<< endl << "try 16 bits, 4Mhz, and 1:32 (preescaler)" << endl
		<< "  Expected answer: 2.097 s / B4 / 10110100" << endl;

	timer0 test1;               //you must have this structure declared (.h)
	test1 = timer0overflow();   //this function must return a timer0 variable type, but receive nothing (no argument)

	cout << endl << "Overflow: " << test1.T_PERIOD << " s." << endl;  //T_PERIOD must be a double
	timer0config(test1.DecVal); //DecVal must be an integer, and this function recieves an integer)                         //v 1.1 correction

	system("pause");

	system("cls");
	cout << "test 1 /assignment 4 - microController Timer0 calculator" << endl
		<< endl << "try 8 bits, 500 khz, and 1:8 (preescaler)" << endl
		<< "  Expected answer: 0.016384 s / F2 / 11110010" << endl;


	test1 = timer0overflow();   //this function must return a timer0 variable type, but receive nothing (no argument)

	cout << endl << "Overflow: " << test1.T_PERIOD << " s." << endl;  //T_PERIOD must be a double
	timer0config(test1.DecVal); //DecVal must be an integer, and this function recieves an integer)                         //v 1.1 correction

	system("pause");
}

void test_quiz_6() {
	system("cls");
	double pie = 3.14159265;
	cout << "Quiz 6" << endl << endl
		<< "--Radians to Degrees conversion--" << endl
		<< "   a) Input: 2 * pie; output must be: 360. Your result: ";
	double input = 2 * pie;
	RadToDeg(input);
	cout << input << endl;

	cout << "   b) Input: pie / 2; output must be: 90. Your result: ";
	input = pie / 2;
	RadToDeg(input);
	cout << input << endl;

	cout << endl << "--Degrees to Radians conversion--" << endl
		<< "   a) Input: 270; output must be: 4.7123. Your result: ";
	input = 270;
	DegToRad(input);
	cout << input << endl;

	cout << "   b) Input: 175; output must be: 3.054. Your result: ";
	input = 175;
	DegToRad(input);
	cout << input << endl;


	system("pause");
}

void test_quiz_7() {
	system("cls");

	cout << "Quiz 7" << endl << endl
		<< "Testing function 'whoAreYou'; a message should pop up with the following" << endl
		<< "content: your name, code of the course, your program, and a description" << endl
		<< "of the header files. More information is up to you but that's the " << endl
		<< "minimum expected. Your code says: " << endl << endl;

	WhoAreYou();

	cout << endl << "testing the vower counter. Type the following phrase: theQwertymanDoesntExist" << endl
		<< "Your output should be 7 or 8 (considering the capital E). If your input string" << endl
		<< "is limited to less than 23 characters, your function should keep asking you " << endl
		<< "for an input. Try a smaller string and check your count." << endl << endl;

	vowelCounter();

	system("pause");
}

void test_test_2() {
	system("cls");

	cout << endl << "NOTE: \n --Assignment 5 & 6 is disregarded due to all the modifications done by test 2" << endl << endl;
	system("pause");

	int working_r = 0;

	do {
		system("cls");
		cout << "Test 2" << endl << endl;
		cout << "Choose which test you want to test? (choose the one you worked on)" << endl
			<< "1) RC Band Pass Filter simulator" << endl << "2) PID controller simulator" << endl << ":: ";
		cin >> working_r;
	} while (working_r != 1 && working_r != 2);

	if (working_r == 1) {
		//IF YOU DONT HAVE THE FILTER TEST CODE IN YOUR HEADER FILES, COMMENT ALL THE FOLLOWING CODE UP TO....
		system("cls");

		Filter_RC tester;
		tester.cap_HP = 20 * pow(10, -9);
		tester.cap_LP = .87 * pow(10, -9);
		tester.Resistance_HP = 7.5 * pow(10, 3);
		tester.Resistance_LP = 2.5 * pow(10, 3);
		tester.Frequency = 3500;

		cout << "Testing FILTER simulator:" << endl;
		cout << "* Loaded values to use for testing:" << endl
			<< "-- Resistance HP (Resistance_HP): 7.5 kOhms" << endl
			<< "-- Resistance LP (Resistance_LP): 2.5 kOhms" << endl
			<< "-- Capacitor HP (cap_HP): 20 nF" << endl
			<< "-- Capacitor LP (cap_LP): .87 nF" << endl
			<< "-- Frequency: 3500 Hz" << endl << endl;
		hi_cutOff_Frequency(tester);
		cout << " a) Testing hi_cutOff_Fequency; expected: 1061.03; your result: " << tester.Fh << endl;
		lo_cutOff_Frequency(tester);
		cout << " b) Testing lo_cutOff_Fequency; expected: 73174.7; your result: " << tester.Fl << endl;
		cout << " c) Testing capacitance with cap_HP; expected: 2273.64; your result: " << capacitance(tester.Frequency, tester.cap_HP) << endl;
		cout << " d) Testing inductance with L=100 mH; expected: 2199.11; your result: " << inductance(tester.Frequency, 0.1) << endl;
		cout << " e) testing impedance with cap_LP, inductor value: 150 mH, and Resitance_LP; " << endl
			<< "    expected: 49032.7 ; your result: " << impedance(tester.Resistance_LP, inductance(tester.Frequency, 0.15), capacitance(tester.Frequency, tester.cap_LP)) << endl;
		resonantFrequency(tester);
		cout << " f) Testing Resonant Frequency; expected: 8811.4; your result: " << tester.Fr << endl;
		cout << " g) Testing pi; expected 3.14159; your result: " << pie() << endl << endl;
		bandPassFilter(tester);
		cout << " h) Testing bandPass; expected: 0.956992; your result: " << tester.Amplitude << endl;
		cout << "---New Frequency: 100,000 Hz---" << endl;
		tester.Frequency = 1 * pow(10, 5);
		bandPassFilter(tester);
		cout << " i) Testing bandPass; expected: 0.590531; your result: " << tester.Amplitude << endl;
		system("pause");
		cout << " --Testing your version of the test now. Initializing..." << endl;

		initializeFilter(tester);
		plotter testPlot;
		testPlot.axis_MIN = 1;
		testPlot.axis_MAX = 50000;
		testPlot._step = 10;
		plotFilter(testPlot, tester);
		//----------H E R E -------------------------------
	}
	else{
		//IF YOU DONT HAVE THE PID TEST CODE IN YOUR HEADER FILES, COMMENT ALL THE FOLLOWING CODE UP TO....
		system("cls");

		PLC tester;
		tester.error[0] = -0.03, tester.error[1] = 0.43, tester.error[2] = 0.12;
		tester.PV[0] = 0, tester.PV[1] = 0.75;
		tester.SP[0] = 0, tester.SP[1] = 0.45;
		tester.DiferentialG = 0.5, tester.ProportionalG = 5, tester.IntegralG = 2.5;
		tester.output[0] = tester.output[1] = 0;
		tester.CharacteristicEffects[0] = tester.CharacteristicEffects[1] = 0;
		tester.output[0] = 0, tester.output[1] = 0.01;
		tester.System_G = 1.2;
		tester.System_T = 2.5;
		tester.System_D = 0;
		cout << "Testing PLC simulator:" << endl;
		cout << "* Loaded values to use for testing:" << endl
			<< "-- System Gain (G): 1.2" << endl
			<< "-- System Time Constant (T): 2.5" << endl
			<< "-- Controller Proportional Gain (G): 5" << endl
			<< "-- Controller Integral Time (T): 2.5" << endl
			<< "-- Controller Derivative Gain (D): 0.5" << endl
			<< "-- Previous error (error[0]): -0.03" << endl
			<< "-- Current error (error[1]): 0.43" << endl
			<< "-- Accumulated error (error[2]): 0.12" << endl
			<< "-- Current Process Value (PV[1]): 0.75" << endl
			<< "-- Current Set Point (SP[1]): 0.45" << endl
			<< "-- Current output (output[1]): 0.01" << endl;
		cout << endl << "** FOR THIS TESTS, YOU WILL HAVE TO SCROLL DOWN AND UP THIS SCREEN **" << endl << endl;
		cout << " a) Exponent func. using 1.2 as input. Expected: 3.32012; Your result: " << Exponent(1.2) << endl;
		SystemFirstEquation(tester);
		cout << " b) System 1st. Equation. Expected: -0.67032; your result: " << tester.CharacteristicEffects[0] << endl;
		SystemSecondEquation(tester);
		cout << " c) System 2nd. Equation. Expected: 0.395616; your result: " << tester.CharacteristicEffects[1] << endl;
		ProcessV(tester);
		cout << " d) Process V function. Expected:" << endl
			<< "   Current process value (PV[1]): 0.506696; your result: " << tester.PV[1] << endl;
		cout << "   Stored output (output[0]). Expected: 0.01. Your result: " << tester.output[0] << endl;
		cout << "   Stored process V (PV[0]). Expected: 0.75. Your result: " << tester.PV[0] << endl;
		Error(tester);
		cout << " e) Error function. Expected:" << endl
			<< "   Previous error (error[0]): 0.43; your result: " << tester.error[0] << endl
			<< "   Current error (error[1]): -0.0566962; your result: " << tester.error[1] << endl
			<< "   Accumulated error (error[2]): 0.0633038; your result: " << tester.error[2] << endl;
		controller(tester);
		cout << " f) Proportional G. func. Expected: -0.283481; your result: " << ProportionalGain(tester) << endl;
		cout << " g) Integral G. func. Expected: 0.0253215; your result: " << IntegralGain(tester) << endl;
		cout << " h) Diferential G. func. Expected: -0.243348; your result: " << DiferentialGain(tester) << endl;
		cout << " i) Controller function. Expected: -0.501508; your result: " << tester.output[1] << endl;
		system("pause");
		cout << " --Testing your version of the test now. Initializing..." << endl;

		plotter testPlot;

		initializeController(tester);
		testPlot.axis_MIN = 1;
		testPlot.axis_MAX = 100;
		testPlot._step = 1;
		plotPLC(testPlot, tester);

		//----------H E R E -------------------------------
	}
	system("pause");
	cout << endl;
}
