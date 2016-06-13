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

TARGET_1 = 1_block
TARGET_2 = 2_poll
TARGET_3 = 3_workBlk
TARGET_4 = 4_post
TARGET_5 = 5_mutexbind
TARGET_6 = 6_dispatch


all: $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4) $(TARGET_5) $(TARGET_6)
	 # $(TARGET_1) $(TARGET_2) $(TARGET_3) $(TARGET_4) $(TARGET_5) $(TARGET_6)

$(TARGET_1):  $(BLOCK_OBJ)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(BLOCK_OBJ) 2>&1 |tee > build.log  > less

$(POLL_OBJ):$(POLL_SRC)
$(TARGET_2):  $(POLL_OBJ)
	$(CC) -o $(TARGET_2) $(LDFLAGS) $(POLL_OBJ) 2>&1 |tee > build.log  > less

$(WORKBLOCK_OBJ):$(WORKBLOCK_SRC)
$(TARGET_3):  $(WORKBLOCK_OBJ)
	$(CC) -o $(TARGET_3) $(LDFLAGS) $(WORKBLOCK_OBJ) 2>&1 |tee > build.log  > less

$(POST_OBJ):$(POST_SRC)
$(TARGET_4):  $(POST_OBJ)
	$(CC) -o $(TARGET_4) $(LDFLAGS) $(POST_OBJ) 2>&1 |tee > build.log > less

$(MUTEXBIND_OBJ):$(MUTEXBIND_SRC)
$(TARGET_5):  $(MUTEXBIND_OBJ)
	$(CC) -o $(TARGET_5) $(LDFLAGS) $(MUTEXBIND_OBJ) 2>&1 |tee > build.log > less

$(DISPATCH_OBJ):$(DISPATCH_SRC)
$(TARGET_6):  $(DISPATCH_OBJ)
	$(CC) -o $(TARGET_6) $(LDFLAGS) $(DISPATCH_OBJ) 2>&1 |tee > build.log 

clean:
	-rm -f $(TARGET_1) $(BLOCK_OBJ)
	-rm -f $(TARGET_2) $(POLL_OBJ)
	-rm -f $(TARGET_3) $(WORKBLOCK_OBJ)
	-rm -f $(TARGET_4) $(POST_OBJ)
	-rm -f $(TARGET_5) $(MUTEXBIND_OBJ)
	-rm -f $(TARGET_6) $(DISPATCH_OBJ)