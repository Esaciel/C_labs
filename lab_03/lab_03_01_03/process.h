#ifndef PROCESS_H__

#define PROCESS_H__


#include <stdlib.h>
#include "definitions.h"

void if_monotonous(int (*a)[S], int *k, size_t rows, size_t columns);

void output_array(int *a, size_t n);

#endif
