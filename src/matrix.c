#include "matrix.h"
#include "define.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//print field
void printField(int*** field, int rows, int columns) {

  printf("printing Field\n");
  int n,m;

  for(m = 0; m < rows; m++) {
    for(n = 0; n < columns; n++) {
      printf("%d",(*field)[m][n]);
    }
    printf("\n");
  }
}

//initialize random Field
int initField(int*** field, int rows, int columns) {
	unsigned int iCnt;

	if (field == NULL) 	/* No memory allocated */
		return -1;	/* Error */

	*field = (int**) malloc(rows*sizeof(int*));

	if (*field == NULL)
		return -2;	/* Error */

	**field = (int*) malloc(rows*columns*sizeof(int));

	if (**field == NULL) {
		free(*field);	/* Clean up */
		*field = NULL;
		return -2;	/* Error */
	}

	for(iCnt = 1;iCnt<rows;iCnt++) { /* Assign pointers in the first "real index"; Value from 1 to N (0 yet set, value N means N+1) */
		(*field)[iCnt] = &((*field)[0][iCnt*columns]);
	}
	return 1;
}

void initRandomField(int*** field, int rows, int columns) {
    if(initField(field, rows, columns) < 0)
        return;

    int ones = 0;

    srand(time(0));
    int i,j;
    for(i=0; i<rows; i++) {
		for(j=0; j<columns; j++) {
			(*field)[i][j] = randomOne();
            if((*field)[i][j])
                ones +=1;
        }
    }
    printf("Matrix initialized with %d ones\n", ones);
}

void initNeighbourMatrix(int rows, int columns) {

    int m,n;
    for (m = 0; m < rows; m++) {
        for(n = 0; n < columns; n++)
            neighbours[m][n] = 0;
    }
}


int*** copyMatrixToHeap(size_t rows, size_t columns, int matrix[rows][columns]) {
    int m,n;
    int*** field = malloc(sizeof(int**));
    initField(field, rows, columns);

    for(m = 0; m < rows; m++) {
        for(n = 0; n < columns; n++) {
            (*field)[m][n] = matrix[m][n];
        }
    }
    return field;
}

int randomOne() {
  return rand() % 2;
}

void cleanMatrix(int*** mat) {
	if (mat != NULL) {
		if (*mat != NULL) {
			if (**mat != NULL)
				free(**mat);
			free(*mat);
			*mat = NULL;
		}
	}
}


