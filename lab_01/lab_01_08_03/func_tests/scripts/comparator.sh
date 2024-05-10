#!/bin/bash

if [ $# -lt 2 ]; then
    echo "Usage: $0 file_1 file_2"
    exit 2
elif ! [ -f "$1" ] && ! [ -e "$1" ]; then
    echo "file_1 doesn't exist"
    exit 2
elif ! [ -f "$2" ]; then
    echo "file_2 doesn't exist"
    exit 2
fi

substring_n_after() 
{
    tail -c +$(($(grep -o -b -m 1 "Result: " "$1" | cut -d: -f1)+1)) "$1"
}

if ! diff <(substring_n_after "$1") <(substring_n_after "$2") >> /dev/null 2>&1; then
    exit 1
fi
exit 0
