#include "definitions.h"
#include "dbkey.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

// Функция удаления записи из бинарного файла
void delete_one(FILE *binfile, size_t num_of_struct, size_t *num_of_structs)
{
    student s;
    memset(&s, 0, sizeof(s));
    // Цикл по количеству записей в файле начиная с указанной
    for (size_t i = num_of_struct + 1; i < *num_of_structs; i++)
    {
        // Чтение следующей после указанной записи и сдвиг её на 1 назад
        fseek(binfile, i * sizeof(s), SEEK_SET);
        fread(&s, sizeof(s), 1, binfile);

        fseek(binfile, (i - 1) * sizeof(s), SEEK_SET);
        fwrite(&s, sizeof(s), 1, binfile);
    }
    // Обрезка последней записи в файле
    ftruncate(fileno(binfile), (*num_of_structs - 1) * sizeof(s));
    // Возврат указателя на нужную позицию
    fseek(binfile, num_of_struct * sizeof(s), SEEK_SET);
    // Уменьшения переменной с количеством записей в файле на 1
    *num_of_structs -= 1;
}

// Функция для ключа "db"
int delete_by_grade(char *binfilename)
{
    student s;
    memset(&s, 0, sizeof(s));

    // Открытие бинарного файла и проверка дооступа к нему
    FILE *binfile = fopen(binfilename, "r+b");
    if (binfile == NULL)
    {
        fprintf(stderr, "%s; Errno %d; %s\n", binfilename, errno, strerror(errno));
        return FILE_ACCESS_ERROR;
    }

    // Расчет размера строготипизированного бинарного файла и проверка кратности его размеру структуры которой он типизирован
    fseek(binfile, 0, SEEK_END);
    long int binfile_size = ftell(binfile);
    fseek(binfile, 0, SEEK_SET);
    if (binfile_size % sizeof(s) != 0)
    {
        fprintf(stderr, "Размер бинарного файла не соответствует размеру структуры\n");
        fclose(binfile);
        return BINFILE_SIZE_ERROR;
    }

    // Расчет числа структур во входном файле
    unsigned long total_grade = 0;
    size_t num_of_structs = binfile_size / sizeof(s);

    // Цикл для расчета общего балла среди всез учеников
    while (ftell(binfile) < binfile_size)
    {
        fread(&s, sizeof(s), 1, binfile);
        total_grade += s.grades[0] + s.grades[1] + s.grades[2] + s.grades[3];
    }
    fseek(binfile, 0, SEEK_SET);
    // Расчет среднего балла учеников
    float avg_grade = (float)total_grade / (num_of_structs * GRADES_COUNT);
    size_t counter = 0;
    // Цикл по количеству структур во входном файле
    while (counter < num_of_structs)
    {
        // Чтение очередной записи в файле и проверка среднего балла очередного ученика
        fread(&s, sizeof(s), 1, binfile);
        if ((float)(s.grades[0] + s.grades[1] + s.grades[2] + s.grades[3]) / GRADES_COUNT < avg_grade)
        {
            // Удаление текущей записи в случае если средний балл текущего ученика меньше среднего по файлу
            delete_one(binfile, counter, &num_of_structs);
            counter--;
        }
        counter++;
    }
    fclose(binfile);
    // Возврат кода ошибки в случае если итоговый файл после удаления пуст
    if (counter == 0)
    {
        fprintf(stderr, "Бинарный файл пуст после удаления\n");
        return EMPTY_BINFILE_ERROR;
    }
    return OK;
}
