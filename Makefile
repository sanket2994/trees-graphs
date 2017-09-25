#Makefile that invokes multiple makefiles


SRCPATH = ./src/
TESTPATH = ./test/
BUILDPATH = ./build/
LIBPATH = ./src/
LIBNAME = libtree.a

all: 
	mkdir build
	$(MAKE) -C $(SRCPATH)
	$(MAKE) -C $(TESTPATH)

clean:
	rm -rf $(BUILDPATH) $(LIBPATH)$(LIBNAME)

