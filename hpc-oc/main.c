// ����������� ����������� ����������
#include <stdio.h>
#include <math.h>
// ����������� ������������� ����� MPI
#define OMPI_IMPORTS
#include "mpi.h"
 
// ������� ��� ������������� ����������
double f(double a)
{
    return (4.0 / (1.0+ a*a));
}
 
// ������� ������� ���������
int main(int argc, char **argv)
{
    // ���������� ����������
    int done = 0, n, myid, numprocs, i;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum, x;
    double startwtime = 0.0, endwtime;
    int namelen;
    char processor_name[MPI_MAX_PROCESSOR_NAME];
 
    // ������������� ���������� MPI
    MPI_Init(&argc, &argv);
    // �������� ������ ������������� MPI_COMM_WORLD
    // (����� ����� ��������� � ������ ������)
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    // �������� ����� �������� �������� � ������ 
    // ������������� MPI_COMM_WORLD
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Get_processor_name(processor_name,&namelen);
 
    // ����� ������ ������ � ����� ����
    fprintf(stdout, "Process %d of %d is on %s\n", myid,numprocs,processor_name);
    fflush(stdout);
 
    // ������������ ���������� MPI
    MPI_Finalize();
    return 0;
}