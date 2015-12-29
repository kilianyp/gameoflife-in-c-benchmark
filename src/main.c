/*
 * Game of life
 * Version 3
 * parallelism
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

#include "gameoflife.h"
#include "define.h"
#include "testlibrary.h"
#include "matrix.h"

int main()
{

#ifdef TEST
    printf("test running");
    testCaseOne();
#else
    int x = 1;
    int ** matrix;
    initRandomField(&matrix, M, N);
    //printField(&matrix, M, N);

    clock_t start, end;
    double time;


    start = clock();
    printf("hello");
    int rc, i;
    pthread_t threads[NTHREADS];
    thread_data *data = (thread_data*)malloc(sizeof(thread_data));

    //thread_data data[NTHREADS];

    while(x <= ITERATIONS)
    {
        for(i = 0; i < NTHREADS; ++i) {

            data->thread_id = i;
            data->field = &matrix;
            data->rows = M;
            data->columns = N;
            printf("thread_id %d", data->thread_id);
            rc = pthread_create(&threads[i], NULL, gameOfLife,data);
            //printField(&matrix, M, N);

        }
        /* wait for threads to finish */
        for(i = 0; i < NTHREADS; ++i)
            pthread_join ( threads [ i ] , NULL );

        printf("iteration %d\n", x);
        x++;

    }
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("%d iterations of a %dx%d matrix took %fs!\n", ITERATIONS, M,N, time);
    //printField(&matrix,M ,N );
    cleanMatrix(&matrix);
    return 0;
#endif
}
