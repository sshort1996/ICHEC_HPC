#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include "alloc2d.h"

#define size 5

int Cramer4by4(int pi, int pj, int mat[size][size])
{
	//do things
	return stuff;
}
int main(int argc, char *argv[]){
	
	char myName[MPI_MAX_PROCESSOR_NAME];
	
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);

	int **A = alloc2dInt( N, M );
	//Rank 0 has a matrix of all zeros and Rank 1 has a matrix of all 1s  
	for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < M; j++ ) {
            A[i][j] = world_rank;
        }
    }
	
}