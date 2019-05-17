#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>
#include <fstream>
#include "Snake.h"
using namespace std;
int main()
{
	Snake c1(5);
	c1.BuildLevel();
	cout << "The game will end when the snake is more than 10" << endl;
	c1.Update();
	
	_getch();
	_getch();
	return 0;
}