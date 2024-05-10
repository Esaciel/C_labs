#ifndef PROCESS_H__

#define PROCESS_H__


#include <stdlib.h>
#include "definitions.h"


void find_minimals(int (*a)[S], size_t rows, size_t columns, int *minimals);

void parallel_bubble_sort(int (*a)[S], size_t rows, size_t columns, int *minimals);

#endif
