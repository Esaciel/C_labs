/*
Вариант 1, задания 2,3 (b, c), тип файлов - бинарные
Реализованы ключи import и export для превращения текстовых данных в бинарные и наоборот

Задание 2 - ключ fb
Поиск во входном файле студентов с фамилией, начинающейся на заданную подстроку, и запись таковых в выходной бинарный файл

Задание 3 - ключ db
Удаления из данного бинарного файла студентов, чей средний балл меньше среднего балла по всем студентам в данном файле
*/
#include "definitions.h"
#include "ie.h"
#include "dbkey.h"
#include "fbkey.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Функция вывода сообщения об использовании
void usage(char *name)
{
    fprintf(stderr, "Использование: %s fb FILE_SRC.bin FILE_DST.bin SUBSTR\n", name);
    fprintf(stderr, "        или:   %s db FILE.bin\n", name);
}

int main(int argc, char **argv)
{
    // Проверка корректного числа аргументов
    if (argc < 3)
    {
        usage(argv[0]);
        return PARAMETER_ERROR;
    }
    // Проверка ключа improt
    else if (strcmp(argv[1], "import") == 0)
    {
        // Проверка корректности числа аргументов
        if (argc != 4)
        {
            usage(argv[0]);
            return PARAMETER_ERROR;
        }
        // Вызов функции импорта и выход с кодом ошибки в случае её возникновения
        int check = f_import(argv[2], argv[3]);
        if (check != OK)
        {
            return check;
        }
    }
    // Проверка ключа export
    else if (strcmp(argv[1], "export") == 0)
    {
        // Проверка корректности числа аргументов
        if (argc != 4)
        {
            usage(argv[0]);
            return PARAMETER_ERROR;
        }
        // Вызов функции экспорта и выход с кодом ошибки в случае её возникновения
        int check = f_export(argv[2], argv[3]);
        if (check != OK)
        {
            return check;
        }
    }
    // Проверка ключа "fb"
    else if (strcmp(argv[1], "fb") == 0)
    {
        // Проверка корректности числа аргументов
        if (argc != 5)
        {
            usage(argv[0]);
            return PARAMETER_ERROR;
        }
        // Вызов функции поиска и переписи, выход с кодом ошибки в случае её возникновения
        int check = find_by_substr(argv[2], argv[3], argv[4]);
        if (check != OK)
        {
            return check;
        }
    }
    // Проверка ключа "db"
    else if (strcmp(argv[1], "db") == 0)
    {
        // Проверка корректности числа аргументов
        if (argc != 3)
        {
            usage(argv[0]);
            return PARAMETER_ERROR;
        }
        // Вызов функции удаления, выход с кодом ошибки в случае её возникновения
        int check = delete_by_grade(argv[2]);
        if (check != OK)
        {
            return check;
        }
    }
    // Выход с кодом ошибки в случае неверного аргумента
    else
    {
        usage(argv[0]);
        return PARAMETER_ERROR;
    }
    return OK;
}
