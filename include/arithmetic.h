// Объявление функций и классов для вычисления арифметических выражений
#ifndef __ARITHMETIC_H__
#define __ARITHMETIC_H__
#include <iostream>
#include <string>
using namespace std;
class Tlexeme 
{protected:
  int Size;
  string* mLexeme; // массив строк разбитых на лексемы
  int* priority;   // приоритет лексем
 public:
  //Конструкторы и деструкторы
  Tlexeme(string a);
  ~Tlexeme();
  //Операции
  int Check_correct(); //Проверка на корректность введения записи
  string Pol(); // Вернуть польскую строку 
  double Calculation(int x=0); // Вычисление
  
 private:
  // Закрытые функции
  int Check_brack();//Проверка скобок
  int Check_sign(); //Проверка знаков операций
};

#endif
