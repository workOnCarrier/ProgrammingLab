
CC = g++

CFLAGS = -I../hdr -Wall
CPPFLAGS = -std=c++0x -I../hdr -Wall -ggdb
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

SRC = legacy.cpp main.cpp myNew.cpp
OBJ = legacy.o main.o myNew.o

TARGET = testType2Type

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
	rm $(TARGET)
	rm $(OBJ)
	make $(CLEAN_CTAGS)


