CC = g++
CFLAGS = -Wall -std=c++0x
SOURCES = bookstore/book.cc bookstore/bookstore.cc

EXAMPLE_SOURCE = example/example.cc
EXAMPLE_EXECUTABLE = example/bookstore_example

all:
	$(CC) $(CFLAGS) $(EXAMPLE_SOURCE) $(SOURCES) -o $(EXAMPLE_EXECUTABLE)
