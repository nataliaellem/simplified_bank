# All makefile tasks
.PHONY: all test build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out
TEST=test.out

all: compile_lib build clean

compile_lib:
	$(CC) $(CFLAGS) -c lib/list.c -o list.out
	$(CC) $(CFLAGS) -c lib/client.c -o client.out
	$(CC) $(CFLAGS) -c lib/manager.c -o manager.out
	$(CC) $(CFLAGS) -c lib/homepage.c -o homepage.out
	$(CC) $(CFLAGS) -c lib/login.c -o login.out
	$(CC) $(CFLAGS) -c lib/helper.c -o helper.out

test: compile_lib
	$(CC) $(CFLAGS) tests/test.c list.out client.out manager.out homepage.out login.out helper.out -o $(TEST)

build:
	$(CC) $(CFLAGS) main.c list.out client.out manager.out homepage.out login.out helper.out -o $(EXEC)

clean:
	rm -rf list.out client.out manager.out homepage.out login.out helper.out 
