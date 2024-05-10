#!/bin/bash

# Использование: ./build_coverage.sh [имя файла]?    если имя файла не указано, используется стандартное main.c

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

if ! gcc -std=c99 -Wall -Werror -O0 --coverage -o "$dir/app.exe" "$file" -lm; then
    exit 2
fi
exit 0
