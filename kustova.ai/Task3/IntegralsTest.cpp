#include <clocale>
#include <iostream>
#include <fstream>
#include "Integrals.h"
using namespace std;

int main()
{
	int r, f1;
	string f3;
	typedef double(*Function)(double);
	Function f2 = 0;
	Integrals c1, i, i2, i3;
	cout << "Enter the integration interval and the number of split segments: ";
	cin >> c1;	//Peregruzka chteniya
	cout << "Choose function: " << endl;
	cout << "1 - Sin(x) " << endl;
	cout << "2 - Cos(x) " << endl;
	cout << "3 - exp(x) " << endl;
	def1:
	cin >> f1;
	switch ( f1)
		{
		case 1:
			f2 = sin;	//Tip f2 - function
			f3 = "Sin(x)";	//Textovoe nazvanie funkcii
			break;
		
		case 2:
			f2 = cos;
			f3 = "Cos(x)";
			break;
		case 3:
			f2 = exp;
			f3 = "exp(x)";
			break;
		default:
			cout << "Viberite cifru iz predstavlennogo spiska: ";
			goto def1;
		}
		
	cout << "Choose a method for calculating integrals: " << endl;
	cout << "1 - Right rectangle method " << endl;
	cout << "2 - Left rectangle method " << endl;
	cout << "3 - Middle rectangle method " << endl;
	cout << "4 - All methods " << endl;
	def2:
	cin >> r;
	switch (r)
	{
	case 1:
		i = i.RightRect(f2, c1);
		cout << "Right rectangels methot: int(" << f3 << ") = " << i << endl;
		break;
	case 2:
		i = i.LeftRect(f2, c1);
		cout << "Left rectangels methot: int(" << f3 << ") = " << i << endl;
		break;
	case 3:
		i = i.MiddleRect(f2, c1);
		cout << "Middle rectangels methot: int(" << f3 << ") = " << i << endl;
		break;
	case 4:
		i = i.RightRect(f2, c1);
		i2 = i2.LeftRect(f2, c1);
		i3 = i3.MiddleRect(f2, c1);
		cout << "Right rectangels methot: int(" << f3 << ") = " << i << endl;
		cout << "Left rectangels methot: int(" << f3 << ") = " << i2 << endl;
		cout << "Middle rectangels methot: int(" << f3 << ") = " << i3 << endl;
		break;
	default:
		cout << "Viberite cifru iz predstavlennogo spiska: ";
		goto def2;
		break;
	}
	
	getchar();
	getchar();
}

