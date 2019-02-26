using System;

namespace Lab3
{
    public partial class Vector
    {
        private int[] _elements;

        public int this[int i] => _elements[i];

        public int Dimension => _elements.Length;

        public Vector(int[] elements)
        {
            _elements = elements;
        }

        public Vector(int size, int number)
        {
            _elements = new int[size];
            for (int i = 0; i < size; i++)
            {
                _elements[i] = number;
            }
        }

        private static Vector Add(Vector a, Vector b)
        {
            var size = a.Dimension;
            var elements = new int[size];
            for (int i = 0; i < size; i++)
            {
                elements[i] = a[i] + b[i];
            }
            return new Vector(elements);
        }

        public static Vector operator +(Vector a, Vector b)
        {
            return Add(a, b);
        }

        public int Min()
        {
            var m = _elements[0];
            var size = Dimension;
            for (int i = 0; i < size; i++)
            {
                if (_elements[i] < m)
                {
                    m = _elements[i];
                }
            }
            return m;
        }

        private static Vector Mul(Vector a, Matrix b)
        {
            var size = a.Dimension;
            var elements = new int[size];
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    elements[i] = elements[i] + a[i] * b[i, j];
                }
            }
            return new Vector(elements);
        }

        public static Vector operator *(Vector a, Matrix b)
        {
            return Mul(a, b);
        }

        public static Vector operator *(Matrix b, Vector a)
        {
            return Mul(a, b);
        }

        public static Vector operator *(Vector a, int b)
        {
            var size = a.Dimension;
            var elements = new int[size];
            for (int i = 0; i < size; i++)
            {
                elements[i] = a[i] * b;
            }
            return new Vector(elements);
        }

        public Vector Sort()
        {
            Array.Sort(_elements);
            return this;
        }

        public void Print()
        {
            Console.Write("( ");
            for (int i = 0; i < Dimension; i++)
            {
                Console.Write(_elements[i] + " ");
            }
            Console.WriteLine(")");
        }
    }

    public partial class Matrix
    {
        private readonly int[,] _elements;

        public int this[int i, int j] => _elements[i, j];

        public int Dimension => _elements.GetLength(0);

        public Matrix(int[,] elements)
        {
            _elements = elements;
        }

        public Matrix(int size, int number)
        {
            _elements = new int[size, size];
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    _elements[i, j] = number;
                }
            }

        }


        public static Matrix operator +(Matrix a, Matrix b)
        {
            var size = a.Dimension;
            var elements = new int[size, size];
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    elements[i, j] = a[i, j] + b[i, j];
                }
            }
            return new Matrix(elements);
        }


        public static Matrix operator *(Matrix a, Matrix b)
        {
            var size = a.Dimension;
            var elements = new int[size, size];
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    var sum = 0;
                    for (int k = 0; k < size; k++)
                    {
                        sum += a[i, k] * b[k, j];
                    }
                    elements[i, j] = sum;
                }
            }
            return new Matrix(elements);
        }

        public Matrix Trans()
        {
            var elements = new int[Dimension, Dimension];
            for (int i = 0; i < Dimension; i++)
            {
                for (int j = 0; j < Dimension; j++)
                {
                    elements[i, j] = _elements[j, i];
                }
            }
            return new Matrix(elements);
        }
        public void Print()
        {
            for (int i = 0; i < Dimension; i++)
            {
                Console.Write("( ");
                for (int j = 0; j < Dimension; j++)
                {
                    Console.Write(_elements[i, j] + " ");
                }
                Console.WriteLine(")");
            }
        }
    }
}
