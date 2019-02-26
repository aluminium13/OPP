using System;
using System.Threading;

namespace Lab3
{
    public class Func2
    {
        int N, sleepTime;

        Matrix MK, MA, MZ, MB;

        public Func2(int n, int sleep)
        {
            N = n;
            sleepTime = sleep;
        }
        public void Calculate()
        {
            Thread.Sleep(sleepTime);
            Console.WriteLine($"T2 started");
            MA = new Matrix(N, 2);
            MZ = new Matrix(N, 2);
            MB = new Matrix(N, 2);
            MK = MA * (MA * MZ) + MB.Trans();
            MK.Print();
            Console.WriteLine($"T2 finished");
        }
    }
}