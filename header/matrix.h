#ifndef __MATRIX__
#define __MATRIX__
#include <stddef.h>

void printField(int*** field, int rows, int columns);
int initField(int*** field, int rows, int columns);
void initRandomField(int*** field, int rows, int colums);
int randomOne();
int*** copyMatrixToHeap(size_t rows, size_t columns, int matrix[rows][columns]);
void cleanMatrix(int*** mat);
void initNeigbourMatrix(int rows, int columns);

#endif
