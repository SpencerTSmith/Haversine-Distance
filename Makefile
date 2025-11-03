SHELL := bash

CFLAGS := -g -O1 -Wall -std=c99 -DDEBUG -DPROFILE

TRY_FOR_MIN_TIME := 5

bin-folder:
	mkdir -p bin

json: bin-folder
	gcc ${CFLAGS} src/make_haversine_json.c -lm -o bin/make.x
	bin/make.x uniform $$RANDOM 10000000

calc: bin-folder
	gcc ${CFLAGS} src/calc_haversine.c  -lm -o bin/calc.x
	bin/calc.x haversine_pairs.json solution_dump.data

test-file-apis: bin-folder
	head -c 1G /dev/urandom > gb_file.txt
	gcc ${CFLAGS} src/test_file_apis.c -o bin/reptest_file_apis.x
	bin/reptest_file_apis.x gb_file.txt $(TRY_FOR_MIN_TIME)

test-page-faults: bin-folder
	gcc ${CFLAGS} src/test_page_faults.c -o bin/reptest_page_faults.x
	bin/reptest_page_faults.x $(TRY_FOR_MIN_TIME)

address-anatomy: bin-folder
	gcc ${CFLAGS} src/address_anatomy.c -o bin/anatomy.x
	bin/anatomy.x

test-loop-deps: bin-folder
	nasm -f elf64 -o bin/loop_deps.o src/loop_deps.asm
	ar rcs bin/loop_deps.a bin/loop_deps.o
	gcc ${CFLAGS} src/test_loop_dependencies.c bin/loop_deps.a -o bin/reptest_loops.x
	bin/reptest_loops.x $(TRY_FOR_MIN_TIME)

test-nops: bin-folder
	nasm -f elf64 -o bin/loop_nops.o src/loop_nops.asm
	ar rcs bin/loop_nops.a bin/loop_nops.o
	gcc ${CFLAGS} src/test_nops.c bin/loop_nops.a -o bin/reptest_nops.x
	bin/reptest_nops.x $(TRY_FOR_MIN_TIME)

test-branches: bin-folder
	nasm -f elf64 -o bin/loop_branch.o src/loop_branch.asm
	ar rcs bin/loop_branch.a bin/loop_branch.o
	gcc ${CFLAGS} src/test_branches.c bin/loop_branch.a -o bin/reptest_branches.x
	bin/reptest_branches.x $(TRY_FOR_MIN_TIME)

test-code-alignment: bin-folder
	nasm -f elf64 -o bin/align_nops.o src/align_nops.asm
	ar rcs bin/align_nops.a bin/align_nops.o
	gcc ${CFLAGS} src/test_code_align.c bin/align_nops.a -o bin/reptest_code_alignment.x
	bin/reptest_code_alignment.x $(TRY_FOR_MIN_TIME)
