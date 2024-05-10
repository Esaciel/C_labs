#include <stdio.h>

int main(void)
{
    int s = 52;
    printf("Year has %d weeks\n", s);
    return 0;
}


/* исходный код


include studio.h                (1,2,3)
main{}                          (4,5,6)
(                               (7)
int s;                          
s: = 56;                        (8)
print (Year has s weeks)        (9,10,11,12)
                                (13)
)                               (14)


ошибки: 
1) нет символа # перед include   2) нет треугольных скобок вокруг stdio.h, 3) неправильное название библиотеки
3) нет указания типа позвращаемого значения int перед main   4) неверный тип скобок после main   5) отсутствует указания принимаемого типа значений void ф-цией main
6) неверный тип скобки начала функции
8) неверный оператор присваивания
9) неправильное название функции вывода   10) отсутствуют двойные кавычки при выводе текста 11) отсутствует форматирование вывода с переменными 12) отсутствует символ ; окончания строки
13) отсутствует ключевое слово return для возвращения из ф-ции main 
13) неверный тип скобки окончания функции


*/