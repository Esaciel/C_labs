/*
Программа проверяет выполнение правила трех сигм для входного файла, выводит 1 в случае елси оно выполняется и 0 в случае если оно не выполняется
Для порядка одинаковых чисел выводом является 0 т.к. сигма равно 0 и интервал равен точки, потому считается что разброс значений для првоерки отсутствует в принципе
*/
#include "process.h"
#include "definitions.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
    FILE *f;
    int check;

    // Проверка количества подаваемых аргументов и выход в случае 
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./app.exe <filename>\n");
        return USAGE_ERROR;
    }

    // Открытие файла для чтения и выход в случае ошибки доступа
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Error %d; %s\n", errno, strerror(errno));
        return FILE_ACCESS_ERROR;
    }

    // Обработка файла и выход с кодов ошиббки в случае её возникновения, иначе - вывод результата
    char result = 0;
    check = process(f, &result);
    fclose(f);
    if (check != OK)
    {
        return check;
    }
    output(result);

    return OK;
}
