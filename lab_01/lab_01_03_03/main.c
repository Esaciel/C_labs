/*
Программа принимает на вход строку из трех чисел:
Скорость тела, ускорение и время движения
Выводит на экран модуль перемещения тела, затем завершает работу
*/

#include <stdio.h>
#include <math.h>

// first test: velocity = 2.5, acceleration = -5, time = 1, expected_shift = 0.000000
// second test: velocity = 2, acceleration = 3, time = 2, expected_shift = 10.000000
// third test: velocity = -5, acceleration = 5, time = 4, expected_shift = 20.000000
// first test: velocity = -2, acceleration = -1, time = 2, expected_shift = 6.000000

int main(void)
{
    long double v, a, t;
    long double s;
    printf("Введите начальную скорость тела, усорение и время его движения через пробел: ");
    scanf("%Lf%Lf%Lf", &v, &a, &t);

    // кв. уравнение для координаты
    s = (t * t * a / 2) + v * t;
    
    printf("Перемещение тела равно %Lf\n", s);
    return 0;
}