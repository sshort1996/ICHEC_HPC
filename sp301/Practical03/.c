#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv)
{
	int ierror, uniSize, myRank;
	const int root = 0;
	int n = atoi(argv[1]);
	int m = atoi(argv[2]);

	//MATRIX ROW COLUMN DATATYPE
	
	//create a matrix with dynamic memory allocation
	int *A = NULL;
	//Then let's fill this matrix with stuff
	int i, j, count = 0; 
    if (myRank == root)
	{
		A = (int *) malloc(n*m*sizeof(int));
		for (i = 0; i <  n; i++) 
		{
			for (j = 0; j < m; j++) 
			{
				*(A + i*m + j) = count;
				count ++;
			}
			printf("\n");
		}
		
		for (i = 0; i <  n; i++) 
			for (j = 0; j < m; j++) 
				printf("%d ", *(A + i*m + j)); 
				printf("\n");
	}
	else
	{
		A = (int *) malloc(n*m*sizeof(int));
		for (i = 0; i <  n; i++) 
		{
			for (j = 0; j < m; j++) 
			{
				*(A + i*m + j) = 0;
			}
		}
	}
	//STUFF^^
	
	//start MPI
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);
	
	//want to send each of 
	//			-a row
	//			-a column	
	//			- a submatrix
	// to other processes. A row should be simple
	
	/*
	int row_num = 1;
	//row we want to send^^
	if(myRank==root)
	{
		MPI_Send(&A[n*row_num],n,MPI_INT,myRank^1,100+row_num,MPI_COMM_WORLD);
		printf("sent!\n");
	}
	if(myRank==root^1)
	{
		MPI_Recv(&A[n*row_num],n,MPI_INT,myRank^1,100+row_num,
		MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("recieved!\n");
		for (i = 0; i <  n; i++) 
			for (j = 0; j < m; j++) 
				printf("%d ", *(A + i*m + j)); 
		
	}
	*/
	//I guess we should do this with datatypes though
	MPI_Datatype row;
	MPI_Type_vector(1, n , m , MPI_INT, &row );
	MPI_Type_commit( &row );
	//now lets reset A to all zeros in the non root process
	if (myRank != 0)
	{
		A = (int *) malloc(n*m*sizeof(int));
		for (i = 0; i <  n; i++) 
		{
			for (j = 0; j < m; j++) 
			{
				*(A + i*m + j) = 0;
			}
		}
	}
	//choose which row to send
	int row_num = 0;
	if(myRank==root)
	{
		MPI_Send(&A[row_num*m],1,row,myRank^1,100+row_num,MPI_COMM_WORLD);
		printf("\n");
		printf("sent row!\n");
	}
	if(myRank==root^1)
	{
		MPI_Recv(&A[row_num*m],1,row,myRank^1,100+row_num,MPI_COMM_WORLD
			, MPI_STATUS_IGNORE);
		printf("\n");
		printf("recieved row!\n");
		for (i = 0; i <  n; i++) 
			for (j = 0; j < m; j++) 
				printf("%d ", *(A + i*m + j)); 
		printf("\n");
	}
	//now for columns
	MPI_Datatype col;
	MPI_Type_vector(m,1,m, MPI_INT, &col );
	MPI_Type_commit( &col );
	//now lets reset A to all zeros in the non root process
	if (myRank != 0)
	{
		A = (int *) malloc(n*m*sizeof(int));
		for (i = 0; i <  n; i++) 
		{
			for (j = 0; j < m; j++) 
			{
				*(A + i*m + j) = 0;
			}
		}
	}
	//choose which col to send
	int col_num = 3;
	if(myRank==root)
	{
		MPI_Send(&A[col_num],1,col,myRank^1,100+col_num,MPI_COMM_WORLD);
		printf("\n");
		printf("sent col\n");
	}
	if(myRank==root^1)
	{
		MPI_Recv(&A[col_num],1,col,myRank^1,100+col_num,MPI_COMM_WORLD
			, MPI_STATUS_IGNORE);
		printf("\n");
		printf("recieved col\n");
		for (i = 0; i <  n; i++) 
			for (j = 0; j < m; j++) 
				printf("%d ", *(A + i*m + j)); 
		printf("\n");
	}
	/*
	//finally for submatrices
	MPI_Datatype subm;
	MPI_Type_vector(2,2,m, MPI_INT, &subm );
	MPI_Type_commit( &subm );
	//now lets reset A to all zeros in the non root process
	if (myRank != 0)
	{
		A = (int *) malloc(n*m*sizeof(int));
		for (i = 0; i <  n; i++) 
		{
			for (j = 0; j < m; j++) 
			{
				*(A + i*m + j) = 0;
			}
		}
	}
	//choose which col to send
	int subm_num = 5;
	if(myRank==root)
	{
		MPI_Send(&A[subm_num],1,subm,myRank^1,100+subm_num,MPI_COMM_WORLD);
		printf("\n");
		printf("sent submatrix\n");
	}
	if(myRank==root^1)
	{
		MPI_Recv(&A[subm_num],1,subm,myRank^1,100+subm_num,MPI_COMM_WORLD
			, MPI_STATUS_IGNORE);
		printf("\n");
		printf("recieved subm!\n");
		for (i = 0; i <  n; i++) 
			for (j = 0; j < m; j++) 
				printf("%d ", *(A + i*m + j)); 
		printf("\n");
	}
	*/
	
	
	
	
	ierror = MPI_Finalize();
}
