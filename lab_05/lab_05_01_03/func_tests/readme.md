# Тесты лабораторной работы №5 задания №1

## Входные данные 

Файл содержащий хотя-бы одно число до первого нечислового значения (в виде аргумента), либо вводимая строка с теми же правилами

## Выходные данные 

Целое положительное число

## Негативные тесты

#### Проверка обработки некорректного использования

- тест 01

Аргументы:
```
file_1 file_2 file_3
```
Входные данные: ...

Ожидаемый результат: Указание корректной строки запуска


#### Проверка случая отсутствия доступа к подаваемому файлу

- тест 02

Аргументы:
```
./func_tests/data/invalid_name.txt
```
Входные данные: ...

Ожидаемый результат: Указание errno и описание возникшей ошибки

#### Проверка файла без валидных чисел перед концеым признаком

- тест 03

Аргументы:
```
./func_tests/data/neg_03_in.txt
```
Входные данные:
```
a 1 2 3
```

Ожидаемый результат: Описание возникшей ошибки

#### Проверка ввода с клавиатуры без валидных чисел перед концевым признаком

- тест 04

Аргументы:
```
(пустой файл)
```
Входные данные:
```
a -1 1 -1 0 a
```

- тест 05

Аргументы:
```
(пустой файл)
```
Входные данные:
```
-100 a 100
```

Ожидаемый результат: Описание возникшей ошибки

## Позитивные тесты

#### Проверка слуая работы с файлами

- тест 01

Аргументы:
```
./func_tests/data/pos_01_in.txt
```
Входные данные:
```
1 -2 3 -4 5 a
```

Ожидаемый результат:
```
4
```

- тест 02

Аргументы:
```
./func_tests/data/pos_02_in.txt
```
Входные данные:
```
1 2 3 4 5
```

Ожидаемый результат:
```
0
```

#### Проверка случая работы с вводом с клавиатуры

- тест 03

Аргументы:
```
(пустой файл)
```
Входные данные:
```
1 -1 -1 1 1 -1 -1 1 b 1 -1 1
```

Ожидаемый результат:
```
4
```

- тест 04

Аргументы:
```
(пустой файл)
```
Входные данные:
```
-1 0 0 0 1 2 3 b
```

Ожидаемый результат:
```
1
```