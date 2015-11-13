
CC = /usr/bin/g++-4.8

CFLAGS = -I. -Wall
CPPFLAGS = -std=c++0x -I. -I../blocks -I../ -Wall -ggdb -c
LDFLAGS = -lpthread -ggdb -Wall -L../bin -lblocks 

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
	$(CC) -o $(TARGET) $(USE_THREAD_OBJ) $(LDFLAGS) 
	cp $(TARGET) ../bin

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
	-rm $(TARGET_1)
	-rm $(TEST_INTERPRETER_OBJ)
	-rm $(USE_THREAD_OBJ)
	-make $(CLEAN_CTAGS)
	-rm buildlog
