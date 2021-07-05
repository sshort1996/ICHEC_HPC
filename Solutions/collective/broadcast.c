#include <stdio.h>
#include <mpi.h>

int main( int argc, char **argv ) {
    int ierror;
    ierror = MPI_Init( &argc, &argv );

    int world_rank, world_size;
    int buf;

    // Find our world rank & size to print it
    ierror = MPI_Comm_rank( MPI_COMM_WORLD, &world_rank );
    ierror = MPI_Comm_size( MPI_COMM_WORLD, &world_size );

    // Only rank 0 reads in from the command line
    if ( world_rank == 0 ) {
        printf( "Please insert a number\n" );
        scanf( "%d", &buf );
    }

    // Do the broadcast
    ierror = MPI_Bcast( &buf, 1, MPI_INT, 0, MPI_COMM_WORLD );

    // Print the value on all processes
    printf( "I am process %d of %d and buf is %d\n", world_rank, world_size, buf );

    ierror = MPI_Finalize();
    return ierror;
}
