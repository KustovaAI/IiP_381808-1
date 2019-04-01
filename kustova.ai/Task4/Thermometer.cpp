#pragma once
#include <string>
#include <iostream>
#include <locale>
#include <algorithm>
#include"Thermometer.h"
#include "Event.h"

using namespace std;

Thermometer::Thermometer()//Konstruktor po umolchaniyu
{
	
	size = 0;
	ifstream is;
	is.open("Thermometer.txt");
	is >> size;
	thermometer = new Event[size];
	int index = 0;
	
	for (int i = 0; i < size; i++)
	{
		int a[5];
		is >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
		thermometer[i] = Event(a[0], a[1],a[2],a[3],a[4]);
	}
	is.close();
}

Thermometer::~Thermometer()	//Destructor
{
	delete[] thermometer;
	size = 0;
}

void Thermometer::StartDate()	//Start date and timeob observation
{
	string d;
	d = thermometer[0].StartDate1();
	cout << "Start date and time of observations: "<<d << endl;
}

void Thermometer::Add()	// Dobavit nablyudenie
{
	int y, m, d, h, t;
	
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	cout << "Enter the day: " << endl;
	cin >> d;
	cout << "Enter the time: " << endl;
	cin >> h;
	cout << "Enter the observation: " << endl;
	cin >> t;
	for (int i = 0; i < size; i++) {
		if (thermometer[i].Find_Date(y, m, d, h))	//esli data i vremya zaniati
		{
			cout << "There is already an observation for this date and time. The changes are saved." << endl;
			thermometer[i].Zamena(t);	//Zamena temperaturi
			goto fos;
		}
	}
	//Sozdanie vtorogo massiva
	Event* tmp;
	tmp = new Event[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = thermometer[i];
	}
	size++;
	tmp[size - 1] = Event(y, m, d, h, t);
	//Udalenie starogo massiva
	delete[] thermometer;	
	//Kopirovanie novogo massiva
	thermometer = new Event[size];
	for (int i = 0; i < size; i++)
	{
		thermometer[i] = tmp[i];
	}
	delete[] tmp;
	cout << "Observation successfully added" << endl;

	fos:
	ofstream os;
	os.open("Thermometer.txt", ios_base::trunc);	//Udalenie zapisi iz faila
	os.close();
	os.open("Thermometer.txt");
	os << size << endl;
	os.close();
	for (int i = 0; i < size; i++)
	{
		thermometer[i].Out();	//Dobalenie zapisi v fail
	}
}

void Thermometer::Find_Temp()	//Poisk temperaturi po date
{
	int y, m, d, h;
	int ok = -1;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	cout << "Enter the day: " << endl;
	cin >> d;
	cout << "Enter the time: " << endl;
	cin >> h;
	for (int i = 0; i < size; i++) {
		if (thermometer[i].Find_Date(y, m, d, h))	//Esli nashlas data
		{
			ok = i;
		}
	}
	if (ok == -1) cout << "There is no observation at this date and time" << endl;
	else cout << "Temperature at this time: " << thermometer[ok].Find_Temp_1() << endl;
}

void Thermometer::Seriya_Nabl()	//Seriya nablyudenii po date
{
	int y, m, d;
	int ok = -1;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	cout << "Enter the day: " << endl;
	cin >> d;
	for (int i = 0; i < size; i++) 
	{
		if (thermometer[i].Find_Seriya_Nabl(y, m, d))
		{
			ok = i;
		}
	}
	if (ok == -1) cout << "There is no observation at this date and time" << endl;
}
void Thermometer::Sred_Date()	//Srednyaa temperatura za sutki
{
	int y, m, d;
	int sum = 0;
	int ok, k = 0 ;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	cout << "Enter the day: " << endl;
	cin >> d;
	for (int i = 0; i < size; i++) 
	{
		ok = 0;
		sum = sum + thermometer[i].Find_Sred_Temp_1(y, m, d, ok);
		k = k + ok;	//kolichestvo vibranih nabludenii
	}
	if (k == 0) cout << "There is no observation at this date" << endl;
	else cout << "The average temperature for the selected date: " << sum / k << endl;
}

void Thermometer::Sred_Month()	// Srednyaa temperatura za mesyac
{
	int y, m;
	int sum = 0;
	int ok, k = 0;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	for (int i = 0; i < size; i++)
	{
		ok = 0;
		sum = sum + thermometer[i].Find_Sred_Temp_2(y, m, ok);
		k = k + ok;
	}
	if (k == 0) cout << "There is no observation at this month" << endl;
	else cout << "The average temperature for the selected month: " << sum / k << endl;
}

void Thermometer::Sred_All()	// Srednyaa temperatura za vsyo vremya
{
	int sum = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		sum = sum + thermometer[i].Find_Sred_Temp_All();
		k++;
	}
	cout << "The average temperature in the history of observations: " << sum / k << endl;
}

void Thermometer::Sred_Day()	//Srednyaa dnevnaya temperatura za mesyac
{
	int y, m;
	int sum = 0;
	int ok, k = 0;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	for (int i = 0; i < size; i++)
	{
		ok = 0;
		sum = sum + thermometer[i].Find_Sred_Day_Temp_1(y, m, ok);
		k = k + ok;
	}
	if (k == 0) cout << "There is no observation of day temperature at this month" << endl;
	else cout << "The average day temperature for the selected month: " << sum / k << endl;
}

void Thermometer::Sred_Night()	//Srednyaa nochnaya temperatura za mesyac
{
	int y, m;
	int sum = 0;
	int ok, k = 0;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	for (int i = 0; i < size; i++)
	{
		ok = 0;
		sum = sum + thermometer[i].Find_Sred_Night_Temp_1(y, m, ok);
		k = k + ok;
	}
	if (k == 0) cout << "There is no observation of night temperature at this month" << endl;
	else cout << "The average night temperature for the selected month: " << sum / k << endl;
}

