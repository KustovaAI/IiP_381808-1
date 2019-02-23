#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
using namespace std;

class Rational
{
public:
	int n, m;

	Rational(); // Konstruktor po umolchaniyu
	Rational(const Rational &t); // Konstruktor kopirovaniya
	Rational(int _n, int _m);// Konstructor inicializacii
	Rational(int _n);//Konstruktor preobrazovaniya tipa
	~Rational();//Destruktor

	friend ostream & operator << (ostream & stream, const Rational &c);
	friend istream & operator >> (ifstream & stream, Rational &c);

	Rational & operator = (const Rational &c);//Peregruzka =
	Rational operator + (const Rational &c);//Peregruzka +
	Rational operator - (const Rational &c);//Peregruzka -
	Rational operator * (const Rational &c);//Peregruzka *
	Rational operator / (const Rational &c);//Peregruzka /
	bool operator == (const Rational &c);//Peregruzka ==
	void Sokrashenie();//Sokrashenie drobi
};

ostream& operator<<(ostream & stream, const Rational &c);//Peregruzka vivoda
istream & operator >> (ifstream & stream, Rational &c);//Peregruzka vvoda
