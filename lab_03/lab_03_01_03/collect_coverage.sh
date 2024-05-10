#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")
cd "$dir" || exit 3

if ! [ -f "app.exe" ]; then
    echo "Отсутствует исполняемый файл app.exe"
elif ! [ -f "main.gcno" ]; then
    echo "Неверная сборка"
fi

exefile="./app.exe"
data_dir="func_tests/data"

while IFS= read -r testfile; do
    "$exefile" < "$testfile" > /dev/null 2>&1
done < <(find "$data_dir" -type f -name "*in.txt" | sort)

for file in *.gcda; do
    (echo -n "Покрытие кода файла ${file/%.gcda/.c}: "; gcov "$file" | grep -oEm 1 '[0-9]+\.[0-9]+%' | cat;)
done
echo ""
exit 0
