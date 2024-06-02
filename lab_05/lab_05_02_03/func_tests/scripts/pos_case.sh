#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")

if [ $# -lt 3 ]; then
    echo "Использование: $0 входной_файл ожидаемый_вывод аргументы"
    exit 2
elif ! [ -f "$1" ]; then
    echo "Файл $1 не существует"
    exit 2
elif ! [ -f "$2" ]; then
    echo "Файл $2 не существует"
    exit 2
elif ! [ -f "$3" ]; then
    echo "Файл $3 не существует"
    exit 2
fi

in_file=$1
args_file=$3
expected_out=$2
exefile="$dir/../../app.exe"
if ! [ -f "$exefile" ]; then
    echo "Отсутствует исполняемый файл app.exe"
    exit 2
fi

comparator="$dir/comparator.sh"

# shellcheck disable=SC2046
# Шеллчек считает разделение слов ошибкой, но в данном случае это ожидаемое поведение при передачи аргументов;
# Для избежания усложнения кода массивами, принято решение отключения этого предупреждения для следующей комманды.

if ! $comparator <(("$exefile" $(cat "$args_file")) < "$in_file") "$expected_out" > /dev/null 2>&1; then
    exit 1
fi
exit 0
