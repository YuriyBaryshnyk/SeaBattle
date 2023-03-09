#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

#include "Aquatorium.h"
#include "ScreenMode.h"
#include "AdmiralList.h"

/// <summary>
/// функція підрахунку очок
/// </summary>
/// <param name="player - посилання на структуру ігрового поля гравця"></param>
/// <returns></returns>
int Score(Aquatorium& player)
{
	int saveBoat=0;
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (player.area[i][j] == 1) saveBoat += 10;
		}
	}
	return ((100 - player.shoot) + saveBoat);
}

bool IfWin(Aquatorium& areaCheck, Aquatorium& areaToScore)
{
	bool gameover = true;
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (areaCheck.area[i][j] == 1) return !gameover;
		}

	}
	areaToScore.shoot = areaCheck.shoot;
	areaToScore.score = Score(areaToScore);
	return true;
}

void Checking (Aquatorium& area, int x, int y)
{
	if (x != 0) 
	{
		if (y != 0) area.fogOfWar[x - 1][y - 1] = 1;
		if (y != 9) area.fogOfWar[x - 1][y + 1] = 1;
	}
	if (x != 9)
	{
		if (y != 0) area.fogOfWar[x + 1][y - 1] = 1;
		if (y != 9) area.fogOfWar[x + 1][y + 1] = 1;
	}
	if((x!=0 && area.area[x - 1][y]==1) || (x != 9 && area.area[x + 1][y] == 1) || (y != 0 && area.area[x][y-1] == 1) || (y != 9 && area.area[x][y + 1] == 1))
		area.area[x][y] = 3;
	else
	{
		area.area[x][y] = 3;
		if (x != 0) area.fogOfWar[x - 1][y] = 1;
		if (x != 9) area.fogOfWar[x + 1][y] = 1;
		if (y != 0) area.fogOfWar[x][y-1] = 1;
		if (y != 9) area.fogOfWar[x][y+1] = 1;
	}
	
}

void EnemyShoot(Aquatorium& player, Aquatorium& enemy, bool ifPlayer)
{
	srand(time(NULL));
	int copy[10][10];
	char ch = 'a';
	int x = rand() % 10;
	int y = rand() % 10;

	while (true)
	{
		for (int i = 0; i < 10; i++)
			for (size_t j = 0; j < 10; j++)
				copy[i][j] = player.area[i][j];

		copy[x][y] = 2;

		system("cls");

		std::cout << "\tENEMY TURN NOW\n\n";
		std::cout << "\tENEMY AQUATORIUM\n\tEnemy shoots: " << player.shoot << std::endl;
		enemy.printArea(enemy.area, ifPlayer);
		std::cout << std::endl;
		std::cout << "\tPLAYER AQUATORIUM\n\tYour shoots: " << enemy.shoot << std::endl;
		player.printArea(copy, !ifPlayer);
		//std::cout << "enemy turn\n";
		//std::cout << std::endl;
		//player.printArea(player.fogOfWar, !ifPlayer);
		Sleep(1000);
	
		if (player.area[x][y] == 0)
		{
			player.fogOfWar[x][y] = 1;
			player.shoot++;
			player.area[x][y] = 5;

			break;
		}

		else if (player.area[x][y] == 1)
		{
			player.fogOfWar[x][y] = 1;
			player.shoot++;
			Checking(player, x, y);
		}
		x = rand() % 10;
		y = rand() % 10;
	}
}

void PlayerShoot(Aquatorium& enemy, Aquatorium& player, bool ifPlayer,bool& game )
{
	srand(time(NULL));
	int copy[10][10];
	char ch = 'a';
	int x = rand() % 10;
	int y = rand() % 10;

	while (true)
	{
		for (int i = 0; i < 10; i++)
			for (size_t j = 0; j < 10; j++)
				copy[i][j] = enemy.area[i][j];

		copy[x][y] = 2;

		system("cls");

			std::cout << "\tPLAYER TURN NOW\n\n";
			std::cout << "\tENEMY AQUATORIUM\n\tEnemy shoots: "<<player.shoot<<std::endl;
			enemy.printArea(copy, !ifPlayer);
			std::cout << std::endl;
			std::cout << "\tPLAYER AQUATORIUM\n\tYour shoots: " << enemy.shoot << std::endl;
			player.printArea(player.area, ifPlayer);
			
			ch = _getch();
			if (ch == '0')
			{
				game = false;
				break;
			}
			if ((ch == '8' || ch == 'w') && x != 0)		x--;
			if ((ch == '2' || ch == 's') && (x != 9))	x++;
			if ((ch == '4' || ch == 'a') && y != 0)		y--;
			if ((ch == '6' || ch == 'd') && (y != 9))	y++;
			if (ch == '\r' && enemy.fogOfWar[x][y] != 1) 
			{
				if (enemy.area[x][y] == 0)
				{
					enemy.fogOfWar[x][y] = 1;
					enemy.shoot++;
					break;
				}

				else if (enemy.area[x][y] == 1)
				{
					enemy.fogOfWar[x][y] = 1;
					enemy.shoot++;
					Checking(enemy, x, y);
					//enemy.area[x][y] = 3;
				}
			}
	}
}

void Game(bool easyMode = true, bool hellMode = false, bool twoPlayers = false)
{
	bool ifPlayer = true;
	bool game = true;
	Aquatorium AreaPlayer;
	Aquatorium AreaEnemy;
	AreaPlayer.SetFleet(ifPlayer);
	Sleep(1000);
	AreaEnemy.SetFleet(!ifPlayer);
	
	
	while (game)
	{
		PlayerShoot(AreaEnemy, AreaPlayer, ifPlayer, game);
		if (!game) break;
		if (IfWin(AreaEnemy, AreaPlayer))
		{
			break;
		}
		EnemyShoot(AreaPlayer, AreaEnemy,  !ifPlayer);
		if (IfWin(AreaPlayer, AreaEnemy))
		{
			break;
		}
	}
	Sleep(1000);
	system("cls");
	if (AreaPlayer.score > 0)
	{
		HelloScreen();
		std::cout << std::endl << "\t\t       YOU WIN\n\t\tENEMY FLEET IS DEFEATED\n";
		std::cout << "\t\tYOUR SCORE: " << AreaPlayer.score;

		AdmiralList list;
		list.Win(AreaPlayer);
	}
	else
	{
		HelloScreen();
		std::cout << std::endl << "\t\t       YOU LOSE\n\t\tYOUR FLEET IS DEFEATED\n";
	}
}
