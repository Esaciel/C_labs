#include "c_and_s_keys.h"
#include "definitions.h"
#include <time.h>

// Функция получения числа по его позиции в строготипизированном бинарном файле
int get_number_by_pos(FILE *binfile, int pos)
{
    int number;
    fseek(binfile, pos * sizeof(int), SEEK_SET);
    fread(&number, sizeof(int), 1, binfile);
    return number;
}

// Функция записи числа в указанную позицию с затиранием в строготипизированном бинарном файле
void put_number_by_pos(FILE *binfile, int pos, int num)
{
    fseek(binfile, pos * sizeof(int), SEEK_SET);
    fwrite(&num, sizeof(int), 1, binfile);
}

// Функция для ключа "s"
int sortfile(FILE *in_bin)
{
    // Расчет размера бинарного файла и проверка кратности его размеру типа int 
    fseek(in_bin, 0, SEEK_END);
    size_t fsize = ftell(in_bin);
    if (fsize % sizeof(int) != 0)
    {
        return BINFILE_TYPE_ERROR;
    }
    // Подсчет количества чисел в строготипизированном файле и возврат кода ошибки если оно равно нулю
    size_t size = fsize / sizeof(int);
    if (size == 0)
    {
        fprintf(stderr, "Файл для сортировки пуст\n");
        return EMPTY_FILE_TO_SORT_ERROR;
    }
    fseek(in_bin, 0, SEEK_SET);
    char flag;
    // Сортировка пузырьком с флагом, с заменой операций индексации для массива на функции get_number_by_pos и put_number_by_pos для строготипизированного бинарного файла
    for (size_t i = 0; i < size - 1; i++)
    {
        flag = 1;
        for (size_t j = 0; j < size - i - 1; j++)
        {
            int num_cur = get_number_by_pos(in_bin, j);
            int num_nxt = get_number_by_pos(in_bin, j + 1);
            if (num_cur > num_nxt)
            {
                put_number_by_pos(in_bin, j, num_nxt);
                put_number_by_pos(in_bin, j + 1, num_cur);
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
    // Проверка возникновения неизвестной ошибки
    if (ferror(in_bin))
    {
        return UNKNOWN_ERROR;
    }
    return OK;
}

// Функция генерации случайных чисел типа int
int randint() 
{
    int randnum = ((int)rand() << 16) | (int)rand();
    if (rand() % 2 == 0) 
    {
        randnum = -randnum;
    }
    return randnum;
}

// Функция для ключа "c"
void fill_file(FILE *out_bin, size_t count)
{
    // Установка якоря для генерации случайных чисел
    srand(time(NULL));
    // генерация случайного числа и запись его в бинарный файл указанное число раз
    for (size_t i = 0; i < count; i++)
    {
        int n = randint();
        fwrite(&n, sizeof(int), 1, out_bin);
    }
}
