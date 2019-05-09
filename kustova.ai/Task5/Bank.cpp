
#include <fstream>
#include <iostream>
#include "Bank.h"

Bank::Bank()
{
	nowClient = nullptr;
	ifstream is("Depozit.txt");		//chtenie dannih iz faila
	is >> nowMonth;
	is >> prC;
	is.close();
}

Bank::~Bank()
{
	delete[] nowClient;
	nowClient = NULL;
	nowMonth = 0;
}

bool Bank::Avtorization(int num, string pas)		//Avtorizaciya klienta
{
	nowClient = nullptr;	
	for (int i = 0; i < prC.count_client; i++)
	{
		if ((prC.client[i].number == num) && (prC.client[i].password == pas))
		{
			nowClient = &prC.client[i];
			return true;
		}
	}
	return false;
}

void Bank::Print_All_Dep()	//Vivod vseh vozmozhnih depozitov
{
	cout << "Up to 100000: " << endl;
	cout << "for 3 month: " << table_procent[0][0] << "%, " << endl;
	cout << "for 6 month: " << table_procent[0][1] << "%, " << endl;
	cout << "for 1 year : " << table_procent[0][2] << "%, " << endl;
	cout << "for 2 year : " << table_procent[0][3] << "%, " << endl;
	cout << "for 3 year : " << table_procent[0][4] << "%" << endl;
	if (nowClient->summ_schet > 100000)
	{
		cout << "From 100000 to 500000: ";
		cout << "for 3 month: " << table_procent[1][0] << "%, " << endl;
		cout << "for 6 month: " << table_procent[1][1] << "%, " << endl;
		cout << "for 1 year : " << table_procent[1][2] << "%, " << endl;
		cout << "for 2 year : " << table_procent[1][3] << "%, " << endl;
		cout << "for 3 year : " << table_procent[1][4] << "%" << endl;
	}
	if (nowClient->summ_schet > 500000)
	{
		cout << "From 500000 to 1000000 ";
		cout << "for 3 month: " << table_procent[2][0] << "%, " << endl;
		cout << "for 6 month: " << table_procent[2][1] << "%, " << endl;
		cout << "for 1 year : " << table_procent[2][2] << "%, " << endl;
		cout << "for 2 year : " << table_procent[2][3] << "%, " << endl;
		cout << "for 3 year : " << table_procent[2][4] << "%" << endl;
	}
}

bool Bank::Check_Dep()	//Proveryaet otkrit li depozit
{
	for (int i = 0; i < prC.count_dep; i++)
	{
		if (prC.depozit[i].ID == nowClient->number) return true;
	}
	return false;
}

void Bank::Print_Dep_Inf()		//Informaciya o vklade
{
	int i;
	for (i = 0; i < prC.count_dep; i++)		//Poisk depozita
	{
		if (prC.depozit[i].ID == nowClient->number) break;
	}
	if (i == prC.count_dep)		//esli depozit ne otkrit
	{
		cout << "No Deposit opened";
		return;
	}
	cout << "Start summ: " << prC.depozit[i].start_sum_dep << endl;
	cout << "Available for withdrawal: " << prC.depozit[i].cap << endl;	//dostupno dlya snyatiya
	cout << "It took months: " << nowMonth - prC.depozit[i].Start_Month << endl;	//skolko proshlo mesyacev
	cout << "Interest rate: " << prC.depozit[i].procent << '%' << endl;	//%-stavka
}

bool Bank::Open_Dep(int numMonth, int money)
{
	if (Check_Dep() || money > nowClient->summ_schet)	//esli nedostatochno sredstv na schetu ili vklad ughe otkrit, to otkazat v otkritii
	{
		cout << "You already have a Deposit or insufficient funds." << endl;
		return false;
	}
	Depozit tmp;
	tmp.cap = 0;
	tmp.start_sum_dep = money;
	nowClient->summ_schet -= money;
	tmp.ID = nowClient->number;
	tmp.Start_Month = nowMonth;

	if (numMonth >= 36) tmp.Srok = 4;	//Srok_3_year
	else if (numMonth >= 24) tmp.Srok = 3;	//Srok_2_year
	else if (numMonth >= 12) tmp.Srok = 2;	//Srok_1_year
	else if (numMonth >= 6) tmp.Srok = 1;	//Srok_6_month
	else tmp.Srok = 0;	//Srok_3_month
	if (money > 500000) tmp.Range = 2;		//Ot_500000_do_1000000
	else if (money > 100000) tmp.Range = 1;	//Ot_100000_do_500000
	else tmp.Range = 0;	//Do_100000
	tmp.procent = table_procent[tmp.Range][tmp.Srok];
	prC.Add_Dep(tmp);
	File();	//Zapis izmenenii v fail
	return true;
}



void Bank::Withdraw_Capital()
{
	int i;
	for (i = 0; i < prC.count_dep; i++)	//Poisk depozita
	{
		if (prC.depozit[i].ID == nowClient->number) break;
	}
	if (i == prC.count_dep) 	//Esli vklad ne otkrit
	{
		cout << "There are no open deposits" << endl;
		return;
	}
	nowClient->summ_schet += prC.depozit[i].cap;	//Pribavlenie pribili ot procentov k summe na schetu
	prC.depozit[i].cap = 0;
	File();
}

bool Bank::Close_Dep()
{
	int i;
	for (i = 0; i < prC.count_dep; i++)	//Poisk depozita
	{
		if (prC.depozit[i].ID == nowClient->number) break;
	}
	if (i == prC.count_dep)	//esli depozit ne otkrit
	{
		cout << "There are no open deposits" << endl;
		return false;
	}

	int c;
	if (prC.depozit[i].Srok == 0) c = 3;
	else if (prC.depozit[i].Srok == 1) c = 6;
	else if (prC.depozit[i].Srok == 2) c = 12;
	else if (prC.depozit[i].Srok == 3) c = 24;
	else if (prC.depozit[i].Srok == 4) c = 36;
	if (nowMonth - prC.depozit[i].Start_Month < c) return false;	// esli ne istek srok depozita
	nowClient->summ_schet += prC.depozit[i].cap + prC.depozit[i].start_sum_dep;		// perevodim dengi na schet
	prC.Delete_Dep(prC.depozit[i].ID);
	File();
	return true;

}

void Bank::File()	//Zapis izmenenii v fail
{
	ofstream os;
	os.open("Depozit.txt", ios_base::trunc);	//Udalenie zapisi iz faila
	os.close();
	os.open("Depozit.txt", ios_base::app);
	os << nowMonth << endl;
	os << prC;
	os.close();
}