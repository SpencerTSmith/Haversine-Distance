#!/usr/bin/env bash

set -euox pipefail

gcc -g -DDEBUG src/test_file_apis.c -o reptest_file_apis.x
./reptest_file_apis.x gb_file.txt 10
