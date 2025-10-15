#!/usr/bin/env bash

gcc -g -DDEBUG src/make_haversine_json.c -lm -o make.x
./make.x uniform $RANDOM 1000000
gcc -g -O2 -DDEBUG src/calc_haversine.c      -lm -o calc.x
./calc.x haversine_pairs.json solution_dump.data
