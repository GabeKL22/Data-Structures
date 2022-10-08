CC=g++
#CFLAGS=-Wall -Wextra -std=c++11 -g
CFLAGS=-Wall -Wextra -g

SOURCES =\
	src/sort_benchmark.cpp\
	src/bubblesort.hpp\
	src/selectionsort.hpp\
	src/insertionsort.hpp\
	src/mergesort.hpp\
	src/quicksort.hpp

.PHONY: all
all: build/sort_benchmark

build/sort_benchmark: $(SOURCES) | build
	$(CC) $(CFLAGS) src/sort_benchmark.cpp -o build/sort_benchmark

build:
	@mkdir -p $@

.PHONY: documentation
documentation: $(SOURCES)
	doxygen

.PHONY: test
test: build/sort_benchmark
	./build/sort_benchmark

.PHONY: clean
clean:
	-rm -rf build
	-rm -rf docs

.PHONY: submit
submit:
	make clean
	~schwesin/bin/submit.bash csc237
