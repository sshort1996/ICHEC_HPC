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

float ran2(long *idum) {
  int j;
  long k;
  static long idum2=123456789; 
  static long iy=0;
  static long iv[NTAB];
  float temp;
  #pragma omp threadprivate(iy)

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
	printf("number of samples entered : %d\n ", nt);


	int i = 0;
	int nd = 0;
	double dis, pi, times; 
	long seed;
	
	srand (time(NULL));
	times = omp_get_wtime();
	
	#pragma omp parallel shared(nt)
	{
	double *px = (double *) malloc(sizeof(double));
	double *py = (double *) malloc(sizeof(double));
	#pragma omp for 
		for (i = 0; i <= nt; i++){
			
			long seed=5*i;
			px[0] = ran2(&seed);
			py[0] = ran2(&seed);
			//printf("x = %g\n", x);
			//printf("%f\n", x[0]);
		dis = sqrt(px[0]*px[0] + py[0]*py[0]);		
		if (dis <=1.0)
		{
			#pragma omp critical
			nd ++;
		}
	
		}
	}
	printf("number of points inside the circle %d\n ", nd);
	pi = 4.0*nd/((float)nt);
	printf("pi is approximately %g\n", pi);
	times = omp_get_wtime() - times;
	printf("result computed in %g seconds\n", times);
}
