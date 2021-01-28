﻿#include <iostream>
#include <cstdarg>
#include <cstdlib>
#include <windows.h>
#include <locale>// библиотека для кириллицы

using namespace std;

int Sum(int n, ...)//функция суммы
{
    va_list al; //список аргументов, переданных через многоточие
    va_start(al, n);//va_start() - инициализация списка

    int r = 0;

    for (int i = 0; i < n / 2; i++) //  цикл для нахождения суммы     S=a1*a2+a3*a4+...
        r += va_arg(al, int) * va_arg(al, int); //va_arg() - получение очередного элемента указанного типа.

    va_end(al);  /* выполнение корректного выхода */
    return r;

}

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Вычисление суммы для 5 параметров" << endl << Sum(5, 1, 2, 3, 4, 5) << endl;
    cout << "Вычисление суммы для 10 параметров" << endl << Sum(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
    cout << "Вычисление суммы для 12 параметров" << endl << Sum(12, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12) << endl;
    system("pause");
    return 0;
}