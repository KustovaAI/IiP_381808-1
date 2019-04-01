#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Event
{
private:
	int year;
	int month;
	int day;
	int hour;
	int temp;

public:

	Event(); // Konstruktor po umolchaniyu	
	Event(const Event&);//konstruktor kopirovaniya
	Event(int _year, int _month, int _day, int _hour, int _temp);//konstruktor kopirovaniya iz faila
	~Event();//Destruktor
	string StartDate1();	//(1) - Start date and timeob observation
	bool Find_Date(int _y, int _m, int _d, int _h);	//(2) -Est li nabludeniye po date
	void Out();	//(2) - Vivod v fail
	void Zamena(int _t);	//(2) -Zamena starogo nabludeniya na novoe
	int Find_Temp_1();	//(3)-Poisk temperaturi po date
	bool Find_Seriya_Nabl(int _y, int _m, int _d);	//(4)-Seriya nablyudenii po date
	int Find_Sred_Temp_1(int _y, int _m, int _d, int &ok);	//(5) - Srednyaa temperatura za sutki
	int Find_Sred_Temp_2(int _y, int _m, int &ok);	//(6) - Srednyaa temperatura za mesyac
	int Find_Sred_Temp_All();	//(7) - Srednyaa temperatura za vsyo vremya
	int Find_Sred_Day_Temp_1(int _y, int _m, int &ok);	//(8)-Srednyaa dnevnaya temperatura za mesyac
	int Find_Sred_Night_Temp_1(int _y, int _m, int &ok);//(9)-Srednyaa nochnaya temperatura za mesyac
	
};
