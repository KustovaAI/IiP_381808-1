#pragma once
#include <string>
#include <iostream>
#include <locale>
#include <algorithm>
#include "Depozit.h"
istream& operator>>(istream& stream, Depozit& d)
{
	int sr;
	stream >> d.ID >> d.start_sum_dep >> d.cap >> d.Start_Month >> sr;
	if (sr >= 36) d.Srok = 4;	//Srok_1_year
	else if (sr >= 24) d.Srok = 3;	//Srok_2_year
	else if (sr >= 12) d.Srok = 2;	//Srok_1_year
	else if (sr >= 6) d.Srok = 1;	//Srok_6_month
	else d.Srok = 0;	//Srok_3_month
	if (d.start_sum_dep > 500000) d.Range = 2;		//Ot_500000_do_1000000
	else if (d.start_sum_dep > 100000) d.Range = 1;	//Ot_100000_do_500000
	else d.Range = 0;	//Do_100000
	// po tablice nahodim procentnuyu stavku
	d.procent = table_procent[d.Range][d.Srok];
	return stream;
}
ostream& operator<<(ostream& stream, const Depozit& d)
{
	int sr;
	if (d.Srok == 4) sr = 36;	//Srok_1_year
	else if (d.Srok == 3) sr = 24;	//Srok_2_year
	else if (d.Srok == 2) sr = 12;	//Srok_1_year
	else if (d.Srok == 1) sr = 6;	//Srok_6_month
	else sr = 3;	//Srok_3_month
	stream << d.ID << ' ' << d.start_sum_dep << ' ' << d.cap << ' ' << d.Start_Month << ' ' << sr << endl;
	return stream;
}