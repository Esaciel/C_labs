/*
Программа позволяет создать файл с заданным количеством чисел типа int в заданный бинарный файл с ключом "c",
Вывести все числа из подаваемого строготипизированного файла на экран с ключом "p",
Отсортировать числа в подаваемом строготипизированном файле с ключом "s"


Для работы со всеми файлами выбран формат (signed)int
Алгоритм сортировки - сортировка пузырьком по возрастанию
Проверка строгой типизации выполнена путем проверки кратности размера файла размеру типа unsigned int
Попытка вывода или сортировки пусмтого файла счиатется как ошибочная ситуация
Обработка ключей "c" и "s" находится в одном файле, т.к. ключ "c" не проверяется и вынос его в отдельный файл вызывает ошибку покрытия в системе тестирования

Также реализованы ключи import и export для превращения текстового файла в бинарный и наоборот соответственно
*/
#include <string.h>
#include <errno.h>
#include "definitions.h"
#include "ie.h"
#include "extract.h"
#include "c_and_s_keys.h"
#include <ctype.h>

// Функция вывода сообщения с использованием при использовании неверного набора ключей
void usage(const char *name)
{
    fprintf(stderr, "Использование: %s import <infile.txt> <outfile.bin>\n", name);
    fprintf(stderr, "        или:   %s export <infile.bin> <outfile.tmp>\n", name);
    fprintf(stderr, "        или:   %s c <num> <outfile.bin>\n", name);
    fprintf(stderr, "        или:   %s p <infile.bin>\n", name);
    fprintf(stderr, "        или:   %s s <infile.bin>\n", name);
}

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        usage(argv[0]);
        return USAGE_ERROR;
    }
    // Проврека ключа import
    if (strcmp(argv[1], "import") == 0)
    {
        // Проверка количества аргументов
        if (argc != 4)
        {
            usage(argv[0]);
            return USAGE_ERROR;
        }
        // Открытие входного текстового и выходного бинарного файлов, проверка доступа к ним
        FILE *in_txt = fopen(argv[2], "r");
        if (in_txt == NULL)
        {
            fprintf(stderr, "Errno %d; %s\n", errno, strerror(errno));
            return FILE_ACCESS_ERROR;
        }
        FILE *out_bin = fopen(argv[3], "wb");
        if (out_bin == NULL)
        {
            fprintf(stderr, "Errno %d; %s\n", errno, strerror(errno));
            fclose(in_txt);
            return FILE_ACCESS_ERROR;
        }
        // Выход с кодом ошибки в случае её возникновения по время превращения текстовых данных в бинарные
        int check = file_import(in_txt, out_bin);
        fclose(in_txt);
        fclose(out_bin);
        if (check != OK)
        {
            return check;
        }
    }
    // Проверка ключа export 
    else if (strcmp(argv[1], "export") == 0)
    {
        // Проверка количества аргументов
        if (argc != 4)
        {
            usage(argv[0]);
            return USAGE_ERROR;
        }
        // Открытие входного бинарного и выходного текстового файлов, проверка доступа к ним
        FILE *in_bin = fopen(argv[2], "rb");
        if (in_bin == NULL)
        {
            fprintf(stderr, "Errno %d; %s\n", errno, strerror(errno));
            return FILE_ACCESS_ERROR;
        }
        FILE *out_tmp = fopen(argv[3], "w");
        if (out_tmp == NULL)
        {
            fprintf(stderr, "Errno %d; %s\n", errno, strerror(errno));
            fclose(in_bin);
            return FILE_ACCESS_ERROR;
        }
        // Выход с кодом ошибки в случае её возникновения по время превращения бинарных данных в текстовые
        int check = file_export(in_bin, out_tmp);
        fclose(in_bin);
        fclose(out_tmp);
        if (check != OK)
        {
            return check;
        }
    }
    // Проверка на ключ для создания файлов
    else if (strcmp(argv[1], "c") == 0)
    {
        // Проверка количества аргументов
        if (argc != 4)
        {
            usage(argv[0]);
            return USAGE_ERROR;
        }
        // Проверка корректности введённого количества чисел при создании файла
        for (size_t i = 0; i < strlen(argv[2]); i++)
        {
            if (!isdigit(argv[2][i]))
            {
                fprintf(stderr, "Неверный аргумент для количества с ключом c\n");
                return WRONG_NUMARG_C_ERROR;
            }
        }
        // Превращения числовой строки в число
        int n = atoi(argv[2]);

        // Открытие бинарного файла для записи и проверка ошибки доступа
        FILE *out_bin = fopen(argv[3], "wb");
        if (out_bin == NULL)
        {
            fprintf(stderr, "Errno %d; %s\n", errno, strerror(errno));
            return FILE_ACCESS_ERROR;
        }
        // Вызов функции для создания файла
        fill_file(out_bin, n);
        fclose(out_bin);
    }
    // Проверка на ключ для вывода файла
    else if (strcmp(argv[1], "p") == 0)
    {
        // Проверка количества аргументов
        if (argc != 3)
        {
            usage(argv[0]);
            return USAGE_ERROR;
        }
        // Открытие бинарного файла для чтения и проверка ошибки доступа
        FILE *out_bin = fopen(argv[2], "rb");
        if (out_bin == NULL)
        {
            fprintf(stderr, "Errno %d; %s\n", errno, strerror(errno));
            return FILE_ACCESS_ERROR;
        }
        // Вызов функции для вывода чисел и выход с кодом ошибки в случае её возникновения
        int check = extract_numbers(out_bin);
        fclose(out_bin);
        if (check != OK)
        {
            return check;
        }
    }
    // Проверка на ключ для сортировки файла
    else if (strcmp(argv[1], "s") == 0)
    {
        // Проверка количества аргументов
        if (argc != 3)
        {
            usage(argv[0]);
            return USAGE_ERROR;
        }
        // Открытие бинарного файла для чтения и записи, и проверка ошибки доступа
        FILE *in_bin = fopen(argv[2], "r+b");
        if (in_bin == NULL)
        {
            fprintf(stderr, "Errno %d; %s\n", errno, strerror(errno));
            return FILE_ACCESS_ERROR;
        }
        // Вызов функции сортировки и выход с кодом ошибки в случае её возникновения
        int check = sortfile(in_bin);
        fclose(in_bin);
        if (check != OK)
        {
            return check;
        }
    }
    // Выход с кодом ошибки в случае неверного первого ключа
    else
    {
        usage(argv[0]);
        return USAGE_ERROR;
    }

    return OK;
}
