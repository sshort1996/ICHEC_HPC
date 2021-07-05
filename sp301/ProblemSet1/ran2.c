/*
* This code generates random numbers between 0 and 1.
* This code is not threadsafe. Below is an example of * how to call ran2.
*
*   float x;
*   long seed=?;
*   x = ran2(seed);
*/
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
  #pragma omp critical
  iv[j] = *idum;
  if (iy < 1) iy += IMM1;
  if ((temp=AM*iy) > RNMX) 
    return RNMX; 
    else return temp;

}
//the idea is to make the fn ran2() thread safe. Let's try do this by looping 
//through the lines below in main() we'll then parallelise the loop and see where 
//ran2() has issues we should be able to make it threadsafe by only adding omp 
//directives ie. we wont edit the code itself
int main(int argc, char *argv[]){
	int n, i, tid;
	long seed;
	
	n = atoi(argv[1]);
	#pragma omp parallel shared(n), private(tid)
	{
		float *x = (float *) malloc(sizeof(float));
		#pragma omp for private(i, seed)
			for (i = 0; i <= n; i++){
				
				//tid=omp_get_thread_num();
				// printf("...\n");
				long seed=5*i;
				x[0] = ran2(&seed);
				//printf("x = %g\n", x);
				//printf("%f\n", x[0]);
			}
		
	}
	
}