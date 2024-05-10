/*
Программа принимает на вход целое положительное число 
В случае неверного ввода - выводит на экран "Error: " и последующее соответствующее сообщение об ошибке, затем завершает работу.
В случае верного ввода - выводит на экран "Result: " и последующее двоичное представление введенного числа с измененными по вариантту битами
пустые биты в начале числа также выводятся на экран, затем программа завершает работу.
*/

#include <stdio.h>

// Функция для вывода полученного в crypt() числа в зашифрованном виде (со сменой каждого нечетного бита с каждым следующим после него четным)
void output(unsigned int a)
{
    for (int i = 0; i < 32; i++)
    {
        printf("%d", (a % 2));
        a /= 2;
    }
}

// Функция для последовательного зеркального разворота двочиного представления введенного числа 
// Необходима вследствии невозможности циклически вывести число в правильном порядке
void crypt(unsigned int a)
{
    unsigned int res = 0;
    for (int i = 0; i < 32;)
    {
        if (a % 2 == 1)
        {
            res |= (1 << (30 - i));
        }
        a /= 2;
        i += 1;
        if (a % 2 == 1)
        {
            res |= (1 << (32 - i));
        }
        a /= 2;
        i += 1;
    }
    output(res);
}

int main(void)
{
    unsigned int num;
    int check;
    printf("Введите целое беззнаковое четырехбайтное число: ");
    check = scanf("%u", &num);
    // Проверка на ввод числа
    if (check != 1)
    {
        printf("Error: введено не числовое значение\n");
        return 1;
    }
    // Далее - вывод результата и завершение программы
    printf("Result: ");
    crypt(num);
    printf("\n");
    return 0;
}
