
CC = /usr/bin/g++-4.8

CFLAGS = -I. -Wall
CPPFLAGS = -std=c++0x -I. -I../../interface -Wall -ggdb -fpic -c
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

TEST_INTERPRETER_SRC = textInterpreter.cpp specialTextTask.cpp textTask.cpp
TEST_INTERPRETER_OBJ =  specialTextTask.o textTask.o textInterpreter.o

TARGET = libblocks.so

all: $(TARGET) 

$(TARGET) : $(TEST_INTERPRETER_OBJ)
	$(CC) -shared -o $(TARGET) $(LDFLAGS) $(TEST_INTERPRETER_OBJ)
	cp $(TARGET) ../bin

#.o.cpp:
.cpp.o :
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	rm tags
 
clean: 
	-rm -f core buildlog 
	-rm $(TARGET)
	-rm ../lib/$(TARGET)
	-rm $(TEST_INTERPRETER_OBJ)
	-make $(CLEAN_CTAGS)
