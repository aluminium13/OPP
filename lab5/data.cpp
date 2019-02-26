#include "data.hpp"

using namespace std;
//enter program name, for example ${workspaceFolder}/a.exe
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void printVector(Vector vec)
{
    cout << "( ";
    for (int i = 0; i < vec.size; i++)
    {
        cout << vec.elements[i] << " ";
    }
    cout << ")" << endl;
}

void Vector::fill(int with)
{
#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        elements[i] = with;
    }
}

void Vector::sort()
{
    int i, j;
    bool swapped;
    for (i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (j = 0; j < size - i - 1; j++)
        {
            if (elements[j] > elements[j + 1])
            {
                swap(&elements[j], &elements[j + 1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    }
}

int VectorMin(Vector const &other)
{
    int min = other.elements[0];
    for (int i = 0; i < N; i++)
    {
        if (other.elements[i] < min)
        {
            min = other.elements[i];
        }
    }
    return min;
}

int Vector::operator*(Vector const &other)
{
    int result, i;
#pragma omp parallel for
    for (i = 0; i < size; i++)
    {
        result += elements[i] * other.elements[i];
    }
    return result;
}

Vector Vector::operator*(int const &other)
{
    int *result = new int[size];
#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        result[i] = elements[i] * other;
    }
    return Vector(result, size);
}

Vector Vector::operator+(Vector const &other)
{
    int *result = new int[size];
#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        result[i] = elements[i] + other.elements[i];
    }
    return Vector(result, size);
}

Vector Vector::operator*(Matrix const &other)
{
    int *result = new int[size];
    int **otherData = other.elements;
#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = 0; j < size; j++)
        {
            sum += otherData[i][j] * elements[i];
        }
        result[i] = sum;
    }
    return Vector(result, size);
}

void printMatrix(Matrix m)
{
    for (int i = 0; i < m.size; i++)
    {
        cout << "( ";
        for (int j = 0; j < m.size; j++)
        {
            cout << m.elements[i][j] << " ";
        }
        cout << ")" << endl;
    }
}

void Matrix::fill(int with)
{
#pragma omp parallel for
    for (int i = 0; i < size; i++)
    {
#pragma omp parallel for
        for (int j = 0; j < size; j++)
        {
            elements[i][j] = with;
        }
    }
}


void Matrix::trans()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            elements[i][j] = elements[j][i];
        }
    }
}

Matrix Matrix::operator*(Matrix const &other)
{
    int **result = new int *[size];
    for (int l = 0; l < size; l++)
    {
        result[l] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int sum = 0;
            for (int k = 0; k < size; k++)
            {
                sum += elements[i][k] * other.elements[k][j];
            }
            result[i][j] = sum;
        }
    }
    return Matrix(result, size);
}

Matrix Matrix::operator+(Matrix const &other)
{
    int **result = new int *[size];
    for (int l = 0; l < size; l++)
    {
        result[l] = new int[size];
    }
#pragma opm parallel for
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            result[i][j] = elements[i][j] + other.elements[i][j];
        }
    }
    return Matrix(result, size);
}

void Function1()
{
#pragma omp critical
    {
        cout << "T1 started...\n";
    }
    Vector B(N), C(N);
    Matrix MA(N), MD(N);
    B.fill(1);
    C.fill(1);
    MA.fill(1);
    MD.fill(1);
    Vector A = B * VectorMin(C) * (MA * MD + MD);
#pragma omp critical
    {
//        printVector(A);
        cout << "T1 finished...\n";
    }
}

void Function2()
{
#pragma omp critical
    {
        cout << "T2 started...\n";
    }
    Matrix MA(N), MZ(N), MB(N);
    MA.fill(2);
    MZ.fill(2);
    MB.fill(2);
    MB.trans();
    Matrix MF = MA * (MA * MZ) + MB;
#pragma omp critical
    {
//        printMatrix(MF);
        cout << "T3 finished...\n";
    }
}

void Function3()
{
#pragma omp critical
    {
        cout << "T3 started...\n";
    }
    Vector R(N), S(N);
    R.fill(3);
    S.fill(3);
    Matrix MT(N), MP(N);
    MT.fill(3);
    MP.fill(3);
    Vector RS = R + S;
    RS.sort();
    Vector O = RS * (MT * MP);
#pragma omp critical
    {
//        printVector(O);
        cout << "T3 finished...\n";
    }
}