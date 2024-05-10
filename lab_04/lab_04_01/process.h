#ifndef PROCESS_H__

#define PROCESS_H__

#include <stddef.h>

char *my_strpbrk(const char *str_1, const char *str_2);
size_t my_strspn(const char *str_1, const char *str_2);
size_t my_strcspn(const char *str_1, const char *str_2);
char *my_strchr(const char *str, int chr);
char *my_strrchr(const char *str, int chr);

#endif
