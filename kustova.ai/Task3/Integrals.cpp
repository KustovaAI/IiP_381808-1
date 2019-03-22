#pragma once
#include <string>
#include <iostream>
#include <locale>
#include <algorithm>
#include"Integrals.h"

using namespace std;

Integrals::Integrals()//Konstruktor po umolchaniyu
{
	a = 0;
	b = 0;
	n = 1;
	in = 0;
}

Integrals::Integrals(double _a, double _b, int _n, double _in)//Konstruktor inicializacii
{
	a = _a;
	b = _b;
	n = _n;
	in = _in;
}

Integrals::Integrals(const Integrals &_c)//Konstruktor kopirovaniya
{
	a = _c.a;
	b = _c.b;
	n = _c.n;
	in = _c.in;
}
Integrals::~Integrals()//Destructor
{
	a = 0;
	b = 0;
	n = 0;
	in = 0;

}

ostream & operator << (ostream & stream, const Integrals & c)//Vivod v potok
{
	stream << c.in << endl;
	return stream;
}

std::istream& operator>>(std::istream & stream, Integrals & c)//Vvod v potok
{
	
	stream >> c.a >> c.b >> c.n;
	return stream;
}

Integrals Integrals::RightRect(double f(double x), const Integrals & c)	//Metod pravih pryamougolnikov
{
	double x, h;
	Integrals sum;
	h = (c.b - c.a) / c.n;  //shag
	for (int i = 1; i <= c.n; i++)
	{
		x = c.a + i * h;
		sum.in = sum.in + f(x);
	}
	sum.in = sum.in * h;
	return sum;

}

Integrals Integrals::LeftRect(double f(double x), const Integrals & c)	//Metod levih pryamougolnikov
{
	double x, h;
	Integrals sum;
	h = (c.b - c.a) / c.n;  //shag

	for (int i = 0; i < c.n; i++)
	{
		x = c.a + i * h;
		sum.in = sum.in + f(x);
	}
	sum.in = sum.in * h;
	return sum;

}

Integrals Integrals::MiddleRect(double f(double x), const Integrals & c)	////Metod srednih pryamougolnikov
{
	double x, h;
	Integrals sum;
	h = (c.b - c.a) / c.n;  //shag
	for (int i = 1; i <= c.n; i++)
	{
		x = c.a + (i - 0.5) * h;
		sum.in = sum.in + f(x);
	}
	sum.in = sum.in * h;
	return sum;

}
