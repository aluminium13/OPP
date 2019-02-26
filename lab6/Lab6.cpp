#include <mpi.h>
#include "data.hpp"
#include <stdio.h>

/* ==========================================
Основи Паралельного програмування
Лабораторна робота №6
Процеси в бібліотеці MPI
Варіант 14
F1: D = (SORT(A + B) + C) *(MA*ME)
F2: ML = SORT(MF + MG*MH)
F3: T = (O + P)*(ML * MS)
Мірчук Наталія Павлівна ІО-62
дата: 12.12.2018
==========================================*/


using namespace std;
const int N = 4;

int main(int argc, char* argv[])
{
    cout << "Main thread started..." << endl;

    // Initialize the MPI environment.
    MPI_Init(&argc, &argv);

    int rank, size;

    // Get the number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // Get the rank of the process
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Get the name of the processor
    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;
    MPI_Get_processor_name(processor_name, &name_len);    

    printf("Processor: %s, rank %d out of %d processors\n", processor_name, rank, size);

    if (rank == 0) {
        Function1();
    } else if (rank == 1) {
        Function2();
    } else if (rank == 2) {
        Function3();
    }

    MPI_Finalize();
    cout << "Main thread fininshed..." << endl;
    return 0;
}