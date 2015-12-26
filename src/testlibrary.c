#include "testlibrary.h"
#include "matrix.h"
#include "gameoflife.h"
#include <stdio.h>

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

    gameOfLife(matrixHeap, 10, 10);

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
    //printField(resultHeap, 10, 10);
    if(compareFields(matrixHeap, resultHeap, 10, 10))
        printf("testCaseOne successfull!\n");
    else
        printf("testCaseOne failed!\n");

    cleanMatrix(resultHeap);
    cleanMatrix(matrixHeap);


}
