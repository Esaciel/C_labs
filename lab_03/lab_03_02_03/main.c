/*
Удалить из введённой матрицы все столбцы, в которых содержится хотя-бы одно число, содержащее в себе заданную цифру, и вывести полученную матрицу на экран
*/
#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "process.h"
#include "definitions.h"

int main(void)
{
    int a[S][S], check = 0, columns_to_delete[S] = { 0 }, digit;
    size_t rows, columns, num_of_deletions;

    // Приглашение ввода и вызов функции записи размерности для количества строк, выход с соответствующим кодом в случае неверного ввода
    printf("Введите число строк в матрице: ");
    check = input_size(&rows);
    if (check != OK)
    {
        return check;
    }

    // Приглашение ввода и вызов функции записи размерности для количества столбцов, выход с соответствующим кодом в случае неверного ввода
    printf("Введите число столбцов в матрице: ");
    check = input_size(&columns);
    if (check != OK)
    {
        return check;
    }

    // Приглашение ввода и вызов функции для ввода матрицы, выход с соотвутствующим кодом в случае неверного ввода
    printf("Введите значения элементов матрицы через пробел: \n");
    check = input_matrix(a, rows, columns);
    if (check != 0)
    {
        return check;
    }

    // Приглашение ввода вызов функции для ввода цифры для поиска, выход с соответствующим кодом в случае неверного ввода
    printf("Введите цифру для поиска: ");
    check = input_digit(&digit);
    if (check != OK)
    {
        return check;
    }
    
    // printf("Исходная матрица:\n");
    // output_matrix(a, rows, columns);

    // Вызов функции заполнения массива с индексами столбцов для удаления и поиска количества этих индексов, вывод сообщения и выход с соответствующим кодом в случае если необходимо удалить все столбцы
    num_of_deletions = find_columns_with_digit(a, rows, columns, columns_to_delete, digit);
    if (num_of_deletions == columns)
    {
        printf("Матрица является пустой после удаления столбцов\n");
        return UNPROCESSABLE_DATA_ERROR;
    }

    // Вызов функции для удаления найденных столбцов
    delete_columns(a, rows, &columns, columns_to_delete);

    // Сообщение о выводе и сам вывод матрицы на экран
    printf("Матрица после удаления столбцов:\n");
    output_matrix(a, rows, columns);

    return OK;
}
