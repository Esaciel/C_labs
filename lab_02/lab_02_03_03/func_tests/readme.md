# Тесты лабораторной работы №2 задания №3

## Входные данные 

Целое положительное число N из промежутка [1;10], затем набор из N целых положительных чисел, все обособленны пробелами

## Выходные данные 

Набор из K целых положительных чисел, причем K <= 2N 

## Позитивные тесты

#### Проверка общих случаев вывода массива c вставкой развернутой версии положительного элемента после каждого такого элемента

- тест 01, входные данные: 5 11 12 13 14 15 , ожидаемый результат: 11 11 12 21 13 31 14 41 15 51

- тест 02, входные данные: 5 -11 12 -13 14 -15 , ожидаемый результат: -11 12 21 -13 14 41 -15

- тест 03, входные данные: 5 -1 -2 -3 -4 -5 , ожидаемый результат: -1 -2 -3 -4 -5

## Негативные тесты 

#### Проверка некорректного ввода размера массива (первого числа)

- тест 01, входные данные: a 1 2 3, ожидаемый результат: строка с описанием ошибки

- тест 02, входные данные: 11 1 2 3 4 5 6 7 8 9 10 11 , ожидаемый результат: строка с описанием ошибки

#### Проверка некорректного количества элементов во вводе

- тест 03, входные данные: 5 11 12 13 , ожидаемый результат: строка с описанием ошибки

#### Проверка некорректного ввода самих элементов

- тест 04, входные данные: 5 11 12 13 14 a, ожидаемый результат: строка с описанием ошибки
