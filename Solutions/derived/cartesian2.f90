program cartesian
    use mpi
    implicit none
    integer (kind=4), parameter  :: ndims=2, M=10, N=10

    integer (kind=4) :: i,j,k,ierror,reorder,matsize,localsum,globalsum
    integer (kind=4) :: world_rank, cart_rank
    integer (kind=4) :: world_size, cart_size
    integer (kind=4) :: Comm_cart, prev_rank, next_rank

    integer (kind=4), dimension(ndims) :: dims, periods
    integer (kind=4) :: A(N,M), randvec(N*M)
    real (kind=4) :: rvec(N*M)


    call MPI_Init( ierror )
    if (ierror .NE. 0) then
      write(6,*) ' Cannot start MPI '
      call MPI_Abort(MPI_COMM_WORLD,100,ierror)
    endif
 
    
! Get the world size and rank
    call MPI_Comm_size( MPI_COMM_WORLD, world_size, ierror )
    call MPI_Comm_rank( MPI_COMM_WORLD, world_rank, ierror ) 

    dims = 0
    call MPI_Dims_create( world_size, ndims, dims, ierror );
! Both dimensions will be periodic
    periods = 1
    reorder = 0
! Initialise our new communicator, note the name is informative
! Create it
    call MPI_Cart_create( MPI_COMM_WORLD, ndims, dims, periods, reorder, comm_cart, ierror )
    if (ierror .NE. 0) then
      write(6,*) ' Cannot create Comm_cart '
      call MPI_Abort(MPI_COMM_WORLD,101,ierror)
    endif
! Find the new size and rank
    call MPI_Comm_size( comm_cart, cart_size, ierror )
    call MPI_Comm_rank( comm_cart, cart_rank, ierror )
! Compute the neighbours for each process
    do i=0,ndims-1
       call MPI_Cart_shift( comm_cart, i, 1, prev_rank, next_rank, ierror );
    end do

! Allocate the submatrix for each process
    matsize = M*N
    
! Rank 0 creates the entire matrix
    if (world_rank .EQ. 0) then
       call random_seed
       call random_number(rvec)
       forall (i=1:matsize) randvec(i) = nint(rvec(i))
    endif

    call MPI_Bcast(randvec,matsize,MPI_INTEGER4,0,MPI_COMM_WORLD, ierror)

! Initialise sub-matrix with same random vector
    k = 0;
    do j=1,M
      do i=1,N
        A(i,j) = randvec(k)
        k = k + 1
      end do
    end do

! Sum the local part of the array
    localsum = sum(A)


! Print the local sum on each process
    write(6,'(a,i4,a,i4,a,i4)') 'I am process ',world_rank,' of ',world_size,' and sum is ',localsum


! Reduce the global sum on process 0
    call MPI_Reduce( localsum, globalSum, 1, MPI_INTEGER4, MPI_SUM, 0, MPI_COMM_WORLD, ierror )

! Print this global sum
    if ( world_rank .eq. 0 ) then
        write(6,*)  'Global sum is ',globalSum
    endif

    call MPI_Finalize(ierror);

end program cartesian

