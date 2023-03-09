#pragma once

/// <summary>
/// сируктура ігрового поля
/// </summary>
struct Aquatorium
{
	/// <summary>
	/// кількість пострілів
	/// </summary>
	int shoot=0;

	/// <summary>
	/// рахунок
	/// </summary>
	int score=0;
	
	/// <summary>
	/// масив туману війни ігрового поля
	/// </summary>
	int fogOfWar[10][10] = { 0 };

	/// <summary>
	/// масив ігрового поля
	/// </summary>
	int area[10][10] = { 0 };

	/// <summary>
	/// функція виводить в консоль ігрове поле
	/// </summary>
	/// <param name="arr - масив ігрового поля"></param>
	/// <param name="ifPlayer - логічна змінна автоматичного ходу"></param>
	void printArea(int arr[10][10], bool ifPlayer);

	/// <summary>
	/// функція розстановки корабля на ігровому полі
	/// </summary>
	/// <param name="deck - змінна розміру корабля"></param>
	/// <param name="ifPlayer - логічна змінна автоматичного ходу"></param>
	void SetShip(int deck, bool ifPlayer);

	/// <summary>
	/// функція розстановки кораблів на ігровому полі
	/// </summary>
	/// <param name="ifPlayer - логічна змінна автоматичного ходу"></param>
	void SetFleet(bool ifPlayer);

};