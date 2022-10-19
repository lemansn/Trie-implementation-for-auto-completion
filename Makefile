$(CC) = gcc
CFLAGS = -Wall -Wextra -std=c11 -pedantic

all:
	$(CC) $(CFLAGS) -o cmpl main.c trie.c trie.h
