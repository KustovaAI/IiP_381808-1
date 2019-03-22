#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Integrals
{
private:
	double a, b, in;
	int n;
	
public:

	Integrals(); // Konstruktor po umolchaniyu	
	Integrals(double _a, double _b, int _n, double _in);// Konstructor inicializacii
	Integrals(const Integrals&);//konstruktor kopirovaniya
	~Integrals();//Destruktor

	friend ostream & operator << (ostream & stream, const Integrals &c);
	friend std::istream & operator >> (std::istream & stream, Integrals &c);

	Integrals RightRect(double f(double x), const Integrals &c);	//Metod pravih pryamougolnikov
	Integrals LeftRect(double f(double x), const Integrals &c);	//Metod levih pryamougolnikov
	Integrals MiddleRect(double f(double x), const Integrals &c);	//Metod srednih pryamougolnikov
	
};

ostream& operator<<(ostream & stream, const Integrals &c);//Peregruzka vivoda
std::istream & operator >> (std::istream & stream, Integrals &c);//Peregruzka vvoda

