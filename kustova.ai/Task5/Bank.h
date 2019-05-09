#pragma once
#include "ProcCenter.h"
class Bank
{
private:
	Client* nowClient;   // tekushii client
	ProcCenter prC;  // dannie po klientam i vkladam

	int nowMonth;	//tekushii mesyac

public:
	Bank();
	~Bank();

public:

	bool Avtorization(int num, string pas);	//Avtorizaciya klienta
	void Print_All_Dep();	//Vivod vseh vozmozhnih depozitov
	bool Check_Dep();	//Proveryaet otkrit li depozit
	void Print_Dep_Inf();	//Informaciya o vklade
	bool Open_Dep(int numMonth, int money);		//Otkritie vklada	
	void Withdraw_Capital();	//Snyatie procentov so vklada
	bool Close_Dep();	//Zakritie depozita

	void File();	//izmenyaet dannie faila

};

