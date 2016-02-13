
CC = g++

CFLAGS = -I. -I../hdr -Wall
CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

SRC = main.cpp # scopedThread.cpp 
OBJ = main.o 

TARGET = threadTrial

all: $(TARGET) 

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJ)

ctags:
	$(CTAGS)

$(CLEAN) : 
	rm $(TARGET) 

$(CLEAN_CTAGS) :
	rm tags
 
clean: 
	rm -f core;
	rm $(TARGET);
	rm $(OBJ);
	make $(CLEAN_CTAGS);


