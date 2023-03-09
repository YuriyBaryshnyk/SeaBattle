#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

#include "Aquatorium.h"

using namespace std;

/// <summary>
/// ��������� ����� ������
/// </summary>
struct Admiral
{
	char* name = nullptr;
	int score=0;
	int battles=0;

	/*void SetName();

	void SetScore();

	void SetBattles();*/

	/// <summary>
	/// ������� ��������� � ������� ��������� ������
	/// </summary>
	void Print();

};

/// <summary>
/// ��������� ������ �������
/// </summary>
struct AdmiralList
{
	/// <summary>
	/// ����� ������ �������
	/// </summary>
	int sizeList=0;
	Admiral* admiral=nullptr;

	ofstream out;
	ifstream in;

	/// <summary>
	/// ������� ������ � ������� ��������� ������� 
	/// </summary>
	void PrintTable();

	/// <summary>
	/// ������� ������ ������ ������� � �������
	/// </summary>
	void PrintList();

	//void AddAdmiral();

	/// <summary>
	/// ������� ���������� ������ ������� � ����
	/// </summary>
	/// <param name="out"></param>
	void SaveList(ofstream& out);

	/// <summary>
	/// ������� ��������� ������ ������� � �����
	/// </summary>
	/// <param name="in"></param>
	void SetList(ifstream& in);

	/// <summary>
	/// ���������� �����
	/// </summary>
	void Sorting();

	/// <summary>
	/// ������� �������� �� ��� ��� ������� � ����� ������
	/// </summary>
	/// <param name="pos - ��������� �� ����� ������� � ����� ��������"></param>
	/// <param name="buff - �����-�����"></param>
	/// <returns></returns>
	bool IfFirst(int& pos, char buff[100]);

	/// <summary>
	/// ������� ����������� �� ������ ������ � �������
	/// </summary>
	void Show();

	/// <summary>
	/// ������� ������������� ������
	/// </summary>
	/// <param name="playerArea - ��������� �������� ���� ������"></param>
	void Win(Aquatorium& playerArea);
};
