/*
Программа принимает на вход набор из трех чисел:
Длины сторон треугольника и угол между ними в градусах
Выводит на экран площадь треугольника, затем завершает работу
*/

#include <stdio.h>
#include <math.h>

// first test: side_a = 4, side_b = 3, angle = 30, expected_area = 3.000000
// second test: side_a = 1, side_b = 17, angle = 45, expected_area = 6.010407
// third test: side_a = 19998, side_b = 2.5, angle = 90,  expected_area = 24997.500000

int main(void)
{
    float side_a, side_b;
    float pi = 3.14159265358979;
    float fi, s, radfi;
    printf("Введите стороны треугольника и угол между ними в градусах через пробел: ");
    scanf("%f%f%f", &side_a, &side_b, &fi);
    radfi = pi * fi / 180; // перевод в радианы 
    s = sinf(radfi) * side_a * side_b * 0.5; // вычисление площади
    printf("Площадь треугольника = %f\n", s);
    return 0;
}
