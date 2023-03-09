#pragma once

/// <summary>
/// функція виводить в консоль меню гри
/// </summary>
/// <param name="cursor"></param>
void PrintMenu(short cursor);

/// <summary>
/// функція забезпечує рух курсора в меню консолі
/// </summary>
/// <param name="cursor"></param>
/// <param name="ch"></param>
void ChangeMenu(short& cursor, char ch);

/// <summary>
/// функція меню гри
/// </summary>
void Menu();

