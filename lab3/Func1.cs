using System;
using System.Threading;

namespace Lab3
{
    public class Func1
    {
        int N, sleepTime;
        Vector A, B, C;
        Matrix MA, MD;

        public Func1(int n, int sleep)
        {
            N = n;
            sleepTime = sleep;
        }
        public void Calculate()
        {
            Thread.Sleep(sleepTime);
            Console.WriteLine($"T1 started");
            B = new Vector(N, 1);
            C = new Vector(N, 1);
            MA = new Matrix(N, 1);
            MD = new Matrix(N, 1);
            A = B * C.Min() * (MA * MD + MD);
            A.Print();
            Console.WriteLine($"T1 finished");
        }
    }
}