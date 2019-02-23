#include <clocale>
#include <iostream>
#include <fstream>
#include "Rational.h"
using namespace std;

int main()
{
	int j, h;
	string g;
	Rational c1, c2, c3, c4, S, R, P, Ch;
	Rational Sdf(1, 2);
	Rational c0(c1);
	cout << "Vvedite chislitel 1 chisla n = ";
	cin >> c1.n;
	cout << "Vvedite znamenatel 1 chisla m = ";
	cin >> c1.m;
	cout << "Vvedite chislitel 2 chisla n = ";
	cin >> c2.n;
	cout << "Vvedite znamenatel 2 chisla m = ";
	cin >> c2.m;
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	ifstream is;//Chtenie iz faila
	is.open("Rational.txt");
	is >> c3;
	is >> c4;
	is.close();
	ofstream os;//Zapis v fail
	os.open("Rational.txt");
	os << c1 << c2 << endl;
	os.close();
	if (c1 == c2) cout << "Chisla ravni" << endl;//==
	else cout << "Chisla ne ravni" << endl;
	S = c1 + c2;//+
	R = c1 - c2;//-
	P = c1 * c2;//*
	Ch = c1 / c2;///
	cout << "c1 + c2 = " << S << endl;
	cout << "c1 - c2 = " << R << endl;
	cout << "c1 * c2 = " << P << endl;
	cout << "c1 / c2 = " << Ch << endl;

	getchar();
	getchar();
}

