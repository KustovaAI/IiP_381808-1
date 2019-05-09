#include "Client.h"

istream& operator>>(istream& stream, Client& c)
{
	stream >> c.number >> c.password >> c.Surname >> c.Name >> c.Patronymic >> c.summ_schet;
	return stream;
}

ostream & operator<<(ostream & stream, const Client & c)
{
	stream << c.number << ' ' << c.password << ' ' << c.Surname << ' ' << c.Name << ' ' << c.Patronymic << ' ' << c.summ_schet << endl;
	return stream;
}
