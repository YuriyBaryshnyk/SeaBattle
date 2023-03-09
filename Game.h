#pragma once
#include "Aquatorium.h"

/// <summary>
/// функція перевірки наявності цілей в акваторії і виходу з режиму
/// </summary>
/// <param name="player - посилання на структуру ігрового поля гравця"></param>
/// <param name="enemy - посилання на структуру ігрового поля супротивника"></param>
/// <returns></returns>
bool IfWin(Aquatorium& player, Aquatorium& enemy);

/// <summary>
/// функція перевірки сусідніх координат цілі
/// </summary>
/// <param name="area - посилання на структуру ігрового поля "></param>
/// <param name="x - координата Х цілі в масивах акваторії і туману війни"></param>
/// <param name="y - координата У цілі в масивах акваторії і туману війни"></param>
void Checking(Aquatorium& area, int x, int y);

/// <summary>
/// функція, що забезпечує хід комп'ютера в будь-якому режимі гри
/// </summary>
/// <param name="player - посилання на структуру ігрового поля гравця"></param>
/// <param name="enemy - посилання на структуру ігрового поля супротивника"></param>
/// <param name="ifPlayer - логічна змінна автоматичного ходу"></param>
void EnemyShoot(Aquatorium& player, Aquatorium& enemy, bool ifPlayer);

/// <summary>
/// функція, що забезпечує хід гравця в будь-якому режимі гри
/// </summary>
/// <param name="enemy - посилання на структуру ігрового поля супроивника"></param>
/// <param name="player - посилання на структуру ігрового поля гравця"></param>
/// <param name="ifPlayer - логіна змінна автоматичного ходу"></param>
/// <param name="game - логічна змінна для виходу з режиму гри у меню"></param>
void PlayerShoot(Aquatorium& enemy, Aquatorium& player, bool ifPlayer, bool& game);

/// <summary>
/// функція запускає гру
/// </summary>
/// <param name="easyMode - логічна змінна для зміни режиму гри на полегшення"></param>
/// <param name="hellMode - логічна змінна для зміни режиму гри"></param>
/// <param name="twoPlayers - логіна зміна для зміни режуму гри на 2 гравця"></param>
void Game(bool easyMode = true, bool hellMode = false,  bool twoPlayers = false);
