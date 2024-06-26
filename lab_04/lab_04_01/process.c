#include "process.h"
#include <stdio.h>

// Реализация функции strpbrk
char *my_strpbrk(const char *str_1, const char *str_2)
{
    // Сравнение каждого символа в первой строке со всеми символами второй строки
    for (int i = 0; str_1[i] != '\0'; i++)
    {
        for (int j = 0; str_2[j] != '\0'; j++)
        {
            if (str_1[i] == str_2[j])
            {
                // Возврат указателя на первое вхождение символа первой строки который присутствует во второй строке
                return (char *)&str_1[i];
            }
        }
    }
    // Возврат NULL в случае если в первой строке нет ни одного символа из второй строки
    return NULL;
}


// Реализация функции strspn
size_t my_strspn(const char *str_1, const char *str_2)
{
    // Инициализация счетчика символов первой строки которые присутствуют во второй строке до первого несоответствия, а также индексов символов в строках
    size_t count = 0, i, j;
    // Сравнение каждого символа первой строки со всеми символами второй строки
    for (i = 0; str_1[i] != '\0'; i++)
    {
        for (j = 0; str_2[j] != '\0'; j++)
        {
            // Увеличение счётчика, переход к следующему символу первой строки если текущий присутствует во второй строке
            if (str_1[i] == str_2[j])
            {
                count++;
                break;
            }
        }
        // Остановка сравнения если текущий символ первой строки не был обнаружен во второй стркое
        if (str_2[j] == '\0')
        {
            break;
        }
    }
    // Возврат значения счетчика
    return count;
}

// Реализация функции strcspn
size_t my_strcspn(const char *str_1, const char *str_2)
{
    // Инициализация счетчика симвоолов первой строки отсутствующих во второй до первого несоответствия условию, а также индексов символов в стрках
    size_t count = 0, i, j;
    // Сравнение каждого символа первой строки со всеми символами второй строки 
    for (i = 0; str_1[i] != '\0'; i++)
    {
        for (j = 0; str_2[j] != '\0'; j++)
        {
            // В случае совадения текущего символа первой строки с любым символом второй строки - возврат значения счетчика, иначе - увеличение его на 1
            if (str_1[i] == str_2[j])
            {
                return count;
            }
        }
        count++;
    }
    // Возврат значения счетчика в случае если все символы первой строки не встречаются во второй
    return count;
}

// Реализация функции strchr
char *my_strchr(const char *str, int chr) 
{
    // Посимвольное сравнение строки и задданного символа
    while (*str != '\0') 
    {
        if (*str == (char)chr) 
        {
            // Возврат указателя на символ в строке в случае нахождения его первого вхождения
            return (char *)str;
        }
        str++;
    }
    // Возвращение указателя на нулевой замыкающий байт строки если заданный символ для поиска является таковым
    if (*str == (char)chr)
    {
        return (char *)str;
    }
    // Возврат NULL в случае отсутствия заданного символа в строке
    return NULL;
}

// Реализация функции strrchr
char *my_strrchr(const char *str, int chr) 
{
    // Инициализация указателя и установка его на конец строки
    char *pointer = (char *)str;
    while (*pointer != '\0')
    {
        pointer++;
    }
    // Посимвольное сравнение строки и заданного символа с конца строки через указатель
    while (pointer >= str) 
    {
        if (*pointer == (char)chr) 
        {
            // Возврат указателя на символ в строке в случае нахождения его последнего вхождения
            return (char *)pointer;
        }
        pointer--;
    }
    // Возврат NULL в случае отсутствия символа в строке
    return NULL;
}
