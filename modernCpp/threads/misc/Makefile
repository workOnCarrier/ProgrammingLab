
CC = /usr/bin/g++-4.8

CFLAGS = -I. -I../hdr -I/usr/include/c++/4.8 -Wall
CPPFLAGS = -std=gnu++11 -I. -I../hdr -Wall -ggdb -pthread
LDFLAGS = -L/usr/lib/gcc/i686-linux-gnu/4.8 -pthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

SRC_1 = first.cpp
OBJ_1 = first.o 

TARGET_1 = misc1
TARGET_2 = atomic
CLEAN = clean

SRC_2 = atomic.cpp
OBJ_2 = atomic.o 

all: $(TARGET_1)  $(TARGET_2) 

$(TARGET_1) : $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1)

$(TARGET_2) : $(OBJ_2)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(OBJ_2)
#.o.cpp:
.cpp.o:
	$(CC) --version
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN) : $(CLEAN_CTAGS)
	-rm $(TARGET_1)  $(OBJ_1)
	-rm $(TARGET_2)  $(OBJ_2)
	-rm -f core

$(CLEAN_CTAGS) :
	-rm tags
 
