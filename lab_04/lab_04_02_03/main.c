/*
Прочитать две строки, вывести строку начинающуюся  на "Result: " и заканчивающуюся на все уникальные по обеим входным строкам слова в том же порядке в котором они были введены
Разделитель между словами в выходной строке - пробел
Ограничение на длину строки - 255 символов, ограничение на длину слова - 16 символов
*/
#include <stdio.h>
#include <string.h>
#include "io.h"
#include "process.h"
#include "definitions.h"

int main(void)
{
    char string[STRLEN + 1] = "\0";
    char words[2 * STRLEN + 1] = "\0";
    int wordcount = 0, z = 0;

    int sum_word_count = 0;
    char resulting_string[(2 * STRLEN) + 1] = "\0";
    int check = OK;
    
    // Ввод первой строки в переменную из входного потока и возврат кода ошибки в случае ошибки ввода
    check = input_string(string);
    if (check != OK)
    {
        return check;
    }
    // Разделение строки на слова и запись их в строку с разделёнными словами и возврат кода ошибки в случае ошибки разделения
    check = split_string(string, words, &wordcount, &z);
    if (check != OK)
    {
        return check;
    }

    // Ввод второй строки в переменную из входного потока и возврат кода ошибки в случае ошибки ввода
    check = input_string(string);
    if (check != OK)
    {
        return check;
    }
    // Добавление слов из второй строик в строку с разделёнными словами и возврат кода ошибки в случае ошибки разделения
    check = split_string(string, words, &wordcount, &z);
    if (check != OK)
    {
        return check;
    }

    // Запись слов в выходную строку слов из строки с разделёнными словами по заданному правилу
    write_to_resulting_string(resulting_string, words, wordcount, &sum_word_count);
    // Возврат кода ошибки в случае если выходная строка окажется пустой
    if (sum_word_count == 0)
    {
        return UNPROCESSABLE_DATA_ERROR;
    }

    // Печать выходной строки
    output_string(resulting_string);

    return OK;
}