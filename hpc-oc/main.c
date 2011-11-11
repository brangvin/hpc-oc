// Подключение необходимых заголовков
#include <stdio.h>
#include <math.h>
// Подключение заголовочного файла MPI
#define OMPI_IMPORTS
#include "mpi.h"
 
// Функция для промежуточных вычислений
double f(double a)
{
    return (4.0 / (1.0+ a*a));
}
 
// Главная функция программы
int main(int argc, char **argv)
{
    // Объявление переменных
    int done = 0, n, myid, numprocs, i;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    double startwtime = 0.0, endwtime;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
 
    // Инициализация подсистемы MPI
    MPI_Init(&argc, &argv);
    // Получить размер коммуникатора MPI_COMM_WORLD
    // (общее число процессов в рамках задачи)
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    // Получить номер текущего процесса в рамках 
    // коммуникатора MPI_COMM_WORLD
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Get_processor_name(processor_name,&namelen);
 
    // Вывод номера потока в общем пуле
    fprintf(stdout, "Process %d of %d is on %s\n", myid,numprocs,processor_name);
    fflush(stdout);
 
    // Освобождение подсистемы MPI
    MPI_Finalize();
    return 0;
}