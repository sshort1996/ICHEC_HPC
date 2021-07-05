program dervied
    use mpi
    implicit none

    integer (kind=4), parameter :: N=10,M=10
    integer (kind=4) :: i,j,ierror,world_size,world_rank
    integer (kind=4) :: src,dest,tag
    integer (kind=4), target :: A(N,M)
    integer (kind=4) :: matRow, matCol, subMat
    integer (kind=4), pointer :: ptr


    call MPI_Init( ierror )
    if (ierror .ne. 0) stop ' Cannot initialize MPI '


! Find our world rank & size to print it
    call MPI_Comm_rank( MPI_COMM_WORLD, world_rank, ierror )
    call MPI_Comm_size( MPI_COMM_WORLD, world_size, ierror )

    if ( world_size .le. 1 ) then
        write(6,*) 'Error: must be run on more that 1 process'
        call MPI_Abort( MPI_COMM_WORLD, 10, ierror )
    endif

    call MPI_Type_vector( M, 1, N, MPI_INTEGER, matRow, ierror )
    call MPI_Type_commit( matRow, ierror )
    call MPI_Type_vector( 1, N, 1, MPI_INTEGER, matCol, ierror )
    call MPI_Type_commit( matCol, ierror )
    call MPI_Type_vector( 3, 2, N, MPI_INTEGER, subMat, ierror )
    call MPI_Type_commit( subMat, ierror )

    call MPI_Type_size(subMat,i,ierror)
    write(6,*) ' Size ',i
    call MPI_Type_extent(SubMat,i,ierror)
     write(6,*) ' extent ',i

    do j = 1,M
        do i = 1,N
            A(i,j) = world_rank;
        end do
    end do

! Will only send messages from 0 to 1
    src = 0; dest = 1; tag = 5;

! Send the 0th row
    if ( world_rank .eq. 0 ) then
        ptr => A(1,1)
        call MPI_Send( ptr, 1, matRow, dest, tag, MPI_COMM_WORLD, ierror )

    else if ( world_rank .eq. 1 ) then
        ptr => A(1,1)
        call MPI_Recv( ptr, 1, matRow, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE, ierror );
    endif

! Let's print the matrix on rank 1 for illustration
! This also resets the matrix
    if ( world_rank .eq. 1 ) then
        write(6,*) 'Should have received the first row:'
        do i = 1,N
            do j = 1,M
                write(6,'(i4)',advance='NO') A(i,j)
                A(i,j) = world_rank
            end do
            write(6,*)
        end do
        write(6,*)
    endif

! Send the 0th column
    if ( world_rank .eq. 0 ) then
        ptr => A(1,1)
        call MPI_Send( ptr, 1, matCol, dest, tag, MPI_COMM_WORLD, ierror )

    else if ( world_rank .eq. 1 ) then
         ptr => A(1,1)
        call MPI_Recv( ptr, 1, matCol, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE, ierror )
    endif

! Let's print the matrix on rank 1 for illustration
! This also resets the matrix
    if ( world_rank .eq. 1 ) then
        write(6,*) 'Should have received the 1st column:'
        do  i = 1,N
            do j = 1,M
                write(6,'(i4)',advance='NO') A(i,j)
                A(i,j) = world_rank
            end do
            write(6,*)
        end do
        write(6,*)
    endif

! Send the 0th column, but receive into the 4th column
    if ( world_rank .eq. 0 ) then
        ptr => A(1,1)
        call MPI_Send( ptr, 1, matCol, dest, tag, MPI_COMM_WORLD, ierror )

    else if ( world_rank .eq. 1 ) then
        ptr => A(1,5)
        call MPI_Recv( ptr, 1, matCol, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE, ierror )
    endif

! Let's print the matrix on rank 1 for illustration
! This also resets the matrix
    if ( world_rank .eq. 1 ) then
        write(6,*) 'Should have received into the 5th column:'
        do  i = 1,N
            do j = 1,M
                write(6,'(i4)',advance='NO')  A(i,j)
                A(i,j) = world_rank
            end do
            write(6,*)
        end do
        write(6,*)
    endif

! Send a submatrix
    if ( world_rank .eq. 0 ) then
        ptr => A(1,1)
        call MPI_Send( ptr, 1, subMat, dest, tag, MPI_COMM_WORLD, ierror )

    else if ( world_rank .eq. 1 ) then
        ptr => A(1,1)
        call MPI_Recv( ptr, 1, subMat, src, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE, ierror )
    endif

! Let's print the matrix on rank 1 for illustration
! This also resets the matrix
    if ( world_rank .eq. 1 ) then
        write(6,*) 'Should have received into the top left corner:'
        do i = 1,N 
            do  j = 1,M 
                write(6,'(i4)',advance='NO') A(i,j)
                A(i,j) = world_rank
            end do
            write(6,*)
        end do
        write(6,*)
    endif

    call MPI_Finalize(ierror)
end program dervied
