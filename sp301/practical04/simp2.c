#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include <time.h>

int main(int argc, char** argv)
{
	int ierror, uniSize, myRank, num, i;
	char buf;
	const int root = atoi(argv[1]);
	
	//PASS MESSAGES THROUGH BROADCAST
	
	//start MPI
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);

	srand(myRank + time(NULL));
	num = (int)((int)rand()/(double)RAND_MAX*25 + 97);
	buf = (char)num;
	char recvbuf[3];
	//char *recvbuf = (char *) malloc(len*sizeof(char));
	i = 0;
	if(myRank == 0)
	{
		do
		{
			//recvbuf[i] = 0;
			printf(" recvbuf : %d\n ", recvbuf[i]);
			i++;
		}while( i < 3 );
	}	
	
	printf("Rank %d num : %d\n \n", myRank, num);
	printf("Rank %d buf : %c\n \n", myRank, buf);

	MPI_Gather(&buf, 1, MPI_CHAR, recvbuf, 1, MPI_CHAR, 
               root, MPI_COMM_WORLD);

	i = 0;
	if(myRank == root)
	{
		do
		{
			printf(" recvbuf : %c\n ", recvbuf[i]);
			i++;
		}while( i < 3);
	}
	ierror = MPI_Finalize();
}
