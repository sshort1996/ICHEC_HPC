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
    int world_rank, cart_rank;
    int world_size, cart_size;
    
    // Get the world size and rank
    MPI_Comm_size( MPI_COMM_WORLD, &world_size );
    MPI_Comm_rank( MPI_COMM_WORLD, &world_rank );

    int ndims = 1;
    int dims[1] = {0};
    // Creates a division of processors on a 1D line
    MPI_Dims_create( world_size, ndims, &dims[0] );
    // Print the dims array to show how it has been changed
    if ( world_rank == 0 ) {
        printf("dims array: %d %d\n", dims[0] );
    }

    // Both dimensions will be periodic
    int periods[1] = { 1 };
    int reorder = 0;
    // Initialise our new communicator, note the name is informative
    MPI_Comm comm_cart;
    // Create a new virtual topology
    MPI_Cart_create( MPI_COMM_WORLD, ndims, dims, periods, reorder, &comm_cart );

    // Find the new size and rank
    MPI_Comm_size( comm_cart, &cart_size );
    MPI_Comm_rank( comm_cart, &cart_rank );

    // Print some information about our rank
    printf( "I am process %d of %d on comm_world and %d of %d on comm_cart.\n", world_rank, world_size, cart_rank, cart_size );

    // Compute the neighbours for each process
    for ( i = 0; i < ndims; i++ ) {
        int prev_rank;
        int next_rank;
		printf("%d\n ", i);
        MPI_Cart_shift( comm_cart, i, 1, &prev_rank, &next_rank );
        printf( "Process %d on comm_cart. Direction %d, prev %d, next %d.\n", cart_rank, i, prev_rank, next_rank );
    }

    MPI_Finalize();
    return 0;
}
