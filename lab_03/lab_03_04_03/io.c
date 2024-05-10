#include <stdio.h>
#include "io.h"

// Функция поиска длины числа, используется при выводе массива
int find_len(int x)
{
    int len = 0;
    while (x) 
    {
        x /= 10;
        len++;
    }
    return len;
}

// Функция поиска максимальной длины числа в массиве, используется при выводе массива
int find_max_len(int (*a)[S], size_t rows, size_t columns)
{
    int max_len = 0;
    int len;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            len = find_len(a[i][j]);
            if (len > max_len)
            {
                max_len = len;
            }
        }
    }
    return max_len;
}

// Функция ввода размерности массива, получает указатель на переменную и записывает в него значение с клваиатуры, выводит сообщения в случае некорректного ввода, возвращает соответственный код 
int input_size(size_t *x)
{
    if (scanf("%zu", x) != 1)
    {
        printf("Введено неверное значение размера\n");
        return SIZE_INPUT_ERROR;
    }
    if (*x == 0 || *x > S)
    {
        printf("Значение размера выходит за допустимые пределы\n");
        return SIZE_RANGE_ERROR;
    }
    return OK;
}

// Функция ввода массива, получает указатель на массив и его размерности, записывает в него значение с клваиатуры, выводит сообщения в случае некорректного ввода, возвращает соответственный код 
int input_matrix(int (*a)[S], size_t rows, size_t columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
        {
            if (scanf("%d", &a[i][j]) != 1)
            {
                printf("Введены неверные значения массива\n");
                return VALUE_INPUT_ERROR;
            }
        }
    }
    return OK;
}

// Функция вывода массива, получает указатель на массив и его размерности, циклический выводит элементы массива на экран
void output_matrix(int (*a)[S], size_t rows, size_t columns)
{
    int maxlen;
    maxlen = find_max_len(a, rows, columns) + 2;
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < (columns - 1); j++)
        {
            printf("% -*d ", maxlen, a[i][j]);
        }
        printf("% -*d\n", maxlen, a[i][columns - 1]);
    }
}
