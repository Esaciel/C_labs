#!/bin/bash

# shellcheck disable=SC2046
# Шеллчек считает разделение слов ошибкой, но в данном случае это ожидаемое поведение при передачи аргументов;
# Для избежания усложнения кода массивами, принято решение отключения этого предупреждения для следующей комманды.

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
comparator="$dir/comparator.sh"
if ! [ -f "$exefile" ]; then
    echo "Отсутствует исполняемый файл app.exe"
    exit 2
fi

comparator="$dir/comparator.sh"

mode=$(cut -d' ' -f1 < "$3")

if [ "$mode" == "db" ]; then
    bin_file=$(cut -d' ' -f2 < "$3")
    tmp_out_file="${expected_out/%_out.txt/_out.tmp}"
    if ! "$exefile" "import" "$in_file" "$bin_file" > /dev/null 2>&1; then
        exit 10
    elif ! "$exefile" $(cat "$args_file") > /dev/null 2>&1; then
        exit 20
    elif ! "$exefile" "export" "$bin_file" "$tmp_out_file" > /dev/null 2>&1; then
        exit 30
    elif ! $comparator "$tmp_out_file" "$expected_out" > /dev/null 2>&1; then
        exit 1
    fi
elif [ "$mode" == "fb" ]; then
    tmp_out_file="${expected_out/%_out.txt/_out.tmp}"
    bin_src=$(cut -d' ' -f2 < "$3")
    bin_dst=$(cut -d' ' -f3 < "$3")
    if ! "$exefile" "import" "$in_file" "$bin_src" > /dev/null 2>&1; then
        exit 10
    elif ! "$exefile" $(cat "$args_file") > /dev/null 2>&1; then
        exit 20
    elif ! "$exefile" "export" "$bin_dst" "$tmp_out_file" > /dev/null 2>&1; then
        exit 30
    elif ! $comparator "$tmp_out_file" "$expected_out" > /dev/null 2>&1; then
        exit 1
    fi
else
    if ! "$exefile" $(cat "$args_file") > /dev/null 2>&1; then
        exit 121
    fi
fi
exit 0
