#!/bin/bash

# Использование: ./sanitizer_check.sh [имя файла]?    если имя файла не указано, используется стандартное main.c

dir=$(dirname "$(readlink -f "$0")")
cd "$dir" || exit 3

if [ "$#" -lt 1 ]; then
    if ! [ -f "main.c" ]; then
        echo "Входной файл main.c не существует"
        exit 1
    fi
elif ! [ -f "$1" ]; then
    echo "Входной файл $1 не существует"
    exit 1
fi

asan="./build_debug_asan.sh"
msan="./build_debug_msan.sh"
ubsan="./build_debug_ubsan.sh"
exefile="./app.exe"
data_dir="func_tests/data"

tester()
{
    $1
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
