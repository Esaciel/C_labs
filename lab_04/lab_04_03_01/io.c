#include <stdio.h>
#include "io.h"
#include "definitions.h"
#include <stdlib.h>

// Функция ввода строки
int input_string(char *string)
{
    // printf("Введите строку длиной не более <=256 и длиной слов <=16: ");
    char ch;
    size_t i = 0;
    // Ввод очередного симола если не достигнут символ перехода на новую строку или символ конца входного потока
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (i < STRLEN)
        {
            string[i] = ch;
        }
        // Возврат кода ошибки если длина строки превысила допустимое значение
        if (i++ == STRLEN)
        {
            return STRING_SIZE_ERROR;
        }
    }
    // Замыкание строки нулевым байтом
    string[i] = '\0';
    // Возврат кода ошибки если строка не была прочитана
    if (ch == EOF && i == 0)
    {
        return STRING_READ_ERROR;
    }
    return OK;
}

// Функция вывода строки
void output_string(char *string)
{
    printf("Result:%s", string);
}
 