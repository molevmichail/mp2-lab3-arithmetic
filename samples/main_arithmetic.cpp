// Реализация пользовательского приложения
#include <iostream>
#include <string>
#include "arithmetic.h"
#include "stack.h"
using namespace std;

int main()
{   
    cout << "Введите выражение: ";
    string a;
    cin >> a;
    Tlexeme A(a);
    if (!A.Check_correct())
    { 
           cout << "Выражение введенно НЕ верно\n";
    }
    else
    { 
           cout<<"Выражение введенно верно\\n";
           cout<< "\n Польская запись: "<< A.Pol();
           cout<<"\n Результат вычислений: "<<A.Calculation()<<endl;
    }
  
}
