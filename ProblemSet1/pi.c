//compute pi using monte carlo sampling
//- generate points ie. two random numbers in (-1,1)
//- compute distance of points from origin
//- Use this to estimate pi
//- Parallelise w/ openMP 
//- Other things also 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define IM1 2147483563
#define IM2 2147483399
#define AM (1.0/IM1)
#define IMM1 (IM1-1)
#define IA1 40014
#define IA2 40692
#define IQ1 53668
#define IQ2 52774
#define IR1 12211
#define IR2 3791
#define NTAB 32
#define NDIV (1+IMM1/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
#define CHUNK 1000

float ran2(long *idum) {
  int j;
  long k;
  static long idum2=123456789; 
  static long iy=0;
  static long iv[NTAB];
  float temp;
  //this prevents the race condition on line 64 & 66
  #pragma omp threadprivate(iy, idum2)
  if (*idum <= 0) {
     if (-(*idum) < 1) *idum=1; 
     else *idum = -(*idum);
     idum2=(*idum);

     for (j=NTAB+7;j>=0;j--) {
        k=(*idum)/IQ1; 
       *idum=IA1*(*idum-k*IQ1)-k*IR1; 
        if (*idum < 0) *idum += IM1; 
        if (j < NTAB) iv[j] = *idum;
     }
     iy=iv[0];
  }

  k=(*idum)/IQ1; 
 *idum=IA1*(*idum-k*IQ1)-k*IR1;
  if (*idum < 0) *idum += IM1; 
  k=idum2/IQ2; 
  idum2=IA2*(idum2-k*IQ2)-k*IR2;

  if (idum2 < 0) idum2 += IM2; j=iy/NDIV;
  iy=iv[j]-idum2;
  
  iv[j] = *idum;
  if (iy < 1) iy += IMM1;
  if ((temp=AM*iy) > RNMX) 
    return RNMX; 
    else return temp;

}
int main(int argc , char** argv)
{
	int nt = atoi(argv[1]);
	int nthreads = atoi(argv[2]);
	printf("number of samples entered : %d\n ", nt);
	
	int i, nd, threads, tid;
	double dis, pi, times; 
	long seed;
	
	srand (time(NULL));
	tid=omp_get_thread_num();
	if (tid == 0)
	{
		times = omp_get_wtime();
	}
	//export OMP_NUM_THREADS seems unreliable, set n threads explicitly here
	#pragma omp parallel shared(nt) num_threads(nthreads)
	{
	double *px = (double *) malloc(sizeof(double));
	double *py = (double *) malloc(sizeof(double));
	threads = omp_get_num_threads();
	
	#pragma omp for schedule(static)
	//loops where each iteration take different amounts of time 
	//might benefit from dynamic scheduling (so says the internet)
	//not sure if the nd++ region would affect this enough to 
	//justify the added overhead so lets go with static
		for (i = 0; i <= nt; i++){
		long seedx=5*i;
		long seedy=2*i;
		//generate a point in the sample region
		px[0] = ran2(&seedx);
		py[0] = ran2(&seedy);
	
		
		//distance of point from origin
		dis = sqrt(px[0]*px[0] + py[0]*py[0]);		
		if (dis <=1.0)
		{
			//one thread updates at a time here
			#pragma omp critical
			nd ++;
		}
	}
	//printf("number of points inside the circle %d\n ", nd);
	pi = 4.0*(float)nd/((float)nt);
	
	
	tid=omp_get_thread_num();
	if (tid == 0)
	{
		printf("pi is approximately %g\n", pi);
		times = omp_get_wtime() - times;
		printf("\n result computed on %d threads in %g seconds\n \n",threads, times);
	}
	}
}
