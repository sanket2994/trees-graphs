CC=gcc
CFLAGS=-I../include -c -g
OBJFILES= delete.o insert.o searching.o print.o
LIBNAME= libtree.a

default: library clean

library: $(OBJFILES)
	ar -crv $(LIBNAME) $(OBJFILES)

insert.o: insert.c
	$(CC) $(CFLAGS) insert.c

delete.o: delete.c
	$(CC) $(CFLAGS) delete.c

searching.o: searching.c
	$(CC) $(CFLAGS) searching.c

print.o: print.c
	$(CC) $(CFLAGS) print.c

clean: 
	rm -f $(OBJFILES)
