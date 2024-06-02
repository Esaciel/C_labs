/*
Задание - посчитать количество смен знака во входном файле (или вводе с клавиатуры); числа введены по концевому признаку до первого нечислового значения
Прототип функции для обработки должен принимать файл на вход
*/
#include "process.h"
#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    // Ицициализация переменных файла и проверочного значения
    FILE *f;
    int check;

    // В случае запуска без аргументов - установка потока ввода как входного файла
    if (argc == 1)
    {
        f = stdin;
    }
    // В случае запуска с одним аргументом - установка подаваемого аргунемта как входного файла
    else if (argc == 2)
    {
        f = fopen(argv[1], "r");
    }
    // В случае запуска с большим количеством аргументов - вывод ошибки
    else
    {
        fprintf(stderr, "Usage: ./app.exe [filename]\n");
        return USAGE_ERROR;
    }

    // Проверка доступа к файлу
    if (f == NULL)
    {
        fprintf(stderr, "Error %d; %s\n", errno, strerror(errno));
        return FILE_ACCESS_ERROR;
    }

    // Запуск обработки файла и проверка наличия ошибок
    size_t count = 0;
    check = process(f, &count);
    fclose(f);
    if (check != OK)
    {
        return check;
    }
    fprintf(stdout, "Знак менялся %zu раз(a)\n", count);

    return OK;
}
