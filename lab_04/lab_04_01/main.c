/*
Задание - реализовать функции { strpbrk, strspn, strcspn, strchr, strrchr } самостоятельно и сравнить b[] выводы с библиотечными для разных входных данных 
*/
#include <stdio.h>
#include <string.h>
#include "process.h"

int main(void)
{
    int error = 0;

    // Инициализация тестовых массивов и сравнение выходных данных для библиотечной и собственной реализации функции strpbrk для каждой пары значений
    const char *string_array_11[] = { "Hello", "World", "HAVE SPACE" };
    const char *string_array_21[] = { "lion", "ghf", "( )" };
    for (int i = 0; i < 3; i++)
    {
        if (strpbrk(string_array_11[i], string_array_21[i]) != my_strpbrk(string_array_11[i], string_array_21[i]))
        {
            error++;
            printf("strpbrk\n");
        }
    }

    // Инициализация тестовых массивов и сравнение выходных данных для библиотечной и собственной реализации функции strspn для каждой пары значений
    const char *string_array_12[] = { "Hello", "World", "    <-spaces", "\t\t tab" };
    const char *string_array_22[] = { "life is Hell", "NaN", "> <", "tab \t" };
    for (int i = 0; i < 4; i++)
    {
        if (strspn(string_array_12[i], string_array_22[i]) != my_strspn(string_array_12[i], string_array_22[i]))
        {
            error++;
            printf("strspn\n");
        }
    }

    // Инициализация тестовых массивов и сравнение выходных данных для библиотечной и собственной реализации функции strcspn для каждой пары значений
    const char *string_array_13[] = { "Hello", "World", "    <-spaces", "word \t\t tab" };
    const char *string_array_23[] = { "Oops", "NaN", "> <", "tab \t" };
    for (int i = 0; i < 4; i++)
    {
        if (strcspn(string_array_13[i], string_array_23[i]) != my_strcspn(string_array_13[i], string_array_23[i]))
        {
            error++;
            printf("strcspn\n");
        }
    }

    // Инициализация тестовых массивов и сравнение выходных данных для библиотечной и собственной реализации функции strchr для каждой пары значений
    const char *string_array_14[] = { "AAaAA", "contains space", "contains double symbol: q q", "check for zero byte", "check for special \ncharacters" };
    const char char_array_4[] = { 'a', ' ', 'q', '\0', '\n' };
    for (int i = 0; i < 5; i++)
    {
        if (strchr(string_array_14[i], (int)char_array_4[i]) != my_strchr(string_array_14[i], (int)char_array_4[i]))
        {
            error++;
            printf("strchr\n");
        }
    }
    // Проверка численного значения символа за пределами значений char типа
    if (strchr(string_array_14[0], 1025) != my_strchr(string_array_14[0], 1025))
    {
        error++;
        printf("strchr special\n");
    }

    // Инициализация тестовых массивов и сравнение выходных данных для библиотечной и собственной реализации функции strrchr для каждой пары значений
    const char *string_array_15[] = { "aAaAa", "contains space multiple times", "contains q several q symbols: q ", "check for zero byte", "check\n for\n special \ncharacters" };
    const char char_array_5[] = { 'a', ' ', 'q', '\0', '\n' };
    for (int i = 0; i < 5; i++)
    {
        if (strrchr(string_array_15[i], (int)char_array_5[i]) != my_strrchr(string_array_15[i], (int)char_array_5[i]))
        {
            error++;
            printf("strrchr\n");
        }
    }
    // Проверка численного значения символа за пределами значений char типа 
    if (strrchr(string_array_15[0], 1025) != my_strrchr(string_array_15[0], 1025))
    {
        error++;
        printf("strrchr special\n");
    }

    // Печать числа несовпавших выводов тестовых данных и возврат идентичного кода
    // printf("Число проваленных тестов: ");
    printf("%d\n", error);
    return error;
}
