#pragma once
#include <string>
#include <iostream>
#include <locale>
#include <algorithm>
#include"Hex.h"

using namespace std;

Hex::Hex()//Konstruktor po umolchaniyu
{
	
	length = 0;
	a = 0;
}

Hex::Hex(int size)//Konstruktor inicializacii
{
	length = size;
	a = new unsigned char[length];
}

Hex::Hex(const Hex &_c)//Konstruktor kopirovaniya
{
	length = _c.length;
	a = new unsigned char[length];
	for (int i = 0; i < length; i++)
	{
		a[i] = _c.a[i];
	}
}
Hex::~Hex()//Destructor
{
	delete[]a;
	length = 0;
	
}


Hex & Hex::operator=(const Hex & c)//Peregruzka =
{
	if (length != c.length)
	{
		length = c.length;
		delete[] a;
		a = new unsigned char[length];
	}
	for (int i = 0; i < length; i++)
	{
		a[i] = c.a[i];
	}
	return *this;
}

Hex Hex::operator + (const Hex & c)//Peregruzka +
{	//Vichislenie dlini stroki
	int d = 0;
	if (length > c.length) 
	{
		d = length;
	}
	else if (length < c.length) 
	{
		d = c.length;
	}
	else 
	{
		if (a[length - 1] + c.a[c.length - 1] > 15) 
		{
			d = length + 1;
		}
		else 
		{
			d = length;
		}
	}
	//Podschet summ
	Hex res(d);
	int tmp = 0;//Perevod v drugoi razryad
	for (int i = 0; i < res.length; i++)
	{
		if (i < c.length && i<length) 
		{
			res.a[i] = (a[i] + c.a[i] + tmp) % 16;
			tmp = (a[i] + c.a[i] + tmp) / 16;
		}
		else if(i<length)
		{
			res.a[i] = (a[i] + tmp) % 16;
			tmp = (a[i] + tmp) / 16;
		}
		else
		{
			res.a[i] = (c.a[i] + tmp) % 16;
			tmp = (c.a[i] + tmp) / 16;
		}

	}
	return res;
}


Hex Hex::operator-(const Hex & c)
{
	int maxLength = max(length, c.length);//Dlina rezultata
	Hex res(maxLength);
	int d = 0;	//perevod v drugoi razryad
	for (int i = 0; i < maxLength; i++)
	{
		int q = (i < length) ? a[i] : 0;	//esli vishli za granicu delaem znachenie = 0
		int w = (i < c.length) ? c.a[i] : 0;	//esli vishli za granicu delaem znachenie = 0

		if (q + d < w)
		{
			res.a[i] = 16 + q + d - w;
			d = -1;
		}
		else
		{
			res.a[i] = q + d - w;
			d = 0;
		}

	}
	return res;
}



Hex Hex::operator *(const Hex & c)//Peregruzka *
{
	
	int max, min;
	if (length >= c.length)
	{
		max = length;
		min = c.length;
	}
	else 
	{
		max = c.length;
		min = length;
	}
	Hex tmp(length + c.length );//Promezhutochnii rezultat
	Hex res(length + c.length );
	tmp.Zero();
	res.Zero();
	int d = 0;	//Perehod v drugoi razryad
	//Podschet summ
	for (int j = 0; j < min; j++) //Rabotaem s razryadami menshego chisla
	{
		for (int i = 0; i < max; i++) //Rabotaem s razryadami bolshego chisla
		{
			if (length > c.length)  
			{
				tmp.a[i] = (a[i] * c.a[j] + d) % 16;
				d = (a[i] * c.a[j] + d) / 16;
			}
			else
			{
				tmp.a[i] = (c.a[i] * a[j] + d) % 16;
				d = (c.a[i] * a[j] + d) / 16;
			}
		}
		//Sdvig chisla
		for (int k = tmp.length - 1; k >= j; k--) tmp.a[k] = tmp.a[k - j];
		for (int k = 0; k < j; k++) tmp.a[k] = 0;
		res = res + tmp;
		d = 0;
		tmp.Zero();
	}
	//Ubiraem neznachashie nuli
	int i = res.length - 1;
	int k = 0;
	while (res.a[i] == 0)
	{
		if (res.a[i] == 0)
		{
			k++;
		}
		i--;
	}
	res.length = res.length - k;
	return res;
}

bool Hex::operator==(const Hex & c)
{
	if (length != c.length)return false;
	
	for (int i = 0; i < length; i++)
		if (a[i] != c.a[i]) return false;
		else return true;

	return false;
}


bool Hex::operator<(const Hex & c)
{
	if (length > c.length)return false;
	if (length < c.length)return true;

	for (int i = length - 1; i >= 0; i--)
		if (a[i] < c.a[i]) return true;
		else if (a[i] > c.a[i]) return false;

	return false;
}
bool Hex::operator>(const Hex & c)
{
	if (length < c.length)return false;
	if (length > c.length)return true;

	for (int i = length - 1; i >= 0; i--)
		if (a[i] > c.a[i]) return true;
		else if (a[i] < c.a[i]) return false;

	return false;
}


ostream & operator << (ostream & stream, const Hex & c)//Vivod v potok
{
	for (int i = c.length-1; i >=0; i--)	//Perevod iz int v char
	{
		if (c.a[i] <= 9 && c.a[i] >= 0)
			stream << (char)(c.a[i] + '0');
		else
			stream << (char)(c.a[i] + 'A' - 10);
	}
	return stream;

}
std::istream& operator>>(std::istream & stream, Hex & c)//Vvod v potok
{
	stream >> c.a;
	c.ToInt();
		return stream;	
}
void Hex::Zero()	//Zanulenie massiva
{
	for (int i = 0; i < length; i++) a[i] = 0;
}

void Hex::ToInt()	//Perevod iz char v int
{
	for (int i = 0; i < length/2; i++)
	{
		swap(a[i], a[length - i - 1]);
	}
	for (int i = 0; i < length; i++)
	{
		if (a[i] <= '9' && a[i] >= '0')
			a[i] -= '0';
		else
			a[i] -= 'A'-10;
	}
}