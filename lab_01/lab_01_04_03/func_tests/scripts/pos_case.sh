#!/bin/bash

if [ $# -lt 2 ]; then
    echo "Usage: $0 file_stream_in file_stream_out"
    exit 2
elif ! [ -f "$1" ]; then
    echo "file_stream_in doesn't exist"
    exit 2
elif ! [ -f "$2" ]; then
    echo "file_stream_out doesn't exist"
    exit 2
fi

in_file=$1
expected_out=$2
exefile="../../app.exe"
comparator="./comparator.sh"

if ! $comparator <("$exefile" < "$in_file") "$expected_out" > /dev/null 2>&1; then
    exit 1
fi
exit 0
