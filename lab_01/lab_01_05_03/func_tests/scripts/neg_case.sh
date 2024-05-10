#!/bin/bash

if [ $# -lt 1 ]; then
    echo "Usage: $0 file_stream_in"
    exit 2
elif ! [ -f "$1" ]; then
    echo "file_stream_in doesn't exist"
    exit 2
fi

in_file=$1
exefile="../../app.exe"
if ! "$exefile" < "$in_file" > /dev/null 2>&1; then
    exit 0
fi
exit 1
