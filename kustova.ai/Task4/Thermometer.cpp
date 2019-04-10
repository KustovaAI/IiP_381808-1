#pragma once
#include <string>
#include <iostream>
#include <locale>
#include <algorithm>
#include"Thermometer.h"


using namespace std;


Thermometer::Thermometer(string fileName) 
{	
	size_buf = 15;
	del_buf = 10;
	size = 0;
	ifstream is;
	is.open(fileName);
	is >> size;
	//thermometer = new Thermometer[size];
	int index = 0;
	year = new int[size_buf];
	month = new int[size_buf];
	day = new int[size_buf];
	hour = new int[size_buf];
	temp = new int[size_buf];
	for (int i = 0; i < size; i++)
	{
		int a[5];
		is >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
		year[i] = a[0];
		month[i] = a[1];
		day[i] = a[2];
		hour[i] = a[3];
		temp[i] = a[4];
	}
	is.close();
}


Thermometer::~Thermometer()	//Destructor
{
	delete[] year;
	delete[] month;
	delete[] day;
	delete[] hour;
	delete[] temp;
	size = 0;
	year = NULL;
	month = NULL;
	day = NULL;
	hour = NULL;
	temp = NULL;
	size_buf = 0;
	del_buf = 0;
	
}

void Thermometer::StartDate()	//Start date and time of observation
{
	cout << "Start date and time of observations: "<<year[0]<<" " << month[0] << " " << day[0] << " " << hour[0]<< endl;
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
		if (year[i] == y && month[i] == m && day[i] == d && hour[i] == h)	//esli data i vremya zaniati
		{
			cout << "There is already an observation for this date and time. The changes are saved." << endl;
			temp[i] = t;	//Zamena temperaturi
			goto fos;
		}
	}
	size++;
	if (size <= size_buf)
	{
		year[size - 1] = y;
		month[size - 1] = m;
		day[size - 1] = d;
		hour[size - 1] = h;
		temp[size - 1] = t;
	}
	else
	{
		size_buf = size_buf + del_buf;
		//Sozdanie vtorogo massiva
		int  *tmp_y;
		int  *tmp_m;
		int  *tmp_d;
		int  *tmp_h;
		int  *tmp_t;
		tmp_y = new int[size_buf];
		tmp_m = new int[size_buf];
		tmp_d = new int[size_buf];
		tmp_h = new int[size_buf];
		tmp_t = new int[size_buf];
		for (int i = 0; i < size - 1; i++)
		{
			tmp_y[i] = year[i];
			tmp_m[i] = month[i];
			tmp_d[i] = day[i];
			tmp_h[i] = hour[i];
			tmp_t[i] = temp[i];
		}
		tmp_y[size - 1] = y;
		tmp_m[size - 1] = m;
		tmp_d[size - 1] = d;
		tmp_h[size - 1] = h;
		tmp_t[size - 1] = t;
		//Udalenie starogo massiva
		delete[] year;
		delete[] month;
		delete[] day;
		delete[] hour;
		delete[] temp;
		//Kopirovanie novogo massiva
		year = new int[size_buf];
		month = new int[size_buf];
		day = new int[size_buf];
		hour = new int[size_buf];
		temp = new int[size_buf];
		for (int i = 0; i < size; i++)
		{
			year[i] = tmp_y[i];
			month[i] = tmp_m[i];
			day[i] = tmp_d[i];
			hour[i] = tmp_h[i];
			temp[i] = tmp_t[i];
		}
		delete[] tmp_y;
		delete[] tmp_m;
		delete[] tmp_d;
		delete[] tmp_h;
		delete[] tmp_t;
	}
	cout << "Observation successfully added" << endl;

	fos:
	ofstream os;
	os.open("Thermometer.txt", ios_base::trunc);	//Udalenie zapisi iz faila
	os.close();
	os.open("Thermometer.txt", ios_base::app);
	os << size << endl;
	for (int i = 0; i < size; i++)
	{
		os << year[i] << " " << month[i] << " " << day[i] << " " << hour[i] << " " << temp[i] << endl;	//Dobalenie zapisi v fail
	}
	os.close();
	
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
		if (year[i] == y && month[i] == m && day[i] == d && hour[i] == h)	
		{
			ok = 1;
			cout << "Temperature at this time: " << temp[i] << endl;
		}
	}
	if (ok == -1) cout << "There is no observation at this date and time" << endl;
	
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
		if (year[i] == y && month[i] == m && day[i] == d)
		{
			ok = i;
			cout << year[i] << " " << month[i] << " " << day[i] << " " << hour[i] << " " << temp[i] << endl;
		}
	}
	if (ok == -1) cout << "There is no observation at this date and time" << endl;
}
void Thermometer::Sred_Date()	//Srednyaa temperatura za sutki
{
	int y, m, d;
	int sum = 0;
	int k = 0 ;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	cout << "Enter the day: " << endl;
	cin >> d;
	for (int i = 0; i < size; i++) 
	{
		if (year[i] == y && month[i] == m && day[i] == d)
		{
			
			sum = sum + temp[i];
			k++;	//kolichestvo vibranih nabludenii
		}
	}
	if (k == 0) cout << "There is no observation at this date" << endl;
	else cout << "The average temperature for the selected date: " << sum / k << endl;
}

void Thermometer::Sred_Month()	// Srednyaa temperatura za mesyac
{
	int y, m;
	int sum = 0;
	int k = 0;
	cout << "Enter the year: " << endl;
	cin >> y;
	cout << "Enter the month: " << endl;
	cin >> m;
	
	for (int i = 0; i < size; i++)
	{
		if (year[i] == y && month[i] == m)
		{

			sum = sum + temp[i];
			k++;	//kolichestvo vibranih nabludenii
		}
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
		sum = sum + temp[i];
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
		if (year[i] == y && month[i] == m && temp[i] >=6 && temp[i] <=18)
		{

			sum = sum + temp[i];
			k++;	//kolichestvo vibranih nabludenii
		}
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
		if (year[i] == y && month[i] == m && (temp[i] < 6 || temp[i] > 18))
		{

			sum = sum + temp[i];
			k++;	//kolichestvo vibranih nabludenii
		}
	}
	if (k == 0) cout << "There is no observation of night temperature at this month" << endl;
	else cout << "The average night temperature for the selected month: " << sum / k << endl;
}

