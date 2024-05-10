#!/bin/bash

if ! gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -c main.c; then
    exit 2
else
    gcc -o app.exe main.o -lm
fi