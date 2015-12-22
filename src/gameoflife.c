#include "gameoflife.h"

void gameOfLife(int*** field) {
  int copy[M][N];
  int m,n;
  for(m = 0; m < M; m++) {
    for(n = 0; n < N; n++) {
      copy[m][n] = (*field)[m][n];
    }
  }

  //printField(copy);

  for(m = 0; m < M; m++) {
    for(n = 0; n < N; n++) {
      int neighbours = 0;

      if(m == 0) { //oben
        if(n == 0) //oben links
          neighbours = checkFields(copy, m, m+1, n, n+1, m, n);
        else if(n == N-1) //oben rechts
          neighbours = checkFields(copy, m, m+1, n-1, n, m, n);
        else //oben
          neighbours = checkFields(copy, m, m+1, n-1, n+1, m, n);
      } else if (m == N-1) { // unten
        if(n == 0) //unten links
          neighbours = checkFields(copy, m-1, m, n, n+1, m, n);
        else if(n == N-1) //unten rechts
          neighbours = checkFields(copy, m-1, m, n-1, n, m, n);
        else
          neighbours = checkFields(copy,m-1, m, n-1, n+1, m, n);
      } else {
        if(n == 0) //links
          neighbours = checkFields(copy, m-1, m+1, n, n+1, m, n);
        else if (n == N-1) //rechts
          neighbours = checkFields(copy, m-1, m+1, n-1, n, m, n);
        else //sonst
          neighbours = checkFields(copy, m-1, m+1, n-1, n+1, m, n);
      }

      if (neighbours < 2) //einsamkeit
        (*field)[m][n] = 0;
      else if (neighbours == 3) //leben
        (*field)[m][n] = 1;
      else if (neighbours > 3) //überbevölkerung
        (*field)[m][n] = 0;
      #ifdef TEST
        printf("%d", neighbours);
      #endif // TEST
    }
    #ifdef TEST
        printf("\n");
    #endif // TEST
  }
}

int checkFields(int field[][N], int top, int bottom, int left, int right,
                int y, int x) {
  int neighbours = 0;
  int i,j;
  for(i=top; i<=bottom; i++) {
    for(j=left; j<= right; j++) {
      if(i != y || j != x)
        neighbours += field[i][j];
    }
  }
  return neighbours;
}
