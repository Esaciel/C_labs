#ifndef PROCESS_H__

#define PROCESS_H__


#include "definitions.h"


int split_string(char *string, char *words, int *wordcount, int *z);

void write_to_resulting_string(char *resulting_string, char *words, int wordnum, int *sum_word_count);

#endif