#include "Snake.h"
Snake::Snake(int s)
{
	size = s;
	count = 0;
	points = 0;
	item1X = 0;
	item1Y = 0;
	for (int i = 0; i < size; i++)
	{
		snakeX[i] = WIDTH / 2 + i;	//Initialize snakes initial position
		snakeY[i] = HEIGHT / 2;
	}
	for (int i = 5; i < 100; i++)	//Ostalnie elementi zanulyaem
	{
		snakeX[i] = NULL;
		snakeY[i] = NULL;
	}
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)		
		{
			Level[i][j] = ' ';		//Pole			
		}
	}
	Level[snakeY[0]][snakeX[0]] = '*';		//Head
	for (int i = 1; i < size; i++)
		Level[snakeY[i]][snakeX[i]] = 'o';		//Body snake

}

Snake::~Snake()
{
	size = 0;
	count = 0;
	points = 0;
	item1X = 0;
	item1Y = 0;
}
void Snake::BuildLevel()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)		//Walls
		{
			Level[0][j] = '#';
			Level[i][0] = '#';
			Level[i][WIDTH - 1] = '#';
			Level[HEIGHT - 1][j] = '#';

		}
	}
}

void Snake::ReDraw()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		cout << endl;
		for (int j = 0; j < WIDTH; j++)
			cout << " " << Level[i][j];		//" " - dlya proporcionalnih razmerov
	}
}

void Snake::ClearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);		//Ustanovka kursora na nachalo
}
void Snake::Update()
{	
	char input = ' ';
	char previnput = 75;	//Nachalnoe napravlenie (left)
	int tailX, tailY;	//Koordinati poslednego elementa zmei
	int  tempX[100], tempY[100];	//Kopiya 
	bool gameOver = false;
	
	while (!gameOver)	//Poka igra ne zakonchena
	{
		SpeedUpdate();		//Skorost

		//Zapominaem poslednii element hvosta
		tailY = snakeY[size - 1];
		tailX = snakeX[size - 1];

		//Udalenie poslednego elementa hvosta
		Level[tailY][tailX] = ' ';
		Items(tailX, tailY);	//Proverka na edu

		//Copy snake (except tail) into temp array, and displace 1 element to the right
		//Leave the first element empty for head
		for (int i = 0; i < size - 1; i++)
		{
			tempX[i + 1] = snakeX[i];	//Copy y values
			tempY[i + 1] = snakeY[i];	//Copy x values
		}

		//Copy a duplicate of the head into first element so it can be moved by user
		tempX[0] = snakeX[0];
		tempY[0] = snakeY[0];

		//Copy temp array back into snake array, including previous head position
		//First 2 elements will be a duplicate of the head with same x and y position
		for (int i = 0; i < size; i++)
		{
			snakeX[i] = tempX[i];		//Vopy y values
			snakeY[i] = tempY[i];		//Vopy x values
		}

		//Stores keystroke
		if (_kbhit())
			input = _getch();	//Kakaya klavisha najata

		//While moving down
		if (previnput == 80)
		{
			snakeY[0] += 1;		//Set heads new position
			if (input == 75)	//Go left
				previnput = 75;
			else if (input == 77)	//Go right
				previnput = 77;
		}
		//While Moving up
		else if (previnput == 72)
		{
			snakeY[0] -= 1;
			if (input == 75)	//Go left
				previnput = 75;
			else if (input == 77)	//Go right
				previnput = 77;
		}
		//While Moving Right
		else if (previnput == 77)
		{
			snakeX[0] += 1;
			if (input == 72)	//Go up
				previnput = 72;
			else if (input == 80)	//Go down
				previnput = 80;
		}
		//While Moving Left
		else if (previnput == 75)
		{
			snakeX[0] -= 1;
			if (input == 72)	//Go up
				previnput = 72;
			else if (input == 80)	//Go down
				previnput = 80;
		}

		//Set snakes new position
		Level[snakeY[0]][snakeX[0]] = '*';		//Head
		for (int i = 1; i < size; i++)
			Level[snakeY[i]][snakeX[i]] = 'o';		//Body

		//Check if game is over
		gameOver = IsGameOver();
		if (size >= 10)
		{
			cout << endl << "\t\t   YOU ARE WIN!";
			gameOver = true;
		}
		//Redraw
		ClearScreen();
		ReDraw();
	}

}

void Snake::SpeedUpdate()
{
	if (points < 100)		//Level1
	{
		Sleep(100);		//Zaderjka
		cout << endl << "Level 1";
	}
	else if ((points >= 100) && (points < 300))		//Level2
	{
		Sleep(80);
		cout << endl << "Level 2";
	}
	else if (points >= 300)		//Level3
	{
		Sleep(50);
		cout << endl << "Level 3";
	}

}

void Snake::Items(int tailX, int tailY)
{
	clock_t interval = clock() % 5000;
	cout << "		 Points: " << points << endl;

	//Show items at certain intervals
	if (count == 0)		//Pervii element
	{		
	fos1:
		srand((unsigned)time(NULL));
		item1X = rand() % (WIDTH - 2) + 1;
		item1Y = rand() % (HEIGHT - 2) + 1;
		for (int i = 0; i < size; i++)
			if ((item1X == snakeX[i]) || (item1Y == snakeY[i]))//Proverka, sovpadayut li koordinat zmei i edi
				goto fos1;
		Level[item1Y][item1X] = '@';
		count++;
	}

	//Check collision width item
	for (int i = 0; i < count; i++)
	{
		if ((snakeX[0] == item1X) && (snakeY[0] == item1Y))
		{
			points += 100;
			//Delete items
		fos2:
			srand((unsigned)time(NULL));
			item1X = rand() % (WIDTH - 2) + 1;
			item1Y = rand() % (HEIGHT - 2) + 1;
			for (int i = 0; i < size; i++)
				if ((item1X == snakeX[i]) || (item1Y == snakeY[i]))//Proverka, sovpadayut li koordinat zmei i edi
					goto fos2;
			Level[item1Y][item1X] = '@';
			count++;
			
			//Snake grows
			size++;
			snakeX[size - 1] = tailX;
			snakeY[size - 1] = tailY;
			
		}
	}
}

bool Snake::IsGameOver()
{
	//Esli stolknovenie s hvostom
	for (int i = 2; i < size; i++)
	{
		if ((snakeX[0] == snakeX[i]) && (snakeY[0] == snakeY[i]))
		{
			cout << endl << "       YOU ARE LOSE!";
			_getch();
			return true;
		}
	}
	if ((snakeX[0] == WIDTH - 1) || (snakeY[0] == HEIGHT - 1) || (snakeX[0] == 0) || (snakeY[0] == 0))		//esli stolknovenie so stenoi
	{
		cout << endl << "         YOU ARE LOSE!";
		_getch();
		return true;
	}
	else
		return false;
}