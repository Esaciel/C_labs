/*
Программа принимает на вход два целых положительных числа
В случае неверного ввода - ввыводит соответствующее сообщение об ошибке, затем
завершает работу. В случае верного ввода - ыводит на экран наибольший общий
делитель введенных чисе, затем завершает работу.
*/

#include <stdio.h>
#include <stdlib.h>

// Алгоритм Эвклида для поиска наибольшего общего делителя
long int euclidean(long int a, long int b)
{
    while (b != 0)
    {
        long int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main(void) 
{
    long int a, b, rc, i;

    printf("Введите два натуральных числа: ");
    rc = scanf("%ld %ld", &a, &b);

    // Проверка на то что числа присвоены переменным (т.е. проверка на верный ввод)
    if (rc != 2)
    {
        printf("Некорректный ввод\n");
        return 1;
    }
    // Проверка на то что введенные числа являются натуральными
    else if (a <= 0 || b <= 0)
    {
        printf("По крайней мере одно из введенных чисел не является натуральным\n");
        return 1;
    }

    i = euclidean(a, b);
    printf("Наибольший общий делитель введенных чисел - %ld\n", i);
    return 0;
}