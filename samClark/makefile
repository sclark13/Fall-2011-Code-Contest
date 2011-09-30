#!/bin/bash

CC     = gcc
CFLAGS = -g -O2

all: algorithm

algorithm: algorithm.o

	$(CC) $(LDFLAGS) -o $@ $^

algorithm.o: algorithm.c

	$(CC) $(CFLAGS) -c -o $@ $<

clean:

	rm -f algorithm algorithm.o

.PHONY: clean
