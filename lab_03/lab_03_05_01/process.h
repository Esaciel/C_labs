#ifndef PROCESS_H__

#define PROCESS_H__


#include <stdlib.h>
#include "definitions.h"


void extract_digits(int (*a)[S], size_t rows, size_t columns, int *digit_array, size_t *d_a_len);

void triple_left_rotate(int *array, size_t arrlen);

void return_digits(int (*a)[S], size_t rows, size_t columns, int *digit_array);

#endif
