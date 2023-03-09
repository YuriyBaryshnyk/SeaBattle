#pragma once
#include "Aquatorium.h"

/// <summary>
/// ������� �������� �������� ����� � ������� � ������ � ������
/// </summary>
/// <param name="player - ��������� �� ��������� �������� ���� ������"></param>
/// <param name="enemy - ��������� �� ��������� �������� ���� ������������"></param>
/// <returns></returns>
bool IfWin(Aquatorium& player, Aquatorium& enemy);

/// <summary>
/// ������� �������� ������ ��������� ���
/// </summary>
/// <param name="area - ��������� �� ��������� �������� ���� "></param>
/// <param name="x - ���������� � ��� � ������� ������� � ������ ����"></param>
/// <param name="y - ���������� � ��� � ������� ������� � ������ ����"></param>
void Checking(Aquatorium& area, int x, int y);

/// <summary>
/// �������, �� ��������� ��� ����'����� � ����-����� ����� ���
/// </summary>
/// <param name="player - ��������� �� ��������� �������� ���� ������"></param>
/// <param name="enemy - ��������� �� ��������� �������� ���� ������������"></param>
/// <param name="ifPlayer - ������ ����� ������������� ����"></param>
void EnemyShoot(Aquatorium& player, Aquatorium& enemy, bool ifPlayer);

/// <summary>
/// �������, �� ��������� ��� ������ � ����-����� ����� ���
/// </summary>
/// <param name="enemy - ��������� �� ��������� �������� ���� �����������"></param>
/// <param name="player - ��������� �� ��������� �������� ���� ������"></param>
/// <param name="ifPlayer - ����� ����� ������������� ����"></param>
/// <param name="game - ������ ����� ��� ������ � ������ ��� � ����"></param>
void PlayerShoot(Aquatorium& enemy, Aquatorium& player, bool ifPlayer, bool& game);

/// <summary>
/// ������� ������� ���
/// </summary>
/// <param name="easyMode - ������ ����� ��� ���� ������ ��� �� ����������"></param>
/// <param name="hellMode - ������ ����� ��� ���� ������ ���"></param>
/// <param name="twoPlayers - ����� ���� ��� ���� ������ ��� �� 2 ������"></param>
void Game(bool easyMode = true, bool hellMode = false,  bool twoPlayers = false);
