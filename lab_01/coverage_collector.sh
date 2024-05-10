#!/bin/bash

find . -maxdepth 1 -type d -name "lab_*_*" -execdir bash -c 'echo $(basename "$0") && cd "$0" && ./collect_coverage.sh "-v" && echo ""' {} \;
