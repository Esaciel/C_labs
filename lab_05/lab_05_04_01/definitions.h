#ifndef DEFINITIONS_H__

#define DEFINITIONS_H__

#define OK                       0
#define FILE_ACCESS_ERROR        1
#define IMPORT_ERROR             2
#define BINFILE_SIZE_ERROR       3
#define BINFILE_EXPORT_ERROR     4
#define TOO_LONG_SUBSTR_ERROR    5
#define NO_SUBSTR_SURNAME_ERROR  6
#define EMPTY_BINFILE_ERROR      7
#define PARAMETER_ERROR         53

#define _XOPEN_SOURCE          500 // По какой-то причине не подключалась автоматически, из-за чего ftruncate была не определена

#define SURNAME_LEN             25
#define NAME_LEN                10
#define GRADES_COUNT             4

typedef struct
{
    char surname[SURNAME_LEN + 2];
    char name[NAME_LEN + 2];
    unsigned int grades[GRADES_COUNT];
} student;

#endif // DEFINITIONS_H__
