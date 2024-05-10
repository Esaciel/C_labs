#!/bin/bash

# Usage: ./func_tests.sh ["-s" for silent mode]

data_dir="../data"
neg_tester="./neg_case.sh"
pos_tester="./pos_case.sh"

pos_count=0

if [ $# -gt 0 ]; then
    v=$1
else
    v=0
fi

echer()
{
    if [ "$v" != "-s" ]; then
        echo "$1"
    fi
}

while IFS= read -r in_file; do

    out_file="${in_file/in/out}"

    if ! [ -f "$out_file" ]; then
        echer "$(basename "$in_file") : не найден выходной файл"
        ((pos_count++))
    elif ! $pos_tester "$in_file" "$out_file"; then
        echer "$(basename "$in_file") : провален"
        ((pos_count++))
    else
        echer "$(basename "$in_file") : пройден"
    fi
    
done < <(find "$data_dir" -type f -name "pos*in.txt" | sort)

echer ""

neg_count=0

while IFS= read -r in_file; do

    if ! $neg_tester "$in_file"; then
        echer "$(basename "$in_file") : провален"
        ((neg_count++))
    else
        echer "$(basename "$in_file") : пройден"
    fi

done < <(find "$data_dir" -type f -name "neg*in.txt" | sort)

echer ""
echer "$pos_count позитивных тестов провалено"
echer "$neg_count негативных тестов провалено"
echer ""

exit $((pos_count + neg_count))
