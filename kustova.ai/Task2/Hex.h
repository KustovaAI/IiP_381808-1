#pragma once
#include <clocale>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Hex
{
private:
	unsigned char *a;
	int length;
	
public:
	
	Hex(); // Konstruktor po umolchaniyu	
	Hex(int size);// Konstructor inicializacii
	Hex(const Hex&);//konstruktor kopirovaniya
	~Hex();//Destruktor

	friend ostream & operator << (ostream & stream, const Hex &c);
	friend std::istream & operator >> (std::istream & stream, Hex &c);

	Hex & operator = (const Hex &c);//Peregruzka =
	Hex operator + (const Hex &c);//Peregruzka +
	Hex operator - (const Hex &c);//Peregruzka -
	Hex operator * (const Hex &c);//Peregruzka *
	bool operator == (const Hex &c);//Peregruzka ==
	bool operator < (const Hex &c);//Peregruzka <
	bool operator > (const Hex &c);//Peregruzka >
	
	void ToInt();	//Perevod iz char v int
	void Zero();	//Zanulenie massiva
	
};

ostream& operator<<(ostream & stream, const Hex &c);//Peregruzka vivoda
std::istream & operator >> (std::istream & stream, Hex &c);//Peregruzka vvoda
