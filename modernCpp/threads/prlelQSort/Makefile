
CC = /usr/bin/g++-4.8

CFLAGS = -I. -I../hdr -I/usr/include/c++/4.8 -Wall
CPPFLAGS = -std=gnu++11 -I. -I../hdr -Wall -ggdb -pthread
LDFLAGS = -L/usr/lib/gcc/i686-linux-gnu/4.8 -pthread -ggdb -Wall

CTAGS = ctags --recurse=yes
CLEAN_CTAGS = clean_tags

all: $(TARGET) 
.cpp.o:
	$(CC) -c $(CPPFLAGS) -o $@ $< > buildlog 2>&1

ctags:
	$(CTAGS)

$(CLEAN_CTAGS) :
	rm tags

TEST_TS_STACK = testThreadSafeStack
TEST_TS_STACKOBJ = testThreadSafeStack.o
$(TEST_TS_STACK): $(TEST_TS_STACKOBJ) ThreadSafeStack.h
	$(CC) -o $(TEST_TS_STACK) $(LDFLAGS) $(TEST_TS_STACKOBJ)  >> buildlog 2>&1
test0:$(TEST_TS_STACK)
	echo "run the threadsafetest"

TESTPRLELQSRT = testPrlelQSrt
TESTPRLELQSRTOBJ = testPrlelQSrt.o
$(TESTPRLELQSRT): $(TESTPRLELQSRTOBJ)  PrlelQSrt.h
	$(CC) -o $(TESTPRLELQSRT) $(LDFLAGS) $(TESTPRLELQSRTOBJ)  >> buildlog 2>&1
test1: $(TESTPRLELQSRT)
	echo "Test correctness of parallel QSort"

TESTLINEARQSORT = testLinrQSrt
TESTLINEARQSORTOBJ = testLinrQSrt.o
$(TESTLINEARQSORT): $(TESTLINEARQSORTOBJ) LinrQSrt.h
	$(CC) -o $(TESTLINEARQSORT) $(LDFLAGS) $(TESTLINEARQSORTOBJ)  >> buildlog 2>&1
test2: $(TESTLINEARQSORT)
	echo "Test correctness of linear QSort"

TESTPERF = comparePerf
TESTPERFOBJ = testperformance.o
$(TESTPERF): $(TESTPERFOBJ)  LinrQSrt.h  PrlelQSrt.h
	$(CC) -o $(TESTPERF) $(LDFLAGS) $(TESTPERFOBJ)  >> buildlog 2>&1
test3: $(TESTPERF)
	echo "Test compare performance of parallel QSort with linear QSort"

all:
	$(test1)
	$(test2)
	$(test3)

clean: 
	-rm -f core
	-rm $(TESTPRLELQSRT)
	-rm $(TESTPRLELQSRTOBJ)
	-rm $(TESTLINEARQSORT)
	-rm $(TESTLINEARQSORTOBJ)
	-rm $(TESTPERF)
	-rm $(TESTPERFOBJ)
	-rm $(TEST_TS_STACK)
	-rm $(TEST_TS_STACKOBJ)
	-make $(CLEAN_CTAGS)
