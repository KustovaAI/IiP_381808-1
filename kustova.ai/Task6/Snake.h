#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;
#define WIDTH 20
#define HEIGHT 20
class Snake
{
private:
	int size;	//Razmer zmei
	int points;		//ochki
	int count;		//eda schetchik 
	int snakeX[100], snakeY[100];	//Koordinati zmei
	char Level[HEIGHT][WIDTH];	//Pole
	int item1X;		//Koordinati eda
	int item1Y;
public:
	Snake(int s);
	~Snake();
	void ClearScreen();		//Clear screen
	void BuildLevel();
	void ReDraw();	//ReDraw level
	void Update();		//Update game loop
	void SpeedUpdate();	//Updates snakes speed
	void Items(int tailX, int tailY);	//Show and eat items
	bool IsGameOver();

};