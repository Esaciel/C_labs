#include "ie.h"
#include "definitions.h"
#include <errno.h>
#include <string.h>

// Функция для ключа import
int file_import(FILE *txtfile, FILE *binfile)
{
    int n = 0;
    // Чтение чисел из текстовго файла до первого неверного прочтения
    while (fscanf(txtfile, "%d", &n) == 1);

    // Проверка возникновения неизвестной ошибки
    if (ferror(txtfile) || ferror(binfile))
    {
        return UNKNOWN_ERROR;
    }
    // Проверка достижения конца текстового файла после чтения чисел (т.е. проверка на строгую типизацию входного текстового файла)
    if (!feof(txtfile))
    {
        fprintf(stderr, "Файл содержит данные помимо signed int\n");
        return NONINTEGER_CONTAINMENTS_ERROR;
    }
    // Возвращение к началу текстового файла и запись чисел из него в бинарный в случае если текстовый файл корректен
    rewind(txtfile);
    while (fscanf(txtfile, "%d", &n) == 1)
    {
        fwrite(&n, sizeof(int), 1, binfile);
    }
    return OK;
}

// Функция для ключа export
int file_export(FILE *binfile, FILE *txtfile)
{
    int n;
    // Расчет размера бинарного файла
    fseek(binfile, 0, SEEK_END);
    size_t fsize = ftell(binfile);
    // Проверка кратности размера бинарного файла размеру целого значения как аналог проверки строгой типизации
    if (fsize % sizeof(int) != 0)
    {
        return BINFILE_TYPE_ERROR;
    }
    // Возврат к началу бинарного файла и запись всех целочисленных значений из него в выходной текстовый файл
    fseek(binfile, 0, SEEK_SET);
    while (fread(&n, sizeof(int), 1, binfile) == 1)
    {
        fprintf(txtfile, "%d ", n);
    }
    // Проверка возникновения неизвестной ошибки
    if (ferror(binfile) || ferror(txtfile))
    {
        return UNKNOWN_ERROR;
    }
    return OK;
}
