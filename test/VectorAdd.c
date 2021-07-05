#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> /* memset */
#include <unistd.h> /* close */
#include <omp.h>

int main(int argc , char** argv){
	// generate two random vectors
	int n = atoi(argv[1]);
	int nSamples = atoi(argv[2]);
	double a[n], b[n], res[n], times[nSamples]; 
	memset( a, 0, n*sizeof(double) );	
	memset( b, 0, n*sizeof(double) );	
	memset( res, 0, n*sizeof(double) );	
	memset( times, 0, nSamples*sizeof(double) );	
	int i, j, k;
	
	
	for (i=1; i <= nSamples; i++)
	{
		for (j = 1; j <= n; j++)
		{
			srand(j);
			a[j] = (double)rand()/(double)RAND_MAX;
			srand(2*j);
			b[j] = (double)rand()/(double)RAND_MAX;
		}
		times[i-1] = omp_get_wtime();
		#pragma omp parallel for shared(a, b) private(res, k)
		for (k=1; k <= n; k++)
		{
			res[k] = a[k] + b[k];	
		}
		times[i-1] = omp_get_wtime()-times[i-1];
	}
	
	double avrg, max = 0;
	double min = 2.0;
	for (i=1; i<= nSamples; i++)
	{
		avrg = avrg + times[i-1];
		if (times[i-1] > max)
		{
			max = times[i-1];
		}
		if (times[i-1] < min)
		{
			min = times[i-1];
		}
	}
	avrg = (double)avrg / (double)nSamples;
	printf("Parallelised code\n");
	printf("\nSummary:\n");
	printf("#Size  n    |  Avg. Time (s) |   Min. Time(s) |   Max. Time(s) \n");
	printf("%12d %16.8f %16.8f %16.8f \n",n,avrg, min , max);
}	

