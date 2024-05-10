#!/bin/bash

find . -maxdepth 1 -type d -name "lab_*_*" -execdir bash -c 'cd "$0" && ./build_debug.sh' {} \;
