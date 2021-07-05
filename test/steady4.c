#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc , char** argv){
	int i, j, tid, nthreads, blocklen;
	int size = atoi(argv[1]);
	
	double w[size][size];
	double w_temp[size][size];
	tid=omp_get_thread_num();
	nthreads=omp_get_num_threads();
	if(nthreads % 100 == 0)
	{
		blocklen = 100/nthreads;
	}
	printf("%d", blocklen);
	
	
	
}
	
