CC=gcc
CFLAGS=-I../include -c -g
OBJFILES= delete.o insert.o searching.o print.o dijktras.o prim.o kruskal.o redBlack.o heap.o
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

dijktras.o: dijktras.c
	$(CC) $(CFLAGS) dijktras.c

prim.o: prim.c
	$(CC) $(CFLAGS) prim.c

kruskal.o: kruskal.c
	$(CC) $(CFLAGS) kruskal.c

redBlack.o: redBlack.c
	$(CC) $(CFLAGS) redBlack.c

heap.o: heap.c
	$(CC) $(CFLAGS) heap.c
clean: 
	rm -f $(OBJFILES)
