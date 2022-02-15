// реализация функций и классов для вычисления арифметических выражений
#include "..\include\arithmetic.h"
#include "..\include\stack.h"
#include <cmath>
#include <cstdlib>

// Определение приоритета опирации
int PR(string a)
{  if(a=="(") {return(0);}
   if(a=="+") {return(1);}
   if(a=="-") {return(1);}
   if(a=="*") {return(2);}
   if(a=="/") {return(2);}
}
// Конвертировать строку в число
double Convert(string a)
{  string::size_type sz = 0;  
   string a1 = a;
   double res = stoll (a1,&sz,0);
   a1 = a1.substr(sz);
   if (!a1.empty())
   { a1 = a1.substr(1);
     res = res + (stoll(a1, NULL)) / (pow(10, a1.length()));
   }
   return res;
}


//Конструкторы и деструкторы    
Tlexeme::Tlexeme(string a1)
{ Size = a1.length();
  TStack <char> S1;
  //разбить на лексемы
  string a = a1];
  int j = 0;
  string S1 = "";
  string* mLexeme1 = new string[Size];
  int* priority1 = new int[Size];

  for (int i = 0; i < Size; i++)
  { //знаки операций 
      if ((a[i] == '+') || (a[i] == '*') || (a[i] == '/') || (a[i] == '-') || (a[i] == '^'))
      {
          if (S1 != "") { mLexeme1[j] = S1; priority1[j] = 2; j++; S1 = ""; }
          mLexeme1[j] = a[i];
          priority1[j] = 1; j++;
      }
              else //скобки
          {
              if ((a[i] == '(') || (a[i] == ')'))
              {
                  if (S1 != "") { mLexeme1[j] = S1; priority1[j] = 2; j++; S1 = ""; }
                  mLexeme1[j] = a[i];
                  priority1[j] = 4; j++;
              }
              else //операнды числа
                      {
                          if ((a[i] >= '0') && (a[i] <= '9'))
                          {
                              S1 = S1 + a[i];
                          }
                          else { Flag = 0; } //ошибка не распознаный символ
                      }
                  }
              }
    
  if (S1 != "") { mLexeme1[j] = S1; priority1[j] = 2; S1 = ""; j++; }
  Size = j;
  mLexeme = new string[Size];
  priority = new int[Size];
  for (int i = 0; i < Size; i++)
  {
      mLexeme[i] = mLexeme1[i];
      priority[i] = priority1[i];
  }
}
Tlexeme::~Tlexeme()
{ delete[] mLexeme;
  delete[] priority;
}
//Операции
int Tlexeme::Check_correct()
{  int a = 1, b = 1, c = 1;
   a = Check_brack(); 
   if (a != 1) { cout << "\tInput error: brackets are entered incorrectly" << endl;  b = 0; }
   a = Check_sign();
   if (a != 1) { cout << "\tInput error: signs of operations are entered incorrectly in place " << a << endl; c = 0}
  return  b + c;
}

int Tlexeme::Check_brack()
{ //что-то стоит между двух скобок одинакового типа
  int a = 1, i = 0;
  while ((i < Size) && (a == 1))
  { if ((mLexeme[i]=="(")&&(mLexeme[i + 1]!="(")&&(mLexeme[i + 2]=="(")) { a = 0; } 
    if ((mLexeme[i] == ")") && (mLexeme[i + 1] != ")") && (mLexeme[i + 2] == ")")) { a = 0; }
    i++;}
  if (a == 1) //проверка на правильность растановки скобок
  { TStack <int> S1; i=0;
    while ((i < Size) && (a == 1))
    { if(priority[i]==4)
      { if(mLexeme[i]=="("){ S1.Push(1); }
        else 
        { if(S1.Empty()){a=0;}
          else {S1.Pop();}
        } 
      } i++;
    }
    if(!(S1.Empty())){a=0;} 
  }
  
  return a;
}

int Tlexeme::Check_sign() 
{ int a=1, i = 1;
  if (priority[0] == 1){a = 0; } //первый символ в выражении знак операции
  while ((i<Size)&&(a == 1))
  { if(priority[i]== 1)
    { if((priority[i+1] == 1)||(mLexeme[i-1]=="(")||(mLexeme[i + 1] == ")")) { a = 0; }
      // два знака подряд, знак после открывающейся скобки, знак перед закрывающейся скобкой
    } i++;
  }
  return a;
}
]
string Tlexeme::Pol()
{ int Nbrack = 0;
  for (int i = 0; i < Size; i++)
 {
    if (priority[i] == 4) { Nbrack++; };
    if (priority[i] == 5) { priority[i] = 1; };
 }
string* mLexeme1; mLexeme1 = mLexeme; mLexeme = new string[Size - Nbrack];
int* priority1; priority1 = priority; priority = new int[Size - Nbrack];
TStack <int> S1;
int j = 0;
for (int i = 0; i < Size; i++)
{
    if ((priority1[i] == 2) || (priority1[i] == 3))
    {
        mLexeme[j] = mLexeme1[i];
        priority[j] = priority1[i];
        j++;
    }
    else
    {
        if (priority1[i] == 1)
        {
            if (S1.Empty()) { S1.Push(i); }
            else
            {
                int pr1 = PR(mLexeme1[i]), pr2 = PR(mLexeme1[S1.Top()]);
                if (pr1 > pr2) { S1.Push(i); }
                else
                {
                    while ((pr1 <= pr2) && (!S1.Empty()))
                    {
                        int q = S1.Pop();
                        mLexeme[j] = mLexeme1[q];
                        priority[j] = priority1[q];
                        j++;
                        if (!S1.Empty()) { pr2 = PR(mLexeme1[S1.Top()]); }
                    } S1.Push(i);
                }
            }
        }
        else
        {
            if (mLexeme1[i] == "(") { S1.Push(i); }
            else
            {
                if (mLexeme1[i] == ")")
                {
                    int w = 0;
                    while ((!S1.Empty()) && (w == 0))
                    {
                        int q = S1.Top();
                        if (mLexeme1[q] == "(") { w = 1; }
                        else
                        {
                            q = S1.Pop();
                            mLexeme[j] = mLexeme1[q];
                            priority[j] = priority1[q];
                            j++;
                        }
                    } S1.Pop();
                }
            }
        }
    }
}
while (!S1.Empty())
{
    int q = S1.Pop(); mLexeme[j] = mLexeme1[q]; priority[j] = priority1[q]; j++;
}
Size = Size - Nbrack;
}
    string a;
    for (int i = 0; i < Size; i++)
    { a = a + mLexeme[i] + " ";}
    return a;
  
}

double Tlexeme::Calculation(int x)
{ if(Flag!=2){Pol_1(); }
  TStack <double> S1;
  int s = Size, j=0;
  double* M1 = new double[Size];;
  string* M2 = new string[Size];
  for (int i = 0; i < Size; i++)
  { if (priority[i]==2){ S1.Push(Convert(mLexeme[i])); }
   
    if (priority[i]==1)
    { double x,y;
      x=S1.Pop();
      if(mLexeme[i]=="sin"){S1.Push(sin(x));}
      else
      { y=S1.Pop();
        if(mLexeme[i]=="+"){ S1.Push(x+y); }
        if(mLexeme[i]=="-"){ S1.Push(y-x); }
        if(mLexeme[i]=="*"){ S1.Push(x*y); }
        if(mLexeme[i]=="/"){ S1.Push(y/x); }
        if(mLexeme[i]=="^"){ S1.Push(pow(y,x)); }
      }
    }
  }
    return S1.Pop();
}
