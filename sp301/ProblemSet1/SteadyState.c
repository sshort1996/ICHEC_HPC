#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include <omp.h>

int main(int argc , char** argv)
{
	int i, j;
	int size = atoi(argv[1]);
	
	double w[size][size];
	double w_new;
	//creat array of zeros
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
	//print to check
	//for (i = 0; i < size; i++)
	//{
	//	for (j = 0; j < size; j++)
	//	{
	//		printf("    %g    ", w[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("w matrix initialised\n");
	printf("Updating ...\n");
	int smooth = 0;
	int count = 0;
	int max_i, max_j;
	
	double max_diff = 0.0;
	double diff = 0.0;
	double times;

	times = omp_get_wtime();	
	while(smooth == 0)
	{
		for (i = 1; i < size-1; i++)
		{
			for (j = 1; j < size-1; j++)
			{
				w_new = (w[i+1][j]+w[i-1][j]+w[i][j+1]+w[i][j-1])/(float)4.0;
				diff = fabs(w_new - w[i][j]);
	
				if (diff > max_diff )
				{
					max_diff = diff;
					max_i = i;
					max_j = j;
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
	printf("reached limit in %d iterations\n", count);
	times = omp_get_wtime() - times;
	printf("time to limit: %f\n",times);
	//print to check
	//for (i = 0; i < size; i++)
	//{
	//	for (j = 0; j < size; j++)
	//	{
	//		printf("    %g    ", w[i][j]);
	//	}
	//	printf("\n");
	//}
	
}
