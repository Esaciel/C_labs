# Тесты лабораторной работы №4 задания №3

## Входные данные 

Две строки длиной не более 255 символов и длиной каждого слова в них не более 16 символов, с как минимум одним словом, отличным от последнего (слова обособленны произвольным числом пробелов)

## Выходные данные 

Строка длиной не более 263 символов начинающаяся на "Result: " и оканчивающаяся на набор слов обособленных пробелами 

## Негативные тесты 

#### Проверка ввода строки некорректной длины

- тест 01, входные данные: строка длиной 257 символов , ожидаемый результат: ненулевой код возврата, [строка с описанием ошибки]

#### Проверка ввода слов с некорректной длиной

- тест 02

входные данные: (слово больше 16 символов)
```
abc abcdefghabcdefhgJ a
```
ожидаемый результат: ненулевой код возврата, строка с [описанием ошибки]

#### Проверка существования строки

- тест 03, входные данные: (пустой файл) , ожидаемый результат: ненулевой код возврата, строка с [описанием ошибки]

#### Проверка ввода строкb без уникальных слов

- тест 04

входные данные:
```
abc abc abc
```
ожидаемый результат: ненулевой код возврата, [строка с описанием ошибки]

## Позитивные тесты

#### Проверка общих случаев поиска уникальных слов (в том числе с граничными значениями длин строк и слов)

- тест 01

входные данные: 
```
   klklk gf  abcdabcF   gf   abcdabcF   koikl  hattori   aaaaaaa   b b b
```
ожидаемый результат:
```
Result: a hatori koil abcdF gf abcdF gf kl
```

- тест 02

входные данные: 
```
abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcdF
```
ожидаемый результат:
```
Result: abcde abcde abcde abcde abcde abcde abcde abcde abcde abcde abcde abcde abcde abcde abcde
```

- тест 03

входные данные: 
```
abcdeabcdeabcdFa                abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde abcdeabcdeabcde
```
ожидаемый результат:
```
Result: abcdeF
```