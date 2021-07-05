#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <math.h>

#include "alloc2d.h"

int CramerRec(int size, int pi, int pj, float mat[size][size], int world_rank, float det, float det2)
{
	size--;
	float constant3;
	float constant4;
	int i, j;
	float a[size][size];

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
		constant4 = (float)pow(-1, pj)*mat[pi][pj];
		MPI_Send(&constant4, 1, MPI_FLOAT, 0, 102, MPI_COMM_WORLD);
		constant4 = 0.0;
	}
	//same for 2*2 with no send
	else if (size == 2){
		constant3 = (float)pow(-1, pj)*mat[0][pj];
	}
	if (size == 2){
		det += (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
		printf("c*det[2,2] = %g* %g = %g\n",constant3, det, det*constant3);
		det *= constant3;
		MPI_Send(&det, 1, MPI_FLOAT, 0, 101, MPI_COMM_WORLD);
		constant3 = 0.0;
		
		
		
	}
	if (size > 2){
		//recursive step
		printf("=================================\n");
		for ( i = 0; i < size; i++){
			CramerRec(size, 0,i, a, world_rank, det, det2);
		} 
	}
}


int main(int argc, char *argv[]){
	
	char myName[MPI_MAX_PROCESSOR_NAME];
	int world_size, myRank, i, j, k, world_rank, ierror, size;
	float det, det2, det3, det4, det_final;
	
	det = 0.0;
	det2 = 0.0;
	det3 = 0.0;
	det4 = 0.0;
	det_final = 0.0;
	size = 5;
	
    ierror = MPI_Init( &argc, &argv );
    ierror = MPI_Comm_rank( MPI_COMM_WORLD, &world_rank );
    ierror = MPI_Comm_size( MPI_COMM_WORLD, &world_size );
	
	float A[5][5] = {
		{1.0 , -0.5 , -1.0/3.0 , -0.25 , -0.2},
		{-0.5 , 1.0/3.0 , -0.25 , -0.2 , -1.0/6.0},
		{-1.0/3.0 , -0.25 , 0.2 , -1.0/6.0 , -1.0/7.0},
		{-0.25 , -0.2 , -1.0/6.0 , 1.0/7.0 , -1.0/8.0},
		{-0.2 , -1.0/6.0 , -1.0/7.0 , -1.0/8.0 , 1.0/9.0},
		};
	if ( world_rank == 1 ) {
		printf( "A from main:\n" );
		for ( i = 0; i < size; i++ ) {
			for ( j = 0; j < size; j++ ) {
				printf( "%g ", A[i][j] );
			}
		printf( "\n" );
		}
	}
	
	float constants0[size];
	float constants4;
	for (i = 0; i < size; i++){
		constants0[i] = (float)pow(-1, i)*A[0][i];
	}
	//call recursive fn once per process
	CramerRec(size, 0,world_rank, A, world_rank, det, det2);
	
	if ( world_rank == 0){
		for (k = 0; k < 5; k++){
			for (j = 0; j < 4; j++){
				for (i = 0; i < 3; i++){
					MPI_Recv(&det2, 4, MPI_FLOAT, k, 101, MPI_COMM_WORLD,
							MPI_STATUS_IGNORE);
					det3 += det2;
					det2 = 0;
				}
				//recieve constant4 in this loop 
				MPI_Recv(&constants4, 1, MPI_FLOAT, k, 102, MPI_COMM_WORLD,
							MPI_STATUS_IGNORE);
				printf("c*det[3,3] = %g * %g = %g\n", constants4 , det3, constants4 * det3);
				det3 *= constants4;
				det4 += det3;
				det3 = 0;
			}
			printf("c*det[4,4] = %g * %g = %g\n", constants0[k] , det4, constants0[k] * det4);
			det4 *= constants0[k];
			det_final += det4;
			det4 = 0;
		}
		printf("\n");det4 = 0;
		printf("=======================================================");det4 = 0;
		printf("\n");det4 = 0;
		
	}
	printf("total 5*5 determinant : %g \n", det_final);
	ierror = MPI_Finalize();
    return ierror;
	
}