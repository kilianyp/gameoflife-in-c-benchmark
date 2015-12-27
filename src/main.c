/*
 * Game of life
 * Version 0.1
 * no parallelism
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "gameoflife.h"
#include "define.h"
#include "testlibrary.h"
#include "matrix.h"


int main() {

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
    while(x <= ITERATIONS) {
      gameOfLife(&matrix, M, N);
      //printField(&matrix, M, N);
      printf("iteration %d\n", x);
      x++;
    }
    end = clock();
    time = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("%d iterations of a %dx%d matrix took %fs!\n", ITERATIONS, M,N, time);

    return 0;
  #endif
}
