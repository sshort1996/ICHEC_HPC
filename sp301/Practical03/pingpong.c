/*Ping Pong message passing
- create an initial message 'msg' containing the integer value 10
- create 2 processes p0 and p1
- p0 increments 'msg' by 1 and passes to p1
- p1 increments 'msg' by 1 and passes back to p0
- repeat passing and inc. n times
- after n times print 'msg', average time per exchange from rank 0
- check the resolution of OMP_Wtime with OMP_WTICK()
*/
#include <stdio.h>
#include <mpi.h>

void msgsend(double *msg, int Rank, int tag, MPI_Datatype trans_type)
{
	//msg++;
	//args: message to pass, number & type of messages in buffer
	//		rank of sender/reciever, message tag, communicator
	MPI_Send(&msg, 1, trans_type, Rank ^ 1, tag, MPI_COMM_WORLD);
	//printf("rank %d sent message %d to rank %d\n", Rank, msg, Rank ^ 1);

	return;
}

void msgrecv(double *msg, int Rank, int tag, MPI_Datatype trans_type)
{
	//msg++;
	MPI_Recv(&msg, 1, trans_type, Rank , tag, MPI_COMM_WORLD,
		 MPI_STATUS_IGNORE);
	//printf("rank %d recieved message %d from rank %d\n", Rank ^ 1, msg, Rank);
	
	return;
}
double pingpong(int Rank, int i, int n, double *msg, int tag, int myRank, double time, MPI_Datatype trans_type)
{
	Rank = 1;
	
	if (myRank == 0){
		time = MPI_Wtime();
	}
	for (i = 0; i <= n; i++ )
	{
		Rank = Rank ^ 1;
		tag = i;
		if(myRank == Rank){
			msgsend(msg, Rank, tag, trans_type);
		}
		else if(myRank == Rank ^ 1){
			msgrecv(msg, Rank, tag, trans_type);
		}
	}
	return time;
}
int main(int argc, char *argv[]){

	int n, tag, ierror, i, myRank,uniSize, iMyName, Rank, len;
	char myName[MPI_MAX_PROCESSOR_NAME];
	MPI_Datatype trans_type;
	double time;
	
	printf("enter 2 as -n please. I dont know how to set comm size from source \n \n");
	n = atoi(argv[1]);
	//msg = atoi(argv[2]);
	len = atoi(argv[2]);
	double *msg = (double *) malloc(len*sizeof(double));
	
	for (i = 0; i <= len; i++){
		msg[i] = (double)i;
	}
	ierror=MPI_Init(&argc,&argv);
	ierror=MPI_Comm_size(MPI_COMM_WORLD,&uniSize);
	ierror=MPI_Comm_rank(MPI_COMM_WORLD,&myRank);	
	
	time = pingpong(Rank, i, n, msg, tag, myRank, time, MPI_INT);
	
	if (myRank == 0){
		time = MPI_Wtime() - time;
		printf("total time for %d pings: %g\n", n, time);
		printf("average time per ping: %g\n\n ", time/(double)n);
		printf("resolution of MPI wall clock : %g\n",MPI_Wtick());
	}
	
	ierror=MPI_Finalize();
	return ierror;
}



/*
MPI_Send(
    void* data,
    int count,
    MPI_Datatype datatype,
    int destination,
    int tag,
    MPI_Comm communicator)
	
	
MPI_Recv(
    void* data,
    int count,
    MPI_Datatype datatype,
    int source,
    int tag,
    MPI_Comm communicator,
    MPI_Status* status)
	
	if(myRank == 0){
		msg++;
		//args: message to pass, number & type of messages in buffer
		//		rank of sender/reciever, message tag, communicator
		MPI_Send(&msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("rank 0 sent message %d to rank 1\n", msg);
	}
	else if(myRank == 1){
		MPI_Recv(&msg, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
		printf("rank 1 recieved message %d from rank 0\n", msg);
	}
	if(myRank == 1){
		msg++;
		//args: message to pass, number & type of messages in buffer
		//		rank of sender/reciever, message tag, communicator
		MPI_Send(&msg, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		printf("rank 1 sent message %d to rank 0\n", msg);
	}
	else if(myRank == 0){
		MPI_Recv(&msg, 1, MPI_INT, 1, 0, MPI_COMM_WORLD,
             MPI_STATUS_IGNORE);
		printf("rank 0 recieved message %d from rank 1\n", msg);
	}
	
*/