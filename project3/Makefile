all: build/test_driver
CC=g++
CFLAGS=-Wall -Wextra -g

SOURCES =\
	src/ArrayBag.cpp\
	src/ArrayBag.h\
	src/ArrayLinkedBag.cpp\
	src/ArrayLinkedBag.h\
	src/BagInterface.h\
	src/LinkedBag.cpp\
	src/LinkedBag.h\
	src/Node.cpp\
	src/Node.h\
	src/test_driver.cpp

.PHONY: all
all: build/test_driver

build/test_driver: $(SOURCES) | build
	$(CC) $(CFLAGS) src/test_driver.cpp -o build/test_driver

build:
	@mkdir -p $@

output:
	@mkdir -p $@

.PHONY: documentation
documentation: $(SOURCES)
	doxygen

.PHONY: test
test: build/test_driver | output
	@./build/test_driver ARRAY > output/array.out
	@./build/test_driver LINKED > output/linked.out
	@./build/test_driver ARRAY_LINKED > output/array_linked.out
	@diff output/array.out output/array_linked.out
	@echo
	@echo TEST SUCCESSFUL 
	@echo

.PHONY: clean
clean:
	-rm -rf build
	-rm -rf output
	-rm -rf docs


