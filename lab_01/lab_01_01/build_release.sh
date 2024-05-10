#!/bin/bash

if ! gcc -std=c99 -c main.c; then
    exit 2
else
    gcc -o app.exe main.o -lm
fi
