#include <stdio.h>
#include <mpi.h>

int min(int a, int b);

int main(int argc, char **argv){

  int ierror,myRank,uniSize;
  int n;
  double *a;
  int ln,chunk,i,start,end;

  ierror=MPI_Init(&argc,&argv);
  ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
  ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);
/*
! Check input
*/
  if (argc!=2){
    printf("wrong usage, wrong number of parameters\n");
    printf("correct usage: %s <n>\n",argv[0]);
    ierror=MPI_Abort(MPI_COMM_WORLD,-101);
  }

/*
! Obtain size of sub-vector
*/
  n=atoi(argv[1]);
  chunk=n/uniSize;
  start=myRank*chunk;
  end=min((myRank+1)*chunk,n);
  if (myRank==uniSize-1) end = n;
  ln=end-start;//dimension of the sub-vector of each process
  a = (double *) malloc(ln*sizeof(double));

/*
! Initialize vector and calc sums 
*/
  for (i=0;i<ln;++i) a[i]=(double)(i)/(double)n;
  double s=0;
  double sum=0.0;
  for(i=0;i<ln;++i) s+=a[i];
  ierror=MPI_Reduce(&s,&sum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);
  if (myRank==0) printf("total sum is: %16.8f \n",sum);

/*
! Finish
*/
  free(a);
  ierror=MPI_Finalize();
  return ierror;
}

int min(int a, int b) {
    if (a > b)
        return b;
    return a;
}
