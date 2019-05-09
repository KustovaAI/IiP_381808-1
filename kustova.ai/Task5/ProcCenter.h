#pragma once
#include "Client.h"
#include "Depozit.h"

class ProcCenter	// predostavlyaed dostup k klientam i vkladam
{

private:
	int size_buf_dep;	//razmer bufera depozitov
	int size_buf_cl;	//razmer bufera klientov
public:
	Depozit * depozit;
	Client * client;
	int count_dep;	//k-vo depozitov
	int count_client;	//k-vo klientov		

public:
	ProcCenter();
	~ProcCenter();
	void Add_Client(Client c);	//Dobavlenie klienta
	void Add_Dep(Depozit d);	//Dobavlenie vklada
	void Delete_Dep(int id1);	//Udalenie depozita
	friend istream & operator>>(istream& stream, ProcCenter& pc);
	friend ostream & operator<<(ostream& stream, const ProcCenter& pc);
};

istream & operator>>(istream& stream, ProcCenter& pc);
ostream & operator<<(ostream& stream, const ProcCenter& pc);