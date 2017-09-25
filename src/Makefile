CC=gcc
CFLAGS=-I../include -c -g
OBJFILES= delete.o insert.o searching.o print.o dijktras.o prim.o kruskal.o heap.o graph.o
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

heap.o: heap.c
	$(CC) $(CFLAGS) heap.c

graph.o: graph.c
	$(CC) $(CFLAGS) graph.c

clean: 
	rm -f $(OBJFILES)
