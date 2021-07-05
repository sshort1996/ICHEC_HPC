#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

#include "alloc2d.h"

int CramerRec(int size, int pi, int pj, int mat[size][size], int world_rank, int name, int det)
{
	size--;
	int constant3;
	int constant4;
	int i, j, size_temp;
	int a[size][size];

	int count_x, count_y;
	count_x = 0;
	count_y = 0;
	//generate minors of size "size"
	for (i = 0; i < size+1; i++){
		for (j = 0; j < size+1; j++){
			if(i != pi && j != pj ){
				a[count_x][count_y] =mat[i][j]; 
				count_y++;
				if (count_y % size == 0 ){
					count_y = 0;
					count_x++;
				}
			}
			
		}
		
	}
	//send constant to multiply by 3*3 determinants to process 0
	if (size == 3){
		constant4 = pow(-1, pj)*mat[pi][pj];
		MPI_Send(&constant4, 1, MPI_INT, 0, 102, MPI_COMM_WORLD);
		printf("constant4: %d \n" , constant4);
		constant4 = 0;
	}
	//same for 2*2 with no send
	else if (size == 2){
		constant3 = pow(-1, pj)*mat[0][pj];
	}
	
	printf( "recursive step %d\n", 4-size );
	for ( i = 0; i < size; i++ ) {
		for ( j = 0; j < size; j++ ) {
			printf( "  %d   ", a[i][j] );
		}
	printf( "\n" );
	}
	
	if (size == 2){
		det += (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
		printf("det fn %d\n", det);
		printf("const fn %d\n", constant3);
		printf("const pos %d\n", pj);
		det *= constant3;
		MPI_Send(&det, 1, MPI_INT, 0, 101, MPI_COMM_WORLD);
		constant3 = 0;
		printf("det fn %d\n", det);
	}
	if (size > 2){
		// oh nooooo! Recursion!
		printf("=================================");
		for ( i = 0; i < size; i++){
			CramerRec(size, 0,i, a, world_rank, size, det);
		} 
	}
}


int main(int argc, char *argv[]){
	
	char myName[MPI_MAX_PROCESSOR_NAME];
	int world_size, myRank, i, j, k, world_rank, ierror, size, det, sum, det2, det3;
	
	det = 0;
	sum = 0;
	det2 = 0;
	det3 = 0;
	size = 5;
	
    ierror = MPI_Init( &argc, &argv );
    ierror = MPI_Comm_rank( MPI_COMM_WORLD, &world_rank );
    ierror = MPI_Comm_size( MPI_COMM_WORLD, &world_size );

	//int **A = alloc2dInt( size, size );
	//int A[size][size];
	//Rank 0 has a matrix of all zeros and Rank 1 has a matrix of all 1s  
	int count = 0;
	//for ( i = 0; i < size; i++ ) {
    //    for ( j = 0; j < size; j++ ) {
    //       A[i][j] = i;
	//		count++;
    //    }
	//}
	int A[5][5] = {
		{9,9,7,4,3},
		{1,4,8,6,2},
		{2,4,5,0,4},
		{8,2,1,1,5},
		{1,1,8,7,7},
		};
	if ( world_rank == 1 ) {
		printf( "A from main slave:\n" );
		for ( i = 0; i < size; i++ ) {
			for ( j = 0; j < size; j++ ) {
				printf( "%d ", A[i][j] );
			}
		printf( "\n" );
		}
	}
	//this call should generate the 'a' submatrix and print from foo()
	int constants0[size];
	int constants4;
	for (i = 0; i < size; i++){
		constants0[i] = pow(-1, i)*A[0][i];
		printf("constants %d\n", constants0[i]);
	}
	for (j = 0; j <= size; j++){
		if ( world_rank == j+1 ) {
			CramerRec(size, 0,j, A, world_rank, size, det);
		}
	}
	

	
	ierror = MPI_Finalize();
    return ierror;
	
}