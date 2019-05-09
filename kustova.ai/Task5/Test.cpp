#include <clocale>
#include <iostream>
#include <fstream>
#include "Bank.h"
using namespace std;

/*
            Depozit.txt
3	- tekushii mesyac
4	- k-vo klientov
2	- k-vo vkladov
---dannie o klientah---
1234 pass Ivanov Ivan Ivanovich 210000
4321 pass1 Smirnov Oleg Dmitrievich 50000
1111 2pass Ivanova Olga Petrovna 725000
9876 pa3ss Kustova Anastasiya Igorevna 400000
---dannie o vkladah---
1234 500000 1500 1 3		--(nomer scheta, summa vklada, summa po procentam,  mesyac nachala vklada, srok vklada v month)
1111 100000 5000 2 24
*/

int main()
{
	Bank c1;
	
	int n;
	string p;
	int n1, month, sum;
	cout << "Enter the card number: " << endl;
	cin >> n;
	cout << "Enter the pin code of the card: " << endl;
	cin >> p;
	c1.Avtorization(n, p);
	def2:
	cout << "The following operations are available to you (choose the action): " << endl;
	cout << "1 - To find out information about the available deposits" << endl;
	cout << "2 - Check for open Deposit" << endl;
	cout << "3 - Open Deposit" << endl;
	cout << "4 - Show the status of the Deposit" << endl;
	cout << "5 - Remove interest" << endl;
	cout << "6 - Close Depozit" << endl;
	def1:
	cin >> n1;
	switch (n1)
	{
	case 1:
		c1.Print_All_Dep();
		break;
	case 2:
		if (c1.Check_Dep()) cout << "There is an open Deposit" << endl;
		else cout << "There is not an open Deposit" << endl;
		break;
	case 3:
		cout << "Enter for how long you want to open a Deposit (3 months, 6 months, 12 month, 24 month, 36 month): " << endl;
		cin >> month;
		cout << "Enter the Deposit summ: " << endl;
		cin >> sum;
		c1.Open_Dep(month, sum);
		break;
	case 4:
		c1.Print_Dep_Inf();
		break;
	case 5:
		c1.Withdraw_Capital();
		cout << "You have withdrawn savings" << endl;
		break;
	case 6:
		c1.Close_Dep();
		cout << "You have closed the Deposit, the money is transferred to a Bank account" << endl;
		break;
	default:
		cout << "Viberite cifru iz predstavlennogo spiska: ";
		goto def1;
	}
	cout << "-----------------------" << endl;
	goto def2;
	cin.get();
	return 0;
}