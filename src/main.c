/*
 * Game of life
 * Version 3
 * parallelism
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include "gameoflife.h"
#include "define.h"
#include "testlibrary.h"
#include "matrix.h"
#ifndef TEST
    int neighbours[M][N];
#endif // TEST
int main()
{

#ifdef TEST
    printf("test running");
    parallelTest();

#else
    int x = 1;
    int ** matrix;
    initRandomField(&matrix, M, N);
    //printField(&matrix, M, N);

    struct timeval t1, t2;
    double elapsedTime;

    gettimeofday(&t1, NULL);
    int i;
    pthread_t threads[NTHREADS];
    thread_data data[NTHREADS];

    //thread_data data[NTHREADS];

    for(i = 0; i < NTHREADS; i++) {
        data[i].thread_id = i;
        data[i].field = &matrix;
        data[i].rows = M;
        data[i].columns = N;
    }

    while(x <= ITERATIONS)
    {
        for(i = 0; i < NTHREADS; ++i) {

            //printf("thread_id %d", data[i].thread_id);
            pthread_create(&threads[i], NULL, gameOfLife,&data[i]);
            //printField(&matrix, M, N);

        }
        /* wait for threads to finish */
        for(i = 0; i < NTHREADS; ++i)
            pthread_join ( threads [ i ] , NULL );

        updateField(&matrix, M, N);

        //printf("iteration %d\n", x);
        x++;

    }
    gettimeofday(&t2, NULL);
    elapsedTime = (t2.tv_sec - t1.tv_sec);
    elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000000.0;
    printf("%d iterations of a %dx%d matrix took %fs!\n", ITERATIONS, M,N, elapsedTime);
    //printField(&matrix,M ,N );
    cleanMatrix(&matrix);
    return 0;
#endif
}
