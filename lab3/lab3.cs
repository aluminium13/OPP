/* ==========================================
Основи Паралельного програмування
Лабораторна робота №3
Потоки в мові C#
Варіант 10
F1: A = B*MIN(C) *(MA*MD+MD)
F2: MK = MA*(MA*MZ) + TRANS(MB)
F3: O = SORT(R + S)*(MT*MP)
Кузьменко Олександра Вікторівна ІО-62
дата: 07.10.2018
==========================================*/

using System;
using System.Threading;

namespace Lab3
{
    class lab3
    {
        public static int N = 4;
        static void Main(string[] args)
        {
            Console.WriteLine("Main thread started");

            Func1 fn1 = new Func1(N, 1000);
            Func2 fn2 = new Func2(N, 700);
            Func3 fn3 = new Func3(N, 1500);

            ThreadStart ts1 = new ThreadStart(fn1.Calculate);
            ThreadStart ts2 = new ThreadStart(fn2.Calculate);
            ThreadStart ts3 = new ThreadStart(fn3.Calculate);

            Thread T1 = new Thread(ts1);
            Thread T2 = new Thread(ts2);
            Thread T3 = new Thread(ts3);

            T1.Start();
            T2.Start();
            T3.Start();

            try
            {
                T1.Join();
                T2.Join();
                T3.Join();
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.GetType());
            }

            Console.WriteLine("Main thread finished");
        }
    }
}
