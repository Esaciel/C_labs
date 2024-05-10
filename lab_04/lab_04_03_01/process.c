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
int split_string(char *string, char *words, int *z)
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
        
        if (check == 1)
        {
            words[j++] = '\0';
            wrdcnt++;
            len = 0;
        }
    }
    // Вынос идекса замыкающего нулевого байта последнего слова строки с разделёнными словами через уазатель
    *z = (j - 1);
    return OK;
}

// Функция удаления всех вхождений символа кроме первого из слова путем замены его на нулевой байт
void process_word(char *word)
{
    // Цикл по длине масикмальной дллине слова который заменяет все последующегие вхождение выбранного символа для каждого символа
    for (int i = 0; i < WORDLEN; i++)
    {
        for (int j = i + 1; j < WORDLEN; j++)
        {
            if ((word[i] != '\0') && (word[j] == word[i]))
            {
                word[j] = '\0';
            }
        }
    }
}


// Функция добавления слов в выходную строку начиная с последнего
int read_words_from_ending(char *words, int z, char *resulting_string)
{
    int word_count = 0;
    int res_index = 0;
    char word_container[WORDLEN + 1] = "";
    char last_word_container[WORDLEN + 1] = "";
    int index = z - 1;
    // Перенос индекса строки в начало последнего слова в строке с разделёнными словами
    while (index >= 0 && words[index] != '\0')
    {
        index--;
    }
    index++;
    // Сохранение последнего слова слова в строке и переном индекса к концу предшествующего слова
    strcpy(last_word_container, &words[index]);
    index -= 2;

    // Цикл для строки с разделёнными словами начиная с конца предпоследнего слова и заканчивая первым
    while (index >= 0)
    {
        // Перенос индекса к началу очередного слова
        while (index >= 0 && words[index] != '\0')
        {
            index--;
        }
        index++;

        // Очистка массива для слова и запись в него текущего слова
        memset(word_container, '\0', (WORDLEN + 1));
        strcpy(word_container, &words[index]);

        // В случае если текущее слово отличается от последнего - удаление из него всех вхождений каждой буквы кроме первого и запись его в выходную стрроку
        if (strcmp(word_container, last_word_container) != 0)
        {
            // Удаление всех вхождений каждой буквы кроме первого из текущего слова
            process_word(word_container);
            // Добавление пробела для разделения слов в выходной строке
            resulting_string[res_index++] = ' ';
            // Добавление всех символов не равных нулевому байту в выходную строку (т.к вхождения символов кроме первого заменялись на нулевые байты - их надо пропускать; во избежание ошибок цикл ограничен максимальной длиной слова)
            for (int k = 0; k < WORDLEN; k++)
            {
                if (word_container[k] != '\0')
                {
                    resulting_string[res_index++] = word_container[k];
                }
            }
            // Увеличение счетчика записанных в выходную строку слов
            word_count++;
        }
        // Перенос индекса к концу слова,, предшествующего только что обработанному
        index -= 2;
    }
    // Возврат кода ошибки в случае если число записанных в выходную строку слов равно нулю, иначе - возврат кода корректной работы
    if (word_count == 0)
    {
        return UNPROCESSABLE_DATA_ERROR;
    }
    return OK;
}