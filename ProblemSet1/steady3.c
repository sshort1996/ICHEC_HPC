#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc , char** argv){
	int i, j, tid;
	int size = atoi(argv[1]);

	double w[size][size], w_temp[size][size], w_new, times;
		
	int smooth = 0;//breaks while loop
	int count = 0;
	
	double max_diff = 0.0;
	double diff = 0.0;
	tid=omp_get_thread_num();
	
	#pragma omp parallel
	{		
		if(tid == 0) 
		{
			times = omp_get_wtime();
		}
		//fill arrays with zeros
		#pragma omp for schedule(static) collapse(2)
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				w[i][j] = 0.0;
				w_temp[i][j] = 0.0;
			}
		}
		//set boundary values
		#pragma omp for schedule(static)
		for (i = 0; i < size; i++)
		{
			w[i][0] = 100.0;
			w[i][size-1] = 100.0;
			w[size-1][i] = 100.0;
			
		}
		//set interior values
		#pragma omp for schedule(static) collapse(2)
		for (i = 1; i < size-1; i++)
		{
			for (j = 1; j < size-1; j++)
			{
				w[i][j] = 75;
			}
		}
		printf("w matrix initialised\n");		
	}
		
		printf("Updating ...\n");
		
		while(smooth == 0)
		{
			
			#pragma omp parallel for schedule(static) shared(max_diff, w, smooth, count) private(w_new, diff) collapse(2)
				for (i = 1; i < size - 1; i++)
				{
					for (j = 1; j < size - 1; j++)
					{
						//calculate new entry
						w_new = (w[i+1][j]+w[i-1][j]+w[i][j+1]+w[i][j-1])/(float)4.0;
						//check difference
						diff = fabs(w_new - w[i][j]);
						
						if (diff > max_diff )
						{
							#pragma omp critical
							max_diff = diff;//new max difference
						}				
						w_temp[i][j] = w_new;//store new entries here temporarily
					}
				}
			#pragma omp parallel for collapse(2)
			for (i = 1; i < size - 1; i++)
			{
				for (j = 1; j < size - 1; j++)
				{
					w[i][j] = w_temp[i][j];//update full matrix from w_temp
				}
			}
			if(max_diff < 0.0001)//stop condition
			{
				smooth = 1;		
			}
			
			
			#pragma omp critical//reset for next interation
			{
				max_diff = 0.0;
				count++;
			}
		}
	
	printf("reached limit in %d iterations\n", count);
	if(tid == 0)
	{	
		times = omp_get_wtime() - times;
		printf("time to limit: %f\n",times);
	}
}
	
