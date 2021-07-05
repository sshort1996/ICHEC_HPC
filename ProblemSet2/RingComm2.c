#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>
#include <math.h>
#include "alloc2d.h"

#define N 20
#define M 20

int main( int argc, char **argv ) {
    MPI_Init( &argc, &argv );

    int i, j;
    int world_rank, ring_rank;
    int world_size, ring_size;
    
    // Get the world size and rank
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

	// Send a message from Pn to Pn+1 over periodic boundaries
	MPI_Request send_request, recv_request;
	MPI_Status status;
	int msg;
	msg = ring_rank;
	int tag;
	
	// Add current rank to msg before each send
	msg += ring_rank;
	MPI_Isend(&msg, 1, MPI_INT, next_rank, 100+ring_rank, comm_ring,  &send_request);
	printf("sent message %d with tag %d from %d to %d\n", msg, 100+ring_rank, ring_rank, next_rank);
	
	MPI_Irecv(&msg, 1, MPI_INT, prev_rank, 100+prev_rank, comm_ring, &recv_request);
	MPI_Wait(&recv_request, &status);
	printf("recieved message %d with tag %d from %d to %d\n", msg, 100+prev_rank, prev_rank, ring_rank);
    MPI_Finalize();

    return 0;
}
