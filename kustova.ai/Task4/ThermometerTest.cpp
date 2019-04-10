#include <clocale>
#include <iostream>
#include <fstream>
#include "Thermometer.h"
using namespace std;

int main()
{
	Thermometer c1("Thermometer.txt");
	int n1;
	def2:
	cout << "Choose action: " << endl;
	cout << "1 - find the starting date and time of observations" << endl;
	cout << "2 - add observation" << endl;
	cout << "3 - find out the temperature in the observation selected by date and time" << endl;
	cout << "4 - issue a series of observations for the selected date" << endl;
	cout << "5 - find the average temperature for the selected date" << endl;
	cout << "6 - find the average temperature for the selected month" << endl;
	cout << "7 - find the average temperature in the history of observations" << endl;
	cout << "8 - find the average day temperature for the selected month" << endl;
	cout << "9 - find the average night temperature for the selected month" << endl;
	def1:
	cin >> n1;
	switch (n1)
	{
	case 1:
		c1.StartDate();
		break;	
	case 2:
		c1.Add();
		break;
	case 3:
		c1.Find_Temp();
		break;
	case 4:
		c1.Seriya_Nabl();
		break;
	case 5:
		c1.Sred_Date();
		break;
	case 6:
		c1.Sred_Month();
		break;
	case 7:
		c1.Sred_All();
		break;
	case 8:
		c1.Sred_Day();
		break;
	case 9:
		c1.Sred_Night();
		break;
	default:
		cout << "Viberite cifru iz predstavlennogo spiska: ";
		goto def1;
	}
	cout << "-----------------------" << endl;
	goto def2;
	getchar();
	getchar();
}

