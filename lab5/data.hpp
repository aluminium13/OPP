#include <iostream>

using namespace std;
extern const int N;

class Matrix
{
    int size;

  public:
    int **elements;
    Matrix(int n)
    {
        size = n;
        this->elements = new int *[size];
        for (int i = 0; i < size; i++)
        {
            elements[i] = new int[size];
        }
    }
    Matrix(int **array, int n)
    {
        size = n;
        this->elements = array;
    }

    friend void printMatrix(Matrix m);
    int **getElements() { return elements; }
    void fill(int with);
    void trans();
    Matrix operator*(Matrix const &other);
    Matrix operator+(Matrix const &other);
};

class Vector
{
    int size;

  public:
    int *elements;
    Vector(int n)
    {
        size = n;
        this->elements = new int[size];
    };
    Vector(int *array, int n)
    {
        size = n;
        this->elements = array;
    }
    ~Vector() noexcept
    {
        delete[] elements;
    }

    friend void printVector(Vector vec);

    void sort();
    void fill(int with);
    int VectorMin(Vector const &other);
    int operator*(Vector const &other);
    Vector operator*(int const &other);
    Vector operator*(Matrix const &other);
    Vector operator+(Vector const &other);
};

void Function1();
void Function2();
void Function3();