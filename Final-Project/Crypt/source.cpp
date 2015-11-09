#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;
void Encrypt(string&);
string Decrypt(string strTarget);

int main() {
	//initialize and get the string from the user
	string strTarget;
	cout << "Enter a string to encrypt: ";
	getline(cin, strTarget);
	string temp(strTarget);
	Encrypt(strTarget);

	cout << "Encrypted: " << strTarget << endl;
	cout << "Decrypted: " << Decrypt(strTarget) << endl;
	cout << "________________________________________________" << endl;
	system("pause");
	return 0;
}

void Encrypt(string &strTarget)
{
	int len = strTarget.length();
	char a;
	string strFinal(strTarget);

	for (int i = 0; i <= (len - 1); i++)
	{
		a = strTarget.at(i);
		int b = (int)a; //get the ASCII value of 'a'
		b += 2; //Mulitply the ASCII value by 2
		if (b > 254) { b = 254; }
		a = (char)b; //Set the new ASCII value back into the char
		strFinal.insert(i, 1, a); //Insert the new Character back into the string
	}
	string strEncrypted(strFinal, 0, len);
	strTarget = strEncrypted;
}

string Decrypt(string strTarget)
{
	int len = strTarget.length();
	char a;
	string strFinal(strTarget);

	for (int i = 0; i <= (len - 1); i++)
	{
		a = strTarget.at(i);
		int b = (int)a;
		b -= 2;

		a = (char)b;
		strFinal.insert(i, 1, a);
	}
	string strDecrypted(strFinal, 0, len);
	return strDecrypted;
}
