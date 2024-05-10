#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")

if [ $# -lt 2 ]; then
    echo "Использование: $0 входной_файл ожидаемый_вывод"
    exit 2
elif ! [ -f "$1" ]; then
    echo "Файл $1 не существует"
    exit 2
elif ! [ -f "$2" ]; then
    echo "Файл $2 не существует"
    exit 2
fi

in_file=$1
expected_out=$2
exefile="$dir/../../app.exe"
if ! [ -f "$exefile" ]; then
    echo "Отсутствует исполняемый файл app.exe"
    exit 2
fi

comparator="$dir/comparator.sh"
substring=""
tmpfile=$(mktemp -t)

"$exefile" < "$in_file" > "$tmpfile"
if ! $comparator "$tmpfile" "$expected_out" "$substring" > /dev/null 2>&1; then
    rm "$tmpfile"
    exit 1
fi
rm "$tmpfile"
exit 
