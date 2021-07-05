#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <time.h>

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

float ran2(long *idum);


int main(int argc, char** argv){

	long sx=0.0, sy= 0.0;
	
	int threads = atoi(argv[2]), nt = atoi(argv[1]), i=0,nd=0;
	printf("will use %d threads to check  %d random points \n", threads, nt);
	float x=0.0, y=0.0;

	#pragma omp parallel shared(nt) num_threads(threads)
	{
	//double *px = (double *) malloc(sizeof(double));
	//double *py = (double *) malloc(sizeof(double));
	//float x=0.0, y=0.0;
	//long sx=0.0, sy= 0.0;

	#pragma omp for //schedule(static)
		for (i = 0; i <nt; i++ ){
			long sx; 
			long sy;
			
			sx = (long)(13.0*i+1);
			sy = (long)(2.0*i-1);
			x = ran2(&sx);
			y = ran2(&sy);
			if (1.0 >= sqrt(x*x+y*y)){
				#pragma omp critical
				nd++;
			}
		}
	}
	printf("%f \n", (nd*4.0)/(float)nt);
}
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