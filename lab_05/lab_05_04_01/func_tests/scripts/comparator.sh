#!/bin/bash

if [ $# -lt 2 ]; then
    echo "Использование: $0 файл_1 файл_2"
    exit 2
elif ! [ -f "$1" ] && ! [ -e "$1" ]; then
    echo "Файл $1 не существует"
    exit 2
elif ! [ -f "$2" ]; then
    echo "Файл $2 не существует"
    exit 2
fi

substring=""

substring_n_after() 
{
    tail -c +$(($(grep -o -b -m 1 "$substring" "$1" | cut -d: -f1)+1)) "$1"
}

if ! diff <(substring_n_after "$1") <(substring_n_after "$2") >> /dev/null 2>&1; then
    exit 1
fi
exit 0
