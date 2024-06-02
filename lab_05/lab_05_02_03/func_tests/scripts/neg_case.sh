#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")

if [ $# -lt 2 ]; then
    echo "Использование: $0 входной_файл аргументы"
    exit 2
elif ! [ -f "$1" ]; then
    echo "Файл $1 не существует"
    exit 2
elif ! [ -f "$2" ]; then
    echo "Файл $2 не существует"
    exit 2
fi

in_file=$1
args_file=$2
exefile="$dir/../../app.exe"
if ! [ -f "$exefile" ]; then
    echo "Отсутствует исполняемый файл app.exe"
    exit 2
fi

# shellcheck disable=SC2046
# Шеллчек считает разделение слов ошибкой, но в данном случае это ожидаемое поведение при передачи аргументов;
# Для избежания усложнения кода массивами, принято решение отключения этого предупреждения для следующей комманды.

if ! ("$exefile" $(cat "$args_file")) < "$in_file" > /dev/null 2>&1; then
    exit 0
fi
exit 1
