/*
 * Game of life
 * Version 0.1
 * no parallelism
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "testlibrary.h"
#include "gameoflife.h"
#include "define.h"


int randomOne() {
  return rand() % 2;
}

//print field
void printField(int*** field) {

  printf("printing Field\n");
  int n,m;

  for(m = 0; m < M; m++) {
    for(n = 0; n < N; n++) {
      printf("%d",(*field)[m][n]);
    }
    printf("\n");
  }
}

//initialize random Field
int initField(int*** field) {
    srand(time(0));
	unsigned int iCnt;
	unsigned int i, j;

	if (field == NULL) 	/* No memory allocated */
		return -1;	/* Error */

	*field = (int**) malloc(M*sizeof(int*));

	if (*field == NULL)
		return -2;	/* Error */

	**field = (int*) malloc(M*N*sizeof(int));

	if (**field == NULL) {
		free(*field);	/* Clean up */
		*field = NULL;
		return -2;	/* Error */
	}

	for(iCnt = 1;iCnt<M;iCnt++) { /* Assign pointers in the first "real index"; Value from 1 to N (0 yet set, value N means N+1) */
		(*field)[iCnt] = &((*field)[0][iCnt*N]);
	}
    printf("%d", randomOne());
	for(i=0; i<M; i++)
		for(j=0; j<N; j++) {

			(*field)[i][j] = randomOne();
        }
	return 0;
}





int main() {


  #ifdef TEST
    printf("test running");
    int fieldrix[M][N] = {{0, 1, 1, 0, 0, 1, 0, 1, 0,1 },
                        {0, 0, 1, 1, 0, 0, 1, 1, 0,1 },
                        {1, 0, 1, 0, 0, 0, 0, 1, 0,1 },
                        {0, 0, 1, 1, 0, 1, 0, 1, 0,0 },
                        {0, 0, 1, 1, 0, 1, 1, 1, 0,1 },
                        {1, 0, 1, 1, 0, 1, 0, 1, 1,1 },
                        {0, 1, 1, 1, 1, 1, 0, 1, 0,0 },
                        {0, 0, 1, 1, 0, 0, 0, 0, 0,1 },
                        {1, 0, 0, 1, 1, 1, 0, 1, 1,1 },
                        {0, 0, 1, 1, 0, 1, 0, 1, 0,1 }};
    printField(fieldrix);
    gameOfLife(fieldrix);
    printField(fieldrix);
    if(simpleTest())
        printf("success");
    else
        printf("nosuccess");
  #else
    int x = 0;
    int ** matrix;
    initField(&matrix);
    printField(&matrix);
    while(x < 10) {
      gameOfLife(&matrix);
      printField(&matrix);
      printf("iteration %d\n", x);
      x++;
    }
    return 0;
  #endif
}
