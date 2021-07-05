program vecsum
  use mpi
  implicit none

  integer (kind=4) :: ierror, myRank, uniSize
  integer (kind=4) :: i,start,iend,n,ln,chunk
  real (kind=8) :: s,sums
  character (len=32) :: arg
  real (kind=8), allocatable :: a(:)


  call MPI_Init(ierror)
  call MPI_Comm_size(MPI_COMM_WORLD,uniSize,ierror)
  call MPI_Comm_rank(MPI_COMM_WORLD,myRank,ierror)

!
! read in commonad line options
!
  if (COMMAND_ARGUMENT_COUNT() /=1) then
    write(*,'(a)')"Wrong usage!!!"
    write(*,'(a)')"Correct usage: "
    CALL get_command_argument(0, arg)
    write(*,'(a)')trim(arg)//" <n> "
    write(*,'(a)')trim(arg)//" 1000 "
    call MPI_Abort(MPI_COMM_WORLD,-101,ierror)
  endif

  CALL get_command_argument(1, arg)
  read(arg,*) n


  chunk=n/uniSize
  start=myRank*chunk+1
  iend=min((myRank+1)*chunk,n)

  if (myRank .eq. uniSize-1) iend = n

!
! Create a sub vector on each process
!
  ln=iend-start;
  allocate(a(ln))
 
!
! initialize vector
!
  forall (i=1:ln) a(i) = real(i)/n
  s=0; sums=0.0;

  s=sum(a)
!
! Perform the reduce
!
  call MPI_Reduce(s,sums,1,MPI_REAL8,MPI_SUM,0,MPI_COMM_WORLD,ierror);

  if (myRank .eq. 0) write(6,*) 'total sum is: ',sums

  deallocate(a)
  call MPI_Finalize(ierror)

end program vecsum
