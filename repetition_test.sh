#!/usr/bin/env bash

set -euox pipefail

gcc -g -DDEBUG src/repetition_test.c -o reptest.x
./reptest.x haversine_pairs.json 10
