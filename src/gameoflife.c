#include "gameoflife.h"
#include <stdio.h>
void gameOfLife(int*** field, int rows, int columns)
{
    int neighbours[rows][columns];
    int m,n;
    for(m = 0; m < rows; m++)
    {
        for(n = 0; n < columns; n++)
        {
            neighbours[m][n] = 0;
        }
    }

    //printField(neighbours);

    for(m = 0; m < rows; m++)
    {
        for(n = 0; n < columns; n++)
        {
            if((*field)[m][n]) {

                if(m == 0)   //oben
                {
                    if(n == 0) //oben links
                        updateNeighbours(m, m+1, n, n+1, m, n, columns, neighbours);
                    else if(n == columns-1) //oben rechts
                        updateNeighbours(m, m+1, n-1, n, m, n, columns, neighbours);
                    else //oben
                        updateNeighbours(m, m+1, n-1, n+1, m, n, columns, neighbours);
                }
                else if (m == rows-1)     // unten
                {
                    if(n == 0) //unten links
                        updateNeighbours(m-1, m, n, n+1, m, n, columns, neighbours);
                    else if(n == columns-1) //unten rechts
                        updateNeighbours(m-1, m, n-1, n, m, n, columns, neighbours);
                    else
                        updateNeighbours(m-1, m, n-1, n+1, m, n, columns, neighbours);
                }
                else
                {
                    if(n == 0) //links
                        updateNeighbours(m-1, m+1, n, n+1, m, n, columns, neighbours);
                    else if (n == columns-1) //rechts
                        updateNeighbours(m-1, m+1, n-1, n, m, n, columns, neighbours);
                    else //sonst
                        updateNeighbours(m-1, m+1, n-1, n+1, m, n, columns, neighbours);
                }
            }
        }
    }
    int num;
    for(m = 0; m < rows; m++)
    {
        for(n = 0; n < columns; n++)
        {
            num = neighbours[m][n];
            #ifdef TEST
            printf("%d", num);
            #endif // TEST
            if (num < 2) //einsamkeit
                (*field)[m][n] = 0;
            else if (num == 3) //leben
                (*field)[m][n] = 1;
            else if (num > 3) //überbevölkerung
                (*field)[m][n] = 0;
        }
        #ifdef TEST
        printf("\n");
        #endif // TEST
    }
}

__attribute__((always_inline)) void updateNeighbours(int top, int bottom, int left, int right, int y, int x, size_t columns, int neighbours[][columns]) {
    int i,j;
    for(i=top; i<=bottom; i++)
    {
        for(j=left; j<= right; j++)
        {
            if(i != y || j != x)
                neighbours[i][j] += 1;
        }
    }
}
