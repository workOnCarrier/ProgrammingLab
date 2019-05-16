CC = g++

CPPFLAGS = -std=c++0x -I. -I../hdr -Wall -ggdb -D_GLIBCXX_USE_NANOSLEEP
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o: $<
		$(CC) -c $(CPPFLAGS) -o $@ $<  > build.log 2>&1

SERVER_SRC = serverMain.cpp
SERVER_OBJ = serverMain.o

CLIENT_SRC = clientMain.cpp
CLIENT_OBJ = clientMain.o


TARGET_1 = server
TARGET_2 = client

all: $(TARGET_1) $(TARGET_2)

$(TARGET_1): $(SERVER_OBJ)
	$(CC)   $(SERVER_OBJ) $(LDFLAGS) -o $(TARGET_1) 2>&1 > build.log 

$(TARGET_2): $(CLIENT_OBJ)
	$(CC)   $(CLIENT_OBJ) $(LDFLAGS) -o $(TARGET_2) 2>&1 > build.log 



clean:
	-rm -f $(TARGET_1) $(SERVER_OBJ)
	-rm -f $(TARGET_2) $(CLIENT_OBJ)
	-rm -f *.o
	-rm -f build.log

