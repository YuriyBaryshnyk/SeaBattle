#pragma once

/// <summary>
/// ��������� �������� ����
/// </summary>
struct Aquatorium
{
	/// <summary>
	/// ������� �������
	/// </summary>
	int shoot=0;

	/// <summary>
	/// �������
	/// </summary>
	int score=0;
	
	/// <summary>
	/// ����� ������ ���� �������� ����
	/// </summary>
	int fogOfWar[10][10] = { 0 };

	/// <summary>
	/// ����� �������� ����
	/// </summary>
	int area[10][10] = { 0 };

	/// <summary>
	/// ������� �������� � ������� ������ ����
	/// </summary>
	/// <param name="arr - ����� �������� ����"></param>
	/// <param name="ifPlayer - ������ ����� ������������� ����"></param>
	void printArea(int arr[10][10], bool ifPlayer);

	/// <summary>
	/// ������� ����������� ������� �� �������� ���
	/// </summary>
	/// <param name="deck - ����� ������ �������"></param>
	/// <param name="ifPlayer - ������ ����� ������������� ����"></param>
	void SetShip(int deck, bool ifPlayer);

	/// <summary>
	/// ������� ����������� ������� �� �������� ���
	/// </summary>
	/// <param name="ifPlayer - ������ ����� ������������� ����"></param>
	void SetFleet(bool ifPlayer);

};