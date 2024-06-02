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
func_tests="./func_tests/scripts/func_tests.sh"

tester()
{
    $1
    $func_tests > /dev/null 2>&1
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
