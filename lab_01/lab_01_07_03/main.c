/*
Программа получает на вход число х и погрешность эпсилон, причем |x| <= 1, 0 < эпсилон <= 1
В случае неверного ввода - выводит соответствующее сообщение об ошибке, затем завершает работу.
В случае верного ввода - выводит на экран значения суммы ряда для арктангена, значения функции арктангенса,
значения абсолютной и относительной погрешности, с соответствующими сообщениями, затем завершает работу
*/

#include <stdio.h>
#include <math.h>

// Функция для вычисления арктангенса через ряд Маклорена
double row_acrtan(double num, double epsilon)
{
    double sum = 0;
    int i = 1;
    double step;
    for (; ;)
    {
        step = pow(num, i) * pow(-1, ((i - 1) / 2)) / i;
        sum += step;
        if (fabs(step) <= epsilon)
        {
            break;
        }
        i += 2;
    }
    return sum;
}

int main(void)
{
    double x, eps;
    int check;
    printf("Введите x, модуль x меньше или равен единицы: ");
    check = scanf("%lf", &x);

    // Проверка на правильное присвоение значения и его ограничений по заданию
    if (check != 1)
    {
        printf("Ошибка ввода\n");
        return 1;
    }
    else if (fabs(x) > 1)
    {
        printf("Значения x вышло за диапозон допустимых значений\n");
        return 1;
    }

    printf("Введите epsilon больше нуля, меньше или равное единице: ");
    check = scanf("%lf", &eps);
    if (check != 1) 
    {
        printf("Ошибка ввода\n");
        return 1;
    }
    else if (eps <= 0 || eps > 1)
    {
        printf("epsilon вышел за диапозон допустимых значений\n");
        return 1;
    }
    
    // Вычисление настоящего значения арктангенса
    double arctg = atan(x);

    double row;

    // Проверка на частный случай x = 0 т.к. значения ряда и функции равны нулю, из-за чего невозможно рассчитать отночительную погрешность программно
    if (fabs(x) < 1e-6)
    {
        printf("s(x) = %lf , f(x) = %lf , delta = %lf , delta_rel = %lf \n", 0.000000, 0.000000, 0.000000, 0.000000);
        return 0;
    }
    // Присвоение значения арктангенса через ряд для общего случая
    else
    {
        row = row_acrtan(x, eps);
    }
    double abs_delta = fabs(arctg - row);
    double rel_delta = fabs(arctg - row) / fabs(arctg);

    // Вывод результата
    printf("s(x) = %lf , f(x) = %lf , delta = %lf , delta_rel = %lf \n", row, arctg, abs_delta, rel_delta);
    return 0;
}
