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

nums_get() 
{
    grep -oE '[+-]?[0-9]+(\.[0-9]+)?(e[-+]?[0-9]+)?' "$1"
}

if ! diff <(nums_get "$1") <(nums_get "$2") > /dev/null 2>&1; then
    exit 1
fi
exit 0
