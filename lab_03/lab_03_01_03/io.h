#ifndef IO_H__

#define IO_H__


#include <stdlib.h>
#include "definitions.h"

int input_size(size_t *x);

int input_matrix(int (*a)[S], size_t rows, size_t columns);

void output_matrix(int (*a)[S], size_t rows, size_t columns);

#endif
