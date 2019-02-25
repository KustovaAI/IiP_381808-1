#include"Rational.h"
Rational::Rational()//Konstruktor po umolchaniyu
{
	n = 1; m = 1;
}
Rational::Rational(const Rational &t)//Konstructor copirovaniya
{
	n = t.n;
	m = t.m;
}
Rational::Rational(int _n, int _m)//Konstruktor inicializacii
{
	n = _n;
	m = _m;
}
Rational::Rational(int _m)//Konstruktor preobrazovaniya tipa
{
	m = 1;
	n = 1;
}
Rational::~Rational()//Destructor
{
	n = 0;
	m = 0;
}


Rational & Rational::operator=(const Rational & c)//Peregruzka =
{
	n = c.n;
	m = c.m;
	return *this;
}
Rational Rational::operator + (const Rational & c)//Peregruzka +
{
	Rational res;
	res.n = n * c.m + m * c.n;
	res.m = m * c.m;
	res.Sokrashenie();
	return res;
}
Rational Rational::operator - (const Rational & c)//Peregruzka -
{
	Rational res;
	res.n = n * c.m - (m * c.n);
	res.m = m * c.m;
	res.Sokrashenie();
	return res;
}
Rational Rational::operator * (const Rational & c)//Peregruzka *
{
	Rational res;
	res.n = n * c.n;
	res.m = m * c.m;
	res.Sokrashenie();
	return res;
}
Rational Rational::operator / (const Rational & c)//Peregruzka /
{
	Rational res;
	res.n = n * c.m;
	res.m = m * c.n;
	res.Sokrashenie();
	return res;
}
bool Rational::operator==(const Rational & c)//Peregruzka =
{
	bool res;
	res = (n == c.n) && (m == c.m);
	return res;
}
ostream & operator << (ostream & stream, const Rational & c)//Vivod v potok
{
	stream << c.n << " " << c.m << endl;
	return stream;
}
istream& operator>>(istream & stream, Rational & c)//Vvod v potok
{
	stream >> c.n >> c.m;
	return stream;
}
void Rational::Sokrashenie()//Sokrashenie drobi
{
	int a, b;
	a = abs(n);
	b = abs(m);
	if (a == 0)
	{
		n = 0; 		m = m;
	}
	else if (b == 0)
	{
		n = n;		m = 0;
	}
	else
	{
		while (a != b)
			if (a > b)
				a -= b;
			else
				b -= a;
		n = n / a;
		m = m / a;
	}
}