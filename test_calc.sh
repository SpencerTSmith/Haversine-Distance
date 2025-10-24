#!/usr/bin/env bash

set -euox pipefail

# gcc -g -DPROFILE -DDEBUG src/make_haversine_json.c -lm -o make.x
# ./make.x uniform $RANDOM 10000000
gcc -g -DPROFILE -DDEBUG src/calc_haversine.c  -lm -o calc.x
./calc.x haversine_pairs.json solution_dump.data
# objdump -Sd -M intel --no-show-raw-ins calc.x >> dump.asm
