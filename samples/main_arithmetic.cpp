// реализация пользовательского приложения


#include <iostream>
#include <string>
#include "arithmetic.h"
#include "stack.h"
using namespace std;
void menu()
{
    cout << "\n\t1. Checking the expression for correctness\n\t2. Translation of the expression into the Polish notation \n\t3. Calculation of the expression \n\t0. Enter a new expression\n\tInput:";
}
int main()
{
    int  entry1 = 1, entry2 = 1;
    while (entry1 != 0)
    {
        cout << "CALCULATING ARITHMETIC EXPRESSIONS:" << endl << endl;
        cout << "\tEnter the expression:\n\tInput: ";
        Tlexeme A;
        cin >> A; entry2 = 1;
        while (entry2 != 0)
        {
            menu();
            cin >> entry2;
            system("cls"); cout << "CALCULATING ARITHMETIC EXPRESSIONS:" << endl << endl;
            cout << "\t" << A;
            if (entry2 == 0) { system("cls"); }
            else
            {
                if (!A.Check_correct())
                {
                    cout << "\t- The entered expression is incorrect.\n\tFurther calculations with it are impossible.Enter a new expression\n\n\tEnter the expression:\n\tInput: ";
                    string a1; cin >> a1; A.Fill(a1);
                    system("cls"); cout << "CALCULATING ARITHMETIC EXPRESSIONS:" << endl << endl;
                    cout << "\tEnter the expression:\n\tInput: " << A;
                }
                else
                {
                    switch (entry2)
                    {
                    case 1: cout << "\t- The entered expression is correct. Choose the following action\n";
                        break;
                    case 2: cout << "\tPolish notation of the expression: " << A.Pol();
                        break;
                    case 3: cout << "\t- Calculation result : " << A.Calculation() << endl; break;
                    }
                }
            }
        }

    }

}
