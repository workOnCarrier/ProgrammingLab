CC = g++

CPPFLAGS = -std=c++0x -I../ -I. -I../hdr -Wall -ggdb -D_GLIBCXX_USE_NANOSLEEP
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o: $<
		$(CC) -c $(CPPFLAGS) -o $@ $<  > build.log 2>&1

TESTUTIL_SRC = test_commonUtils.cpp
UTIL_SRC = ../commonUtils.cpp
UTIL_OBJ = commonUtils.o
TESTUTIL_OBJ = test_commonUtils.o

TARGET_1 = 1_util
TARGET_2 = 2_
TARGET_3 = 3_
TARGET_4 = 4_
TARGET_5 = 5_
TARGET_6 = 6_
TARGET_7 = 7_
TARGET_8 = 8_
TARGET_9 = 9_
TARGET_10 = 10_
TARGET_11 = 11_
TARGET_12 = 12_

all: $(TARGET_1) 
#$(TARGET_2) $(TARGET_3) $(TARGET_4) $(TARGET_5)\
	$(TARGET_6) $(TARGET_7) $(TARGET_8) \
	$(TARGET_9)  $(TARGET_10) \
	$(TARGET_11)

$(UTIL_OBJ): $(UTIL_SRC)
	make -C .. $(UTIL_OBJ)

$(TARGET_1):  ../$(UTIL_OBJ) $(TESTUTIL_OBJ)
	$(CC)  $(TESTUTIL_OBJ)  ../$(UTIL_OBJ) $(LDFLAGS) -o $(TARGET_1) 2>&1  > build.log  ;
	

$(POLL_OBJ):$(POLL_SRC)
$(TARGET_2):  $(POLL_OBJ)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(POLL_OBJ) 2>&1 |tee > build.log  ;

$(WORKBLOCK_OBJ):$(WORKBLOCK_SRC)
$(TARGET_3):  $(WORKBLOCK_OBJ)
	$(CC) -o $(TARGET_3) $(LDFLAGS) $(WORKBLOCK_OBJ) 2>&1 |tee > build.log ;

$(POST_OBJ):$(POST_SRC)
$(TARGET_4):  $(POST_OBJ)
	$(CC) -o $(TARGET_4) $(LDFLAGS) $(POST_OBJ) 2>&1 |tee > build.log ;

$(MUTEXBIND_OBJ):$(MUTEXBIND_SRC)
$(TARGET_5):  $(MUTEXBIND_OBJ)
	$(CC) -o $(TARGET_5) $(LDFLAGS) $(MUTEXBIND_OBJ) 2>&1 |tee > build.log ;

$(DISPATCH_OBJ):$(DISPATCH_SRC)
$(TARGET_6):  $(DISPATCH_OBJ)
	$(CC) -o $(TARGET_6) $(LDFLAGS) $(DISPATCH_OBJ) 2>&1 |tee > build.log 

$(NONSTRAND_OBJ): $(NONSTRAND_SRC)
$(TARGET_7): $(NONSTRAND_OBJ)
	$(CC) -o $(TARGET_7) $(LDFLAGS) $(NONSTRAND_OBJ) 2>&1  > build.log 

$(STRAND_OBJ): $(STRAND_SRC)
$(TARGET_8): $(STRAND_OBJ)
	$(CC) -o $(TARGET_8) $(LDFLAGS) $(STRAND_OBJ) 2>&1  > build.log 

$(STRANDWRAP_OBJ): $(STRANDWRAP_SRC)
$(TARGET_9): $(STRANDWRAP_OBJ)
	$(CC) -o $(TARGET_9) $(LDFLAGS) $(STRANDWRAP_OBJ) 2>&1 |tee > build.log 

$(EXCEPTHANDLE_OBJ): $(EXCEPTHANDLE_SRC)
$(TARGET_10): $(EXCEPTHANDLE_OBJ)
	$(CC) -o $(TARGET_10) $(LDFLAGS) -lboost_thread $(EXCEPTHANDLE_OBJ) 2>&1 |tee > build.log 

$(STRANDTIMER_OBJ): $(STRANDTIMER_SRC)
$(TARGET_11): $(STRANDTIMER_OBJ)
	$(CC) -o $(TARGET_11) $(LDFLAGS) $(STRANDTIMER_OBJ) 2>&1 |tee > build.log 

clean:
	-rm -f $(TARGET_1) $(UTIL_OBJ) $(TESTUTIL_OBJ)
	-rm -f $(TARGET_2) $()
	-rm -f $(TARGET_3) $()
	-rm -f $(TARGET_4) $()
	-rm -f $(TARGET_5) $()
	-rm -f $(TARGET_6) $()
	-rm -f $(TARGET_7) $()
	-rm -f $(TARGET_8) $()
	-rm -f $(TARGET_9) $()
	-rm -f $(TARGET_10) $()
	-rm -f $(TARGET_11) $()

