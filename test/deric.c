#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv)
{
	int ierror, uniSize, myRank, num;
	const int root = 0;
	
	//
	
	//start MPI
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);

	srand(time(NULL));
	num = (int)rand()/(double)RAND_MAX*25 + 97;
	//MPI_Bcast(&num, 1, MPI_INT, root, MPI_COMM_WORLD);
	
	
	printf("Rank %d num : %d\n \n", myRank, num);

	ierror = MPI_Finalize();
}
