CC=g++
CFLAGS=-Wall -Wextra -g -std=c++11

SOURCES =\
	src/Node.hpp\
	src/int_test_driver.cpp\
	src/string_test_driver.cpp

.PHONY: all
all: build/int_test_driver build/string_test_driver

build/int_test_driver: src/Node.hpp src/int_test_driver.cpp | build
	$(CC) $(CFLAGS) src/int_test_driver.cpp -o $@

build/string_test_driver: src/Node.hpp src/string_test_driver.cpp | build
	$(CC) $(CFLAGS) src/string_test_driver.cpp -o $@

build:
	@mkdir -p $@

.PHONY: documentation
documentation: $(SOURCES)
	doxygen

.PHONY: test
test: build/int_test_driver build/string_test_driver
	./build/int_test_driver
	@./build/int_test_driver > test/test.out
	@diff test/test.ref test/test.out
	@echo TEST SUCCESSFUL
	@echo
	./build/string_test_driver

.PHONY: clean
clean:
	-rm -r build
	-rm -r test/test.out
	-rm -r docs

