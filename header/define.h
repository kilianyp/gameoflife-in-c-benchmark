#ifndef __DEFINE__
#define __DEFINE__

#define M 1000 //Zeilen
#define N 1000 //Spalten
#define ITERATIONS 500
#define NTHREADS 2

//struct to pass in argument
typedef struct{
    int thread_id;
    int ***field;
    int rows; //rows of the processed matrix
    int columns; //columns of the whole processed matrix
} thread_data;
#endif
