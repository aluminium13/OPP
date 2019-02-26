#include <iostream>
#include <algorithm>
#include "data.hpp"

using namespace std;

int *Vector(int n, int with)
{
    int *result = new int[n];
    for (int i = 0; i < n; i++)
    {
        result[i] = with;
    }
    return result;
}

int multVecByVec(int *a, int *b)
{
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        result += a[i] * b[i];
    }
    return result;
}

int VectorMin(int *vec)
{
    int min = vec[0];
    for (int i = 0; i < N; i++)
    {
        if (vec[i] < min)
        {
            min = vec[i];
        }
    }
    return min;
}

int *VectorSum(int *a, int *b)
{
    int *result = new int[N];
    for (int i = 0; i < N; i++)
    {
        result[i] = a[i] + b[i];
    }
    return result;
}

void VectorSort(int *vec)
{
    sort(vec, vec + N);
}

int *multVecByMat(int *a, int **b)
{
    int i, j;
    int *result = new int[N];
    for (i = 0; i < N; i++)
    {
        int sum = 0;
        for (j = 0; j < N; j++)
        {
            sum += a[i] * b[i][j];
        }
        result[i] = sum;
    }
    return result;
}

int *multVecByNum(int *a, int b)
{
    int *result = new int[N];
    for (int i = 0; i < N; i++)
    {
        result[i] = a[i] * b;
    }
    return result;
}

void printVector(int *vec)
{
    int i;
    cout << "( ";
    for (i = 0; i < N; i++)
    {
        cout << vec[i] << " ";
    }
    cout << ")" << endl;
}

int **Matrix(int n, int with)
{
    int i, j;
    int **result = new int *[n];
    for (i = 0; i < n; i++)
    {
        result[i] = new int[n];
        for (j = 0; j < n; j++)
        {
            result[i][j] = with;
        }
    }
    return result;
}

void Trans(int **mat)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            mat[i][j] = mat[j][i];
        }
    }
}

int **MatrixMult(int **a, int **b)
{
    int i, j, k;
    int **result = new int *[N];
    for (i = 0; i < N; i++)
    {
        result[i] = new int[N];
        for (j = 0; j < N; j++)
        {
            int sum = 0;
            for (k = 0; k < N; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

int **MatrixSum(int **a, int **b)
{
    int i, j;
    int **result = new int *[N];
    for (i = 0; i < N; i++)
    {
        result[i] = new int[N];
        for (j = 0; j < N; j++)
        {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

void printMatrix(int **mat)
{
    int i;
    cout << "matrix: " << endl;
    for (i = 0; i < N; i++)
    {
        printVector(mat[i]);
    }
    cout << endl;
}