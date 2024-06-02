#ifndef IE_C__

#define IE_C__

#include <stdio.h>
#include <stdlib.h>

int file_import(FILE *txtfile, FILE *binfile);

int file_export(FILE *binfile, FILE *txtfile);

#endif
