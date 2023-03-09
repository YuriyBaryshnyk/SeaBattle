#pragma once
#include <iostream>
#include <windows.h>

#include "ScreenMode.h"

void HelloScreenDinamic()
{
	short n = 0;
	bool seaBattle[5][36] = { {1,1,1,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1},
							  {1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0},
							  {1,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0},
							  {0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0},
							  {1,1,1,0,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1}
	};
	while (n<21)
	{
		system("cls");
		std::cout << std::endl;
		if (n == 0) Sleep(1000);
		for (size_t i = 0; i < 5; i++)
		{
			//for (short j = n; j < 15; j++) std::cout << "  ";
			for (short k =n ; k < n+15; k++)
			{
				if (seaBattle[i][k])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 15));
					std::cout << "  ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
				}
				else std::cout << "  ";
			}
			std::cout << std::endl;
			

		}
		std::cout << std::endl;
		for (size_t i = 0; i < 5; i++)
		{
			for (short j = 0; j < 5; j++) std::cout << "  ";
			for (short k = n; k < n + 15; k++)
			{
				if (seaBattle[i][k])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 15));
					std::cout << "  ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
				}
				else std::cout << "  ";
			}
			std::cout << std::endl;
			//system("pause");
		}
		std::cout << std::endl;
		for (size_t i = 0; i < 5; i++)
		{
			for (short j = 0; j < 10; j++) std::cout << "  ";
			for (short k = n; k < n + 15; k++)
			{
				if (seaBattle[i][k])
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 15));
					std::cout << "  ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
				}
				else std::cout << "  ";
			}
			std::cout << std::endl;
		}
		n++;
		Sleep(200);	
	}
	//system("pause");
	Sleep(1000);
}

void HelloScreen()
{
	bool seaBattle[5][36] = { {1,1,1,0,1,1,1,0,0,1,0,0,0,1,1,1,0,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,0,1,1,1},
							  {1,0,0,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0},
							  {1,1,1,0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,1,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,1,0},
							  {0,0,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,0,1,0,0},
							  {1,1,1,0,1,1,1,0,1,0,1,0,0,1,1,1,0,1,0,1,0,0,1,0,0,0,1,0,0,1,1,1,0,1,1,1}
	};

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 7; j++) std::cout << "  ";
		for (size_t j = 0; j < 11; j++)
		{
			if (seaBattle[i][j])
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 15));
				std::cout << "  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
			}
			else std::cout << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 13; j < 36; j++)
		{
			if (seaBattle[i][j])
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((15 << 4) | 15));
				std::cout << "  ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((0 << 4) | 7));
			}
			else std::cout << "  ";
		}
		std::cout << std::endl;
	}
}

void Rules()
{
	HelloScreen();

	std::cout<<std::endl << "\t\t\tRULES\n";

	std::cout << "Use 'W', 'A', 'D','S' or '8','2','4','6' to move the cursor over the water area\n";
	std::cout << "Press 'Enter' to select a position or target on the map\n";
	std::cout << "Press 'X' or '5' to rotate the ship \n\n";
	std::cout << "Press '0'to run away from the battlefield like a coward \n\n";
	std::cout << "You can't place ships on their sides or corners\n\n";
	std::cout << "You can't shoot repeatedly at the same coordinate\n\n";
	std::cout << "Green - is a color of your ships\n";
	std::cout << "Red - is a color of destroyed ships\n";
	std::cout << "LightBlue - is a color of empty coordinate (It's water)\n";
	std::cout << "Blue - is a color coordinate where the enemy shot\n\n";
	std::cout << "Grey - is a color of the fog of war, which does not allow you to see the enemy's water area.\n\n";
	system("pause");
}