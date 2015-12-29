#include "gameoflife.h"
#include <stdio.h>
void* gameOfLife(void *threadarg)
{
    thread_data* data = (thread_data*) threadarg;
    int id = data->thread_id;
    int data_rows = data->rows;
    int rows_per_thread = data->rows/NTHREADS;
    int row_start = data->rows/NTHREADS*(data->thread_id), row_end = data->rows/NTHREADS*(data->thread_id+1);
    int*** field = data->field;
    //smaller matrix
    int neighbours[data->rows/NTHREADS][data->columns];
    int m,n;


    for(m = 0; m < rows_per_thread; m++)
    {
        for(n = 0; n < data->columns; n++)
        {
            neighbours[m][n] = 0;
        }
    }
    //printField(neighbours);
    //WHY -1???
    for(m = 0; m < rows_per_thread-1; m++)
    {
        for(n = 0; n < data->columns; n++)
        {
            if((*field)[m+row_start][n]) {

                if(m == 0)   //oben
                {
                    if(n == 0) //oben links
                        updateNeighbours(m, m+1, n, n+1, m, n, data->columns, neighbours);
                    else if(n == data->columns-1) //oben rechts
                        updateNeighbours(m, m+1, n-1, n, m, n, data->columns, neighbours);
                    else //oben
                        updateNeighbours(m, m+1, n-1, n+1, m, n, data->columns, neighbours);
                }
                else if (m == data->rows-1)     // unten
                {
                    if(n == 0) //unten links
                        updateNeighbours(m-1, m, n, n+1, m, n, data->columns, neighbours);
                    else if(n == data->columns-1) //unten rechts
                        updateNeighbours(m-1, m, n-1, n, m, n, data->columns, neighbours);
                    else
                        updateNeighbours(m-1, m, n-1, n+1, m, n, data->columns, neighbours);
                }
                else
                {
                    if(n == 0) //links
                        updateNeighbours(m-1, m+1, n, n+1, m, n, data->columns, neighbours);
                    else if (n == data->columns-1) //rechts
                        updateNeighbours(m-1, m+1, n-1, n, m, n, data->columns, neighbours);
                    else //sonst
                        updateNeighbours(m-1, m+1, n-1, n+1, m, n, data->columns, neighbours);
                }
            }
        }
    }
    int num;
    for(m = 0; m < data->rows/NTHREADS; m++)
    {
        for(n = 0; n < data->columns; n++)
        {
            num = neighbours[m][n];
            #ifdef TEST
            printf("%d", num);
            #endif // TEST
            if (num < 2) //einsamkeit
                (*field)[m+row_start][n] = 0;
            else if (num == 3) //leben
                (*field)[m+row_start][n] = 1;
            else if (num > 3) //überbevölkerung
                (*field)[m+row_start][n] = 0;
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
