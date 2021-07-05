#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv)
{
	int ierror, uniSize, myRank, num, i, locSum, totSum;
	const int root = 0;
	int n = atoi(argv[1]);
	//VECTOR SUM THROUGH MPI SCATTER
	
	//start MPI
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);
	
	//create vector A and chunks si
	int *si = (int *) malloc(n*sizeof(int));
	int *A = NULL;
	if(myRank == 0)
	{	
		A = (int *) malloc(n*uniSize*sizeof(int));
		printf("%d processors active\n", uniSize);	
		
		for (i = 0; i < n*uniSize; i++)
		{
			A[i] = i;
			printf("A[i]=%d\n", A[i]);
		}
	}
	locSum = 0;
	ierror = MPI_Scatter(A, n, MPI_INT, si, n, MPI_INT, 
		root, MPI_COMM_WORLD);
	printf("scatter done \n");
			//for (i = 0; i < n; i++)
			//{
				//scatter A to processes in chunks s_i
	
		//}
	
	//}
	//sum local chunks s_i, return local sum 
	
	totSum = 0;
	for (i = 0; i < n; i++)
	{
		locSum += si[i];
		
	}
	printf("local sum  = %d \n", locSum);
	//rank 0 gathers local sums computes total sum
    ierror = MPI_Reduce(&locSum, &totSum, n, MPI_INT, 
		MPI_SUM,root,MPI_COMM_WORLD);
	
	printf("root process total sum = %d,",totSum);
	printf("\n");

	free(A);
	free(si);
	ierror = MPI_Finalize();
}
