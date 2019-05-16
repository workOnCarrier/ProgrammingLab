CC = g++-5

CPPFLAGS = -DDEBUG -std=c++14 -I. -I../hdr -Wall -ggdb
LDFLAGS =   -ggdb -lboost_system -lpthread

.cpp.o:
		$(CC) -c $(CPPFLAGS) -o $@ $<  #> buildlog 2>&1

SRC_1 = heaprun.cpp
OBJ_1 = heaprun.o


TARGET_1 = heaprun.exe

all:    $(TARGET_1) 

run:
	./$(TARGET_1)

$(TARGET_1):  $(OBJ_1)
	$(CC) -o $(TARGET_1) $(LDFLAGS) $(OBJ_1) > buildlog 2>&1


clean:
	-rm -f $(TARGET_1) $(OBJ_1)
	-rm -f buildlog

