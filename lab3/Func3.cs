using System;
using System.Threading;

namespace Lab3
{
    public class Func3
    {
        int N, sleepTime;
        Vector O, R, S;
        Matrix MT, MP;

        public Func3(int n, int sleep)
        {
            N = n;
            sleepTime = sleep;
        }
        public void Calculate()
        {
            Thread.Sleep(sleepTime);
            Console.WriteLine($"T3 started");
            R = new Vector(N, 3);
            S = new Vector(N, 3);
            MT = new Matrix(N, 3);
            MP = new Matrix(N, 3);
            O = (R + S).Sort() * (MT * MP);
            O.Print();
            Console.WriteLine($"T3 finished");
        }
    }
}