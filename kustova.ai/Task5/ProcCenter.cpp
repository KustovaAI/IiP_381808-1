#include "ProcCenter.h"

ProcCenter::ProcCenter()
{
	count_client = count_dep = 0;
	depozit = nullptr;
	client = nullptr;
}

ProcCenter::~ProcCenter()
{
	delete[] client;
	delete[] depozit;
	depozit = NULL;
	client = NULL;
}
void ProcCenter::Add_Client(Client c)	//Dobavlenie klienta
{
	if (count_client + 1 > size_buf_cl)		//esli ne hvataet pamyati
	{
		Client* tmp = client;
		client = new Client[count_client + 10];		//Rezerviruem bolshe pamyati 
		for (int i = 0; i < count_client; i++)
		{
			client[i] = tmp[i];		//kopirovanie v novuyu pamyat
		}

		client[count_client] = c;	//dobavlyaem tekushii 
		count_client++;
	}
	else
	{
		client[count_client] = c;	//dobavlenie v konec
		count_client++;
	}
}

void ProcCenter::Add_Dep(Depozit d)		//Dobavlenie vklada
{
	if (count_dep + 1 > size_buf_dep)	//esli ne hvataet pamyati
	{
		Depozit* tmp = depozit;
		depozit = new Depozit[count_dep + 10];	//Rezerviruem bolshe pamyati
		for (int i = 0; i < count_dep; i++)
		{
			depozit[i] = tmp[i];	//kopirovanie v novuyu pamyat
		}
		depozit[count_dep] = d;	//dobavlyaem tekushii 
		count_dep++;
	}
	else
	{
		depozit[count_dep] = d;
		count_dep++;
	}

}

void ProcCenter::Delete_Dep(int id1)	//Udalenie depozita
{
	int i;
	for (i = 0; i < count_dep; i++)
	{
		if (depozit[i].ID == id1) break;	//Poisk depozita
	}
	if (i == count_dep) return;
	for (; i < count_dep - 1; i++)
	{
		depozit[i] = depozit[i + 1];	//smeshenie depozitov posle udaleniya
	}
	count_dep--;
}



istream & operator>>(istream & stream, ProcCenter & pc)
{
	stream >> pc.count_client >> pc.count_dep;	//realnoe k-vo klientov/vkladov
	pc.size_buf_cl = pc.count_client + 10;	//razmer bufera s zapasom
	pc.size_buf_dep = pc.count_dep + 10;
	pc.client = new Client[pc.size_buf_cl];
	pc.depozit = new Depozit[pc.size_buf_dep];
	for (int i = 0; i < pc.count_client; i++)
	{
		stream >> pc.client[i];
	}
	for (int i = 0; i < pc.count_dep; i++)
	{
		stream >> pc.depozit[i];
	}
	return stream;
}

ostream & operator<<(ostream & stream, const ProcCenter & pc)
{
	stream << pc.count_client << endl;
	stream << pc.count_dep << endl;
	for (int i = 0; i < pc.count_client; i++)
	{
		stream << pc.client[i];
	}
	for (int i = 0; i < pc.count_dep; i++)
	{
		stream << pc.depozit[i];
	}
	return stream;
}
