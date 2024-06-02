#include "definitions.h"
#include "ie.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

// Функция для ключа import
int f_import(char *txtfilename, char *binfilename)
{
    // Откртиые входного текстового и выходного бинарного файлов, проверка доступа к ним
    FILE *txtfile = fopen(txtfilename, "r");
    if (txtfile == NULL)
    {
        fprintf(stderr, "%s; Errno %d; %s\n", txtfilename, errno, strerror(errno));
        return FILE_ACCESS_ERROR;
    }
    FILE *binfile = fopen(binfilename, "wb");
    if (binfile == NULL)
    {
        fprintf(stderr, "%s, Errno %d; %s\n", binfilename, errno, strerror(errno));
        fclose(txtfile);
        return FILE_ACCESS_ERROR;
    }
    unsigned int tmp;
    student s;
    memset(&s, 0, sizeof(s));
    size_t count = 0;
    // Цикл для чтения структур из входного файла по чтению фамилии
    while (fgets(s.surname, sizeof(s.surname), txtfile) != NULL)
    {
        count++;
        // Замена символа новой строки в фамилии на нулевой байт, выход с кодом возврата если этот символ не обнаружен (т.к. тогда длина фамилии больше допустимой)
        if (s.surname[strlen(s.surname) - 1] == '\n')
        {
            s.surname[strlen(s.surname) - 1] = '\0';
        }
        else
        {
            fprintf(stderr, "Слишком длинная фамилия во входном файле\n");
            return IMPORT_ERROR;
        }
        // Чтение имени и замена символа новой строки на нулевой байт, выход с кодом возврата если этот символ не обнаружен (т.к. тогда длина имения больше допустимой)
        if (fgets(s.name, sizeof(s.name), txtfile) == NULL)
        {
            return IMPORT_ERROR;
        }
        else if (s.name[strlen(s.name) - 1] != '\n')
        {
            return IMPORT_ERROR;
        }
        else
        {
            s.name[strlen(s.name) - 1] = '\0';
        }

        // Чтение четырех беззнаковых чисел и выход в случае ошибки чтения
        for (int i = 0; i < GRADES_COUNT; i++)
        {
            if (fscanf(txtfile, "%u", &s.grades[i]) != 1)
            {
                return IMPORT_ERROR;
            }
        }
        // Чтение еще одного беззнакового числа для проверки что их не больше четырех а также для переноса файловго указателя к следующей структуре
        // Также проверка что после этого чтения не достигнут конец файла, т.к. это не обработается за ошибку, но корректно обработается при чтении следующей фамилии как остановка чтения
        if (fscanf(txtfile, "%u", &tmp) != 0 && !feof(txtfile))
        {
            return IMPORT_ERROR;
        }
        // Запись очередной только что прочитанной структуры в выходной бинарный файл
        fwrite(&s, sizeof(s), 1, binfile);
        memset(&s, 0, sizeof(s));
    }
    fclose(txtfile);
    fclose(binfile);
    return OK;
}

// Функция для ключа export
int f_export(char *binfilename, char *txtfilename)
{
    student s;
    memset(&s, 0, sizeof(s));
    // Откртиые входного юинарного файла, проверка доступа к нему
    FILE *binfile = fopen(binfilename, "rb");
    if (binfile == NULL)
    {
        fprintf(stderr, "%s; Errno %d; %s\n", binfilename, errno, strerror(errno));
        return FILE_ACCESS_ERROR;
    }

    // Расчет размера бинарного файла и проверка кратности его размеру структуры которой он типизирован
    fseek(binfile, 0, SEEK_END);
    long int binfile_size = ftell(binfile);
    fseek(binfile, 0, SEEK_SET);
    if (binfile_size % sizeof(s) != 0)
    {
        fprintf(stderr, "Размер бинарного файла не соответствует размеру структуры\n");
        fclose(binfile);
        return BINFILE_SIZE_ERROR;
    }

    // Откртиые выходного текстового файла, проверка доступа к нему
    FILE *txtfile = fopen(txtfilename, "w");
    if (txtfile == NULL)
    {
        fprintf(stderr, "%s; Errno %d; %s\n", txtfilename, errno, strerror(errno));
        fclose(binfile);
        return FILE_ACCESS_ERROR;
    }

    // Чтение записей из бинарного файла и переписывание его полей по одному в стрке в выходной текстовый файл
    while (ftell(binfile) < binfile_size)
    {
        fread(&s, sizeof(s), 1, binfile);
        fprintf(txtfile, "%s\n%s\n%u %u %u %u\n", s.surname, s.name, s.grades[0], s.grades[1], s.grades[2], s.grades[3]);
    }

    fclose(binfile);
    fclose(txtfile);
    return OK;
}
