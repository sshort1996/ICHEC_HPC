#ifndef ALLOCD
#define ALLOCD

#include <stdlib.h>
#include <mpi.h>


char **alloc2dChar( size_t n1, size_t n2 ) {
    if ( n1*n2 == 0 ) {
        n1 = n2 = 1;
    }
    size_t i;
    //Array of pointers of size n1 (int* dummy[n1])
    char **dummy = (char **) calloc( n1, sizeof( char * ) );
    if ( dummy == NULL ) {
        printf( " Could not allocate memory 1 2d float\n" );
        MPI_Abort( MPI_COMM_WORLD, 1 );
    }
    //Dynamically allocate memory of size n1*n2 and let dummy* point to it
    *dummy = (char *) calloc( n1*n2, sizeof( char ) );
    //Position allocated memory across n1 pointers
    for ( i = 1; i < n1; i++ ) {
        dummy[i] = (*dummy + n2*i);
    }
    return dummy;
}

#endif
