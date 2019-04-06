//1.	Написать программу, которая буду выводить информацию о стране и о столице данной страны.Страна о которой нужно вывести 
//информацию определяется с помощью констант.Для этого нужно :
//1 ) Создать структуру, которая будет содержать информацию о столице страны(минимум 4 - поля);
//2 ) Создать структуру, которая будет содержать информацию о стране(минимум 5 - ть полей) и одним из этих полей должна быть 
//структура столица .
//3 ) Создать минимум 3 объекта(переменные) структуры страны и заполнить их информацией.
//4 ) В программе должно делаться проверка, есть ли определенная константе страна, если она установлена, то делать проверку, 
//какой стране соответствует данная константа и выводить информацию о данной стране.Затем делать проверку  определена ли константа
//столица, если определена то выводить информацию о столице данной страны. И так для всех стран.
//5 ) Нужно создать константу для каждой страны, которые мы описали в объектах структуры.Например(# define USA 1 i # define UA 2
//и т.д.) .
//6 ) Нужно определить две константы страна и столица.Константе страна нужно придать значение соответствующей страны.
//А константу столица нужно просто определить.Например:
//# define USA 1
//# define UA 2
//# define COUNTRY UA
//# define CAPITAL
//
//Условия к задачам :
//1. Для определения констант использовать директиву # define
//2. Чтобы проверить определена константа или нет использовать директивы # ifdef - # endif; # ifndef - # endif
//3. Для определения части кода, которая должна компилироваться или не должна использовать - #if #else #endif
//4. Собственные файлы заголовков(headers) описывать с помощью директив так, чтобы избежать многократного подключение 
//файла заголовка в другие файлы.

#include<iostream>
#include<locale.h>
#include<cstdlib>
#include<fstream>
#include<ctime>
using namespace std;

#define KAZ 0
#define RUS 2
#define BEL 1
int cur_size = 0;
int buf_size = 0;

struct Astana
{
	char name[30];
	int population;
	int district;
	int area;

	void print()
	{
		cout << endl << "Столица: " << name << " " << population << " " << district << " " << area << endl;
	}
};

struct Country
{
	char name[30];
	int population;
	int budget;
	int area;
	Astana capital;
	void print()
	{
		cout << endl << name << " " << population << " " << budget << " " << area;
		capital.print();
	}
};


template<typename T>
void add(T *&country, T elem)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		country = new T[buf_size];
	}
	else
	{
		if (cur_size == buf_size)
		{
			buf_size *= 2;
			T *tmp = new T[buf_size];
			for (int i = 0; i < cur_size; i++)
			{
				tmp[i] = country[i];
			}
			delete[] country;
			country = tmp;
		}
	}
	country[cur_size++] = elem;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	Country *country = nullptr;
	Country elem;
	ifstream fin("DataBase.txt");
	
	if (!fin)
	{
		cout << "\n Файл DataBase.txt не найден! \n\n";
	}
	else
	{
		while (!fin.eof())
		{
			fin >> elem.name >> elem.population >> elem.budget >> elem.area >> elem.capital.name >> elem.capital.population >>
				elem.capital.district >> elem.capital.area;
			add(country, elem);
		}

		cout << "Введите аббревиатуру страны: KAZ, RUS, BEL -> ";

		char coutry[4];
		cin >> coutry;

		if (strcmp(coutry, "KAZ") == 0) country[KAZ].print();
		if (strcmp(coutry, "RUS") == 0) country[RUS].print();
		if (strcmp(coutry, "BEL") == 0) country[BEL].print();

		cout << endl;
	}

	system("pause");
}