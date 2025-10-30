SHELL := bash

CFLAGS := -g -Wextra -Wall -std=c99 -DDEBUG -DPROFILE

json:
	gcc ${CFLAGS} src/make_haversine_json.c -lm -o make.x
	./make.x uniform $$RANDOM 10000000

calc:
	gcc ${CFLAGS} src/calc_haversine.c  -lm -o calc.x
	./calc.x haversine_pairs.json solution_dump.data

test-file-apis:
	head -c 1G /dev/urandom > gb_file.txt
	gcc ${CFLAGS} src/test_file_apis.c -o reptest_file_apis.x
	./reptest_file_apis.x gb_file.txt 10

test-page-faults:
	gcc ${CFLAGS} src/test_page_faults.c -o reptest_page_faults.x
	./reptest_page_faults.x 10

address-anatomy:
	gcc ${CFLAGS} src/address_anatomy.c -o anatomy.x
	./anatomy.x
