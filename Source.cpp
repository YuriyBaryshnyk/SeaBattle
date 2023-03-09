#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

#include "Menu.h"
#include "ScreenMode.h"


using namespace std;

int main()
{
	HelloScreenDinamic();
	
	Menu();

	system("cls");
	HelloScreen();
	cout <<endl<<endl<<endl<< "\t\t    GAME OVER\n\n\n";
	Sleep(2000);
	
	return 0;
}