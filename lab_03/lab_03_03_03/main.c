/*
Отсортировать строки вводимой матрицы по убыванию их наименьших элементов и вывести полученную в результате матрицу на экран 
*/
#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "process.h"
#include "definitions.h"

int main(void)
{
    int a[S][S], check = 0, minimals[S];
    size_t rows = 0, columns = 0;

    // Приглашение ввода и вызов функции записи размерности для количества строк, выход с соответствующим кодом в случае неверного ввода
    printf("Введите число строк в матрице: ");
    check = input_size(&rows);
    if (check != 0)
    {
        return check;
    }

    // Приглашение ввода и вызов функции записи размерности для количества столбцов, выход с соответствующим кодом в случае неверного ввода
    printf("Введите число столбцов в матрице: ");
    check = input_size(&columns);
    if (check != 0)
    {
        return check;
    }

    // Приглашение ввода и вызов функции для ввода матрицы, выход с соотвутствующим кодом в случае неверного ввода
    printf("Введите значения элементов матрицы через пробел:\n");
    check = input_matrix(a, rows, columns);
    if (check != 0)
    {
        return check;
    }

    // printf("Исходная матрица:\n");
    // output_matrix(a, rows, columns);

    // Вызов функции для поиска минимальных значений в каждой строки и записи их в соответствующий массив
    find_minimals(a, rows, columns, minimals);

    // Сортировка строк матрицы в соответствии с их минимальными значениями
    parallel_bubble_sort(a, rows, columns, minimals);
    
    // Сообщение о выводе и сам вывод матрицы на экран
    printf("Отсортированная матрица:\n");
    output_matrix(a, rows, columns);

    return OK;
}
