#include <iostream>

extern const int N;

using namespace std;

int *Vector(int n, int with);

int *VectorSum(int *a, int *b);
void VectorSort(int *vec);

int multVecByVec(int *a, int *b);
int *multVecByNum(int *a, int b);
int VectorMin(int *vec);
int *multVecByMat(int *a, int **b);

int **Matrix(int n, int with);

int **MatrixSum(int **a, int **b);
int **MatrixMult(int **a, int **b);

void Trans(int **mat);

void printVector(int *vec);
void printMatrix(int **mat);
