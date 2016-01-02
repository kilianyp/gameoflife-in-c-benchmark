#include "gameoflife.h"
#include <stdio.h>
void* gameOfLife(void *threadarg)
{

    thread_data* data = (thread_data*) threadarg;
    int rows_per_thread = data->rows/NTHREADS;
    int row_start = rows_per_thread*(data->thread_id), row_end = rows_per_thread*(data->thread_id+1);
    int*** field = data->field;
    //smaller matrix
    int m,n;

    //printField(neighbours);

    for(m = row_start; m < row_end; m++)
    {
        for(n = 0; n < data->columns; n++)
        {
            if((*field)[m][n]) {

                if(m == 0)   //oben
                {
                    if(n == 0) //oben links
                        updateNeighbours(m, m+1, n, n+1, m, n, data->columns);
                    else if(n == data->columns-1) //oben rechts
                        updateNeighbours(m, m+1, n-1, n, m, n, data->columns);
                    else //oben
                        updateNeighbours(m, m+1, n-1, n+1, m, n, data->columns);
                }
                else if (m == data->rows-1)     // unten
                {
                    if(n == 0) //unten links
                        updateNeighbours(m-1, m, n, n+1, m, n, data->columns);
                    else if(n == data->columns-1) //unten rechts
                        updateNeighbours(m-1, m, n-1, n, m, n, data->columns);
                    else
                        updateNeighbours(m-1, m, n-1, n+1, m, n, data->columns);
                }
                else
                {
                    if(n == 0) //links
                        updateNeighbours(m-1, m+1, n, n+1, m, n, data->columns);
                    else if (n == data->columns-1) //rechts
                        updateNeighbours(m-1, m+1, n-1, n, m, n, data->columns);
                    else //sonst
                        updateNeighbours(m-1, m+1, n-1, n+1, m, n, data->columns);
                }
            }
        }
    }

}

__attribute__((always_inline)) void updateNeighbours(int top, int bottom, int left, int right, int y, int x, size_t columns) {
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

void* updateField(void *threadarg) {
    thread_data* data = (thread_data*) threadarg;
    int rows_per_thread = data->rows/NTHREADS;
    int row_start = rows_per_thread*(data->thread_id), row_end = rows_per_thread*(data->thread_id+1);
    int num, m, n;

    for(m = row_start; m < row_end; m++)
    {
        for(n = 0; n < data->columns; n++)
        {
            num = neighbours[m][n];
            #ifdef TEST
            printf("%d", num);
            #endif // TEST
            if (num < 2) //einsamkeit
                (*data->field)[m][n] = 0;
            else if (num == 3) //leben
                (*data->field)[m][n] = 1;
            else if (num > 3) //überbevölkerung
                (*data->field)[m][n] = 0;
        }
        #ifdef TEST
        printf("\n");
        #endif // TEST
    }
}
