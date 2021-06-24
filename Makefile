.PHONY: clean
clean:
	test -d bin || mkdir bin
	rm -fR bin/*

bin/core.o: include/cxxpznn1/core.hpp src/core.cpp
	g++ \
		-std=c++17 \
		-I./include \
		src/core.cpp \
		-c -o bin/core.o

bin/cxxpznn1: bin/core.o src/cli.cpp
	g++ \
		-std=c++17 \
		-I./include \
		src/cli.cpp \
		bin/core.o \
		-o bin/cxxpznn1 \
		-L${HOME}/.local/lib \
		-lboost_program_options

bin/test_grid: bin/core.o test/test_grid.cpp
	g++ \
		-std=c++17 \
		-I./include \
		test/test_grid.cpp \
		bin/core.o \
		-o bin/test_grid

bin/test_direction: bin/core.o test/test_direction.cpp
	g++ \
		-std=c++17 \
		-I./include \
		test/test_direction.cpp \
		bin/core.o \
		-o bin/test_direction

bin/test_puzzle: bin/core.o test/test_puzzle.cpp
	g++ \
		-std=c++17 \
		-I./include \
		test/test_puzzle.cpp \
		bin/core.o \
		-o bin/test_puzzle
