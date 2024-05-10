#!/bin/bash

gcc -std=c99 -Wall -Werror -O0 --coverage -o app.exe main.c -lm

exefile="./app.exe"
data_dir="func_tests/data"

while IFS= read -r testfile; do
    "$exefile" < "$testfile" > /dev/null 2>&1
done < <(find "$data_dir" -type f -name "*in.txt" | sort)

(echo "Покрытие кода: "; gcov app-main.gcno | grep -oEm 1 '[0-9]+\.[0-9]+%' | cat; echo "";)
