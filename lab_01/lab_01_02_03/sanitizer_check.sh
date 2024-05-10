#!/bin/bash

asan="./build_debug_asan.sh"
msan="./build_debug_msan.sh"
ubsan="./build_debug_ubsan.sh"
exefile="./app.exe"
data_dir="func_tests/data"

tester()
{
    "$1"
    while IFS= read -r testfile; do
        echo "$(basename "$testfile")..."
        "$exefile" < "$testfile" 2>&1 >/dev/null
    done < <(find "$data_dir" -type f -name "*in.txt" | sort)
}

echo "Adress sanitizer:"
tester "$asan"
echo "Done"
echo ""

echo "Memory sanitizer:"
tester "$msan"
echo "Done"
echo ""

echo "Undefined behavior sanitizer:"
tester "$ubsan"
echo "Done"
echo ""

exit 0
