#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "definitions.h"
#include "fbkey.h"

// Функция для ключа "fb"
int find_by_substr(char *file_src_name, char *file_dst_name, char *substr)
{
    student s;
    memset(&s, 0, sizeof(s));
    
    // Провекра длины подстроки для поиска (не может быть больше допустимой длины фамилии) 
    if (strlen(substr) > SURNAME_LEN)
    {
        fprintf(stderr, "Подстрока не может быть длиннее фамилии\n");
        return TOO_LONG_SUBSTR_ERROR;
    }

    // Открытие входного бинарного файла для чтения и проверка ошибки доступа к нему
    FILE *file_src = fopen(file_src_name, "rb");
    if (file_src == NULL)
    {
        fprintf(stderr, "%s; Errno %d; %s\n", file_src_name, errno, strerror(errno));
        return FILE_ACCESS_ERROR;
    }

    // Расчет размера входного файла и проверка кратности его размеру стуктуры которой он типизирован
    fseek(file_src, 0, SEEK_END);
    long int file_src_size = ftell(file_src);
    fseek(file_src, 0, SEEK_SET);
    if (file_src_size % sizeof(s) != 0)
    {
        fprintf(stderr, "Размер бинарного файла не соответствует размеру структуры\n");
        fclose(file_src);
        return BINFILE_SIZE_ERROR;
    }

    size_t num_of_structs = file_src_size / sizeof(s);

    // Открытие выходного бинарного файла для записи и проверка ошибки доступа к нему
    FILE *file_dst = fopen(file_dst_name, "wb");
    if (file_dst == NULL)
    {
        fclose(file_src);
        fprintf(stderr, "%s; Errno %d; %s\n", file_dst_name, errno, strerror(errno));
        return FILE_ACCESS_ERROR;
    }

    size_t position = 0;
    size_t counter = 0;

    // Цикл для поиска учеников с фамилией, начинающихся на заданную подстроку, во входном файле, и запись их в выходной файл
    while (position < num_of_structs)
    {
        fread(&s, sizeof(s), 1, file_src);
        if (strncmp(s.surname, substr, strlen(substr)) == 0)
        {
            fwrite(&s, sizeof(s), 1, file_dst);
            counter++;
        }
        position++;
    }
    fclose(file_src);
    fclose(file_dst);
    // Проверка счетчика переписанных учеников и выход с кодом ошибки если во входном файле не было найдено учеников с фамилией на заданную подстркоку
    if (counter == 0)
    {
        fprintf(stderr, "Во входном файле нет фамилий, начинающихся на заданную подстроку\n");
        return NO_SUBSTR_SURNAME_ERROR;
    }
    return OK;
}
