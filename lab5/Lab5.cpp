/* ==========================================
Основи Паралельного програмування
Лабораторна робота №5
Процеси в OpenMP
Варіант 10
F1: A = B*MIN(C) *(MA*MD+MD)
F2: MK = MA*(MA*MZ) + TRANS(MB)
F3: O = SORT(R + S)*(MT*MP)
Кузьменко Олександра Вікторівна ІО-62
дата: 18.11.2018
==========================================*/

#include <iostream>
#include "data.hpp"
#include "omp.h"
#include <stdio.h>

using namespace std;
const int N = 1000;

int main()
{
    cout << "Main thread started..." << endl;

#pragma omp parallel sections
    {
#pragma omp section
        {
            Function1();
        }
#pragma omp section
        {
            Function2();
        }
#pragma omp section
        {
            Function3();
        }
    }

    cout << "Main thread fininshed..." << endl;
    return 0;
}