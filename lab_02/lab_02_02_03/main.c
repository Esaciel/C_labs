#include <stdio.h>
#include <math.h>
#define S 10

// Проверка является ли принимаемое функцией число - числом Армстронга
long int is_armstrong(long int num) 
{
    // Ненулевой код в случае если входное число не натуральное 
    if (num <= 0)
    {
        return 1;
    }
    long int original, remainder, n = 0, result = 0;

    original = num;

    // Подсчет количества символов в числе
    while (original != 0) 
    {
        original /= 10;
        ++n;
    }

    original = num;

    // Алгоритм подсчета суммы цифр числа, возведенных в степень общего их количества 
    while (original != 0) 
    {
        remainder = original % 10;
        result += pow(remainder, n);
        original /= 10;
    }

    // Если найденная ранее сумма равна начальному числу - число является числом Армстронга, функция возвращает нулевой код, иначе - ненулевой
    if (result == num)
        return 0;
    else
        return 1;
}

// функция для вывода массива, принимает сам массив и длину обрабатываемой его части
void output_array(long int*a, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%ld ", a[i]);
    }
}

// Функция заполнения нового массива, принимает начальный массив, новый массив и длину начального массива
long int fill_new_array(long int*a, long int*new_a, size_t len)
{
    size_t new_len = 0;
    // проверяет каждое число в начальном массиве, если оно является числом Армстронга - добавляет его в новый массив и увеличивет его длину на единицу
    for (size_t i = 0; i < len; i++)
    {
        if (is_armstrong(a[i]) == 0)
        {
            new_a[new_len] = a[i];
            new_len++;
        }
    }

    // Если чисел Армстронга не обнаружено - выводит сообщение об ошибке и ненулевой код возврата, иначе - выводит массив из чисел Армстронга и нулевой код возврата
    if (new_len == 0)
    {
        printf("Во входном массиве нет чисел Армстронга\n");
        return 2;
    }
    else
    {
        printf("Массив из чисел Армстронга начального массива: ");
        output_array(new_a, new_len);
        return 0;
    }
}

// Функция заполнение массива, принимает на вход сам массив и его обрабатываемую длину
long int input_array(long int*a, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        // Записывает очередное значение в соответствующую ячейку памяти, в случае неудачной записи возвращает ненулевой код
        if (scanf("%ld", &a[i]) != 1)
        {
            return 1;
        }
    }
    return 0;
}

int main(void) 
{
    long int check = 0;
    size_t arr_len;
    // Ввод длины массива первым числом, в случае неверного ввода - сообщение об ошибке и ненулевой код возврата
    printf("Введите длину массива (от одного до десяти): ");
    check = scanf("%zu", &arr_len);
    if (check != 1 || arr_len < 1 || arr_len > 10)
    {
        printf("Введен неверный размер массива\n");
        return 1;
    }
    long int array[S] = { 0 };
    long int new_array[S] = { 0 };

    long int exit_code = 0;

    // Ввод начального массива через функцию, в случае неверного ввода - вывод сообщения об ошибке и выход с ненулевым кодом
    printf("Введите элементы целочисленного массива через пробел: ");
    exit_code = input_array(array, arr_len);
    if (exit_code != 0)
    {
        printf("Элементы введены неверно\n");
        return exit_code;
    }

    // Вывод начального массива
    // printf("Введенный массив: ");
    // output_array(array, arr_len);
    // printf("\n");
    

    // Заполнение нового массива и его вывод через соответствующую функцию, затем выход с идентичным этой функции кодом возврата (ненулевмы кодом в случае отсутствия числе Армстронга, нулевым в случае их наличия)
    exit_code = fill_new_array(array, new_array, arr_len);
    printf("\n");
    return exit_code;
}
