#!/bin/bash

# Использование: ./sanitizer_check.sh [имя файла]?    если имя файла не указано, используется стандартное main.c

dir=$(dirname "$(readlink -f "$0")")

if [ "$#" -lt 1 ]; then
    if ! [ -f "$dir/main.c" ]; then
        echo "Входной файл $dir/main.c не существует"
        exit 1
    else
        file="$dir/main.c"
    fi
elif ! [ -f "$dir/$1" ]; then
    echo "Входной файл $dir/$1 не существует"
    exit 1
else
    file="$dir/$1"
fi

asan="$dir/build_debug_asan.sh"
msan="$dir/build_debug_msan.sh"
ubsan="$dir/build_debug_ubsan.sh"
exefile="$dir/app.exe"
data_dir="$dir/func_tests/data"

tester()
{
    $1 "$(basename "$file")"
    while IFS= read -r testfile; do
        echo "$(basename "$testfile")..."
        "$exefile" < "$testfile" 2>&1 >/dev/null
    done < <(find "$data_dir" -type f -name "*in.txt" | sort)
}

echo "Адресный санитайзер:"
tester "$asan"
echo "Проверка завершена."
echo ""

echo "Санитайзер памяти:"
tester "$msan"
echo "Проверка завершена."
echo ""

echo "Санитайзер неопределенного поведения:"
tester "$ubsan"
echo "Проверка завершена."

exit 0
