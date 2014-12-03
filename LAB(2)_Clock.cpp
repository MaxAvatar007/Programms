#include <iostream>
#include <locale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int h, m; // h - часы m - минуты
	do
	{
		cout << "ведите целое кол-во часов: ";
		cin >> h;
		if (cin.fail()) // если пользователь ввЄл символ, то программа определит cin.fail() как true
		{
			cin.clear(); // отменяет состояние ошибки у функции
			cin.ignore(std::numeric_limits<int>::max(), '\n'); // извлечь и отменить все символы в потоке, вплоть до '\n' или до 'end of stream'
		}
		if ((h < 0) || (23 < h)) cout << "Неправильно введены часы! Введите 0 <= H < 24" << endl;
	} while ((h < 0) || (23 < h)); //цикл провер¤ет правильность ввода часов
	do
	{
		cout << "ведите целое кол-во минут: ";
		cin >> m;
		if (cin.fail())
		{
			cin.clear(); // отмен¤ет состояние ошибки у функции
			cin.ignore(std::numeric_limits<int>::max(), '\n'); // извлечь и отменить все символы в потоке, вплоть до '\n' или до 'end of stream'
		}
		if ((m < 0) || (59 < m)) cout << "Неправильно введены минуты! Введите 0 <= M < 60" << endl;
	} while ((m < 0) || (59 < m)); //цикл провер¤ет правильность ввода минут
	int c = h; //переменная — понадобится для определения времени суток
	if (12 < h) h = h - 12; // ѕереводим время из 24 часового формата в 12 часовой
	if ((0 == h) && (0 == m)) cout << "полночь ";
	else if ((12 == h) && (0 == m)) cout << "полдень ";
	else
	{
		cout << h << " ";
		cout << "час";
		if (h == 1) cout << "";
		else if ((1 < h) && (h < 5)) cout << "а";
		else cout << "ов";
		int d = m; // переменная d будет отбрасывать дес¤тки в минутах
		int k = 0; // переменная к будет явл¤еться целым частным, полученным из деления кол-ва минут на 10
		if (9 < m)
		{
			k = m / 10;
			d = m - 10 * k;
		}
		if (0 != m)
		{
			cout << " " << m << " минут";
			if ((1 < d) && (d < 5) && (k != 1)) cout << "ы";
			else if ((d == 1) && (k != 1)) cout << "а";
		}
		if ((h != 0) && (h != 12))
		{
			cout << " ";
			if ((0 < c) && (c < 5)) cout << "ночи";
			if ((5 <= c) && (c < 12)) cout << "утра";
			if ((12 < c) && (c < 18)) cout << "дня";
			if ((18 <= c) && (c <= 23)) cout << "вечера";
		}
		else if ((h == 12) && (0 < m)) cout << " дня ";
		if (0 == m) cout << " ровно";
	}
	cout << endl;
	return 0;
}
