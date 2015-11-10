
CC = /usr/bin/g++-4.8

CFLAGS = -I. -Wall
CPPFLAGS = -std=c++0x -I. -I../blocks -I../ -Wall -ggdb -c
LDFLAGS = -lpthread -L../lib -lblocks -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

TEST_INTERPRETER_SRC = testTextInterpreter.cpp
TEST_INTERPRETER_OBJ = testTextInterpreter.o
TARGET = hailThread

all: $(TARGET) 

TARGET_1 = dummyTest
$(TARGET_1) : $(TEST_INTERPRETER_OBJ)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(TEST_INTERPRETER_OBJ)

USE_THREAD_SRC = useThreadPool.cpp
USE_THREAD_OBJ = useThreadPool.o

$(TARGET) : $(USE_THREAD_OBJ)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(USE_THREAD_OBJ)

#.o.cpp:
.cpp.o :
	$(CC) --version
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	rm tags
 
clean: 
	-rm -f core
	-rm $(TARGET)
	-rm $(TEST_INTERPRETER_OBJ)
	-make $(CLEAN_CTAGS)
	-rm buildlog 
