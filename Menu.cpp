#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Menu.h"
#include "ScreenMode.h"
#include "Aquatorium.h"
#include "Game.h"
#include"AdmiralList.h"

using namespace std;

void PrintMenu(short cursor)
{
	HelloScreen();
	std::cout << std::endl;
	std::cout << "\t\t\tMENU\n";

	if (cursor == 1)	cout << "\t\tX ";
	else			    cout << "\t\t ";
	cout << "1 PLAYER STANDART MODE\n";

	if (cursor == 2)	cout << "\t\tX ";
	else			    cout << "\t\t ";
	cout << "1 PLAYER HELL MODE\n";

	if (cursor == 3)	cout << "\t\tX ";
	else			    cout << "\t\t ";
	cout << "2 PLAYERS\n";

	if (cursor == 4)	cout << "\t\tX ";
	else			    cout << "\t\t ";
	cout << "RULES\n";

	if (cursor == 5)	cout << "\t\tX ";
	else			    cout << "\t\t ";
	cout << "BEST ADMIRALS' LIST\n";

	if (cursor == 6)	cout << "\t\tX ";
	else			    cout << "\t\t ";
	cout << "EXIT\n";

}

void ChangeMenu(short& cursor, char ch)
{
	if (ch == 's' || ch == '2')
		cursor++;
	if (ch == 'w' || ch == '8')
		cursor--;

	if (cursor == 7) cursor = 1;
	if (cursor == 0) cursor = 6;
}

void Menu()
{
	/// <summary>
	/// логічна змінна для закінчення гри
	/// </summary>
	bool game = true;

	while (game)
	{
		short mode = 1;
		char ch = 'a';
		while (ch != '\r')
		{
			system("cls");
			//Screen
			PrintMenu(mode);
			ch = _getch();
			ChangeMenu(mode, ch);
		}

		switch (mode)
		{
		case 6:
			game = false;
			break;

		case 1:
			Game(false);
			break;
		
		case 2:
			system("cls");
			HelloScreen();
			std::cout << "\n\tSORRY, THIS OPTION IS UNDER DEVELOPMENT\n\tTRY OTHER GAME MODE";
			_getch();

			//Game(false, true);

			break;
			
		case 3:
			system("cls");
			HelloScreen();
			std::cout << "\n\tSORRY, THIS OPTION IS UNDER DEVELOPMENT\n\tTRY OTHER GAME MODE";
			_getch();

			//Game(false, false, true)

			break;

		case 4:
			system("cls");
			Rules();
			break;

		case 5:
			AdmiralList list;
			list.Show();	
		
			break;
		}
	}
}