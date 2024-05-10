#!/bin/bash

# Использование: ./build_debug_msan.sh [имя файла]?    если имя файла не указано, используется стандартное main.c

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


if ! clang -std=c99 -Wall -fsanitize=memory -fPIE -pie -fno-omit-frame-pointer -g "$file" -o "$dir/app.exe"; then
    exit 2
fi
exit 0
