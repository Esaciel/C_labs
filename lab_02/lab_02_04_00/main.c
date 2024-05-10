#include <stdio.h>
#include <math.h>
#define S 10

// функция для вывода массива, принимает сам массив и длину обрабатываемой его части
void output_array(int*a, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", a[i]);
    }
}

// Функция сортировки пузырьком, принмает на вход массив и длину обрабатываемой его части
void bubble_sort(int*arr, int arr_len)
{
    int i, j, temp;
    // Стандартный алгоритм сравнения двух соседних элементов 
    for (i = 0; i < arr_len; i++)
    {
        for (j = 0; j < (arr_len - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Вывод сообщения, затем вывод отсортированного массива через функцию вывода 
    printf("Массив отсортированный способом 'пузырька': ");
    output_array(arr, arr_len);
}

// Функция ввода массива, принимает сам массив и массив содержащий значение длины данного массива
int input_array(int*a, int*len)
{
    int tmp;
    // Записывает очередной элемент в соответствующую ячейку памяти и увеличивает длину массива на 1, в случае неудачного ввода останавливается с кодом возврата 0
    for (size_t i = 0; i < S; i++)
    {
        if (scanf("%d", &a[i]) != 1)
        {
            return 0;
        }
        len[0]++;
    }

    // В случае если после ввода всех десяти элементов массива не наситал коонцевой признак, т.е 11 элемент ввода снова число - возвращает код возврата 100, иначе - 0  
    if (scanf("%d", &tmp) == 1)
    {
        return 100;
    }
    return 0;
}

int main(void) 
{
    int array[S] = { 0 };
    int getlen[1] = { 0 };
    int exit_code = 0;

    // Ввод массива через функцию и запись кода возврата в переменную
    printf("Введите от одного до десяти элементов целочисленного массива с концевым признаком в виде нечислового значения: ");
    exit_code = input_array(array, getlen);

    // Вывод начального массива
    // printf("Введенный массив: ");
    // output_array(array, getlen[0]);
    // printf("\n");

    // В случае если длина массива равна нулю, т.е функция не получила значений либо первым же значением наступил концевой признак - вывод ненулевого кода возврата
    if (getlen[0] == 0)
    {
        printf("Не было введено ни одного элемента\n");
        return 2;
    }

    // Сортировка массива на основе его самого и его длины
    bubble_sort(array, getlen[0]);
    printf("\n");

    // Выход с кодом из ранее записанной переменной (0 в случае успешного ввода массива, 100 в случае если концевой признак не наступил после ввода 10 элементов)
    return exit_code;
}