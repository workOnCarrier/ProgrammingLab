CC = /usr/bin/g++-4.8

CFLAGS = -I. -Wall
CPPFLAGS = -std=c++0x -I../include -I../blocks -Wall -ggdb -fpic -c
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

TEST_INTERPRETER_SRC = 
TEST_INTERPRETER_OBJ = 


all:
	make -C textEcho

#.o.cpp:
.cpp.o :
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	rm tags
 
clean: 
	-rm -f core
	-make -C textEcho clean
	-make $(CLEAN_CTAGS)
