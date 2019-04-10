#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Thermometer
{
private:
	int size_buf;	//razmer bufera
	int size;	//realnoe kol-vo izmereniy
	int del_buf;
	int *year;
	int *month;
	int *day;
	int *hour;
	int *temp;

public:

	Thermometer(string fileName);
	~Thermometer();//Destruktor
	
	void StartDate();//(1) - Start date and timeob observation
	void Add();	//(2) - Dobavit nablyudenie
	void Find_Temp();	//(3)-Poisk temperaturi po date
	void Seriya_Nabl();//(4)-Seriya nablyudenii po date
	void Sred_Date();//(5) - Srednyaa temperatura za sutki
	void Sred_Month();//(6) - Srednyaa temperatura za mesyac
	void Sred_All();//(7) - Srednyaa temperatura za vsyo vremya
	void Sred_Day();//(8)-Srednyaa dnevnaya temperatura za mesyac
	void Sred_Night();//(9)-Srednyaa nochnaya temperatura za mesyac
	
};

