#include <iostream>
using namespace std;

struct transistor{
	int Hfe;
	double Vce, Ic, Ib, Ie;
	char NPNorPNP;
};

transistor calculateHfe(double, double);

int main(){
	transistor amplifier, secondAmplifier;
	int temporal;

	amplifier.Hfe = 150;
	amplifier.Ic = 50;
	amplifier.Ib = amplifier.Ic / amplifier.Hfe;

	secondAmplifier.Hfe = 200;

	amplifier.Ie = amplifier.Ic + amplifier.Ib;

	cout << amplifier.Hfe << endl;
	cout << amplifier.Ib << endl;
	cout << amplifier.Ic << endl;
	cout << amplifier.Ie << endl;

	transistor thirdAmplifier;
	thirdAmplifier = calculateHfe(15, 0.15);

	cout << "Hfe = " << thirdAmplifier.Hfe << endl;
	cout << "Ic = " << thirdAmplifier.Ic << endl;
	cout << "Ib = " << thirdAmplifier.Ib << endl;

	system("pause");
	return 0;
}

transistor calculateHfe(double Ic, double Ib){
	transistor temporal;		//function must return data type variable
	temporal.Hfe = Ic / Ib;
	temporal.Ic = Ic;
	temporal.Ib = Ib;
	return temporal;
}
