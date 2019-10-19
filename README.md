# Parallel & Distributed Computing Assignments
Programs written in C with OpenMP or MPI.

<br>

**To run OpenMP programs**

```bash
    $ gcc <filename>.c -fopenmp
    $ ./a.out
```

**To run MPI programs**
```bash
    $ mpicc -o <filename> <filename>.c
    $ mpirun <filename>
```

<br>
<br>

### Questions:

1.  a) Using OpenMP, Design, develop and run a      multi-threaded program to perform and print     vector addition.

    b) Using OpenMP, Design, develop and run a multi-threaded program to perform Loop work Sharing.
    
    c) Using OpenMP, Design, develop and run a multi-threaded program to perform Section work sharing.

<br> 

2.  a) Using OpenMP, design, develop and run a      multi-threaded program to generate and          print Fibonacci series. One thread has to       generate the numbers up to the specified        limit and another thread has to print them.

    b) Using OpenMP, Design, develop and run a multi-threaded program to perform matrix multiplication.

<br>

3.  a) Using OpenMP, Design, develop and run a      multi-threaded program to perform Combined      parallel loop reduction.

    b) Using OpenMP, Design, develop and run a multi-threaded program to perform and Orphaned parallel loop reduction.

    c) Write a parallel loop that computes the maximum and minimum values in an array.

<br>

4.  a) Using MPI, Design, develop and run a         simple send/receive communication program.      initializes MPI, Transfer the data from         source to destination, then Finalizes           (Quits) MPI.

    b) Using MPI in visual studio, Design, develop and run message passing mechanisms.

<br>

5.  a) Using MPI, Design, develop and run           Broadcast communication (MPI_Bcast) using       MPI_Send and MPI_Recv.

    b) Using MPI, Design, develop and run reduce communication for vector addition (MPI_Reduce) using MPI_Send and MPI_Recv.

<br>

6.  a) Using MPI, Design, develop and run           matrix multiplication using MPI_Send and        MPI_Recv. In this code, the master task         distributes a matrix multiply operation to      numtasks-1 worker tasks.

    b) Using MPI, Design, develop and compute pi value using MPI_Send and MPI_Recv.