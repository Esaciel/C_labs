#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")
cd "$dir" || exit 3

if ! [ -f "app.exe" ]; then
    echo "Отсутствует исполняемый файл app.exe"
elif ! [ -f "main.gcno" ]; then
    echo "Неверная сборка"
fi

func_tests="./func_tests/scripts/func_tests.sh"

$func_tests > /dev/null 2>&1

for file in *.gcda; do
    (echo -n "Покрытие кода файла ${file/%.gcda/.c}: "; gcov "$file" | grep -oEm 1 '[0-9]+\.[0-9]+%' | cat;)
done
echo ""
exit 0
