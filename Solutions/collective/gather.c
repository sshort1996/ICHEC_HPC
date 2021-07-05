#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main( int argc, char **argv ) {
    int ierror;
    ierror = MPI_Init( &argc, &argv );

    int world_rank, world_size;

    // Find our world rank & size to print it
    ierror = MPI_Comm_rank( MPI_COMM_WORLD, &world_rank );
    ierror = MPI_Comm_size( MPI_COMM_WORLD, &world_size );

    srand(time(NULL)*world_rank);
    //generates a random number between 97 and 122
    int number = rand() % 26 + 97;
    //transforms number in a character
    char letter = number;

    // We need an array buf to hold one element from each process
    char *buf;
    buf = malloc( sizeof( char ) * world_size );

    // Do the gather onto rank 0
    ierror = MPI_Gather( &letter, 1, MPI_CHAR, buf, 1, MPI_CHAR, 0, MPI_COMM_WORLD );

    int i;
    // Print the value on all processes
    if ( world_rank == 0 )  {
            printf( "I am process %d of %d\n", world_rank, world_size );
        for ( i = 0; i < world_size; i++ ) {
            printf( "%c ", buf[i] );
        }
        printf ("\n" );
    }

    // Do the gather onto rank 1. We expect the same results
    ierror = MPI_Gather( &letter, 1, MPI_CHAR, buf, 1, MPI_CHAR, 1, MPI_COMM_WORLD );

    // Print the value on all processes
    if ( world_rank == 1 )  {
            printf( "I am process %d of %d\n", world_rank, world_size );
        for ( i = 0; i < world_size; i++ ) {
            printf( "%c ", buf[i] );
        }
        printf ("\n" );
    }

    ierror = MPI_Finalize();
    return ierror;
}
