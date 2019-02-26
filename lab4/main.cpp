#include <iostream>
#include "data.hpp"
#include <windows.h>
#include <stdio.h>

const int N = 4;

int *Function1(int *B, int *C, int **MA, int **MD)
{
    B = multVecByNum(B, VectorMin(C));
    MA = MatrixSum(MatrixMult(MA, MD), MD);
    return multVecByMat(B, MA);
}

int **Function2(int **MA, int **MZ, int **MB)
{
    MA = MatrixMult(MA, MatrixMult(MA, MZ));
    Trans(MB);
    return MatrixSum(MA, MB);
}

int *Function3(int *R, int *S, int **MT, int **MD)
{
    R = VectorSum(R, S);
    VectorSort(R);
    MT = MatrixMult(MT, MD);
    return multVecByMat(R, MT);
}

void threadFunc1()
{
    cout << "thread 1 starting" << endl;
    int *B = Vector(N, 1);
    int *C = Vector(N, 1);
    int **MA = Matrix(N, 1);
    int **MD = Matrix(N, 1);
    Sleep(1000);
    int *A = Function1(B, C, MA, MD);
    cout << "Function 1 result:" << endl;
    printVector(A);
    cout << "thread 1 finished" << endl;
}

void threadFunc2()
{
    cout << "thread 2 starting" << endl;
    int **MA = Matrix(N, 2);
    int **MZ = Matrix(N, 2);
    int **MB = Matrix(N, 2);
    Sleep(700);
    int **MK = Function2(MA, MZ, MB);
    cout << "Function 2 result:" << endl;
    printMatrix(MK);
    cout << "thread 2 finished" << endl;
}

void threadFunc3()
{
    cout << "thread 3 starting" << endl;
    int *R = Vector(N, 3);
    int *S = Vector(N, 3);
    int **MT = Matrix(N, 3);
    int **MD = Matrix(N, 3);
    Sleep(1700);
    int *O = Function3(R, S, MT, MD);
    cout << "Function 3 result:" << endl;
    printVector(O);
    cout << "thread 3 finished" << endl;
}

int main()
{
    cout << "Lab4 main thread started..." << endl;
    DWORD Tid1, Tid2, Tid3;
    HANDLE hThread[3];

    hThread[0] = CreateThread(NULL, 300000000, (LPTHREAD_START_ROUTINE)threadFunc1, NULL, 0, &Tid1);
    hThread[1] = CreateThread(NULL, 300000000, (LPTHREAD_START_ROUTINE)threadFunc2, NULL, 0, &Tid2);
    hThread[2] = CreateThread(NULL, 300000000, (LPTHREAD_START_ROUTINE)threadFunc3, NULL, 0, &Tid3);

    SetThreadPriority(hThread[0], THREAD_BASE_PRIORITY_MIN);
    SetThreadPriority(hThread[1], THREAD_PRIORITY_BELOW_NORMAL);
    SetThreadPriority(hThread[2], THREAD_PRIORITY_ABOVE_NORMAL);

    WaitForMultipleObjects(3, hThread, TRUE, INFINITE);
    for (int i = 0; i < 3; i++)
    {
        CloseHandle(hThread[i]);
    }

    cout << "Lab4 main thread fininshed..." << endl;
    return 0;
}