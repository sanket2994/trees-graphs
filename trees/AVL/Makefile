
CC=gcc
CFLAGS=-I -g

default: main clean
OBJFILES= main.o avl.o

main:main.o avl.o
	$(CC) $(CFLAGS) -o main $(OBJFILES)

main.o:main.c
	$(CC) -c main.c

avl.o:avl.c
	$(CC) -c avl.c

clean:
	rm -f $(OBJFILES)
