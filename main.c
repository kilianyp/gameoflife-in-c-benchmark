/*
 * Game of life
 * Version 0.1
 * no parallelism
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define M 10 //Zeilen
#define N 10 //Spalten


int randomOne() {
  return round((double)rand() / (double)RAND_MAX);
}

//print field
void printField(int field[][N]) {

  printf("printing Field\n");
  int n,m;

  for(m = 0; m < M; m++) {
    for(n = 0; n < N; n++) {
      printf("%d",field[m][n]);
    }
    printf("\n");
  }
}

//initialize random Field
void initField(int field[][N]) {
  printf("initializing Field\n");
  int n,m;
  srand(time(0));

  for(m = 0; m < M; m++) {
    for(n = 0; n < N; n++) {
      field[m][n] = randomOne();
    }
  }
}

void gameOfLife(int field[][N]) {
  for(m = 0; m < M; m++) {
    for(n = 0; n < N; n++) {
      int neighbours = 0;

      if(m == 0 && n == 0) { //oben links

      } else if (m == 0 && n == N-1) { // oben rechts

      } else if (m == N-1 && n == 0) { // unten links

      } else if (m == N-1 && n == N-1) // unten rechts
    }
  }
}

int main() {

  int matrix[M][N];


  initField(matrix);
  printField(matrix);

  return 0;

}
