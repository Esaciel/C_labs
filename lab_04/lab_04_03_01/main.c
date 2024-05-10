/*
Прочитать строку, вывести все слова (в порядке с конца к началу) если они отличны от последнего слова в строке, кроме этого - удалить из выходных слов все вхождения каждого символа кроме первого из них
Ограничение на длину строки - 255 символов, ограничение на длину слова - 16 символов
*/
#include <stdio.h>
#include "definitions.h"
#include "io.h"
#include "process.h"

int main(void)
{
    char string[STRLEN + 1] = { 0 };
    char words[STRLEN + 1] = { 0 };
    int check = 0, ending_index = 0;
    char resulting_string[STRLEN + 1] = { 0 };

    // Ввод строки из входного потока и возврат кода ошибки в случае её возникновения
    check = input_string(string);
    if (check != OK)
    {
        return check;
    }
    
    // Разбиение строки на слова и возврат кода ошибки в случае её возникновения
    check = split_string(string, words, &ending_index);
    if (check != OK)
    {
        return check;
    }

    // Запись в выходную строку по заданию и возврат кода ошибки в случае её возникновения
    check = read_words_from_ending(words, ending_index, resulting_string);
    if (check != OK)
    {
        return check;
    }

    // Вывод выходной строки
    output_string(resulting_string);
    return OK;
}