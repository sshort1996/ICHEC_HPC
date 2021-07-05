program cartesian
    use mpi
    implicit none
    integer (kind=4), parameter  :: ndims=2, M=20, N=20

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

! Print the dims array to show how it has been changed
    if ( world_rank .EQ. 0 ) then
        write(6,*) 'dims array: ',dims(1), dims(2)
    endif

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

! Print some information about our rank
    write(6,'(a,i4,a,i4,a,i4,a,i4,a)') 'I am process ',world_rank,' of ', world_size,' on comm_world and ', &
           cart_rank,' of ',cart_size,' on comm_cart.'

   

! Compute the neighbours for each process
    do i=0,ndims-1
       call MPI_Cart_shift( comm_cart, i, 1, prev_rank, next_rank, ierror );
       write(6,'(a,i4,a,i2,a,i4,a,i4)') 'Process ',cart_rank,' on comm_cart. Direction ',i,' prev ', &
              prev_rank,' next ',next_rank
    end do

    call MPI_Finalize(ierror);

end program cartesian

