#include <clocale>
#include <iostream>
#include <fstream>
#include "Hex.h"
using namespace std;

int main()
{
	int n1, n2;
	Hex S, R, P;
	cout << "Enter the length of the first number: ";
	cin >> n1;
	Hex c1(n1);
	cout << "Enter the first number: ";
	cin >> c1;
	cout << "Enter the length of the second number: ";
	cin >> n2;
	Hex c2(n2);
	cout << "Enter the second number: ";
	cin >> c2;
	cout << "c1 = " << c1 << endl;
	cout << "C2 = " << c2 << endl;
	Hex c3(n1);
	Hex c4(n2);
	ofstream os;//Zapis v fail
	os.open("Hex.txt");
	os << c1 << endl;
	os << c2 << endl;
	os.close();
	ifstream is;//Chtenie iz faila
	is.open("Hex.txt");
	is >> c3;
	is >> c4;
	is.close();
	if (c1 == c2)	cout << "c1 = c2" << endl;
	else if (c1 < c2)	cout << "c1 < c2" << endl;
	else if (c1 > c2)	cout << "c1 = c2" << endl;
	
	S = c1 + c2;
	cout << "c1 + c2 = " << S << endl;
	R = c1 - c2;
	cout << "c1 - c2 = " << R << endl;
	P = c1 * c2;
	cout << "c1 * c2 = " << P << endl;
	cout << "The data from the file " << c3 << endl << c4 << endl;

	
	getchar();
	getchar();
}

