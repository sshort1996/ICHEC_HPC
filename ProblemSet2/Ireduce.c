#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv)
{
	int ierror, uniSize, myRank, Sum;
	const int root = 0;
	
    int i, j;
    int world_rank, ring_rank;
    int world_size, ring_size;

	//start MPI
	ierror=MPI_Init(&argc,&argv);
    MPI_Comm_size( MPI_COMM_WORLD, &world_size );
    MPI_Comm_rank( MPI_COMM_WORLD, &world_rank );

    int ndims = 1;
    int dims[1] = {0};
    // Creates a division of processors in a cartesian grid
    MPI_Dims_create( world_size, ndims, &dims[0] );
    // Print the dims array to show how it has been changed
    if ( world_rank == 0 ) {
        printf("dims array: %d %d\n", dims[0], dims[1] );
    }

    // Both dimensions will be periodic
    int periods[1] = {1};
    int reorder = 0;
    // Initialise our new communicator, note the name is informative
    MPI_Comm comm_ring;
    // Create a new virtual topology
    MPI_Cart_create( MPI_COMM_WORLD, ndims, dims, periods, reorder, &comm_ring );

    // Find the new size and rank
    MPI_Comm_size( comm_ring, &ring_size );
    MPI_Comm_rank( comm_ring, &ring_rank );

    // Print some information about our rank
    printf( "I am process %d of %d on comm_world and %d of %d on comm_ring.\n", world_rank, world_size-1, ring_rank, ring_size-1 );

    // Compute the neighbours for each process
    
	int prev_rank;
	int next_rank;
	MPI_Cart_shift( comm_ring, 0, 1, &prev_rank, &next_rank );
	printf( "Process %d on comm_cart. prev %d, next %d.\n", ring_rank, prev_rank, next_rank );



    ierror = MPI_Reduce(&myRank, &Sum,1, MPI_INT, 
		MPI_SUM,root,comm_ring);
	
	if (ring_rank == 0){
		printf("root process total sum = %d,",Sum);
		printf("\n");	
	}
	ierror = MPI_Finalize();
}
