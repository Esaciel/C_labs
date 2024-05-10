#!/bin/bash

# Использование: ./build_debug.sh [имя файла]?    если имя файла не указано, используется стандартное main.c

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


if ! gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -c "$file" -o "$dir/main.o"; then
    exit 2
else
    gcc -o "$dir/app.exe" "$dir/main.o" -lm
fi
