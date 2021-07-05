#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>
int main(int argc , char** argv)
{
	int i, j;
	int size = atoi(argv[1]);
	
	double w[size][size];
	double w_1[size][size];
	double w_new;
	
	//create array of zeros
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			w[i][j] = 0.0;
		}
	}
	//set boundary values
	for (i = 0; i < size; i++)
	{
		w[i][0] = 100.0;
		w[i][size-1] = 100.0;
		w[size-1][i] = 100.0;
		
	}
	//set interior values
	for (i = 1; i < size-1; i++)
	{
		for (j = 1; j < size-1; j++)
		{
			w[i][j] = 75;
		}
	}
	printf("w matrix initialised\n");
	printf("Updating ...\n");
	int smooth = 0;
	int count = 0;
	int max_i, max_j, tid, threads;
	
	double max_diff = 0.0;
	double diff = 0.0;
	double times;
	times = omp_get_wtime();
	#pragma omp parallel num_threads(1)
	{
		threads = omp_get_num_threads();
		while(smooth == 0)
		{
			printf("parallel\n");
			#pragma omp barrier
			{
				//since each entry to be updated depends on the previous updated entry
				//we cannot parallelise the entire update at once (Not sure of this 
				//assumption we'll do the other way in another script). What we do instead is
				//compute the sum of the cell to the right and below (R and D) the cell
				//of interest in parallel. Then we finish the rest of the computation in 
				//series. 
				#pragma omp for schedule(static) private(w_1)
				for (i = 1; i < size-1; i++)
				{	
					//compute w_1 = R+D (entries to the right and down from 
					//w[i][j]) in parallel for all matrix
					for (j = 1; j < size-1; j++)
					{
						w_1[i][j] = w[i][j-1]+ w[i][j+1];	
						//printf("---\n");	
					}
				}		
			}
			printf("serial\n");
			#pragma omp barrier
			{
				#pragma omp single			
				{
					for (i = 1; i < size-1; i++)
					{
						
					
						for (j = 1; j < size-1; j++)
						{
							w_new = (w_1[i][j] + w[i+1][j] + w[i][j-1])/(float)4.0;
							diff = fabs(w_new - w[i][j]);
				
							if (diff > max_diff )
							{
								max_diff = diff;
								max_i = i;
								max_j = j;
								//tid=omp_get_thread_num();
								//printf("thread %d\n", tid);
								//printf("+++\n");	
							}				
							w[i][j] = w_new;
						}
					}
				printf("max diff %g at position (%d, %d)\n", max_diff, max_i, max_j);
				if(max_diff < 0.0001)
				{
					smooth = 1;
					
				}
				max_diff = 0.0;
				count++;
				}
			}
		}
	}
	times = omp_get_wtime() - times;
	printf("reached limit in %d iterations...kind of\n", count);
	printf("time to limit (%d threads): %f\n", threads, times);
			
}