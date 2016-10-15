
CC = /usr/bin/g++-5
RANLIB = ranlib
CFLAGS = -I. -Wall
CPPFLAGS = -std=c++0x -I. -I../../interface -Wall -ggdb -fpic -c
LDFLAGS = -L ../../bin -lGenUtils -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

PLUGIN_SRC = StartMyServOption.cpp StartServiceTask.cpp libmain.cpp serviceInterpreter.cpp
PLUGIN_OBJ = StartMyServOption.o StartServiceTask.o libmain.o serviceInterpreter.o

PLUGIN_TEST_SRC = testPlugin.cpp
PLUGIN_TEST_OBJ = testPlugin.o

TARGET = libserviceMgmt.so

TEST_TARGET = testLib

all: $(TARGET) 

$(TARGET) : $(PLUGIN_OBJ)
	$(CC) -shared -o $(TARGET) $(LDFLAGS) $(PLUGIN_OBJ)
	cp $(TARGET) ../../bin

$(TEST_TARGET) : $(PLUGIN_TEST_OBJ) $(TARGET)
	$(CC) -o $(TEST_TARGET) $(PLUGIN_TEST_OBJ) $(LDFLAGS) -lserviceMgmt 

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
