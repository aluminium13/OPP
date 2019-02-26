/* ==========================================
Основи Паралельного програмування
Лабораторна робота №2
Процеси в мові Java. Задачі
F1: A = B*MIN(C) *(MA*MD+MD)
F2: MK = MA*(MA*MZ) + TRANS(MB)
F3: O = SORT(R + S)*(MT*MP)
Кузьменко Олександра Вікторівна ІО-62
дата: 13.09.2018
==========================================*/
public class lab2 {
    public static int N = 4;

    public static void main(String[] args) {
        System.out.println("Main process started");
        taskOne t1 = new taskOne(7, 1000);
        taskTwo t2 = new taskTwo(4, 2000);
        taskThree t3 = new taskThree(1, 500);

        t1.start();
        t2.start();
        t3.start();

        try {
            t1.join();
            t2.join();
            t3.join();
        } catch (InterruptedException e) {
            System.out.println("System error");
        }
        System.out.println("Main process finished");
    }
}