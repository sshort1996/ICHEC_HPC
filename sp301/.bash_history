./steady2 100
export OMP_NUM_THREADS=1
./steady2 100
export OMP_NUM_THREADS=2
./steady2 100
export OMP_NUM_THREADS=16
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 100
export OMP_NUM_THREADS=1
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 100
export OMP_NUM_THREADS=4
./steady2 100
cd ProblemSet1
gcc -o steady2 steady2.c -fopenmp -lm
export OMP_NUM_THREADS=1
./steady2 10
export OMP_NUM_THREADS=4
./steady2 10
./steady2 100
./steady2 10
export OMP_NUM_THREADS=1
./steady2 10
gcc -o pi pi.c -fopenmp -lm
./pi 1000
./pi 10000
./pi 100000
export GET_NUM_THREADS=1
./pi 100000
export GET_NUM_THREADS=4
./pi 100000
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
export GET_NUM_THREADS=4
./pi 1000000
export GET_NUM_THREADS=4
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
export GET_NUM_THREADS=4
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
export GET_NUM_THREADS=1
./pi 1000000
export GET_NUM_THREADS=1
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 1000000
gcc -o pi pi.c -fopenmp -lm
./pi 100000000
gcc -o pi pi.c -fopenmp -lm
./pi 100000000
gcc -o pi pi.c -fopenmp -lm
./pi 100000000
gcc -o pi pi.c -fopenmp -lm
./pi 100000000
gcc -o pi pi.c -fopenmp -lm
./pi 100000000
gcc -o pi pi.c -fopenmp -lm
./pi 100000000
gcc -o pi pi.c -fopenmp -lm
./pi 10000
gcc -o pi pi.c -fopenmp -lm
./pi 10000
gcc -o pi pi.c -fopenmp -lm
./pi 10000
gcc -o pi pi.c -fopenmp -lm
./pi 10000
gcc -o pi pi.c -fopenmp -lm
./pi 10000
gcc -o pi pi.c -fopenmp -lm
./pi 10000
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 10
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 100
gcc -o steady2 steady2.c -fopenmp -lm
./steady2 1000
./steady2 500
mkdir practical04
cd practical04
touch simp.c
vi simp.c
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpirun ./simp 10
mpicc -o simp simp.c
mpirun ./simp 10
mpicc -o simp simp.c
mpirun ./simp 10
mpicc -o simp simp.c
mpirun ./simp
mpicc -o simp simp.c
mpirun ./simp
mpicc -o simp simp.c
mpirun ./simp
mpicc -o simp simp.c
mpirun ./simp
mpicc -o simp simp.c
mpirun ./simp
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp simp.c
mpirun ./simp 5
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2
mpicc -o simp2 simp2.c
mpirun ./simp2 0
mpicc -o simp3 simp3.c
mpirun ./simp2 100
mpirun ./simp3 100
mpicc -o simp3 simp3.c
mpirun ./simp3 100
mpicc -o simp3 simp3.c
mpirun ./simp3 100
mpirun -n 4 ./simp3 100
mpirun -n 12 ./simp3 100
mpicc -o simp3 simp3.c
mpirun -n 12 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 2 ./simp3 10
mpirun -n 3 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 3 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 3 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 3 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 3 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 3 ./simp3 10
mpicc -o simp3 simp3.c
mpirun -n 3 ./simp3
mpirun -np 3 ./simp3
mpicc -o sescatter sescatter.c
mpirun -n 4 ./sescatter 
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3
mpicc -o sescatter sescatter.c
mpirun -n 4 ./sescatter 
mpicc -o simp3 simp3.c
mpirun -n 4 ./sescatter 
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
dir
cd practical04
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 3 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpirun -np 3 ./simp3 6
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpirun -np 6 ./simp3 24
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 24
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 12
mpirun -np 6 ./simp3 6
mpirun -np 6 ./simp3 3
mpirun -np 6 ./simp3 24
mpicc -o simp3 simp3.c
mpirun -np 6 ./simp3 24
mpicc deriv -o deriv.c
mpicc deriv.c -o deriv
mpirun ./deriv
mpicc deriv.c -o deriv
mpirun ./deriv
mpirun ./deriv 2 2
mpicc deriv.c -o deriv
mpirun ./deriv 2 2
mpicc deriv.c -o deriv
mpirun ./deriv 2 2
mpicc deriv.c -o deriv
mpirun ./deriv 2 2
mpicc deriv.c -o deriv
mpirun ./deriv 2 2
gcc deriv.c -o deriv
./ deriv 2 2 
./deriv 2 2 
gcc deriv.c -o deriv
./deriv 2 2 
./deriv 4 4
gcc deriv.c -o deriv
mpicc deriv.c -o deriv
mpirun ./deriv 2 2
mpirun -np 2 ./deriv 2 2
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 2
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 2
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 2
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpirun -np 2 ./deriv 2 2
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 2
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpirun -np 2 ./deriv 4 2
mpirun -np 2 ./deriv 2 4
mpirun -np 2 ./deriv 43
mpirun -np 2 ./deriv 4 3
mpirun -np 2 ./deriv 1 2
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
cd practical04
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpirun -np 2 ./deriv 2 2
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 2
mpirun -np 2 ./deriv 2 3
mpirun -np 2 ./deriv 3 2
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 3 2
mpirun -np 2 ./deriv 2 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 2 3
mpirun -np 2 ./deriv 3 2
mpirun -np 2 ./deriv 3 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 3 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 3 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 3 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 3 3
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 3 4
mpirun -np 2 ./deriv 2 3
mpirun -np 2 ./deriv 3 2
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 3 2
mpirun -np 2 ./deriv 4 4
mpicc deriv.c -o deriv
mpirun -np 2 ./deriv 4 4
mpirun -np 2 ./deriv 4 3
mpirun -np 2 ./deriv 3 4
cd ProblemSet1
gcc steady3.c -o steady3
gcc steady3 -o steady3.c
gcc steady3.c -o steady3
./steady3 10
gcc steady3.c -o steady3
./steady3 10
gcc steady3.c -o steady3
./steady3 10
gcc steady3.c -o steady3
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
gcc steady3.c -o steady3 -fopenmp
./steady3 10
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=3
./steady3 100
export OMP_NUM_THREADS=5
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
export OMP_NUM_THREADS=12
./steady3 100
export OMP_NUM_THREADS=24
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
export OMP_NUM_THREADS=16
./steady3 100
export OMP_NUM_THREADS=16
./steady3 100
export OMP_NUM_THREADS=16
./steady3 100
export OMP_NUM_THREADS=16
./steady3 100
export OMP_NUM_THREADS=32
./steady3 100
export OMP_NUM_THREADS=32
./steady3 100
export OMP_NUM_THREADS=32
./steady3 100
export OMP_NUM_THREADS=32
./steady3 100
export OMP_NUM_THREADS=16
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=32
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=3
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=5
./steady3 100
export OMP_NUM_THREADS=6
./steady3 100
gcc steady3.c -o steady3 -fopenmp
cd ProblemSet1
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
export OMP_NUM_THREADS=12
./steady3 100
export OMP_NUM_THREADS=16
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
gcc steady3.c -o steady3 -fopenmp
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=1
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
gcc steady3.c -o steady3 -fopenmp
export OMP_NUM_THREADS=1
./steady3 100
gcc steady3.c -o steady3 -fopenmp
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
export OMP_NUM_THREADS=1
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
./steady4 90
./steady4 100
export OMP_NUM_THREADS=4
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
export OMP_NUM_THREADS=4
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
export OMP_NUM_THREADS=3
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
export OMP_NUM_THREADS=2
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
export OMP_NUM_THREADS=1
gcc steady4.c -o steady4 -fopenmp
./steady4 100
export OMP_NUM_THREADS=2
./steady4 100
export OMP_NUM_THREADS=4
./steady4 100
export OMP_NUM_THREADS=4
./steady4 100
gcc steady4.c -o steady4 -fopenmp
./steady4 100
export OMP_NUM_THREADS=5
./steady4 100
export OMP_NUM_THREADS=5
gcc steady4.c -o steady4 -fopenmp
./steady4 100
export OMP_NUM_THREADS=7
./steady4 100
EXIT
exit
cd ProblemSet1
gcc steady4.c -o steady4 -fopenmp
./steady4 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=1
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
export OMP_NUM_THREADS=4
./steady3 100
export OMP_NUM_THREADS=8
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
export OMP_NUM_THREADS=1
./steady3 100
export OMP_NUM_THREADS=1
./steady3 1000
./steady3 500
./steady3 200
export OMP_NUM_THREADS=2
./steady3 200
export OMP_NUM_THREADS=4
./steady3 200
export OMP_NUM_THREADS=8
./steady3 200
dir
vi pi.c
gcc pi.c -o pi -fopenmp
gcc pi.c -o pi -fopenmp -lm
./pi 1000
export OMP_NUM_THREADS=4
./pi 1000
export OMP_NUM_THREADS=4
./pi 1000
export OMP_NUM_THREADS=4
./pi 1000
gcc pi.c -o pi -fopenmp -lm
./pi 1000
./pi 10000
./pi 100000
gcc pi.c -o pi -fopenmp -lm
./pi 1000000
gcc pi.c -o pi -fopenmp -lm
./pi 1000000 4
./pi 1000000 8
./pi 1000000 12
./pi 1000000 16
./pi 1000000 32
./pi 1000000 64
gcc pi.c -o pi -fopenmp -lm
./pi 1000000 16
gcc steady3.c -o steady3 -fopenmp
./steady3 100
export OMP_NUM_THREADS=2
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
gcc steady3.c -o steady3 -fopenmp
./steady3 100
