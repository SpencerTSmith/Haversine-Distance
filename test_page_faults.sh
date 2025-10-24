#!/usr/bin/env bash

set -euox pipefail

gcc -g -DDEBUG src/test_page_faults.c -o reptest_page_faults.x
./reptest_page_faults.x 10
