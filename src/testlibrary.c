#include "testlibrary.h"


int compareFields(int A[][N], int B[][N]) {
    int m,n;
    for(m = 0; m < M; m++) {
        for (n=0; n < N; n++) {
            if(A[m][n] != B[m][n])
                return 0;

        }
    }
    return 1;
}

int simpleTest() {
    int matrix[M][N] = {{0, 0, 1, 0, 0, 1, 0, 1, 0,1 },
                        {0, 0, 1, 1, 0, 1, 1, 1, 0,1 },
                        {1, 0, 1, 0, 0, 0, 0, 1, 0,1 },
                        {0, 0, 1, 1, 0, 1, 0, 1, 0,1 },
                        {0, 0, 1, 1, 0, 1, 1, 1, 0,1 },
                        {1, 0, 1, 1, 0, 1, 0, 1, 0,1 },
                        {0, 0, 1, 1, 1, 1, 0, 1, 0,1 },
                        {0, 0, 1, 1, 0, 0, 0, 1, 0,1 },
                        {1, 0, 0, 1, 1, 1, 0, 1, 0,1 },
                        {0, 0, 1, 1, 0, 1, 0, 1, 0,1 }};

    return compareFields(matrix, matrix);

}
