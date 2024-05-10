#include <stdio.h>
#include "process.h"

// Функция для перемены массивов, принимает указатели на оба массива и их общую длину
void switch_arrays(int *first, int *second, size_t size)
{
    int tmp;
    for (size_t i = 0; i < size; i++)
    {
        tmp = first[i];
        first[i] = second[i];
        second[i] = tmp;
    } 
}

// Функция поиска минимального значения в каждой строке матрицы, принимает на вход указатель на матрицу, её резмерности и указатель на массив минимальных элементов строк
void find_minimals(int (*a)[S], size_t rows, size_t columns, int *minimals)
{
    // Цикл (строка -> столбец) для записи в соотвутствующую ячейку массива минимальных значений минимального значения каждой строки
    for (size_t i = 0; i < rows; i++)
    {
        minimals[i] = a[i][0];
        for (size_t j = 1; j < columns; j++)
        {
            if (a[i][j] < minimals[i])
            {
                minimals[i] = a[i][j];
            }
        }
    }
}

// Функция параллельной сортировки строк матрицы и массива их минимальных значений, принимает на вход указатель на матрицу, её размерности, и указатель на массив минимальных значений строк этой матрцицы
void parallel_bubble_sort(int (*a)[S], size_t rows, size_t columns, int *minimals)
{
    int arr_tmp;
    char flag = 1;
    // Цикл для сортировки пузырьком с флагом
    while (flag)
    {
        flag = 0;
        for (size_t i = 0; i < (rows - 1); i++)
        {
            // Сравнение соседних элементов массива мин. значений, в случае выполнения условий сортировки - перемена этих значений и соответствующих им соседних строк матрицы через описанную ранее функцию 
            if (minimals[i] < minimals[i + 1])
            {
                flag = 1;

                arr_tmp = minimals[i + 1];
                minimals[i + 1] = minimals[i];
                minimals[i] = arr_tmp;

                switch_arrays(a[i], a[i + 1], columns);
            }
        }
    }
}
