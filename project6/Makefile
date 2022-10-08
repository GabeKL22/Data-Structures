CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -g

SOURCES =\
	src/CompleteBinaryTree.h\
	src/CompleteBinaryTree.cpp\
	src/test_driver.cpp

.PHONY: all
all: build/test_driver

build/test_driver: $(SOURCES) | build
	$(CC) $(CFLAGS) src/test_driver.cpp -o build/test_driver

build:
	@mkdir -p $@

.PHONY: documentation
documentation: $(SOURCES)
	doxygen

.PHONY: test
test: build/test_driver
	./build/test_driver

.PHONY: clean
clean:
	-rm -rf build
	-rm -rf docs

.PHONY: submit
submit:
	make clean
	~schwesin/bin/submit.bash csc237
