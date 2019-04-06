//1.	�������� ���������, ������� ���� �������� ���������� � ������ � � ������� ������ ������.������ � ������� ����� ������� 
//���������� ������������ � ������� ��������.��� ����� ����� :
//1 ) ������� ���������, ������� ����� ��������� ���������� � ������� ������(������� 4 - ����);
//2 ) ������� ���������, ������� ����� ��������� ���������� � ������(������� 5 - �� �����) � ����� �� ���� ����� ������ ���� 
//��������� ������� .
//3 ) ������� ������� 3 �������(����������) ��������� ������ � ��������� �� �����������.
//4 ) � ��������� ������ �������� ��������, ���� �� ������������ ��������� ������, ���� ��� �����������, �� ������ ��������, 
//����� ������ ������������� ������ ��������� � �������� ���������� � ������ ������.����� ������ ��������  ���������� �� ���������
//�������, ���� ���������� �� �������� ���������� � ������� ������ ������. � ��� ��� ���� �����.
//5 ) ����� ������� ��������� ��� ������ ������, ������� �� ������� � �������� ���������.��������(# define USA 1 i # define UA 2
//� �.�.) .
//6 ) ����� ���������� ��� ��������� ������ � �������.��������� ������ ����� ������� �������� ��������������� ������.
//� ��������� ������� ����� ������ ����������.��������:
//# define USA 1
//# define UA 2
//# define COUNTRY UA
//# define CAPITAL
//
//������� � ������� :
//1. ��� ����������� �������� ������������ ��������� # define
//2. ����� ��������� ���������� ��������� ��� ��� ������������ ��������� # ifdef - # endif; # ifndef - # endif
//3. ��� ����������� ����� ����, ������� ������ ��������������� ��� �� ������ ������������ - #if #else #endif
//4. ����������� ����� ����������(headers) ��������� � ������� �������� ���, ����� �������� ������������� ����������� 
//����� ��������� � ������ �����.

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
		cout << endl << "�������: " << name << " " << population << " " << district << " " << area << endl;
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
		cout << "\n ���� DataBase.txt �� ������! \n\n";
	}
	else
	{
		while (!fin.eof())
		{
			fin >> elem.name >> elem.population >> elem.budget >> elem.area >> elem.capital.name >> elem.capital.population >>
				elem.capital.district >> elem.capital.area;
			add(country, elem);
		}

		cout << "������� ������������ ������: KAZ, RUS, BEL -> ";

		char coutry[4];
		cin >> coutry;

		if (strcmp(coutry, "KAZ") == 0) country[KAZ].print();
		if (strcmp(coutry, "RUS") == 0) country[RUS].print();
		if (strcmp(coutry, "BEL") == 0) country[BEL].print();

		cout << endl;
	}

	system("pause");
}