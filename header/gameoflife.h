#include "define.h"
#include <stddef.h>
__attribute__((always_inline))  void updateNeighbours(int top, int bottom, int left, int right,
                                                        int y, int x,size_t columns,int neigbours[][columns]);


void* gameOfLife(void* threadarg);
