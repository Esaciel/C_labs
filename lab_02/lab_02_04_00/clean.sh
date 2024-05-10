#!/bin/bash

dir=$(dirname "$(readlink -f "$0")")

rm -f "$dir/"*.exe "$dir/"*.o "$dir/"*.gcov "$dir/"*.gcda "$dir/"*.gcno
