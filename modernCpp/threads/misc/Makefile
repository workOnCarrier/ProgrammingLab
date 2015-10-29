
CC = g++

CFLAGS = -I. -I../hdr -Wall
CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb
LDFLAGS = -lpthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

SRC = first.cpp
OBJ = first.o 

TARGET = misc1

all: $(TARGET) 

$(TARGET) : $(OBJ)
	$(CC) -o $(TARGET) $(LDFLAGS) $(OBJ)

#.o.cpp:
.cpp.o:
	$(CC) --version
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN) : 
	rm $(TARGET) 

$(CLEAN_CTAGS) :
	rm tags
 

TESTKEYINPUTSOURCE = testKIS
TESTINPUTOBJ = testKeyInputSource.o
$(TESTKEYINPUTSOURCE): $(TESTINPUTOBJ)  keyInputSource.h
	$(CC) -o $(TESTKEYINPUTSOURCE) $(LDFLAGS) $(TESTINPUTOBJ)  >> buildlog 2>&1

TESTCONCDS = testConcDS
TESTCONCDSOBJ = testConcurrentDS.o
$(TESTCONCDS) : $(TESTCONCDSOBJ) concurrentDS.h
	$(CC) -o $(TESTCONCDS) $(LDFLAGS) $(TESTCONCDSOBJ) >> buildlog 2>&1
	
test1: $(TESTKEYINPUTSOURCE)
	echo "tests key input by user : testKIS"

test2 : $(TESTCONCDS)
	echo "test concurrent data structure : " $(TESTCONCDS)

clean: 
	rm -f core &
	rm $(TARGET) &
	rm $(OBJ) &
	make $(CLEAN_CTAGS) &
	rm $(TESTKEYINPUTSOURCE) &
	rm $(TESTINPUTOBJ) &
	rm $(TESTCONCDS)
	rm $(TESTCONCDSOBJ)


