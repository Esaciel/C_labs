#!/bin/bash

# Использование: ./build_debug_ubsan.sh [имя файла]?    если имя файла не указано, используется стандартное main.c

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

for file in *.c; do
    if ! gcc -std=c99 -Wall -g -c "$file"; then
        exit 2
    fi
done

if ! clang -fsanitize=undefined -fno-omit-frame-pointer ./*.o -o "app.exe"; then
    exit 2
fi
exit 0
