#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
#include "Client.h"
using namespace std;

struct Depozit
{
	int ID;      // ID vladelca vklada
	int start_sum_dep; // nachalnaya summa vklada
	int Srok;    // na kakoy srok otkrit vklad
	int Start_Month;   // mesyac otkritiya depozita
	int Range;      // diapazon suum vklada
	float procent; // %-stavka	
	int cap;      // dengi po procentam
};

istream& operator>>(istream& stream, Depozit& d);
ostream& operator<<(ostream& stream, const Depozit& d);
// tablica po procentam
const float table_procent[3][5] =
{
	// 3month___6month___1year___2year___3year
	/*0-100*/    {2.5f,      3.1f,     3.7f,    4.3f,   4.9f},
	/*100-500*/  {3.2f,      3.9f,     4.6f,    5.1f,   5.5f},
	/*500-1m*/   {3.8f,      4.5f,     5.1f,    5.6f,   5.9f}
};

