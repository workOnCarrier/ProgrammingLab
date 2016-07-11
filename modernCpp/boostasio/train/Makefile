CC = g++

CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb -D_GLIBCXX_USE_NANOSLEEP
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o: $<
		$(CC) -c $(CPPFLAGS) -o $@ $<  > build.log 2>&1
#		> buildlog 2>&1

BLOCK_SRC = blocked.cpp
BLOCK_OBJ = blocked.o

POLL_SRC = poll.cpp
POLL_OBJ = poll.o

WORKBLOCK_SRC = workBlocked.cpp
WORKBLOCK_OBJ = workBlocked.o

POST_SRC = post.cpp
POST_OBJ = post.o

MUTEXBIND_SRC = mutexbind.cpp
MUTEXBIND_OBJ =  mutexbind.o

DISPATCH_SRC = dispatch.cpp
DISPATCH_OBJ =  dispatch.o

NONSTRAND_SRC = nonStrand.cpp
NONSTRAND_OBJ = nonStrand.o

STRAND_SRC = strand.cpp
STRAND_OBJ = strand.o

STRANDWRAP_SRC = strandwrap.cpp
STRANDWRAP_OBJ = strandwrap.o

EXCEPTHANDLE_SRC = exceptHandle.cpp
EXCEPTHANDLE_OBJ =  exceptHandle.o

TARGET_1 = 1_block
TARGET_2 = 2_poll
TARGET_3 = 3_workBlk
TARGET_4 = 4_post
TARGET_5 = 5_mutexbind
TARGET_6 = 6_dispatch
TARGET_7 = 7_nonStrand
TARGET_8 = 8_strand
TARGET_9 = 9_strandwrap
TARGET_10 = 10_except

all: $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4) $(TARGET_5)\
	$(TARGET_6) $(TARGET_7) $(TARGET_8) \
	$(TARGET_9) \
	$(TARGET_10)
	# $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4) $(TARGET_5) $(TARGET_6) $(TARGET_7) $(TARGET_8) $(TARGET_9) $(TARGET_10)

$(TARGET_1):  $(BLOCK_OBJ)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(BLOCK_OBJ) 2>&1 |tee > build.log  ;

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
	$(CC) -o $(TARGET_7) $(LDFLAGS) $(NONSTRAND_OBJ) 2>&1 |tee > build.log 

$(STRAND_OBJ): $(STRAND_SRC)
$(TARGET_8): $(STRAND_OBJ)
	$(CC) -o $(TARGET_8) $(LDFLAGS) $(STRAND_OBJ) 2>&1 |tee > build.log 

$(STRANDWRAP_OBJ): $(STRANDWRAP_SRC)
$(TARGET_9): $(STRANDWRAP_OBJ)
	$(CC) -o $(TARGET_9) $(LDFLAGS) $(STRANDWRAP_OBJ) 2>&1 |tee > build.log 

$(EXCEPTHANDLE_OBJ): $(EXCEPTHANDLE_SRC)
$(TARGET_10): $(EXCEPTHANDLE_OBJ)
	$(CC) -o $(TARGET_10) $(LDFLAGS) $(EXCEPTHANDLE_OBJ) 2>&1 |tee > build.log 

clean:
	-rm -f $(TARGET_1) $(BLOCK_OBJ)
	-rm -f $(TARGET_2) $(POLL_OBJ)
	-rm -f $(TARGET_3) $(WORKBLOCK_OBJ)
	-rm -f $(TARGET_4) $(POST_OBJ)
	-rm -f $(TARGET_5) $(MUTEXBIND_OBJ)
	-rm -f $(TARGET_6) $(DISPATCH_OBJ)
	-rm -f $(TARGET_7) $(NONSTRAND_OBJ)
	-rm -f $(TARGET_8) $(STRAND_OBJ)
	-rm -f $(TARGET_9) $(STRANDWRAP_OBJ)
	-rm -f $(TARGET_10) $(EXCEPTHANDLE_OBJ)
