#!/usr/bin/env bash

set -euox pipefail

gcc -g -DDEBUG src/repetition_test.c -o reptest.x
./reptest.x gb_file.txt 10
