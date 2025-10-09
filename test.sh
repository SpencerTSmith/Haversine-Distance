#!/usr/bin/env bash

gcc -g -DDEBUG -lm src/make_haversine_json.c -o make.x
./make.x uniform $RANDOM 10000000
gcc -g -DDEBUG -lm src/calc_haversine.c      -o calc.x
./calc.x haversine_pairs.json solution_dump.data
