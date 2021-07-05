#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc , char** argv){
	int i, j, tid, nthreads, blocklen;
	int size = atoi(argv[1]);
	
	double w[size][size];
	double w_temp[size][size];
	
	
	
	//#pragma omp parallel
	//{
		
	//omp_set_num_threads(2);
	tid=omp_get_thread_num();
	nthreads=omp_get_num_threads();
	
	if (tid == 0)
	{
		printf("%d threads\n", nthreads);
		blocklen = (int)size/(double)nthreads;
		printf("block length per process : %d\n", blocklen);
	}
	for (i = 0; i < nthreads; i++)
	{
		//if (tid == i)
		//{
		printf("thread %d\n", i);
		//}
	}
//	}
	
	
}
	
