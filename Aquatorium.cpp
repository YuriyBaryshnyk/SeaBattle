#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

#include "Aquatorium.h"

using namespace std;
	
enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

/// <summary>
/// функція зміник кольору елементів консолі
/// </summary>
/// <param name="text - колір тексту"></param>
/// <param name="background - колір фону"></param>
void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

/// <summary>
/// функція перевірки поля на випадок виходу за мужі
/// </summary>
/// <param name="arr масив"></param>
/// <param name="x - координата Х цілі в масивах акваторії і туману війни"></param>
/// <param name="y - координата У цілі в масивах акваторії і туману війни"></param>
/// <param name="deckX - розмір корабля по осі Х"></param>
/// <param name="deckY - розмір корабля по осі У"></param>
/// <returns></returns>
bool VerifyPlace(const int arr[10][10], int x, int y, int deckX,int deckY)
{
	for (int i = x - 1; i <= x + deckX; i++)
	{
		if (i>=0 && x<10)
		for (int j = y - 1; j <= y + deckY; j++)
		{
			if(j>=0 && j<10)
			if (arr[i][j] == 1) return false;
		}
	}
	return true;
}

void Aquatorium::printArea(int arr[10][10], bool ifPlayer)
{
	cout << "    " << "A B C D E F G H J K\n";
	for (size_t i = 0; i < 10; i++)
	{
		cout << setw(3) << i + 1 << " ";
		for (size_t j = 0; j < 10; j++)
		{
			if (ifPlayer  || fogOfWar[i][j] == 1 || arr[i][j] == 2)
			{
				if (arr[i][j] == 1)
				{
					SetColor(Green, Green);
					cout << arr[i][j];
					cout << arr[i][j];
					SetColor(LightGray, Black);
				}
				else if (arr[i][j] == 2)
				{
					SetColor(White, White);
					cout << arr[i][j];
					cout << arr[i][j];
					SetColor(LightGray, Black);
				}
				else if (arr[i][j] == 0)
				{
					SetColor(LightBlue, LightBlue);
					cout << arr[i][j];
					cout << arr[i][j];
					SetColor(LightGray, Black);
				}
				else if (arr[i][j] == 3)
				{
					SetColor(Red, Red);
					cout << arr[i][j];
					cout << arr[i][j];
					SetColor(LightGray, Black);
				}
				else if (arr[i][j] == 5)
				{
					SetColor(Blue, Blue);
					cout << arr[i][j];
					cout << arr[i][j];
					SetColor(LightGray, Black);
				}
			}
			
			else 
			{
				SetColor(LightGray, LightGray);
				cout << arr[i][j];
				cout << arr[i][j];
				SetColor(LightGray, Black);
			}
		}
		cout <<" "<< endl;
	}
}

void Aquatorium::SetShip(int deck, bool ifPlayer)
{
	srand(time(NULL));
	int copy[10][10];
	char ch = 'a';
	bool place = false;
	int deckX = deck;
	int deckY = 1;
	if (!ifPlayer && (rand() % 2 == 0)) swap(deckX, deckY);
	int x = rand() % (10 - deckX);
	int y = rand() % (10 - deckY);

	while (place==false)
	{
		for (int i = 0; i < 10; i++)
			for (size_t j = 0; j < 10; j++)
				copy[i][j] = area[i][j];
	
		for (size_t i = x; i <= x + deckX-1; i++)
			for (size_t j = y; j <= y+deckY-1; j++)
					copy[i][j] = 2;

		if (ifPlayer) {
			system("cls");
			cout << "\tSITE YOUR SHIP\n\n";
			printArea(copy, ifPlayer);

			ch = _getch();
			if ((ch == '8' || ch == 'w') && x != 0) x--;
			if ((ch == '2' || ch == 's') && (x < (10 - deckX))) x++;
			if ((ch == '4' || ch == 'a') && y != 0) y--;
			if ((ch == '6' || ch == 'd') && (y < (10 - deckY))) y++;
			if ((ch == '5' || ch == 'x') && deckY == 1 && (y + deckX < 11)) swap(deckX, deckY);
			else if ((ch == '5' || ch == 'x') && deckX == 1 && (x + deckY < 11)) swap(deckX, deckY);

			if (ch == '\r') place = VerifyPlace(area, x, y, deckX, deckY);
		}
		if (!ifPlayer)  place = VerifyPlace(area, x, y, deckX, deckY);
		if (place == false && !ifPlayer)
		{
			swap(deckX, deckY);
			x = rand() % (10 - deckX);
			y = rand() % (10 - deckY);
		}
	}

	for (int i = 0; i < 10; i++)
		for (size_t j = 0; j < 10; j++)
		{
			area[i][j] = copy[i][j];
			if (copy[i][j] == 2)	area[i][j] = 1;
		}
}

void Aquatorium::SetFleet(bool ifPlayer)
{
	SetShip(4, ifPlayer);
	for (size_t i = 0; i < 2; i++) SetShip(3, ifPlayer);
	for (size_t i = 0; i < 3; i++) SetShip(2, ifPlayer);
	for (size_t i = 0; i < 4; i++) SetShip(1, ifPlayer);
	if (ifPlayer)
	{
		system("cls");
		cout << "\tYour fleet is complete!!!\n\n";
		printArea(area, ifPlayer);
		Sleep(1000);
	}
}

