#include "process.h"
#include "definitions.h"
#include <math.h>

// Функция проверки выполнения правила трех сигм
int process(FILE *f, char *result)
{
    int n = 0, count = 0;
    float num;
    float qsum = 0.0, sum = 0.0;
    double sigma;
    // Чтение чисел до остановки, подсчет их количества, суммы их квадратов и суммы самих чисел
    while (fscanf(f, "%f", &num) == 1)
    {
        n++;
        qsum += (num * num);
        sum += num;
    }
    // Выход в случае если файл не содержит чисел или содержит данные помимо числовых.
    if (!feof(f))
    {
        fprintf(stderr, "Файл содержит некорректное значнеие.\n");
        return INCORRECT_DATA_ERROR;
    }
    if (n == 0)
    {
        fprintf(stderr, "Отсутствуют данные для обработки.\n");
        return NO_DATA_ERROR;
    }

    count = n;
    // Подсчет стандартного отклонения по формуле для генеральной совокупности т.к. отсутствует информация о природе данных в файле
    sigma = sqrt((n * qsum - (sum * sum)) / (n * n));
    // Выход в случае если стандартное отклонение равно нулю, т.е. все числа одинаковые
    if (fabs(sigma) < 1e-8)
    {
        *result = 0;
        return OK;
    }
    rewind(f);
    // Подсчет количества чисел, которые удовлетворяют правилу трех сигм, как разность общего количества чисел и количества неудовлетворяющих данному правилу
    while (fscanf(f, "%f", &num) == 1)
    {
        if (fabs(num - sum / n) > 3 * sigma)
        {
            count--;
        }
    }
    // Проверка выполнения правила трех сигм (для интервала 99.73%) и возврат результата расчета через указатель
    if ((float)count / n < (float)0.9973)
    {
        *result = 0;
    }
    else
    {
        *result = 1;
    }
    return OK;
}

// Вывод сообщения и соответствующего числа для выполнения/невыполнения правила трех сигм
void output(char result)
{
    if (result == 1)
    {
        fprintf(stdout, "Правило трех сигм выполняется. ");
    }
    else
    {
        fprintf(stdout, "Правило трех сигм не выполняется. ");
    }
    fprintf(stdout, "%d\n", (int)result);
}