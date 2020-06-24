# All makefile tasks
.PHONY: all build clean

# Variable definitions
CC=gcc
CFLAGS=-Wall -Wextra
EXEC=exec.out

all: build clean

build:
	$(CC) $(CFLAGS) -c lib/list.c -o list.out
	$(CC) $(CFLAGS) -c lib/client.c -o client.out
	$(CC) $(CFLAGS) -c lib/manager.c -o manager.out
	$(CC) $(CFLAGS) -c lib/homepage.c -o homepage.out
	$(CC) $(CFLAGS) -c lib/login.c -o login.out
	$(CC) $(CFLAGS) main.c list.out client.out manager.out homepage.out login.out -o $(EXEC)

clean:
	rm -rf list.out client.out manager.out homepage.out login.out
