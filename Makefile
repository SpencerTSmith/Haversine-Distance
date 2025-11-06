SHELL := bash

ON_WARNINGS := -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-align -Wredundant-decls
NO_WARNINGS := -Wno-unused-parameter -Wno-unused-function -Wno-override-init

OPTIMIZATION := -O1

CFLAGS := -g -std=c11 -DDEBUG -DPROFILE ${ON_WARNINGS} ${NO_WARNINGS} ${OPTIMIZATION}

TRY_FOR_MIN_TIME := 10

bin-folder:
	mkdir -p bin

json: bin-folder
	gcc ${CFLAGS} src/make_haversine_json.c -lm -o bin/make.x
	bin/make.x uniform $$RANDOM 10000000

calc: bin-folder
	gcc ${CFLAGS} src/calc_haversine.c  -lm -o bin/calc.x
	bin/calc.x haversine_pairs.json solution_dump.data

address-anatomy: bin-folder
	gcc ${CFLAGS} src/address_anatomy.c -o bin/address_anatomy.x
	bin/address_anatomy.x

tests: test-common test-arguments

test-common: bin-folder
	gcc ${CFLAGS} src/tests/test_common.c -o bin/test_common.x
	bin/test_common.x

test-arguments: bin-folder
	gcc ${CFLAGS} src/tests/test_arguments.c -o bin/test_arguments.x
	bin/test_arguments.x positional --verbose -v --foo --bar --baz=foo,bar,boo positional2 --bunk=bip,bop,bam,

reptest-file-apis: bin-folder
	head -c 1G /dev/urandom > gb_file.txt
	gcc ${CFLAGS} src/reptest_file_apis.c -o bin/reptest_file_apis.x
	bin/reptest_file_apis.x gb_file.txt $(TRY_FOR_MIN_TIME)

reptest-page-faults: bin-folder
	gcc ${CFLAGS} src/reptest_page_faults.c -o bin/reptest_page_faults.x
	bin/reptest_page_faults.x $(TRY_FOR_MIN_TIME)

reptest-loop-dependencies: bin-folder
	nasm -f elf64 -o bin/reptest_loop_dependencies.o src/reptest_loop_dependencies.asm
	ar rcs bin/reptest_loop_dependencies.a bin/loop_deps.o
	gcc ${CFLAGS} src/reptest_loop_dependencies.c bin/reptest_loop_dependencies.a -o bin/reptest_loop_dependencies.x
	bin/reptest_loop_dependencies.x $(TRY_FOR_MIN_TIME)

reptest-nops: bin-folder
	nasm -f elf64 -o bin/reptest_nops.o src/reptest_nops.asm
	ar rcs bin/reptest_nops.a bin/reptest_nops.o
	gcc ${CFLAGS} src/reptest_nops.c bin/reptest_nops.a -o bin/reptest_nops.x
	bin/reptest_nops.x $(TRY_FOR_MIN_TIME)

reptest-branches: bin-folder
	nasm -f elf64 -o bin/reptest_branches.o src/reptest_branches.asm
	ar rcs bin/reptest_branches.a bin/reptest_branches.o
	gcc ${CFLAGS} src/reptest_branches.c bin/reptest_branches.a -o bin/reptest_branches.x
	bin/reptest_branches.x $(TRY_FOR_MIN_TIME)

reptest-code-alignment: bin-folder
	nasm -f elf64 -o bin/reptest_code_alignment.o src/reptest_code_alignment.asm
	ar rcs bin/reptest_code_alignment.a bin/reptest_code_alignment.o
	gcc ${CFLAGS} src/reptest_code_alignment.c bin/reptest_code_alignment.a -o bin/reptest_code_alignment.x
	bin/reptest_code_alignment.x $(TRY_FOR_MIN_TIME)

reptest-rat: bin-folder
	nasm -f elf64 -o bin/reptest_rat.o src/reptest_rat.asm
	ar rcs bin/reptest_rat.a bin/reptest_rat.o
	gcc ${CFLAGS} src/reptest_rat.c bin/reptest_rat.a -o bin/reptest_rat.x
	bin/reptest_rat.x $(TRY_FOR_MIN_TIME)

reptest-read-ports: bin-folder
	nasm -f elf64 -o bin/reptest_read_ports.o src/reptest_read_ports.asm
	ar rcs bin/reptest_read_ports.a bin/reptest_read_ports.o
	gcc ${CFLAGS} src/reptest_read_ports.c bin/reptest_read_ports.a -o bin/reptest_read_ports.x
	bin/reptest_read_ports.x $(TRY_FOR_MIN_TIME)

reptest-write-ports: bin-folder
	nasm -f elf64 -o bin/reptest_write_ports.o src/reptest_write_ports.asm
	ar rcs bin/reptest_write_ports.a bin/reptest_write_ports.o
	gcc ${CFLAGS} src/reptest_write_ports.c bin/reptest_write_ports.a -o bin/reptest_write_ports.x
	bin/reptest_write_ports.x $(TRY_FOR_MIN_TIME)
