#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv)
{
	int ierror, uniSize, myRank, num;
	const int root = 0;
	
	//PASS MESSAGES THROUGH BROADCAST
	
	//start MPI
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);
	//rank 0 reads in num 
	
	//read in a number
	if(myRank == root)
	{
		num = atoi(argv[1]);
		printf("\n Rank 0 num before broadcast : %d\n", num);	
		//buket used scanf to read num
	}
	else
	{
		printf("\n num before broadcast : %d\n", num);	
	}
	//Broadcast num to all available ranks (Rank 0 as root)
	
	if(myRank == root)
	{
		printf("Broadcasting...\n");
	}
	
	MPI_Bcast(&num, 1, MPI_INT, root, MPI_COMM_WORLD);
	
	
	printf("Rank %d num : %d\n \n", myRank, num);

	ierror = MPI_Finalize();
}
