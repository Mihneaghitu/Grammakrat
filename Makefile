all: combinator

CC = g++
CFLAGS = -std=c++17 -Wall -Wextra -pedantic -g

combinator:
	$(CC) $(CFLAGS) -o combinator parser_combinator.cpp

clean:
	rm -f combinator
