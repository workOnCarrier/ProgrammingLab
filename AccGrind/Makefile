CC = /usr/bin/g++-5

CFLAGS = -I. -Wall
CPPFLAGS = -std=c++0x -I../include -I../blocks -Wall -ggdb -fpic -c
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

TEST_INTERPRETER_SRC = 
TEST_INTERPRETER_OBJ = 


all:
	-make -C interface
	-make -C framework
	-make -C plugins
	-make ctags

#.o.cpp:
.cpp.o :
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	rm tags
 
clean: 
	-rm -f core
	-make -C interface clean
	-make -C framework clean
	-make -C plugins clean
	-make $(CLEAN_CTAGS)
