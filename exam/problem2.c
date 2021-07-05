#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <mpi.h>

// Function prototypes
int *randomarray(int n, int max);
int quartile(int n, int *arr, int myRank, int uniSize);
void printarray(int n, int *arr);


/*
 * Create a random array
 */
int *randomarray(int n, int max){
    int *arr, i;
/* Notice to get max values need to add 1. */
    max = max+1;
    
	arr = malloc(n * sizeof(int));
    for (i=0; i<n; i++){
	arr[i] = rand() % max;
    }
    return arr;
}





/*
 * Find 1st quartile without sorting the array.
 */
int quartile(int n, int *arr, int myRank, int uniSize){
   int mark1, mark2, quart, i, check, suml, sumh, arr_temp, end;

	mark1 = n/4+1;
	mark2 = 3*n/4+1;
	printf("n = %d mark1 = %d mark2 = %d \n", n, mark1, mark2);
	
/*

! * Test to see if arr[i] is 1st quartile, if so stop
! * sumh is the number of elements arr>=arr[i]
! * suml are the number of elements arr<=arr[i] 
	
*/
/* OMP version if parallelising the outer loop do not break out
       of parallel region.

  * MPI version look at subarray
*/
	//Quart if (sumh >= mark2 AND suml >= mark1)

	printf("\n Rank %d arr  \n", myRank);	
	printarray(n,arr);		
	
	i = 0;
	suml = 0;
	sumh = 0;
	
	check = myRank*(n/uniSize);
	
	if (myRank == 0){
		end = n/uniSize + (n-uniSize*(n/uniSize));
	} 
	else{
		end = (myRank-1)*(n/uniSize);
	}
	
	quart = 0;
	
	
	
	do { 
		sumh = 0;
		suml = 0;
		
		
		printf("Rank %d : checking index %d \n", myRank, check);
		for (i = 0; i <= n; i++){
			
			//printf("arr[i] = %d \n", arr[i]);
			if (arr[i] <=arr[check]){
				suml ++;
			}
			else if (arr[i] >= arr[check]){
				sumh ++;
			}
		}
		if (sumh >= mark2 && suml >= mark1){
			printf("sumh %d suml %d \n", sumh, suml);
			quart = 1;
		}
		

		if(quart ==0){

			check ++;

		}		
		
	} while(quart == 0 && check < end);
	if (quart == 0){
		printf("quart not found\n");
	}
	else{
		printf("Rank %d: first quartile is %d at index %d \n", myRank, arr[check], check);
		
		quart = arr[check];
	}
	
	return quart;
}



void printarray(int n, int *arr){
    int i;

    printf("[ ");
    for (i=0; i<n; i++){
	printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main(int argc, char **argv){

    int i, n, max, *arr, ierror, myRank, uniSize, quart;
	const int root=0;

/* 
 * Fix seed, array size and max
 */ 
    srand(4123);
    max = 10000;
    n = 1001;

	//start MPI
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);

	
	// n will be the size of chunks N will be n*uniSize
	if (myRank != root){
		arr = malloc(n * sizeof(int));
	}
	else{
		arr = randomarray(n, max);		
	}
    
	MPI_Bcast(&arr, n, MPI_INT, root, MPI_COMM_WORLD);
	
	int *quartile_res;
	quart = quartile(n, arr, myRank, uniSize);
	if (myRank == root){
		quartile_res = malloc(uniSize * sizeof(int));
	}
	
	
	MPI_Gather(&quart, 1, MPI_INT, quartile_res, 1, MPI_INT ,root, MPI_COMM_WORLD);	
	
	if (myRank == root){
		for (i = 0; i <= n; i++){
			if( quartile_res[i] != 0){
				quart = quartile_res[i];
				break;
			}
				
		}
		printf("===================\n");
		printf("1st quartile is %d \n", quart);
		printf("===================\n");
	
	}
	free(arr);
	
	
		
	ierror = MPI_Finalize();
    
    return 0;
}


