#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

#include "AdmiralList.h"
//
//void Admiral::SetName()
//{
//	char ch[100];
//	cout << "Admiral, please, enter your name: ";
//	cin.ignore();
//	cin.getline(ch, 100);
//	name = new char[strlen(ch) + 1];
//	strcpy(name, ch);
//}
//
//void Admiral::SetScore()
//{
//
//}
//
//void Admiral::SetBattles()
//{
//
//}

void Admiral::Print()
{
	cout << setw(20) << name << setw(7) << (score>>9)
		<< setw(12) << (score & 511) << setw(9) << battles <<  endl;
}

void AdmiralList::PrintTable()
{
	cout << setw(3) << "N" << setw(20) << "Admiral name" << setw(7) << "Score" 
		<< setw(12) << "Best score" << setw(9) << "Battles" << endl;
}

void AdmiralList::PrintList()
{
	for (size_t i = 0; i < sizeList; i++)
	{
		cout <<setw(3) <<i + 1;
		admiral[i].Print();
	}
}

//void AdmiralList::AddAdmiral()
//{
//	Admiral* temp = new Admiral[sizeList + 1];
//	for (size_t i = 0; i < sizeList; i++)
//	{
//		temp[i] = admiral[i];
//	}
//	delete[] admiral;
//
//	//temp[sizeList].SetName();
//	//temp[sizeList].SetScore();
//	//temp[sizeList].battles=1; //розділити bit-операціями на всього і win
//	
//	admiral = temp;
//	sizeList++;
//}

void AdmiralList::SaveList(ofstream& out)
{
	for (size_t i = 0; i < sizeList; i++)
	{
		out << admiral[i].name << endl;
		out << admiral[i].score << endl;
		out << admiral[i].battles << endl;
	}
}

void AdmiralList::SetList(ifstream& in)
{
	char buff[100];
	while (in.getline(buff, 100))
	{
		Admiral* temp = new Admiral[sizeList + 1];
		for (size_t i = 0; i < sizeList; i++)
		{
			temp[i] = admiral[i];
		}
		delete[] admiral;

		temp[sizeList].name = new char[strlen(buff) + 1];
		strcpy(temp[sizeList].name, buff);
		in >> temp[sizeList].score;
		in >> temp[sizeList].battles;

		in.ignore();
		admiral = temp;
		sizeList++;
	}
}

void AdmiralList::Sorting()
{
	int pos = 0;
	while (pos < sizeList)
	{
		if (pos == 0) pos++;
		if (admiral[pos].score  < admiral[pos-1].score) pos++;
		else {swap(admiral[pos], admiral[pos - 1]); pos--; }
	}
}

bool AdmiralList::IfFirst(int& pos,char buff[100])
{
	for (size_t i = 0; i < sizeList; i++)
	{
		if (_stricmp(buff, admiral[i].name)==0)
		{
			pos = i;
			return true;
		}
	}
	return false;
}

void AdmiralList::Show()
{
	system("cls");

	in.open("Admiral list.txt");
	if (in.is_open())
	{
		SetList(in);
		Sorting();
		PrintTable();
		PrintList();
	}
	else
	{
		std::cout << "\tSORRY, FILE NOT FOUND\n";
	}
	in.close();
	_getch();
}

void  AdmiralList::Win(Aquatorium& playerArea)
{
	//ввести ім"я
	char buff[100];
	cout <<endl<<"\t\tAdmiral, please, enter your name: ";
	//cin.ignore();
	cin.getline(buff, 100);

	in.open("Admiral list.txt");
	if (in.is_open())
	{
		SetList(in);
		int pos = 0;
		if (IfFirst(pos, buff))
		{
			int bestScore = (admiral[pos].score & 511);
			admiral[pos].score >>= 9;
			admiral[pos].score += playerArea.score;
			admiral[pos].score <<= 9;
			if (bestScore < playerArea.score) (admiral[pos].score |= playerArea.score);
			else (admiral[pos].score |= bestScore);

			admiral[pos].battles++;
		}
		else
		{
			Admiral* temp = new Admiral[sizeList + 1];
			for (size_t i = 0; i < sizeList; i++)
			{
				temp[i] = admiral[i];
			}
			delete[] admiral;

			temp[sizeList].name = new char[strlen(buff) + 1];
			strcpy(temp[sizeList].name, buff);

			temp[sizeList].score += playerArea.score;
			temp[sizeList].score <<= 9;
			temp[sizeList].score |= playerArea.score;

			temp[sizeList].battles++;
			
			admiral = temp;
			sizeList++;
		}
	}
	else
	{
		Admiral* admiral = new Admiral[sizeList+1];
		admiral[sizeList].name = new char[strlen(buff) + 1];
		strcpy(admiral[sizeList].name, buff);

		admiral[sizeList].score += playerArea.score;
		admiral[sizeList].score <<= 9;
		admiral[sizeList].score |= playerArea.score;

		admiral[sizeList].battles++;

		sizeList++;
	}
	in.close();

	out.open("Admiral list.txt");
	SaveList(out);
	out.close();
}