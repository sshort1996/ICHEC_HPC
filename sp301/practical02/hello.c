#include<stdio.h>
#include<omp.h>

int main(void){
	int tid, nthreads, max_td;
	omp_set_num_threads(4);
	#pragma omp parallel private(tid),shared(nthreads)
	/*parallel block one*/
	{
		nthreads=omp_get_num_threads();
		tid=omp_get_thread_num();
		if (tid == 0)
		{
			printf("the total number of threads is %d\n", nthreads);
		}	
		printf("Hello from thread %d out of %d\n", tid+1,nthreads);
	}
	
	omp_set_num_threads(8);
	#pragma omp parallel private(tid),shared(nthreads)
	/*parallel block two*/
	{
		nthreads=omp_get_num_threads();
		tid=omp_get_thread_num();
		if (tid == 0)
		{
			printf("the total number of threads is %d\n", nthreads);
		}	
		printf("Hello from thread %d out of %d\n", tid+1,nthreads);
	}
	omp_set_num_threads(12);
	#pragma omp parallel private(tid),shared(nthreads)
	/*parallel block three*/
	{
		nthreads=omp_get_num_threads();
		tid=omp_get_thread_num();
		if (tid == 0)
		{
			printf("the total number of threads is %d\n", nthreads);
		}	
		printf("Hello from thread %d out of %d\n", tid+1,nthreads);
	}
	
}