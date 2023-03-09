#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

#include "Aquatorium.h"

using namespace std;

/// <summary>
/// структура даних гравця
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
	/// функція виведення в консоль параметрів гравця
	/// </summary>
	void Print();

};

/// <summary>
/// структура списку гравців
/// </summary>
struct AdmiralList
{
	/// <summary>
	/// розмір списку гравців
	/// </summary>
	int sizeList=0;
	Admiral* admiral=nullptr;

	ofstream out;
	ifstream in;

	/// <summary>
	/// функція виводу в консоль заголовку таблиці 
	/// </summary>
	void PrintTable();

	/// <summary>
	/// функція виводу списку гравців в консоль
	/// </summary>
	void PrintList();

	//void AddAdmiral();

	/// <summary>
	/// функція збереження саиску гравців у файл
	/// </summary>
	/// <param name="out"></param>
	void SaveList(ofstream& out);

	/// <summary>
	/// функція копіювання списку гравців з файлу
	/// </summary>
	/// <param name="in"></param>
	void SetList(ifstream& in);

	/// <summary>
	/// сортування гнома
	/// </summary>
	void Sorting();

	/// <summary>
	/// функція перевірки чи був вже гравець з таким іменем
	/// </summary>
	/// <param name="pos - посилання на змінну позиції у масиві структур"></param>
	/// <param name="buff - масив-рядок"></param>
	/// <returns></returns>
	bool IfFirst(int& pos, char buff[100]);

	/// <summary>
	/// функція редагування та виводу списку в консоль
	/// </summary>
	void Show();

	/// <summary>
	/// функція ідентифікації гравця
	/// </summary>
	/// <param name="playerArea - структура ігрового поля гравця"></param>
	void Win(Aquatorium& playerArea);
};
