#include "extract.h"
#include "definitions.h"

// Функция для ключа "p"
int extract_numbers(FILE *in_bin)
{
    int n;
    int count = 0;
    // Расчет размера входного бинарного файла и проверка кратности его размера размеру типа int
    fseek(in_bin, 0, SEEK_END);
    size_t fsize = ftell(in_bin);
    if (fsize % sizeof(int) != 0)
    {
        return BINFILE_TYPE_ERROR;
    }
    // Возврат к началу файла и вывод всех целых чисел в нем на экран, также подсчет колиичества чисел в этом файле
    fseek(in_bin, 0, SEEK_SET);
    while (fread(&n, sizeof(int), 1, in_bin) == 1)
    {
        fprintf(stdout, "%d ", n);
        count++;
    }
    // В случае если счетчик равен нулю, т.е. бинарный файл пуст - возврат кода ошибки
    if (count == 0)
    {
        fprintf(stderr, "Файл для вывода пуст\n");
        return EMPTY_FILE_TO_CAT_ERROR;
    }
    // Проверка возникновения неизвестной ошибки
    if (ferror(in_bin))
    {
        return UNKNOWN_ERROR;
    }
    return OK;
}
