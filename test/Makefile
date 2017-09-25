CC=gcc 
IFLAGS = -I../include -g -c
CFLAGS = -o
LIBNAME = libtree.a
LFLAGS = -ltree -L
LIBPATH = ../src/
EXEC = avl bst redBlack dijktras prim kruskal
EXECPATH = ../build/
all: $(EXEC) clean


#executable for AVL tree
avl:  avl_app.o $(LIBPATH)$(LIBNAME)
	$(CC) $(CFLAGS) $(EXECPATH)avl avl_app.o $(LFLAGS)$(LIBPATH)

avl_app.o: avl_app.c
	$(CC) $(IFLAGS) avl_app.c


#executable for BST tree
bst:  bst_app.o $(LIBPATH)$(LIBNAME)
	$(CC) $(CFLAGS) $(EXECPATH)bst bst_app.o $(LFLAGS)$(LIBPATH)

bst_app.o: bst_app.c
	$(CC) $(IFLAGS) bst_app.c


#Executable for red black tree
redBlack:  redBlack_app.o $(LIBPATH)$(LIBNAME)
	$(CC) $(CFLAGS) $(EXECPATH)redBlack redBlack_app.o $(LFLAGS)$(LIBPATH)

redBlack_app.o: redBlack_app.c
	$(CC) $(IFLAGS) redBlack_app.c

#executable for prim MST
prim:  prim_app.o $(LIBPATH)$(LIBNAME)
	$(CC) $(CFLAGS) $(EXECPATH)prim prim_app.o $(LFLAGS)$(LIBPATH)

prim_app.o: prim_app.c
	$(CC) $(IFLAGS) prim_app.c

#executable for kruskal MST
kruskal: kruskal_app.o $(LIBPATH)$(LIBNAME)
	$(CC) $(CFLAGS) $(EXECPATH)kruskal kruskal_app.o $(LFLAGS)$(LIBPATH)

kruskal_app.o: kruskal_app.c
	$(CC) $(IFLAGS) kruskal_app.c


#executable for dijiktras
dijktras: dijktras_app.o $(LIBPATH)$(LIBNAME)
	$(CC) $(CFLAGS) $(EXECPATH)dijktras dijktras_app.o $(LFLAGS)$(LIBPATH)

dijktras_app.o: dijktras_app.c
	$(CC) $(IFLAGS) dijktras_app.c

#cleaning all the intermediate .o files generated
clean: 
	rm -f *.o


