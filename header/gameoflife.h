#include "define.h"
#include <stddef.h>
__attribute__((always_inline))  void updateNeighbours(int top, int bottom, int left, int right,
                                                        int y, int x,size_t columns);


void* gameOfLife(void* threadarg);
void updateField(int*** field, int rows, int columns);
