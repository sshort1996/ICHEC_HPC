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
    int world_rank, cart_rank;
    int world_size, cart_size;
    
    // Get the world size and rank
    MPI_Comm_size( MPI_COMM_WORLD, &world_size );
    MPI_Comm_rank( MPI_COMM_WORLD, &world_rank );

    int ndims = 2;
    int dims[2] = { 0, 0 };
    // Creates a division of processors in a cartesian grid
    MPI_Dims_create( world_size, ndims, &dims[0] );
    // Both dimensions will be periodic
    int periods[2] = { 1, 1 };
    int reorder = 0;
    // Initialise our new communicator, note the name is informative
    MPI_Comm comm_cart;
    // Create a new virtual topology
    MPI_Cart_create( MPI_COMM_WORLD, ndims, dims, periods, reorder, &comm_cart );
    // Find the new size and rank
    MPI_Comm_size( comm_cart, &cart_size );
    MPI_Comm_rank( comm_cart, &cart_rank );
    // Compute the neighbours for each process
    for ( i = 0; i < ndims; i++ ) {
        int prev_rank;
        int next_rank;
        MPI_Cart_shift( comm_cart, i, 1, &prev_rank, &next_rank );
    }

    // Allocate the submatrix for each process on comm_cart
    int n=N/dims[0];
    int m=M/dims[1];
    int **A = alloc2dInt( n, m );
    //Initialise matrix
    srand(time(NULL)*cart_rank);
    for (i=0; i<n; i++) {
       for (j=0; j<m; j++) {
          A[i][j] = (int) rint(((float)rand()/RAND_MAX));
       }
    }

    // Sum the local part of the array
    int sum = 0;
    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < m; j++ ) {
            sum += A[i][j];
        }
    }

    // Print the local sum on each process
    printf( "I am process %d of %d and sum is %d\n", cart_rank, cart_size, sum );

    // Reduce the global sum on process 0
    int globalSum;
    MPI_Reduce( &sum, &globalSum, 1, MPI_INT, MPI_SUM, 0,  comm_cart);

    // Print this global sum
    if ( world_rank == 0 ) {
        printf( "Global sum is %d\n", globalSum );
    }

    MPI_Finalize();
    return 0;
}
