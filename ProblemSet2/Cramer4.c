#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

#include "alloc2d.h"

int CramerRec(int size, int pi, int pj, int mat[size][size], int world_rank, int name, int det, int det2)
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
		//printf("constant4: %d \n" , constant4);
		constant4 = 0;
	}
	//same for 2*2 with no send
	else if (size == 2){
		constant3 = pow(-1, pj)*mat[0][pj];
	}
	
	//printf( "recursive step %d\n", 4-size );
	//for ( i = 0; i < size; i++ ) {
	//	for ( j = 0; j < size; j++ ) {
	//		printf( "  %d   ", a[i][j] );
	//	}
	//printf( "\n" );
	//}

	if (size == 2){
		det += (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
		printf("c*det[2,2] = %d * %d = %d\n",constant3, det, det*constant3);
		det *= constant3;
		//det2 += det;
		//printf("det2 = %d\n", det2 ); 
		MPI_Send(&det, 1, MPI_INT, 0, 101, MPI_COMM_WORLD);
		constant3 = 0;
		
		
		
	}
	if (size > 2){
		// oh nooooo! Recursion!
		printf("=================================\n");
		for ( i = 0; i < size; i++){
			CramerRec(size, 0,i, a, world_rank, size, det, det2);
		} 
	}
}


int main(int argc, char *argv[]){
	
	char myName[MPI_MAX_PROCESSOR_NAME];
	int world_size, myRank, i, j, k, world_rank, ierror, size, det, const3, det2, det3, det4, det_final;
	
	det = 0;
	const3 = 0;
	det2 = 0;
	det3 = 0;
	det4 = 0;
	det_final = 0;
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
		{4,6,3,1,8},
		{5,5,6,9,9},
		{2,3,4,0,4},
		{8,2,9,7,5},
		{1,3,8,7,7},
		};
	if ( world_rank == 1 ) {
		printf( "A from main:\n" );
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
	}
	//call recursive fn once per process
	
	if ( world_rank != 0 ) {
		CramerRec(size, 0,world_rank-1, A, world_rank, size, det, det2);
		//printf("constants %d\n", constants0[world_rank-1]);
		
	}
	if ( world_rank == 0){
		for (k = 0; k < 5; k++){
			for (j = 0; j < 4; j++){
				for (i = 0; i < 3; i++){
					MPI_Recv(&det2, 4, MPI_INT, k+1, 101, MPI_COMM_WORLD,
							MPI_STATUS_IGNORE);
					det3 += det2;
					det2 = 0;
				}
				//recieve constant4 in this loop 
				MPI_Recv(&constants4, 1, MPI_INT, k+1, 102, MPI_COMM_WORLD,
							MPI_STATUS_IGNORE);
				//printf("const4 = %d \n",constants4);
				printf("c*det[3,3] = %d * %d = %d\n", constants4 , det3, constants4 * det3);
				det3 *= constants4;
				det4 += det3;
				det3 = 0;
			}
			printf("c*det[4,4] = %d * %d = %d\n", constants0[k] , det4, constants0[k] * det4);
			det4 *= constants0[k];
			det_final += det4;
			det4 = 0;
		}
		printf("\n");det4 = 0;
		printf("=======================================================");det4 = 0;
		printf("\n");det4 = 0;
		printf("total 5*5 determinant : %d \n", det_final);
	}
	//for (i = 0; i < 20; i++){
				
	//}
	

	
	ierror = MPI_Finalize();
    return ierror;
	
}