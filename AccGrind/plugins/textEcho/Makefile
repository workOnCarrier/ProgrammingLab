
CC = /usr/bin/g++-4.8
RANLIB = ranlib
CFLAGS = -I. -Wall
CPPFLAGS = -std=c++0x -I. -I../../interface -Wall -ggdb -fpic -c
LDFLAGS = -L ../../bin -lGenUtils -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

PLUGIN_SRC = textInterpreter.cpp specialTextTask.cpp textTask.cpp libmain.cpp
PLUGIN_OBJ =  specialTextTask.o textTask.o textInterpreter.o libmain.o

PLUGIN_TEST_SRC = testPlugin.cpp
PLUGIN_TEST_OBJ = testPlugin.o

TARGET = libtextEcho.so

TEST_TARGET = testLib

all: $(TARGET) 

$(TARGET) : $(PLUGIN_OBJ)
	$(CC) -shared -o $(TARGET) $(LDFLAGS) $(PLUGIN_OBJ)
	cp $(TARGET) ../../bin

$(TEST_TARGET) : $(PLUGIN_TEST_OBJ) $(TARGET)
	$(CC) -o $(TEST_TARGET) $(PLUGIN_TEST_OBJ) $(LDFLAGS) -ltextEcho 

#.o.cpp:
.cpp.o :
	echo "$(CC) -c $(CPPFLAGS) -o $@ $< "> buildlog 2>&1
	$(CC) -c $(CPPFLAGS) -o $@ $< >> buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	rm tags
 
clean: 
	-rm -f core buildlog 
	-rm $(TARGET)
	-rm ../../bin/$(TARGET)
	-rm $(PLUGIN_OBJ)
	-make $(CLEAN_CTAGS)
	-rm $(TEST_TARGET)
	-rm $(PLUGIN_TEST_OBJ)
