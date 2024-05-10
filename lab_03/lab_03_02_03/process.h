#ifndef PROCESS_H__

#define PROCESS_H__


#include <stdlib.h>
#include "definitions.h"


int input_digit(int *digit);

size_t find_columns_with_digit(int (*a)[S], size_t rows, size_t columns, int *columns_to_delete, int digit);

void delete_columns(int (*a)[S], size_t rows, size_t *columns, int *columns_to_delete);

#endif
