// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

#ifndef __TSTACK_H__
#define __TSTACK_H__
#define STACK_SIZE (1000)
#include <vector>

template <class StackType>
class TStack
{
protected:
    int Head;
    int Size;
    StackType* mStack;
    void Overcrowded();       //проверка на переполнение
public:
    //конструкторы и деструкторы
    TStack();
    ~TStack();
    //операции со стеком
    void Push(StackType i);   //вставка элемента
    StackType Pop();          //извлечение элемента
    StackType Top();          //просмотр верхнего элемента (без удаления)
    bool Empty();             //проверка на пустоту
    int Count();              //получение количества элементов в стеке
    void Clear();             //очистка стека
};

//реализация функций класса вектора
//конструкторы и деструкторы

template <class StackType>
TStack<StackType>::TStack()
{
    Head = 0;
    Size = STACK_SIZE;
    mStack = new StackType[Size];
}
template <class StackType>
TStack<StackType>::~TStack()
{
    delete[] mStack;
}
//операции со стеком
template <class StackType> //вставка элемента
void TStack<StackType>::Push(StackType i)
{
    Overcrowded();
    mStack[Head] = i;
    Head++;
}
template <class StackType> //извлечение элемента
StackType TStack<StackType>::Pop()
{
    if (!Empty())
    {
        Head--; return mStack[Head];
    }
    else { throw 1; }
}
template <class StackType> //просмотр верхнего элемента (без удаления)
StackType TStack<StackType>::Top()
{
    if (!Empty()) { return mStack[Head - 1]; }
    else { throw 1; }
}
template <class StackType> //проверка на пустоту
bool TStack<StackType>::Empty()
{
    if (Head == 0) { return 1; }
    else { return 0; }
}
template <class StackType> //получение количества элементов в стеке
int TStack<StackType>::Count()
{
    return Head;
}
template <class StackType> //очистка стека
void TStack<StackType>::Clear()
{
    Head = 0;
}
template <class StackType> //проверка на переполнение
void TStack<StackType>::Overcrowded()
{
    if (Head == Size)
    {
        StackType* mStack1;
        mStack1 = mStack;
        Size = Size * 2;
        mStack = new StackType[Size];
        for (int i = 0; i < Size / 2; i++)
        {
            mStack[i] = mStack1[i];
        }
    }
}
#endif
    
