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

int Vector::operator*(Vector const &other)
{
    int result, i;
    for (i = 0; i < size; i++)
    {
        result += elements[i] * other.elements[i];
    }
    return result;
}

Vector Vector::operator*(int const &other)
{
    int *result = new int[size];
    for (int i = 0; i < size; i++)
    {
        result[i] = elements[i] * other;
    }
    return Vector(result, size);
}

Vector Vector::operator+(Vector const &other)
{
    int *result = new int[size];
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
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            elements[i][j] = with;
        }
    }
}

void Matrix::sort()
{   
    int aux;
    for (int i = size-1; i >= 1; i--) {  
        for ( int j=0; j < i ; j++) {
            if(elements[i][j] > elements[i][j+1]) {
                aux = elements[i][j];
                elements[i][j] =elements[i][j+1];
                elements[i][j+1] = aux;
            }
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
    cout << "T1 started...\n";
    Vector B(N), A(N), C(N);
    Matrix MA(N), ME(N);
    A.fill(1);
    B.fill(1);
    C.fill(1);
    MA.fill(1);
    ME.fill(1);
    Vector AB = A + B;
    AB.sort();
    Vector D = (AB + C)* (MA * ME);
    printVector(D);
    cout << "T1 finished...\n";
}

void Function2()
{   
    cout << "T2 started...\n";
    Matrix MF(N), MG(N), MH(N);
    MF.fill(2);
    MG.fill(2);
    MH.fill(2);
    Matrix ML = (MF + MG*MH);
    ML.sort();
    printMatrix(ML);
    cout << "T3 finished...\n";
}

void Function3()
{ 
    cout << "T3 started...\n";
    Vector O(N), P(N);
    O.fill(3);
    P.fill(3);
    Matrix ML(N), MS(N);
    ML.fill(3);
    MS.fill(3);
    Vector T = (O + P) * (ML * MS);
    printVector(T);
    cout << "T3 finished...\n";
}