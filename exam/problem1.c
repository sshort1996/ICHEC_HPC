#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


// Function prototypes
int *randomarray(int n, int max);
int quartile(int n, int *arr);
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
int quartile(int n, int *arr){
   int mark1, mark2, quart, i, check, suml, sumh, arr_temp, tid;

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
	i = 0;
	suml = 0;
	sumh = 0;
	check = 0;
	arr_temp = 0;
	quart = 0;

	

	do { 
		sumh = 0;
		suml = 0;
		
		
		//printf("checking index %d \n", check);
		#pragma omp parallel for reduction(+:sumh,suml)
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

			check++;

		}
		
			
		
		
		
		
	} while(quart == 0 && check <= n);
	printf("first quartile is %d at index %d \n", arr[check], check);
	quart = arr[check];
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

    int i, n, max, *arr, ierr;

/* 
 * Fix seed, array size and max
 */ 
    srand(4123);
    max = 10000;
    n = 1001;


    arr = randomarray(n, max);
	

/*
 * For the MPI code broadcast arr from root
 */


    printf("call printarray()...\n");
    printarray(n,arr);


    printf("1st quartile is %d\n",quartile(n,arr));

    free(arr);
    return 0;
}


