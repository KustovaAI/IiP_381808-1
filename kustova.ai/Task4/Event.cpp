#include <clocale>
#include <iostream>
#include <fstream>
using namespace std;
#include "Event.h"

Event::Event()
{
	day = 0;
	month = 0;
	year = 0;
	hour = 0;
	temp = 0;

}

Event::Event(int _year, int _month, int _day, int _hour, int _temp)
{
	day = _day;
	month = _month;
	year = _year;
	hour = _hour;
	temp = _temp;
}

Event::Event(const Event &_c)
{
	day = _c.day;
	month = _c.month;
	year = _c.year;
	hour = _c.hour;
	temp = _c.temp;
}
Event::~Event()
{
	day = 0;
	month = 0;
	year = 0;
	hour = 0;
	temp = 0;
}

string Event::StartDate1()	//1 - Data nachala nabludeniy
{
	string str;
	char y, m, d, h;
	str = to_string(year) + " " + to_string(month) + " "+ to_string(day) + " "+ to_string(hour);
	return str;
}

bool Event::Find_Date(int _y, int _m, int _d, int _h)	//Poisk sovpadeniya po date
{
	if (year == _y && month == _m && day == _d && hour == _h) return true;
	return false;
}
void Event::Zamena(int _t)
{
	temp = _t;
}
int Event::Find_Temp_1()
{
	return temp;
}

bool Event::Find_Seriya_Nabl(int _y, int _m, int _d)
{
	if (year == _y && month == _m && day == _d)
	{
		cout << year << " " << month << " " << day << " " << hour << " " << temp << endl;
		return true;
	}
	return false;

}
int Event::Find_Sred_Temp_1(int _y, int _m, int _d, int &ok)
{
	int res = 0;
	int ok1;
	if (year == _y && month == _m && day == _d)
	{
		res = temp;
		ok = 1;
	}
	return res;
}
int Event::Find_Sred_Temp_2(int _y, int _m, int & ok)
{
	int res = 0;
	int ok1;
	if (year == _y && month == _m)
	{
		res = temp;
		ok = 1;
	}
	return res;
}

int Event::Find_Sred_Temp_All()
{
	return temp;
}
int Event::Find_Sred_Day_Temp_1(int _y, int _m, int & ok)
{
	int res = 0;
	int ok1;
	if (year == _y && month == _m && hour >=6 && hour <=18)
	{
		res = temp;
		ok = 1;
	}
	return res;
}
int Event::Find_Sred_Night_Temp_1(int _y, int _m, int & ok)
{
	int res = 0;
	int ok1;
	if (year == _y && month == _m && (hour < 6 || hour > 18))
	{
		res = temp;
		ok = 1;
	}
	return res;
}

void Event::Out()
{
	ofstream os;
	os.open("Thermometer.txt", ios_base::app);
	os << year << " " << month << " " << day << " " << hour << " " << temp << endl;
	os.close();
}