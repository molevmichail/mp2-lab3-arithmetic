// объявление функций и классов для вычисления арифметических выражений
#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__
#include <iostream>
#include <string>
using namespace std;

class Tlexeme
{
protected:
	int Size;
	string* mLexeme; //массив строк разбитых на лексемы
	int* priority;   //приоритет лексем
	int Flag = -1;   //флаг обработки
public:
	//конструкторы и деструкторы
	Tlexeme(string a = "0");
	~Tlexeme();
	//операции
	void Fill(string a); //загрузить новую строку
	int Check_correct(); //проверка на корректность введения записи
	string Pol(); //вернуть польскую строку
	double Calculation(int x = 0); //вычисление
	//перегрузка операций ввода/вывода
	friend istream& operator>>(istream& in, Tlexeme& l)
	{
		in >> l.mLexeme[0];
		string a = l.mLexeme[0];
		l.Size = (l.mLexeme[0]).length();
		l.mLexeme = new string[l.Size];
		l.priority = new int[l.Size];
		l.mLexeme[0] = a;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Tlexeme& l)
	{
		for (int i = 0; i < l.Size; i++)
		{
			out << l.mLexeme[i] << ' ';
		}
		cout << endl;
		/*for (int i = 0; i < l.Size; i++)
		{ out << l.priority[i] << ' ';}
		cout << endl;*/
		return out;
	}
private:
	//закрытые функции
	void Divide(); //разбить на лексемы
	void Pol_1(); //конвертировать в польскую запись
	int Check_brack();//проверка скобок
	int Check_sign(); //проверка знаков операций
	int Check_point(); //проверка точек в дробных числах
	int Check_variable();//проверка переменных
	int Check_function();//проверка функции
};

#endif
