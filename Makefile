CC = gcc
CFLAGS = -g -Wall -Wextra -Iinclude -std=23

TARGET = lib/darray.a

.PHONY: release
release: CFLAGS += -03
release: $(TARGET) tests

.PHONOY: debug
debug: CFLAGS += -O0 -g
debug: $(TARGET) tests

.PHONY: build
build: 
	mkdir -p build
	mkdir -p bin/tests
	mkdir -p lib

.PHONY: clean
clean: 
	rm -rf $(TARGET)
	rm -rf lib bin build

$(TARGET): build build/darray.o
	ar rcs $(TARGET) build/darray.o

.PHONY: tests
tests: LDLIBS += -lcheck -lsubunit
tests: test/darray-tests.c
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) test/darray-tests.c $(TARGET) -o bin/tests/darray-tests

build/darray.o: src/darray.c include/darray.h
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -c src/darray.c -o build/darray.o
