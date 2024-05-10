#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")

if ! [ -f "$dir/app.exe" ]; then
    echo "Отсутствует исполняемый файл app.exe"
elif ! [ -f "$(find "$dir" -name 'app-*.gcno')" ]; then
    echo "Неверная сборка"
fi

exefile="$dir/app.exe"
data_dir="$dir/func_tests/data"

while IFS= read -r testfile; do
    "$exefile" < "$testfile" > /dev/null 2>&1
done < <(find "$data_dir" -type f -name "*in.txt" | sort)

(echo "Покрытие кода: "; gcov "$dir/"app-*.gcno | grep -oEm 1 '[0-9]+\.[0-9]+%' | cat; echo "";)
mv ./*.c.gcov "$dir" > /dev/null 2>&1
