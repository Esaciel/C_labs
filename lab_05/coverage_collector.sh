#!/bin/bash

find . -maxdepth 1 -type d -name "lab_*_*" -execdir bash -c 'echo $(basename "$0") && cd "$0" && ./build_coverage.sh && ./collect_coverage.sh echo ""' {} \;
