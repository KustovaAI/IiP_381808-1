#pragma once
#include <string>
using namespace std;

struct Client	//Predstavlyaet informaciy. o kliente v Bank
{
	unsigned int number;      // nomer sceta
	string password;      // parol
	string Surname;       // familiya
	string Name;          // imya
	string Patronymic;    // otchestvo
	unsigned int summ_schet;   // dengi na schetu

};

istream& operator>>(istream& stream, Client& c);
ostream& operator<<(ostream& stream, const Client& c);