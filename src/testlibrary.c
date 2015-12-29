#include "testlibrary.h"
#include "matrix.h"
#include "gameoflife.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int compareFields(int*** A, int*** B, int rows, int columns) {
    int m,n;
    for(m = 0; m < rows; m++) {
        for (n=0; n < columns; n++) {
            if((*A)[m][n] != (*B)[m][n])
                return 0;

        }
    }
    return 1;
}


void testCaseOne()  {
    int matrix[10][10] = {{0, 0, 1, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 1, 1, 0,1 },
                          {1, 0, 1, 0, 0, 0, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 1, 1, 0,1 },
                          {1, 0, 1, 1, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 1, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 0, 0, 1, 0,1 },
                          {1, 0, 0, 1, 1, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 0, 1, 0,1 }};

    int*** matrixHeap = copyMatrixToHeap(10,10,matrix);


    printField(matrixHeap, 10, 10);

    //gameOfLife(matrixHeap, 10, 10);

    printField(matrixHeap, 10, 10);

    int result[10][10] = {{0, 0, 1, 1, 1, 1, 0, 1, 0,0 },
                          {0, 0, 1, 1, 1, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 0, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 1, 0, 0, 0, 0, 0, 1, 0,1 },
                          {0, 1, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 0, 0, 0,0 }};


    int*** resultHeap = copyMatrixToHeap(10,10,result);
    printField(resultHeap, 10, 10);
    if(compareFields(matrixHeap, resultHeap, 10, 10))
        printf("testCaseOne successfull!\n");
    else
        printf("testCaseOne failed!\n");

    cleanMatrix(resultHeap);
    cleanMatrix(matrixHeap);


}

void parallelTest() {
        int matrix[10][10] = {{0, 0, 1, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 1, 1, 0,1 },
                          {1, 0, 1, 0, 0, 0, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 1, 1, 0,1 },
                          {1, 0, 1, 1, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 1, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 0, 0, 1, 0,1 },
                          {1, 0, 0, 1, 1, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 0, 1, 0,1 }};

    int*** matrixHeap = copyMatrixToHeap(10,10,matrix);

    printf("print original field");
    printField(matrixHeap, 10, 10);

    pthread_t threads[NTHREADS];
    thread_data *data = (thread_data*)malloc(sizeof(thread_data));
    thread_data testdata;

    //thread_data data[NTHREADS];

    int i;
    for(i = 0; i < NTHREADS; ++i) {

        data->thread_id = i;
        data->field = matrixHeap;
        data->rows = 10;
        data->columns = 10;
        testdata.thread_id = i;
        testdata.field = matrixHeap;
        testdata.rows = 10;
        testdata.columns = 10;
        printf("thread_id %d", data->thread_id);
        pthread_create(&threads[i], NULL, gameOfLife,&testdata);
        //printField(&matrix, M, N);

    }
    for(i = 0; i < NTHREADS; ++i)
            pthread_join ( threads [ i ] , NULL );

    printf("print calculated field");
    printField(matrixHeap, 10, 10);

    int result[10][10] = {{0, 0, 1, 1, 1, 1, 0, 1, 0,0 },
                          {0, 0, 1, 1, 1, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 0, 0, 1, 0,1 },
                          {0, 0, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 1, 0, 0, 0, 0, 0, 1, 0,1 },
                          {0, 1, 0, 0, 0, 1, 0, 1, 0,1 },
                          {0, 0, 1, 1, 0, 1, 0, 0, 0,0 }};


    int*** resultHeap = copyMatrixToHeap(10,10,result);
    printf("print correct field\n");
    printField(resultHeap, 10, 10);
    if(compareFields(matrixHeap, resultHeap, 10, 10))
        printf("parallelTest successfull!\n");
    else
        printf("parallelTest failed!\n");

    cleanMatrix(resultHeap);
    cleanMatrix(matrixHeap);



}
