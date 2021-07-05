program gather
    use mpi
    implicit none

    integer (kind=4) :: i,ierror, world_rank, world_size
    character (len=1) :: letter
    real (kind=4) :: number(1000)
    character (len=1), allocatable :: buf(:)
  
    call MPI_Init( ierror )
    if (ierror .ne. 0) stop ' Cannot initialize MPI '

! Find our world rank & size to print it
    call MPI_Comm_rank( MPI_COMM_WORLD, world_rank, ierror )
    call MPI_Comm_size( MPI_COMM_WORLD, world_size, ierror )


    call random_seed( )
    call random_number(number)
    number = number*25.0 + 97.0;
    letter = achar(nint(number(10)))

! We need an array buf to hold one element from each process
    allocate(buf(0:world_size-1))

! Do the gather onto rank 0
    call MPI_Gather( letter, 1, MPI_CHARACTER, buf, 1, MPI_CHARACTER, 0, MPI_COMM_WORLD, ierror )


! Print the value on all processes
    if ( world_rank .eq. 0 )  then
            write(6,'(a,i0,a,i0)') 'I am process ',world_rank,' of ',world_size
        do i = 0,world_size-1
            write(6,'(a1)',advance='NO')  buf(i)
        end do
        write(6,*)
    endif

! Do the gather onto rank 1. We expect the same results
    call MPI_Gather( letter, 1, MPI_CHARACTER, buf, 1, MPI_CHARACTER, 1, MPI_COMM_WORLD, ierror )

! Print the value on all processes
    if ( world_rank .eq. 1 )  then
            write(6,'(a,i0,a,i0)') 'I am process ',world_rank,' of ',world_size
        do i = 0,world_size-1
           write(6,'(a1)',advance='NO') buf(i)
        end do
        write(6,*)
    endif

    call MPI_Finalize(ierror);
end program gather
