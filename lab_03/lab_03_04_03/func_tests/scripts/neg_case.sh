#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")

if [ $# -lt 1 ]; then
    echo "Использование: $0 входной_файл"
    exit 2
elif ! [ -f "$1" ]; then
    echo "Файл $1 не существует"
    exit 2
fi

in_file=$1
exefile="$dir/../../app.exe"
if ! [ -f "$exefile" ]; then
    echo "Отсутствует исполняемый файл app.exe"
    exit 2
fi

if ! "$exefile" < "$in_file" > /dev/null 2>&1; then
    exit 0
fi
exit 1
