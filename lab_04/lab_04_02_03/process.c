#include "process.h"
#include "definitions.h"
#include <string.h>
#include <ctype.h>

// Проврека является ли символ разделительным
int is_separator(char c)
{
    // Инициализация массивов разделителей и сравнение данного символа с каждым значением, возврат 1 если символ является разделителем и 0 елси не является
    char separators[8] = { ',', ':', ';', '-', '.', '!', '?', ' ' };
    for (int i = 0; i < 8; i++)
    {
        if (c == separators[i])
        {
            return 1;
        }
    }
    return 0;
}

// Функция разбиения строки на слова (ставит их друг за другом и разделяет нулевым байтом)
int split_string(char *string, char *words, int *wordcount, int *z)
{
    int i = 0, j = *z, len = 0, wrdcnt = 0, check;
    // Цикл по входной строке до её конца (до нулевого байта)
    while (string[i] != '\0')
    {
        check = 0;
        // Пропуск всех разделителей перед словом
        while (is_separator(string[i]))
        {
            i++;
        }

        // Запись непробельных символов из строки в область памяти разделённых слов
        while (is_separator(string[i]) == 0 && string[i] != '\0')
        {
            check = 1;
            words[j++] = string[i++];
            if (len++ == WORDLEN)
            {
                // Возврат кода ошибки в случае если длина слова привысила разрешённые 16 символов
                return WORD_SIZE_ERROR;
            }
        }
        // Замыкание очередного слова нулевым байтом и увеличение счетчика числа слов
        if (check == 1)
        {
            words[j++] = '\0';
            wrdcnt++;
            len = 0;
        }
    }
    // Вынос указателя на текущий индекс области памяти с разделёнными словами и их количество через переданные указатели
    *z = j;
    *wordcount += wrdcnt;
    return OK;
}

// Функция проверки количества вхождений заданного слова в строку с разбитыми словами
int occurance_num_check(char *words, char *word, int wordnum)
{
    char *word_pointer = words;
    int occurances = 0;
    // Цикл по полученному числу слов
    for (int i = 0; i < wordnum; i++)
    {
        //  Сравнение очередного слова в строке с заданными и увеличение счетчика числа вхождений в случае совпадения
        if (strcmp(word_pointer, word) == 0)
        {
            occurances++;
        }
        // Переход к следующему слову путем пропуска разделяющих их нулевых байтов
        while (*word_pointer != '\0')
        {
            word_pointer++;
        }
        word_pointer++;
    }
    // Возврат количества вхождений слова
    return occurances;
}


// Функция записи в выходную строку
void write_to_resulting_string(char *resulting_string, char *words, int wordnum, int *sum_word_count)
{
    char *word_pointer = words;
    // Цикл по полученному числу слов
    for (int i = 0; i < wordnum; i++)
    {
        // Запись в выходную строку пробела и очередного слова в случае если оно уникально (т.е число вхождений очередного слова в строку с разделёнными словами равно 1)
        if (occurance_num_check(words, word_pointer, wordnum) == 1)
        {
            strcat(resulting_string, " ");
            strcat(resulting_string, word_pointer);
            *sum_word_count += 1;
        }
        // Переход к следующему слову путем пропуска разделяющих их нулевых байтов
        while (*word_pointer != '\0')
        {
            word_pointer++;
        }
        word_pointer++;
    }
}
